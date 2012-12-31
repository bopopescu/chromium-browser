#!/usr/bin/env python
copyright = '''
/*
 * Copyright 2009 VMware, Inc.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * on the rights to use, copy, modify, merge, publish, distribute, sub
 * license, and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  IN NO EVENT SHALL
 * VMWARE AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
'''

GENERATE, UBYTE, USHORT, UINT = 'generate', 'ubyte', 'ushort', 'uint'
FIRST, LAST = 'first', 'last'

INTYPES = (GENERATE, UBYTE, USHORT, UINT)
OUTTYPES = (USHORT, UINT)
PRIMS=('tris', 
       'trifan', 
       'tristrip', 
       'quads', 
       'quadstrip', 
       'polygon')

LONGPRIMS=('PIPE_PRIM_TRIANGLES', 
           'PIPE_PRIM_TRIANGLE_FAN', 
           'PIPE_PRIM_TRIANGLE_STRIP', 
           'PIPE_PRIM_QUADS', 
           'PIPE_PRIM_QUAD_STRIP', 
           'PIPE_PRIM_POLYGON')

longprim = dict(zip(PRIMS, LONGPRIMS))
intype_idx = dict(ubyte='IN_UBYTE', ushort='IN_USHORT', uint='IN_UINT')
outtype_idx = dict(ushort='OUT_USHORT', uint='OUT_UINT')


def prolog():
    print '''/* File automatically generated by u_unfilled_gen.py */'''
    print copyright
    print r'''

/**
 * @file
 * Functions to translate and generate index lists
 */

#include "indices/u_indices.h"
#include "indices/u_indices_priv.h"
#include "pipe/p_compiler.h"
#include "util/u_debug.h"
#include "pipe/p_defines.h"
#include "util/u_memory.h"


static unsigned out_size_idx( unsigned index_size )
{
   switch (index_size) {
   case 4: return OUT_UINT;
   case 2: return OUT_USHORT;
   default: assert(0); return OUT_USHORT;
   }
}

static unsigned in_size_idx( unsigned index_size )
{
   switch (index_size) {
   case 4: return IN_UINT;
   case 2: return IN_USHORT;
   case 1: return IN_UBYTE;
   default: assert(0); return IN_UBYTE;
   }
}


static u_generate_func generate_line[OUT_COUNT][PRIM_COUNT];
static u_translate_func translate_line[IN_COUNT][OUT_COUNT][PRIM_COUNT];

'''

def vert( intype, outtype, v0 ):
    if intype == GENERATE:
        return '(' + outtype + ')(' + v0 + ')'
    else:
        return '(' + outtype + ')in[' + v0 + ']'

def line( intype, outtype, ptr, v0, v1 ):
    print '      (' + ptr + ')[0] = ' + vert( intype, outtype, v0 ) + ';'
    print '      (' + ptr + ')[1] = ' + vert( intype, outtype, v1 ) + ';'

# XXX: have the opportunity here to avoid over-drawing shared lines in
# tristrips, fans, etc, by integrating this into the calling functions
# and only emitting each line at most once.
# 
def do_tri( intype, outtype, ptr, v0, v1, v2 ):
    line( intype, outtype, ptr, v0, v1 )
    line( intype, outtype, ptr + '+2', v1, v2 )
    line( intype, outtype, ptr + '+4', v2, v0 )

def do_quad( intype, outtype, ptr, v0, v1, v2, v3 ):
    line( intype, outtype, ptr, v0, v1 )
    line( intype, outtype, ptr + '+2', v1, v2 )
    line( intype, outtype, ptr + '+4', v2, v3 )
    line( intype, outtype, ptr + '+6', v3, v0 )

def name(intype, outtype, prim):
    if intype == GENERATE:
        return 'generate_' + prim + '_' + outtype
    else:
        return 'translate_' + prim + '_' + intype + '2' + outtype

def preamble(intype, outtype, prim):
    print 'static void ' + name( intype, outtype, prim ) + '('
    if intype != GENERATE:
        print '    const void * _in,'
    print '    unsigned nr,'
    print '    void *_out )'
    print '{'
    if intype != GENERATE:
        print '  const ' + intype + '*in = (const ' + intype + '*)_in;'
    print '  ' + outtype + ' *out = (' + outtype + '*)_out;'
    print '  unsigned i, j;'
    print '  (void)j;'

def postamble():
    print '}'


def tris(intype, outtype):
    preamble(intype, outtype, prim='tris')
    print '  for (j = i = 0; j < nr; j+=6, i+=3) { '
    do_tri( intype, outtype, 'out+j',  'i', 'i+1', 'i+2' );
    print '   }'
    postamble()


def tristrip(intype, outtype):
    preamble(intype, outtype, prim='tristrip')
    print '  for (j = i = 0; j < nr; j+=6, i++) { '
    do_tri( intype, outtype, 'out+j',  'i', 'i+1/*+(i&1)*/', 'i+2/*-(i&1)*/' );
    print '   }'
    postamble()


def trifan(intype, outtype):
    preamble(intype, outtype, prim='trifan')
    print '  for (j = i = 0; j < nr; j+=6, i++) { '
    do_tri( intype, outtype, 'out+j',  '0', 'i+1', 'i+2' );
    print '   }'
    postamble()



def polygon(intype, outtype):
    preamble(intype, outtype, prim='polygon')
    print '  for (j = i = 0; j < nr; j+=6, i++) { '
    do_tri( intype, outtype, 'out+j',  '0', 'i+1', 'i+2' );
    print '   }'
    postamble()


def quads(intype, outtype):
    preamble(intype, outtype, prim='quads')
    print '  for (j = i = 0; j < nr; j+=8, i+=4) { '
    do_quad( intype, outtype, 'out+j', 'i+0', 'i+1', 'i+2', 'i+3' );
    print '   }'
    postamble()


def quadstrip(intype, outtype):
    preamble(intype, outtype, prim='quadstrip')
    print '  for (j = i = 0; j < nr; j+=8, i+=2) { '
    do_quad( intype, outtype, 'out+j', 'i+2', 'i+0', 'i+1', 'i+3' );
    print '   }'
    postamble()


def emit_funcs():
    for intype in INTYPES:
        for outtype in OUTTYPES:
            tris(intype, outtype)
            tristrip(intype, outtype)
            trifan(intype, outtype)
            quads(intype, outtype)
            quadstrip(intype, outtype)
            polygon(intype, outtype)

def init(intype, outtype, prim):
    if intype == GENERATE:
        print ('generate_line[' + 
               outtype_idx[outtype] + 
               '][' + longprim[prim] + 
               '] = ' + name( intype, outtype, prim ) + ';')
    else:
        print ('translate_line[' + 
               intype_idx[intype] + 
               '][' + outtype_idx[outtype] + 
               '][' + longprim[prim] + 
               '] = ' + name( intype, outtype, prim ) + ';')


def emit_all_inits():
    for intype in INTYPES:
        for outtype in OUTTYPES:
            for prim in PRIMS:
                init(intype, outtype, prim)

def emit_init():
    print 'void u_unfilled_init( void )'
    print '{'
    print '  static int firsttime = 1;'
    print '  if (!firsttime) return;'
    print '  firsttime = 0;'
    emit_all_inits()
    print '}'


    

def epilog():
    print '#include "indices/u_unfilled_indices.c"'


def main():
    prolog()
    emit_funcs()
    emit_init()
    epilog()


if __name__ == '__main__':
    main()
