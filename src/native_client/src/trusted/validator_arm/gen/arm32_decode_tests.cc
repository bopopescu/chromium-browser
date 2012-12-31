/*
 * Copyright 2012 The Native Client Authors.  All rights reserved.
 * Use of this source code is governed by a BSD-style license that can
 * be found in the LICENSE file.
 */

// DO NOT EDIT: GENERATED CODE

#ifndef NACL_TRUSTED_BUT_NOT_TCB
#error This file is not meant for use in the TCB
#endif


#include "gtest/gtest.h"
#include "native_client/src/trusted/validator_arm/actual_vs_baseline.h"
#include "native_client/src/trusted/validator_arm/actual_classes.h"
#include "native_client/src/trusted/validator_arm/baseline_classes.h"
#include "native_client/src/trusted/validator_arm/inst_classes_testers.h"

namespace nacl_arm_test {

// Generates a derived class decoder tester for each decoder action
// in the parse tables. This derived class introduces a default
// constructor that automatically initializes the expected decoder
// to the corresponding instance in the generated DecoderState.

class Binary2RegisterBitRangeTester_Bfi_Rule_18_A1_P48_NotRnIsPc
    : public Binary2RegisterBitRangeTesterNotRnIsPc {
 public:
  Binary2RegisterBitRangeTester_Bfi_Rule_18_A1_P48_NotRnIsPc()
    : Binary2RegisterBitRangeTesterNotRnIsPc(
      state_.Binary2RegisterBitRange_Bfi_Rule_18_A1_P48_instance_)
  {}
};

class Binary2RegisterBitRangeNotRnIsPcTester_Sbfx_Rule_154_A1_P308_
    : public Binary2RegisterBitRangeNotRnIsPcTester {
 public:
  Binary2RegisterBitRangeNotRnIsPcTester_Sbfx_Rule_154_A1_P308_()
    : Binary2RegisterBitRangeNotRnIsPcTester(
      state_.Binary2RegisterBitRangeNotRnIsPc_Sbfx_Rule_154_A1_P308_instance_)
  {}
};

class Binary2RegisterBitRangeNotRnIsPcTester_Ubfx_Rule_236_A1_P466_
    : public Binary2RegisterBitRangeNotRnIsPcTester {
 public:
  Binary2RegisterBitRangeNotRnIsPcTester_Ubfx_Rule_236_A1_P466_()
    : Binary2RegisterBitRangeNotRnIsPcTester(
      state_.Binary2RegisterBitRangeNotRnIsPc_Ubfx_Rule_236_A1_P466_instance_)
  {}
};

class Binary2RegisterImmedShiftedTestTester_Cmn_Rule_33_A1_P76_
    : public Binary2RegisterImmedShiftedTestTester {
 public:
  Binary2RegisterImmedShiftedTestTester_Cmn_Rule_33_A1_P76_()
    : Binary2RegisterImmedShiftedTestTester(
      state_.Binary2RegisterImmedShiftedTest_Cmn_Rule_33_A1_P76_instance_)
  {}
};

class Binary2RegisterImmedShiftedTestTester_Cmp_Rule_36_A1_P82_
    : public Binary2RegisterImmedShiftedTestTester {
 public:
  Binary2RegisterImmedShiftedTestTester_Cmp_Rule_36_A1_P82_()
    : Binary2RegisterImmedShiftedTestTester(
      state_.Binary2RegisterImmedShiftedTest_Cmp_Rule_36_A1_P82_instance_)
  {}
};

class Binary2RegisterImmedShiftedTestTester_Teq_Rule_228_A1_P450_
    : public Binary2RegisterImmedShiftedTestTester {
 public:
  Binary2RegisterImmedShiftedTestTester_Teq_Rule_228_A1_P450_()
    : Binary2RegisterImmedShiftedTestTester(
      state_.Binary2RegisterImmedShiftedTest_Teq_Rule_228_A1_P450_instance_)
  {}
};

class Binary2RegisterImmedShiftedTestTester_Tst_Rule_231_A1_P456_
    : public Binary2RegisterImmedShiftedTestTester {
 public:
  Binary2RegisterImmedShiftedTestTester_Tst_Rule_231_A1_P456_()
    : Binary2RegisterImmedShiftedTestTester(
      state_.Binary2RegisterImmedShiftedTest_Tst_Rule_231_A1_P456_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_Adc_Rule_6_A1_P14_NotRdIsPcAndS
    : public Binary2RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Binary2RegisterImmediateOpTester_Adc_Rule_6_A1_P14_NotRdIsPcAndS()
    : Binary2RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Binary2RegisterImmediateOp_Adc_Rule_6_A1_P14_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_Add_Rule_5_A1_P22_NeitherRdIsPcAndSNorRnIsPcAndNotS
    : public Binary2RegisterImmediateOpTesterNeitherRdIsPcAndSNorRnIsPcAndNotS {
 public:
  Binary2RegisterImmediateOpTester_Add_Rule_5_A1_P22_NeitherRdIsPcAndSNorRnIsPcAndNotS()
    : Binary2RegisterImmediateOpTesterNeitherRdIsPcAndSNorRnIsPcAndNotS(
      state_.Binary2RegisterImmediateOp_Add_Rule_5_A1_P22_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_And_Rule_11_A1_P34_NotRdIsPcAndS
    : public Binary2RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Binary2RegisterImmediateOpTester_And_Rule_11_A1_P34_NotRdIsPcAndS()
    : Binary2RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Binary2RegisterImmediateOp_And_Rule_11_A1_P34_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_Eor_Rule_44_A1_P94_NotRdIsPcAndS
    : public Binary2RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Binary2RegisterImmediateOpTester_Eor_Rule_44_A1_P94_NotRdIsPcAndS()
    : Binary2RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Binary2RegisterImmediateOp_Eor_Rule_44_A1_P94_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_Orr_Rule_113_A1_P228_NotRdIsPcAndS
    : public Binary2RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Binary2RegisterImmediateOpTester_Orr_Rule_113_A1_P228_NotRdIsPcAndS()
    : Binary2RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Binary2RegisterImmediateOp_Orr_Rule_113_A1_P228_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_Rsb_Rule_142_A1_P284_NotRdIsPcAndS
    : public Binary2RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Binary2RegisterImmediateOpTester_Rsb_Rule_142_A1_P284_NotRdIsPcAndS()
    : Binary2RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Binary2RegisterImmediateOp_Rsb_Rule_142_A1_P284_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_Rsc_Rule_145_A1_P290_NotRdIsPcAndS
    : public Binary2RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Binary2RegisterImmediateOpTester_Rsc_Rule_145_A1_P290_NotRdIsPcAndS()
    : Binary2RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Binary2RegisterImmediateOp_Rsc_Rule_145_A1_P290_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_Sbc_Rule_151_A1_P302_NotRdIsPcAndS
    : public Binary2RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Binary2RegisterImmediateOpTester_Sbc_Rule_151_A1_P302_NotRdIsPcAndS()
    : Binary2RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Binary2RegisterImmediateOp_Sbc_Rule_151_A1_P302_instance_)
  {}
};

class Binary2RegisterImmediateOpTester_Sub_Rule_212_A1_P420_NeitherRdIsPcAndSNorRnIsPcAndNotS
    : public Binary2RegisterImmediateOpTesterNeitherRdIsPcAndSNorRnIsPcAndNotS {
 public:
  Binary2RegisterImmediateOpTester_Sub_Rule_212_A1_P420_NeitherRdIsPcAndSNorRnIsPcAndNotS()
    : Binary2RegisterImmediateOpTesterNeitherRdIsPcAndSNorRnIsPcAndNotS(
      state_.Binary2RegisterImmediateOp_Sub_Rule_212_A1_P420_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Adc_Rule_2_A1_P16_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Adc_Rule_2_A1_P16_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Adc_Rule_2_A1_P16_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Add_Rule_6_A1_P24_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Add_Rule_6_A1_P24_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Add_Rule_6_A1_P24_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_And_Rule_7_A1_P36_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_And_Rule_7_A1_P36_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_And_Rule_7_A1_P36_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Bic_Rule_20_A1_P52_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Bic_Rule_20_A1_P52_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Bic_Rule_20_A1_P52_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Eor_Rule_45_A1_P96_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Eor_Rule_45_A1_P96_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Eor_Rule_45_A1_P96_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Orr_Rule_114_A1_P230_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Orr_Rule_114_A1_P230_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Orr_Rule_114_A1_P230_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Rsb_Rule_143_P286_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Rsb_Rule_143_P286_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Rsb_Rule_143_P286_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Rsc_Rule_146_A1_P292_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Rsc_Rule_146_A1_P292_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Rsc_Rule_146_A1_P292_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Sbc_Rule_152_A1_P304_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Sbc_Rule_152_A1_P304_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Sbc_Rule_152_A1_P304_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpTester_Sub_Rule_213_A1_P422_NotRdIsPcAndS
    : public Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Binary3RegisterImmedShiftedOpTester_Sub_Rule_213_A1_P422_NotRdIsPcAndS()
    : Binary3RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Binary3RegisterImmedShiftedOp_Sub_Rule_213_A1_P422_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpRegsNotPcTester_Pkh_Rule_116_A1_P234_RegsNotPc
    : public Binary3RegisterImmedShiftedOpTesterRegsNotPc {
 public:
  Binary3RegisterImmedShiftedOpRegsNotPcTester_Pkh_Rule_116_A1_P234_RegsNotPc()
    : Binary3RegisterImmedShiftedOpTesterRegsNotPc(
      state_.Binary3RegisterImmedShiftedOpRegsNotPc_Pkh_Rule_116_A1_P234_instance_)
  {}
};

class Binary3RegisterImmedShiftedOpRegsNotPcTester_Sxtab16_Rule_221_A1_P436_NotRnIsPcAndRegsNotPc
    : public Binary3RegisterImmedShiftedOpTesterNotRnIsPcAndRegsNotPc {
 public:
  Binary3RegisterImmedShiftedOpRegsNotPcTester_Sxtab16_Rule_221_A1_P436_NotRnIsPcAndRegsNotPc()
    : Binary3RegisterImmedShiftedOpTesterNotRnIsPcAndRegsNotPc(
      state_.Binary3RegisterImmedShiftedOpRegsNotPc_Sxtab16_Rule_221_A1_P436_instance_)
  {}
};

class Binary3RegisterOpTester_Asr_Rule_15_A1_P42_RegsNotPc
    : public Binary3RegisterOpTesterRegsNotPc {
 public:
  Binary3RegisterOpTester_Asr_Rule_15_A1_P42_RegsNotPc()
    : Binary3RegisterOpTesterRegsNotPc(
      state_.Binary3RegisterOp_Asr_Rule_15_A1_P42_instance_)
  {}
};

class Binary3RegisterOpTester_Lsl_Rule_89_A1_P180_RegsNotPc
    : public Binary3RegisterOpTesterRegsNotPc {
 public:
  Binary3RegisterOpTester_Lsl_Rule_89_A1_P180_RegsNotPc()
    : Binary3RegisterOpTesterRegsNotPc(
      state_.Binary3RegisterOp_Lsl_Rule_89_A1_P180_instance_)
  {}
};

class Binary3RegisterOpTester_Lsr_Rule_91_A1_P184_RegsNotPc
    : public Binary3RegisterOpTesterRegsNotPc {
 public:
  Binary3RegisterOpTester_Lsr_Rule_91_A1_P184_RegsNotPc()
    : Binary3RegisterOpTesterRegsNotPc(
      state_.Binary3RegisterOp_Lsr_Rule_91_A1_P184_instance_)
  {}
};

class Binary3RegisterOpTester_Ror_Rule_140_A1_P280_RegsNotPc
    : public Binary3RegisterOpTesterRegsNotPc {
 public:
  Binary3RegisterOpTester_Ror_Rule_140_A1_P280_RegsNotPc()
    : Binary3RegisterOpTesterRegsNotPc(
      state_.Binary3RegisterOp_Ror_Rule_140_A1_P280_instance_)
  {}
};

class Binary3RegisterOpAltATester_Mul_Rule_105_A1_P212_RegsNotPc
    : public Binary3RegisterOpAltATesterRegsNotPc {
 public:
  Binary3RegisterOpAltATester_Mul_Rule_105_A1_P212_RegsNotPc()
    : Binary3RegisterOpAltATesterRegsNotPc(
      state_.Binary3RegisterOpAltA_Mul_Rule_105_A1_P212_instance_)
  {}
};

class Binary3RegisterOpAltATester_Smmul_Rule_176_P350_RegsNotPc
    : public Binary3RegisterOpAltATesterRegsNotPc {
 public:
  Binary3RegisterOpAltATester_Smmul_Rule_176_P350_RegsNotPc()
    : Binary3RegisterOpAltATesterRegsNotPc(
      state_.Binary3RegisterOpAltA_Smmul_Rule_176_P350_instance_)
  {}
};

class Binary3RegisterOpAltATester_Smuad_Rule_177_P352_RegsNotPc
    : public Binary3RegisterOpAltATesterRegsNotPc {
 public:
  Binary3RegisterOpAltATester_Smuad_Rule_177_P352_RegsNotPc()
    : Binary3RegisterOpAltATesterRegsNotPc(
      state_.Binary3RegisterOpAltA_Smuad_Rule_177_P352_instance_)
  {}
};

class Binary3RegisterOpAltATester_Smulwx_Rule_180_A1_P358_RegsNotPc
    : public Binary3RegisterOpAltATesterRegsNotPc {
 public:
  Binary3RegisterOpAltATester_Smulwx_Rule_180_A1_P358_RegsNotPc()
    : Binary3RegisterOpAltATesterRegsNotPc(
      state_.Binary3RegisterOpAltA_Smulwx_Rule_180_A1_P358_instance_)
  {}
};

class Binary3RegisterOpAltATester_Smulxx_Rule_178_P354_RegsNotPc
    : public Binary3RegisterOpAltATesterRegsNotPc {
 public:
  Binary3RegisterOpAltATester_Smulxx_Rule_178_P354_RegsNotPc()
    : Binary3RegisterOpAltATesterRegsNotPc(
      state_.Binary3RegisterOpAltA_Smulxx_Rule_178_P354_instance_)
  {}
};

class Binary3RegisterOpAltATester_Smusd_Rule_181_P360_RegsNotPc
    : public Binary3RegisterOpAltATesterRegsNotPc {
 public:
  Binary3RegisterOpAltATester_Smusd_Rule_181_P360_RegsNotPc()
    : Binary3RegisterOpAltATesterRegsNotPc(
      state_.Binary3RegisterOpAltA_Smusd_Rule_181_P360_instance_)
  {}
};

class Binary3RegisterOpAltATester_Usad8_Rule_253_A1_P500_RegsNotPc
    : public Binary3RegisterOpAltATesterRegsNotPc {
 public:
  Binary3RegisterOpAltATester_Usad8_Rule_253_A1_P500_RegsNotPc()
    : Binary3RegisterOpAltATesterRegsNotPc(
      state_.Binary3RegisterOpAltA_Usad8_Rule_253_A1_P500_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qadd16_Rule_125_A1_P252_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qadd16_Rule_125_A1_P252_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qadd16_Rule_125_A1_P252_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qadd8_Rule_126_A1_P254_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qadd8_Rule_126_A1_P254_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qadd8_Rule_126_A1_P254_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qadd_Rule_124_A1_P250_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qadd_Rule_124_A1_P250_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qadd_Rule_124_A1_P250_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qasx_Rule_127_A1_P256_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qasx_Rule_127_A1_P256_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qasx_Rule_127_A1_P256_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qdadd_Rule_128_A1_P258_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qdadd_Rule_128_A1_P258_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qdadd_Rule_128_A1_P258_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qdsub_Rule_129_A1_P260_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qdsub_Rule_129_A1_P260_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qdsub_Rule_129_A1_P260_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qsax_Rule_130_A1_P262_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qsax_Rule_130_A1_P262_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qsax_Rule_130_A1_P262_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qsub16_Rule_132_A1_P266_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qsub16_Rule_132_A1_P266_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qsub16_Rule_132_A1_P266_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qsub8_Rule_133_A1_P268_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qsub8_Rule_133_A1_P268_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qsub8_Rule_133_A1_P268_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Qsub_Rule_131_A1_P264_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Qsub_Rule_131_A1_P264_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Qsub_Rule_131_A1_P264_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Sadd16_Rule_148_A1_P296_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Sadd16_Rule_148_A1_P296_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Sadd16_Rule_148_A1_P296_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Sasx_Rule_150_A1_P300_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Sasx_Rule_150_A1_P300_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Sasx_Rule_150_A1_P300_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Sel_Rule_156_A1_P312_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Sel_Rule_156_A1_P312_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Sel_Rule_156_A1_P312_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Ssad8_Rule_149_A1_P298_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Ssad8_Rule_149_A1_P298_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Ssad8_Rule_149_A1_P298_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Ssax_Rule_185_A1_P366_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Ssax_Rule_185_A1_P366_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Ssax_Rule_185_A1_P366_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Ssub16_Rule_186_A1_P368_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Ssub16_Rule_186_A1_P368_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Ssub16_Rule_186_A1_P368_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Ssub8_Rule_187_A1_P370_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Ssub8_Rule_187_A1_P370_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Ssub8_Rule_187_A1_P370_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Sxtab_Rule_220_A1_P434_NotRnIsPcAndRegsNotPc
    : public Binary3RegisterOpAltBTesterNotRnIsPcAndRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Sxtab_Rule_220_A1_P434_NotRnIsPcAndRegsNotPc()
    : Binary3RegisterOpAltBTesterNotRnIsPcAndRegsNotPc(
      state_.Binary3RegisterOpAltB_Sxtab_Rule_220_A1_P434_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uadd16_Rule_233_A1_P460_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uadd16_Rule_233_A1_P460_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uadd16_Rule_233_A1_P460_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uadd8_Rule_234_A1_P462_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uadd8_Rule_234_A1_P462_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uadd8_Rule_234_A1_P462_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uasx_Rule_235_A1_P464_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uasx_Rule_235_A1_P464_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uasx_Rule_235_A1_P464_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uqadd16_Rule_247_A1_P488_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uqadd16_Rule_247_A1_P488_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uqadd16_Rule_247_A1_P488_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uqadd8_Rule_248_A1_P490_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uqadd8_Rule_248_A1_P490_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uqadd8_Rule_248_A1_P490_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uqasx_Rule_249_A1_P492_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uqasx_Rule_249_A1_P492_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uqasx_Rule_249_A1_P492_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uqsax_Rule_250_A1_P494_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uqsax_Rule_250_A1_P494_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uqsax_Rule_250_A1_P494_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uqsub16_Rule_251_A1_P496_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uqsub16_Rule_251_A1_P496_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uqsub16_Rule_251_A1_P496_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Uqsub8_Rule_252_A1_P498_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Uqsub8_Rule_252_A1_P498_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Uqsub8_Rule_252_A1_P498_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Usax_Rule_257_A1_P508_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Usax_Rule_257_A1_P508_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Usax_Rule_257_A1_P508_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Usub16_Rule_258_A1_P510_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Usub16_Rule_258_A1_P510_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Usub16_Rule_258_A1_P510_instance_)
  {}
};

class Binary3RegisterOpAltBTester_Usub8_Rule_259_A1_P512_RegsNotPc
    : public Binary3RegisterOpAltBTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBTester_Usub8_Rule_259_A1_P512_RegsNotPc()
    : Binary3RegisterOpAltBTesterRegsNotPc(
      state_.Binary3RegisterOpAltB_Usub8_Rule_259_A1_P512_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Shadd16_Rule_159_A1_P318_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Shadd16_Rule_159_A1_P318_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Shadd16_Rule_159_A1_P318_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Shadd8_Rule_160_A1_P320_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Shadd8_Rule_160_A1_P320_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Shadd8_Rule_160_A1_P320_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Shasx_Rule_161_A1_P322_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Shasx_Rule_161_A1_P322_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Shasx_Rule_161_A1_P322_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Shsax_Rule_162_A1_P324_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Shsax_Rule_162_A1_P324_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Shsax_Rule_162_A1_P324_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Shsub16_Rule_163_A1_P326_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Shsub16_Rule_163_A1_P326_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Shsub16_Rule_163_A1_P326_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Shsub8_Rule_164_A1_P328_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Shsub8_Rule_164_A1_P328_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Shsub8_Rule_164_A1_P328_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Sxtah_Rule_222_A1_P438_NotRnIsPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterNotRnIsPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Sxtah_Rule_222_A1_P438_NotRnIsPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterNotRnIsPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Sxtah_Rule_222_A1_P438_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uhadd16_Rule_238_A1_P470_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhadd16_Rule_238_A1_P470_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uhadd16_Rule_238_A1_P470_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uhadd8_Rule_239_A1_P472_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhadd8_Rule_239_A1_P472_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uhadd8_Rule_239_A1_P472_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uhasx_Rule_240_A1_P474_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhasx_Rule_240_A1_P474_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uhasx_Rule_240_A1_P474_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uhsax_Rule_241_A1_P476_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhsax_Rule_241_A1_P476_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uhsax_Rule_241_A1_P476_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uhsub16_Rule_242_A1_P478_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhsub16_Rule_242_A1_P478_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uhsub16_Rule_242_A1_P478_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uhsub8_Rule_243_A1_P480_RegsNotPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhsub8_Rule_243_A1_P480_RegsNotPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterRegsNotPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uhsub8_Rule_243_A1_P480_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uxtab_Rule_260_A1_P514_NotRnIsPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterNotRnIsPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uxtab_Rule_260_A1_P514_NotRnIsPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterNotRnIsPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uxtab_Rule_260_A1_P514_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uxtah_Rule_262_A1_P516_NotRnIsPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterNotRnIsPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uxtah_Rule_262_A1_P516_NotRnIsPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterNotRnIsPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uxtah_Rule_262_A1_P516_instance_)
  {}
};

class Binary3RegisterOpAltBNoCondUpdatesTester_Uxtah_Rule_262_A1_P518_NotRnIsPc
    : public Binary3RegisterOpAltBNoCondUpdatesTesterNotRnIsPc {
 public:
  Binary3RegisterOpAltBNoCondUpdatesTester_Uxtah_Rule_262_A1_P518_NotRnIsPc()
    : Binary3RegisterOpAltBNoCondUpdatesTesterNotRnIsPc(
      state_.Binary3RegisterOpAltBNoCondUpdates_Uxtah_Rule_262_A1_P518_instance_)
  {}
};

class Binary3RegisterShiftedTestTester_Cmn_Rule_34_A1_P78_RegsNotPc
    : public Binary3RegisterShiftedTestTesterRegsNotPc {
 public:
  Binary3RegisterShiftedTestTester_Cmn_Rule_34_A1_P78_RegsNotPc()
    : Binary3RegisterShiftedTestTesterRegsNotPc(
      state_.Binary3RegisterShiftedTest_Cmn_Rule_34_A1_P78_instance_)
  {}
};

class Binary3RegisterShiftedTestTester_Cmp_Rule_37_A1_P84_RegsNotPc
    : public Binary3RegisterShiftedTestTesterRegsNotPc {
 public:
  Binary3RegisterShiftedTestTester_Cmp_Rule_37_A1_P84_RegsNotPc()
    : Binary3RegisterShiftedTestTesterRegsNotPc(
      state_.Binary3RegisterShiftedTest_Cmp_Rule_37_A1_P84_instance_)
  {}
};

class Binary3RegisterShiftedTestTester_Teq_Rule_229_A1_P452_RegsNotPc
    : public Binary3RegisterShiftedTestTesterRegsNotPc {
 public:
  Binary3RegisterShiftedTestTester_Teq_Rule_229_A1_P452_RegsNotPc()
    : Binary3RegisterShiftedTestTesterRegsNotPc(
      state_.Binary3RegisterShiftedTest_Teq_Rule_229_A1_P452_instance_)
  {}
};

class Binary3RegisterShiftedTestTester_Tst_Rule_232_A1_P458_RegsNotPc
    : public Binary3RegisterShiftedTestTesterRegsNotPc {
 public:
  Binary3RegisterShiftedTestTester_Tst_Rule_232_A1_P458_RegsNotPc()
    : Binary3RegisterShiftedTestTesterRegsNotPc(
      state_.Binary3RegisterShiftedTest_Tst_Rule_232_A1_P458_instance_)
  {}
};

class Binary4RegisterDualOpTester_Mla_Rule_94_A1_P190_RegsNotPc
    : public Binary4RegisterDualOpTesterRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Mla_Rule_94_A1_P190_RegsNotPc()
    : Binary4RegisterDualOpTesterRegsNotPc(
      state_.Binary4RegisterDualOp_Mla_Rule_94_A1_P190_instance_)
  {}
};

class Binary4RegisterDualOpTester_Mls_Rule_95_A1_P192_RegsNotPc
    : public Binary4RegisterDualOpTesterRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Mls_Rule_95_A1_P192_RegsNotPc()
    : Binary4RegisterDualOpTesterRegsNotPc(
      state_.Binary4RegisterDualOp_Mls_Rule_95_A1_P192_instance_)
  {}
};

class Binary4RegisterDualOpTester_Smlad_Rule_167_P332_NotRaIsPcAndRegsNotPc
    : public Binary4RegisterDualOpTesterNotRaIsPcAndRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Smlad_Rule_167_P332_NotRaIsPcAndRegsNotPc()
    : Binary4RegisterDualOpTesterNotRaIsPcAndRegsNotPc(
      state_.Binary4RegisterDualOp_Smlad_Rule_167_P332_instance_)
  {}
};

class Binary4RegisterDualOpTester_Smlawx_Rule_171_A1_340_RegsNotPc
    : public Binary4RegisterDualOpTesterRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Smlawx_Rule_171_A1_340_RegsNotPc()
    : Binary4RegisterDualOpTesterRegsNotPc(
      state_.Binary4RegisterDualOp_Smlawx_Rule_171_A1_340_instance_)
  {}
};

class Binary4RegisterDualOpTester_Smlaxx_Rule_166_A1_P330_RegsNotPc
    : public Binary4RegisterDualOpTesterRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Smlaxx_Rule_166_A1_P330_RegsNotPc()
    : Binary4RegisterDualOpTesterRegsNotPc(
      state_.Binary4RegisterDualOp_Smlaxx_Rule_166_A1_P330_instance_)
  {}
};

class Binary4RegisterDualOpTester_Smlsd_Rule_172_P342_NotRaIsPcAndRegsNotPc
    : public Binary4RegisterDualOpTesterNotRaIsPcAndRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Smlsd_Rule_172_P342_NotRaIsPcAndRegsNotPc()
    : Binary4RegisterDualOpTesterNotRaIsPcAndRegsNotPc(
      state_.Binary4RegisterDualOp_Smlsd_Rule_172_P342_instance_)
  {}
};

class Binary4RegisterDualOpTester_Smmla_Rule_174_P346_NotRaIsPcAndRegsNotPc
    : public Binary4RegisterDualOpTesterNotRaIsPcAndRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Smmla_Rule_174_P346_NotRaIsPcAndRegsNotPc()
    : Binary4RegisterDualOpTesterNotRaIsPcAndRegsNotPc(
      state_.Binary4RegisterDualOp_Smmla_Rule_174_P346_instance_)
  {}
};

class Binary4RegisterDualOpTester_Smmls_Rule_175_P348_RegsNotPc
    : public Binary4RegisterDualOpTesterRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Smmls_Rule_175_P348_RegsNotPc()
    : Binary4RegisterDualOpTesterRegsNotPc(
      state_.Binary4RegisterDualOp_Smmls_Rule_175_P348_instance_)
  {}
};

class Binary4RegisterDualOpTester_Usda8_Rule_254_A1_P502_NotRaIsPcAndRegsNotPc
    : public Binary4RegisterDualOpTesterNotRaIsPcAndRegsNotPc {
 public:
  Binary4RegisterDualOpTester_Usda8_Rule_254_A1_P502_NotRaIsPcAndRegsNotPc()
    : Binary4RegisterDualOpTesterNotRaIsPcAndRegsNotPc(
      state_.Binary4RegisterDualOp_Usda8_Rule_254_A1_P502_instance_)
  {}
};

class Binary4RegisterDualResultTester_Smlal_Rule_168_A1_P334_RegsNotPc
    : public Binary4RegisterDualResultTesterRegsNotPc {
 public:
  Binary4RegisterDualResultTester_Smlal_Rule_168_A1_P334_RegsNotPc()
    : Binary4RegisterDualResultTesterRegsNotPc(
      state_.Binary4RegisterDualResult_Smlal_Rule_168_A1_P334_instance_)
  {}
};

class Binary4RegisterDualResultTester_Smlald_Rule_170_P336_RegsNotPc
    : public Binary4RegisterDualResultTesterRegsNotPc {
 public:
  Binary4RegisterDualResultTester_Smlald_Rule_170_P336_RegsNotPc()
    : Binary4RegisterDualResultTesterRegsNotPc(
      state_.Binary4RegisterDualResult_Smlald_Rule_170_P336_instance_)
  {}
};

class Binary4RegisterDualResultTester_Smlalxx_Rule_169_A1_P336_RegsNotPc
    : public Binary4RegisterDualResultTesterRegsNotPc {
 public:
  Binary4RegisterDualResultTester_Smlalxx_Rule_169_A1_P336_RegsNotPc()
    : Binary4RegisterDualResultTesterRegsNotPc(
      state_.Binary4RegisterDualResult_Smlalxx_Rule_169_A1_P336_instance_)
  {}
};

class Binary4RegisterDualResultTester_Smlsld_Rule_173_P344_RegsNotPc
    : public Binary4RegisterDualResultTesterRegsNotPc {
 public:
  Binary4RegisterDualResultTester_Smlsld_Rule_173_P344_RegsNotPc()
    : Binary4RegisterDualResultTesterRegsNotPc(
      state_.Binary4RegisterDualResult_Smlsld_Rule_173_P344_instance_)
  {}
};

class Binary4RegisterDualResultTester_Smull_Rule_179_A1_P356_RegsNotPc
    : public Binary4RegisterDualResultTesterRegsNotPc {
 public:
  Binary4RegisterDualResultTester_Smull_Rule_179_A1_P356_RegsNotPc()
    : Binary4RegisterDualResultTesterRegsNotPc(
      state_.Binary4RegisterDualResult_Smull_Rule_179_A1_P356_instance_)
  {}
};

class Binary4RegisterDualResultTester_Umaal_Rule_244_A1_P482_RegsNotPc
    : public Binary4RegisterDualResultTesterRegsNotPc {
 public:
  Binary4RegisterDualResultTester_Umaal_Rule_244_A1_P482_RegsNotPc()
    : Binary4RegisterDualResultTesterRegsNotPc(
      state_.Binary4RegisterDualResult_Umaal_Rule_244_A1_P482_instance_)
  {}
};

class Binary4RegisterDualResultTester_Umlal_Rule_245_A1_P484_RegsNotPc
    : public Binary4RegisterDualResultTesterRegsNotPc {
 public:
  Binary4RegisterDualResultTester_Umlal_Rule_245_A1_P484_RegsNotPc()
    : Binary4RegisterDualResultTesterRegsNotPc(
      state_.Binary4RegisterDualResult_Umlal_Rule_245_A1_P484_instance_)
  {}
};

class Binary4RegisterDualResultTester_Umull_Rule_246_A1_P486_RegsNotPc
    : public Binary4RegisterDualResultTesterRegsNotPc {
 public:
  Binary4RegisterDualResultTester_Umull_Rule_246_A1_P486_RegsNotPc()
    : Binary4RegisterDualResultTesterRegsNotPc(
      state_.Binary4RegisterDualResult_Umull_Rule_246_A1_P486_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Adc_Rule_3_A1_P18_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Adc_Rule_3_A1_P18_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Adc_Rule_3_A1_P18_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Add_Rule_7_A1_P26_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Add_Rule_7_A1_P26_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Add_Rule_7_A1_P26_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_And_Rule_13_A1_P38_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_And_Rule_13_A1_P38_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_And_Rule_13_A1_P38_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Bic_Rule_21_A1_P54_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Bic_Rule_21_A1_P54_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Bic_Rule_21_A1_P54_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Eor_Rule_46_A1_P98_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Eor_Rule_46_A1_P98_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Eor_Rule_46_A1_P98_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Orr_Rule_115_A1_P212_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Orr_Rule_115_A1_P212_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Orr_Rule_115_A1_P212_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Rsb_Rule_144_A1_P288_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Rsb_Rule_144_A1_P288_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Rsb_Rule_144_A1_P288_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Rsc_Rule_147_A1_P294_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Rsc_Rule_147_A1_P294_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Rsc_Rule_147_A1_P294_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Sbc_Rule_153_A1_P306_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Sbc_Rule_153_A1_P306_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Sbc_Rule_153_A1_P306_instance_)
  {}
};

class Binary4RegisterShiftedOpTester_Sub_Rule_214_A1_P424_RegsNotPc
    : public Binary4RegisterShiftedOpTesterRegsNotPc {
 public:
  Binary4RegisterShiftedOpTester_Sub_Rule_214_A1_P424_RegsNotPc()
    : Binary4RegisterShiftedOpTesterRegsNotPc(
      state_.Binary4RegisterShiftedOp_Sub_Rule_214_A1_P424_instance_)
  {}
};

class BinaryRegisterImmediateTestTester_Cmn_Rule_32_A1_P74_
    : public BinaryRegisterImmediateTestTester {
 public:
  BinaryRegisterImmediateTestTester_Cmn_Rule_32_A1_P74_()
    : BinaryRegisterImmediateTestTester(
      state_.BinaryRegisterImmediateTest_Cmn_Rule_32_A1_P74_instance_)
  {}
};

class BinaryRegisterImmediateTestTester_Cmp_Rule_35_A1_P80_
    : public BinaryRegisterImmediateTestTester {
 public:
  BinaryRegisterImmediateTestTester_Cmp_Rule_35_A1_P80_()
    : BinaryRegisterImmediateTestTester(
      state_.BinaryRegisterImmediateTest_Cmp_Rule_35_A1_P80_instance_)
  {}
};

class BinaryRegisterImmediateTestTester_Teq_Rule_227_A1_P448_
    : public BinaryRegisterImmediateTestTester {
 public:
  BinaryRegisterImmediateTestTester_Teq_Rule_227_A1_P448_()
    : BinaryRegisterImmediateTestTester(
      state_.BinaryRegisterImmediateTest_Teq_Rule_227_A1_P448_instance_)
  {}
};

class BranchImmediate24Tester_B_Rule_16_A1_P44_
    : public BranchImmediate24Tester {
 public:
  BranchImmediate24Tester_B_Rule_16_A1_P44_()
    : BranchImmediate24Tester(
      state_.BranchImmediate24_B_Rule_16_A1_P44_instance_)
  {}
};

class BranchImmediate24Tester_Bl_Blx_Rule_23_A1_P58_
    : public BranchImmediate24Tester {
 public:
  BranchImmediate24Tester_Bl_Blx_Rule_23_A1_P58_()
    : BranchImmediate24Tester(
      state_.BranchImmediate24_Bl_Blx_Rule_23_A1_P58_instance_)
  {}
};

class BranchToRegisterTester_Blx_Rule_24_A1_P60_RegsNotPc
    : public BranchToRegisterTesterRegsNotPc {
 public:
  BranchToRegisterTester_Blx_Rule_24_A1_P60_RegsNotPc()
    : BranchToRegisterTesterRegsNotPc(
      state_.BranchToRegister_Blx_Rule_24_A1_P60_instance_)
  {}
};

class BranchToRegisterTester_Bx_Rule_25_A1_P62_
    : public BranchToRegisterTester {
 public:
  BranchToRegisterTester_Bx_Rule_25_A1_P62_()
    : BranchToRegisterTester(
      state_.BranchToRegister_Bx_Rule_25_A1_P62_instance_)
  {}
};

class BreakPointAndConstantPoolHeadTester_Bkpt_Rule_22_A1_P56_
    : public Immediate16UseTester {
 public:
  BreakPointAndConstantPoolHeadTester_Bkpt_Rule_22_A1_P56_()
    : Immediate16UseTester(
      state_.BreakPointAndConstantPoolHead_Bkpt_Rule_22_A1_P56_instance_)
  {}
};

class CondNopTester_Dbg_Rule_40_A1_P88_
    : public CondNopTester {
 public:
  CondNopTester_Dbg_Rule_40_A1_P88_()
    : CondNopTester(
      state_.CondNop_Dbg_Rule_40_A1_P88_instance_)
  {}
};

class CondNopTester_Nop_Rule_110_A1_P222_
    : public CondNopTester {
 public:
  CondNopTester_Nop_Rule_110_A1_P222_()
    : CondNopTester(
      state_.CondNop_Nop_Rule_110_A1_P222_instance_)
  {}
};

class CondNopTester_Yield_Rule_413_A1_P812_
    : public CondNopTester {
 public:
  CondNopTester_Yield_Rule_413_A1_P812_()
    : CondNopTester(
      state_.CondNop_Yield_Rule_413_A1_P812_instance_)
  {}
};

class CondVfpOpTester_Vabs_Rule_269_A2_P532_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vabs_Rule_269_A2_P532_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vabs_Rule_269_A2_P532_instance_)
  {}
};

class CondVfpOpTester_Vadd_Rule_271_A2_P536_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vadd_Rule_271_A2_P536_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vadd_Rule_271_A2_P536_instance_)
  {}
};

class CondVfpOpTester_Vcmp_Vcmpe_Rule_292_A1_P572_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vcmp_Vcmpe_Rule_292_A1_P572_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vcmp_Vcmpe_Rule_292_A1_P572_instance_)
  {}
};

class CondVfpOpTester_Vcmp_Vcmpe_Rule_292_A2_P572_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vcmp_Vcmpe_Rule_292_A2_P572_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vcmp_Vcmpe_Rule_292_A2_P572_instance_)
  {}
};

class CondVfpOpTester_Vcvt_Rule_297_A1_P582_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vcvt_Rule_297_A1_P582_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vcvt_Rule_297_A1_P582_instance_)
  {}
};

class CondVfpOpTester_Vcvt_Rule_298_A1_P584_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vcvt_Rule_298_A1_P584_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vcvt_Rule_298_A1_P584_instance_)
  {}
};

class CondVfpOpTester_Vcvt_Vcvtr_Rule_295_A1_P578_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vcvt_Vcvtr_Rule_295_A1_P578_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vcvt_Vcvtr_Rule_295_A1_P578_instance_)
  {}
};

class CondVfpOpTester_Vcvtb_Vcvtt_Rule_300_A1_P588_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vcvtb_Vcvtt_Rule_300_A1_P588_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vcvtb_Vcvtt_Rule_300_A1_P588_instance_)
  {}
};

class CondVfpOpTester_Vdiv_Rule_301_A1_P590_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vdiv_Rule_301_A1_P590_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vdiv_Rule_301_A1_P590_instance_)
  {}
};

class CondVfpOpTester_Vm_la_ls_Rule_423_A2_P636_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vm_la_ls_Rule_423_A2_P636_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vm_la_ls_Rule_423_A2_P636_instance_)
  {}
};

class CondVfpOpTester_Vmov_Rule_326_A2_P640_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vmov_Rule_326_A2_P640_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vmov_Rule_326_A2_P640_instance_)
  {}
};

class CondVfpOpTester_Vmov_Rule_327_A2_P642_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vmov_Rule_327_A2_P642_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vmov_Rule_327_A2_P642_instance_)
  {}
};

class CondVfpOpTester_Vmul_Rule_338_A2_P664_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vmul_Rule_338_A2_P664_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vmul_Rule_338_A2_P664_instance_)
  {}
};

class CondVfpOpTester_Vneg_Rule_342_A2_P672_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vneg_Rule_342_A2_P672_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vneg_Rule_342_A2_P672_instance_)
  {}
};

class CondVfpOpTester_Vnm_la_ls_ul_Rule_343_A1_P674_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vnm_la_ls_ul_Rule_343_A1_P674_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vnm_la_ls_ul_Rule_343_A1_P674_instance_)
  {}
};

class CondVfpOpTester_Vnm_la_ls_ul_Rule_343_A2_P674_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vnm_la_ls_ul_Rule_343_A2_P674_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vnm_la_ls_ul_Rule_343_A2_P674_instance_)
  {}
};

class CondVfpOpTester_Vsqrt_Rule_388_A1_P762_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vsqrt_Rule_388_A1_P762_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vsqrt_Rule_388_A1_P762_instance_)
  {}
};

class CondVfpOpTester_Vsub_Rule_402_A2_P790_
    : public CondVfpOpTester {
 public:
  CondVfpOpTester_Vsub_Rule_402_A2_P790_()
    : CondVfpOpTester(
      state_.CondVfpOp_Vsub_Rule_402_A2_P790_instance_)
  {}
};

class DuplicateToVfpRegistersTester_Vdup_Rule_303_A1_P594_
    : public DuplicateToVfpRegistersTester {
 public:
  DuplicateToVfpRegistersTester_Vdup_Rule_303_A1_P594_()
    : DuplicateToVfpRegistersTester(
      state_.DuplicateToVfpRegisters_Vdup_Rule_303_A1_P594_instance_)
  {}
};

class ForbiddenCondNopTester_Bxj_Rule_26_A1_P64_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Bxj_Rule_26_A1_P64_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Bxj_Rule_26_A1_P64_instance_)
  {}
};

class ForbiddenCondNopTester_Ldm_Rule_2_B6_A1_P5_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Ldm_Rule_2_B6_A1_P5_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Ldm_Rule_2_B6_A1_P5_instance_)
  {}
};

class ForbiddenCondNopTester_Ldm_Rule_3_B6_A1_P7_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Ldm_Rule_3_B6_A1_P7_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Ldm_Rule_3_B6_A1_P7_instance_)
  {}
};

class ForbiddenCondNopTester_Msr_Rule_B6_1_6_A1_PB6_12_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Msr_Rule_B6_1_6_A1_PB6_12_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Msr_Rule_B6_1_6_A1_PB6_12_instance_)
  {}
};

class ForbiddenCondNopTester_Msr_Rule_B6_1_7_P14_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Msr_Rule_B6_1_7_P14_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Msr_Rule_B6_1_7_P14_instance_)
  {}
};

class ForbiddenCondNopTester_Sev_Rule_158_A1_P316_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Sev_Rule_158_A1_P316_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Sev_Rule_158_A1_P316_instance_)
  {}
};

class ForbiddenCondNopTester_Smc_Rule_B6_1_9_P18_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Smc_Rule_B6_1_9_P18_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Smc_Rule_B6_1_9_P18_instance_)
  {}
};

class ForbiddenCondNopTester_Stm_Rule_11_B6_A1_P22_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Stm_Rule_11_B6_A1_P22_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Stm_Rule_11_B6_A1_P22_instance_)
  {}
};

class ForbiddenCondNopTester_Wfe_Rule_411_A1_P808_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Wfe_Rule_411_A1_P808_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Wfe_Rule_411_A1_P808_instance_)
  {}
};

class ForbiddenCondNopTester_Wfi_Rule_412_A1_P810_
    : public UnsafeCondNopTester {
 public:
  ForbiddenCondNopTester_Wfi_Rule_412_A1_P810_()
    : UnsafeCondNopTester(
      state_.ForbiddenCondNop_Wfi_Rule_412_A1_P810_instance_)
  {}
};

class ForbiddenUncondNopTester_Blx_Rule_23_A2_P58_
    : public UnsafeUncondNopTester {
 public:
  ForbiddenUncondNopTester_Blx_Rule_23_A2_P58_()
    : UnsafeUncondNopTester(
      state_.ForbiddenUncondNop_Blx_Rule_23_A2_P58_instance_)
  {}
};

class Load2RegisterImm12OpTester_Ldr_Rule_58_A1_P120_NotRnIsPc
    : public LoadStore2RegisterImm12OpTesterNotRnIsPc {
 public:
  Load2RegisterImm12OpTester_Ldr_Rule_58_A1_P120_NotRnIsPc()
    : LoadStore2RegisterImm12OpTesterNotRnIsPc(
      state_.Load2RegisterImm12Op_Ldr_Rule_58_A1_P120_instance_)
  {}
};

class Load2RegisterImm12OpTester_Ldr_Rule_59_A1_P122_
    : public LoadStore2RegisterImm12OpTester {
 public:
  Load2RegisterImm12OpTester_Ldr_Rule_59_A1_P122_()
    : LoadStore2RegisterImm12OpTester(
      state_.Load2RegisterImm12Op_Ldr_Rule_59_A1_P122_instance_)
  {}
};

class Load2RegisterImm12OpTester_Ldrb_Rule_62_A1_P128_NotRnIsPc
    : public LoadStore2RegisterImm12OpTesterNotRnIsPc {
 public:
  Load2RegisterImm12OpTester_Ldrb_Rule_62_A1_P128_NotRnIsPc()
    : LoadStore2RegisterImm12OpTesterNotRnIsPc(
      state_.Load2RegisterImm12Op_Ldrb_Rule_62_A1_P128_instance_)
  {}
};

class Load2RegisterImm12OpTester_Ldrb_Rule_63_A1_P130_
    : public LoadStore2RegisterImm12OpTester {
 public:
  Load2RegisterImm12OpTester_Ldrb_Rule_63_A1_P130_()
    : LoadStore2RegisterImm12OpTester(
      state_.Load2RegisterImm12Op_Ldrb_Rule_63_A1_P130_instance_)
  {}
};

class Load2RegisterImm8DoubleOpTester_Ldrd_Rule_66_A1_P136_NotRnIsPc
    : public LoadStore2RegisterImm8DoubleOpTesterNotRnIsPc {
 public:
  Load2RegisterImm8DoubleOpTester_Ldrd_Rule_66_A1_P136_NotRnIsPc()
    : LoadStore2RegisterImm8DoubleOpTesterNotRnIsPc(
      state_.Load2RegisterImm8DoubleOp_Ldrd_Rule_66_A1_P136_instance_)
  {}
};

class Load2RegisterImm8DoubleOpTester_Ldrd_Rule_67_A1_P138_
    : public LoadStore2RegisterImm8DoubleOpTester {
 public:
  Load2RegisterImm8DoubleOpTester_Ldrd_Rule_67_A1_P138_()
    : LoadStore2RegisterImm8DoubleOpTester(
      state_.Load2RegisterImm8DoubleOp_Ldrd_Rule_67_A1_P138_instance_)
  {}
};

class Load2RegisterImm8OpTester_Ldrh_Rule_74_A1_P152_NotRnIsPc
    : public LoadStore2RegisterImm8OpTesterNotRnIsPc {
 public:
  Load2RegisterImm8OpTester_Ldrh_Rule_74_A1_P152_NotRnIsPc()
    : LoadStore2RegisterImm8OpTesterNotRnIsPc(
      state_.Load2RegisterImm8Op_Ldrh_Rule_74_A1_P152_instance_)
  {}
};

class Load2RegisterImm8OpTester_Ldrh_Rule_75_A1_P154_
    : public LoadStore2RegisterImm8OpTester {
 public:
  Load2RegisterImm8OpTester_Ldrh_Rule_75_A1_P154_()
    : LoadStore2RegisterImm8OpTester(
      state_.Load2RegisterImm8Op_Ldrh_Rule_75_A1_P154_instance_)
  {}
};

class Load2RegisterImm8OpTester_Ldrsb_Rule_78_A1_P160_NotRnIsPc
    : public LoadStore2RegisterImm8OpTesterNotRnIsPc {
 public:
  Load2RegisterImm8OpTester_Ldrsb_Rule_78_A1_P160_NotRnIsPc()
    : LoadStore2RegisterImm8OpTesterNotRnIsPc(
      state_.Load2RegisterImm8Op_Ldrsb_Rule_78_A1_P160_instance_)
  {}
};

class Load2RegisterImm8OpTester_Ldrsh_Rule_82_A1_P168_NotRnIsPc
    : public LoadStore2RegisterImm8OpTesterNotRnIsPc {
 public:
  Load2RegisterImm8OpTester_Ldrsh_Rule_82_A1_P168_NotRnIsPc()
    : LoadStore2RegisterImm8OpTesterNotRnIsPc(
      state_.Load2RegisterImm8Op_Ldrsh_Rule_82_A1_P168_instance_)
  {}
};

class Load2RegisterImm8OpTester_Ldrsh_Rule_83_A1_P170_
    : public LoadStore2RegisterImm8OpTester {
 public:
  Load2RegisterImm8OpTester_Ldrsh_Rule_83_A1_P170_()
    : LoadStore2RegisterImm8OpTester(
      state_.Load2RegisterImm8Op_Ldrsh_Rule_83_A1_P170_instance_)
  {}
};

class Load2RegisterImm8OpTester_ldrsb_Rule_79_A1_162_
    : public LoadStore2RegisterImm8OpTester {
 public:
  Load2RegisterImm8OpTester_ldrsb_Rule_79_A1_162_()
    : LoadStore2RegisterImm8OpTester(
      state_.Load2RegisterImm8Op_ldrsb_Rule_79_A1_162_instance_)
  {}
};

class Load3RegisterDoubleOpTester_Ldrd_Rule_68_A1_P140_
    : public LoadStore3RegisterDoubleOpTester {
 public:
  Load3RegisterDoubleOpTester_Ldrd_Rule_68_A1_P140_()
    : LoadStore3RegisterDoubleOpTester(
      state_.Load3RegisterDoubleOp_Ldrd_Rule_68_A1_P140_instance_)
  {}
};

class Load3RegisterImm5OpTester_Ldr_Rule_60_A1_P124_
    : public LoadStore3RegisterImm5OpTester {
 public:
  Load3RegisterImm5OpTester_Ldr_Rule_60_A1_P124_()
    : LoadStore3RegisterImm5OpTester(
      state_.Load3RegisterImm5Op_Ldr_Rule_60_A1_P124_instance_)
  {}
};

class Load3RegisterImm5OpTester_Ldrb_Rule_64_A1_P132_
    : public LoadStore3RegisterImm5OpTester {
 public:
  Load3RegisterImm5OpTester_Ldrb_Rule_64_A1_P132_()
    : LoadStore3RegisterImm5OpTester(
      state_.Load3RegisterImm5Op_Ldrb_Rule_64_A1_P132_instance_)
  {}
};

class Load3RegisterOpTester_Ldrh_Rule_76_A1_P156_
    : public LoadStore3RegisterOpTester {
 public:
  Load3RegisterOpTester_Ldrh_Rule_76_A1_P156_()
    : LoadStore3RegisterOpTester(
      state_.Load3RegisterOp_Ldrh_Rule_76_A1_P156_instance_)
  {}
};

class Load3RegisterOpTester_Ldrsb_Rule_80_A1_P164_
    : public LoadStore3RegisterOpTester {
 public:
  Load3RegisterOpTester_Ldrsb_Rule_80_A1_P164_()
    : LoadStore3RegisterOpTester(
      state_.Load3RegisterOp_Ldrsb_Rule_80_A1_P164_instance_)
  {}
};

class Load3RegisterOpTester_Ldrsh_Rule_84_A1_P172_
    : public LoadStore3RegisterOpTester {
 public:
  Load3RegisterOpTester_Ldrsh_Rule_84_A1_P172_()
    : LoadStore3RegisterOpTester(
      state_.Load3RegisterOp_Ldrsh_Rule_84_A1_P172_instance_)
  {}
};

class LoadExclusive2RegisterDoubleOpTester_Ldrexd_Rule_71_A1_P146_
    : public LoadExclusive2RegisterDoubleOpTester {
 public:
  LoadExclusive2RegisterDoubleOpTester_Ldrexd_Rule_71_A1_P146_()
    : LoadExclusive2RegisterDoubleOpTester(
      state_.LoadExclusive2RegisterDoubleOp_Ldrexd_Rule_71_A1_P146_instance_)
  {}
};

class LoadExclusive2RegisterOpTester_Ldrex_Rule_69_A1_P142_
    : public LoadExclusive2RegisterOpTester {
 public:
  LoadExclusive2RegisterOpTester_Ldrex_Rule_69_A1_P142_()
    : LoadExclusive2RegisterOpTester(
      state_.LoadExclusive2RegisterOp_Ldrex_Rule_69_A1_P142_instance_)
  {}
};

class LoadExclusive2RegisterOpTester_Ldrexb_Rule_70_A1_P144_
    : public LoadExclusive2RegisterOpTester {
 public:
  LoadExclusive2RegisterOpTester_Ldrexb_Rule_70_A1_P144_()
    : LoadExclusive2RegisterOpTester(
      state_.LoadExclusive2RegisterOp_Ldrexb_Rule_70_A1_P144_instance_)
  {}
};

class LoadExclusive2RegisterOpTester_Ldrexh_Rule_72_A1_P148_
    : public LoadExclusive2RegisterOpTester {
 public:
  LoadExclusive2RegisterOpTester_Ldrexh_Rule_72_A1_P148_()
    : LoadExclusive2RegisterOpTester(
      state_.LoadExclusive2RegisterOp_Ldrexh_Rule_72_A1_P148_instance_)
  {}
};

class LoadRegisterListTester_Ldm_Ldmia_Ldmfd_Rule_53_A1_P110_
    : public LoadStoreRegisterListTester {
 public:
  LoadRegisterListTester_Ldm_Ldmia_Ldmfd_Rule_53_A1_P110_()
    : LoadStoreRegisterListTester(
      state_.LoadRegisterList_Ldm_Ldmia_Ldmfd_Rule_53_A1_P110_instance_)
  {}
};

class LoadRegisterListTester_Ldmda_Ldmfa_Rule_54_A1_P112_
    : public LoadStoreRegisterListTester {
 public:
  LoadRegisterListTester_Ldmda_Ldmfa_Rule_54_A1_P112_()
    : LoadStoreRegisterListTester(
      state_.LoadRegisterList_Ldmda_Ldmfa_Rule_54_A1_P112_instance_)
  {}
};

class LoadRegisterListTester_Ldmdb_Ldmea_Rule_55_A1_P114_
    : public LoadStoreRegisterListTester {
 public:
  LoadRegisterListTester_Ldmdb_Ldmea_Rule_55_A1_P114_()
    : LoadStoreRegisterListTester(
      state_.LoadRegisterList_Ldmdb_Ldmea_Rule_55_A1_P114_instance_)
  {}
};

class LoadRegisterListTester_Ldmib_Ldmed_Rule_56_A1_P116_
    : public LoadStoreRegisterListTester {
 public:
  LoadRegisterListTester_Ldmib_Ldmed_Rule_56_A1_P116_()
    : LoadStoreRegisterListTester(
      state_.LoadRegisterList_Ldmib_Ldmed_Rule_56_A1_P116_instance_)
  {}
};

class LoadVectorRegisterTester_Vldr_Rule_320_A1_A2_P628_
    : public LoadStoreVectorOpTester {
 public:
  LoadVectorRegisterTester_Vldr_Rule_320_A1_A2_P628_()
    : LoadStoreVectorOpTester(
      state_.LoadVectorRegister_Vldr_Rule_320_A1_A2_P628_instance_)
  {}
};

class LoadVectorRegisterListTester_Vldm_Rule_318_A1_A2_P626_
    : public LoadStoreVectorRegisterListTester {
 public:
  LoadVectorRegisterListTester_Vldm_Rule_318_A1_A2_P626_()
    : LoadStoreVectorRegisterListTester(
      state_.LoadVectorRegisterList_Vldm_Rule_318_A1_A2_P626_instance_)
  {}
};

class LoadVectorRegisterListTester_Vldm_Rule_319_A1_A2_P626_
    : public LoadStoreVectorRegisterListTester {
 public:
  LoadVectorRegisterListTester_Vldm_Rule_319_A1_A2_P626_()
    : LoadStoreVectorRegisterListTester(
      state_.LoadVectorRegisterList_Vldm_Rule_319_A1_A2_P626_instance_)
  {}
};

class LoadVectorRegisterListTester_Vldm_Rule_319_A1_A2_P626_NotRnIsSp
    : public LoadStoreVectorRegisterListTesterNotRnIsSp {
 public:
  LoadVectorRegisterListTester_Vldm_Rule_319_A1_A2_P626_NotRnIsSp()
    : LoadStoreVectorRegisterListTesterNotRnIsSp(
      state_.LoadVectorRegisterList_Vldm_Rule_319_A1_A2_P626_instance_)
  {}
};

class LoadVectorRegisterListTester_Vpop_Rule_354_A1_A2_P694_
    : public LoadStoreVectorRegisterListTester {
 public:
  LoadVectorRegisterListTester_Vpop_Rule_354_A1_A2_P694_()
    : LoadStoreVectorRegisterListTester(
      state_.LoadVectorRegisterList_Vpop_Rule_354_A1_A2_P694_instance_)
  {}
};

class MaskedBinary2RegisterImmediateOpTester_Bic_Rule_19_A1_P50_NotRdIsPcAndS
    : public Binary2RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  MaskedBinary2RegisterImmediateOpTester_Bic_Rule_19_A1_P50_NotRdIsPcAndS()
    : Binary2RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.MaskedBinary2RegisterImmediateOp_Bic_Rule_19_A1_P50_instance_)
  {}
};

class MaskedBinaryRegisterImmediateTestTester_Tst_Rule_230_A1_P454_
    : public BinaryRegisterImmediateTestTester {
 public:
  MaskedBinaryRegisterImmediateTestTester_Tst_Rule_230_A1_P454_()
    : BinaryRegisterImmediateTestTester(
      state_.MaskedBinaryRegisterImmediateTest_Tst_Rule_230_A1_P454_instance_)
  {}
};

class MoveImmediate12ToApsrTester_Msr_Rule_103_A1_P208_
    : public MoveImmediate12ToApsrTester {
 public:
  MoveImmediate12ToApsrTester_Msr_Rule_103_A1_P208_()
    : MoveImmediate12ToApsrTester(
      state_.MoveImmediate12ToApsr_Msr_Rule_103_A1_P208_instance_)
  {}
};

class MoveVfpRegisterOpTester_Vmov_Rule_330_A1_P648_
    : public MoveVfpRegisterOpTester {
 public:
  MoveVfpRegisterOpTester_Vmov_Rule_330_A1_P648_()
    : MoveVfpRegisterOpTester(
      state_.MoveVfpRegisterOp_Vmov_Rule_330_A1_P648_instance_)
  {}
};

class MoveVfpRegisterOpWithTypeSelTester_Vmov_Rule_328_A1_P644_
    : public MoveVfpRegisterOpWithTypeSelTester {
 public:
  MoveVfpRegisterOpWithTypeSelTester_Vmov_Rule_328_A1_P644_()
    : MoveVfpRegisterOpWithTypeSelTester(
      state_.MoveVfpRegisterOpWithTypeSel_Vmov_Rule_328_A1_P644_instance_)
  {}
};

class MoveVfpRegisterOpWithTypeSelTester_Vmov_Rule_329_A1_P646_
    : public MoveVfpRegisterOpWithTypeSelTester {
 public:
  MoveVfpRegisterOpWithTypeSelTester_Vmov_Rule_329_A1_P646_()
    : MoveVfpRegisterOpWithTypeSelTester(
      state_.MoveVfpRegisterOpWithTypeSel_Vmov_Rule_329_A1_P646_instance_)
  {}
};

class Store2RegisterImm12OpTester_Str_Rule_194_A1_P384_
    : public LoadStore2RegisterImm12OpTester {
 public:
  Store2RegisterImm12OpTester_Str_Rule_194_A1_P384_()
    : LoadStore2RegisterImm12OpTester(
      state_.Store2RegisterImm12Op_Str_Rule_194_A1_P384_instance_)
  {}
};

class Store2RegisterImm12OpTester_Strb_Rule_197_A1_P390_
    : public LoadStore2RegisterImm12OpTester {
 public:
  Store2RegisterImm12OpTester_Strb_Rule_197_A1_P390_()
    : LoadStore2RegisterImm12OpTester(
      state_.Store2RegisterImm12Op_Strb_Rule_197_A1_P390_instance_)
  {}
};

class Store2RegisterImm8DoubleOpTester_Strd_Rule_200_A1_P396_
    : public LoadStore2RegisterImm8DoubleOpTester {
 public:
  Store2RegisterImm8DoubleOpTester_Strd_Rule_200_A1_P396_()
    : LoadStore2RegisterImm8DoubleOpTester(
      state_.Store2RegisterImm8DoubleOp_Strd_Rule_200_A1_P396_instance_)
  {}
};

class Store2RegisterImm8OpTester_Strh_Rule_207_A1_P410_
    : public LoadStore2RegisterImm8OpTester {
 public:
  Store2RegisterImm8OpTester_Strh_Rule_207_A1_P410_()
    : LoadStore2RegisterImm8OpTester(
      state_.Store2RegisterImm8Op_Strh_Rule_207_A1_P410_instance_)
  {}
};

class Store3RegisterDoubleOpTester_Strd_Rule_201_A1_P398_
    : public LoadStore3RegisterDoubleOpTester {
 public:
  Store3RegisterDoubleOpTester_Strd_Rule_201_A1_P398_()
    : LoadStore3RegisterDoubleOpTester(
      state_.Store3RegisterDoubleOp_Strd_Rule_201_A1_P398_instance_)
  {}
};

class Store3RegisterImm5OpTester_Str_Rule_195_A1_P386_
    : public LoadStore3RegisterImm5OpTester {
 public:
  Store3RegisterImm5OpTester_Str_Rule_195_A1_P386_()
    : LoadStore3RegisterImm5OpTester(
      state_.Store3RegisterImm5Op_Str_Rule_195_A1_P386_instance_)
  {}
};

class Store3RegisterImm5OpTester_Strb_Rule_198_A1_P392_
    : public LoadStore3RegisterImm5OpTester {
 public:
  Store3RegisterImm5OpTester_Strb_Rule_198_A1_P392_()
    : LoadStore3RegisterImm5OpTester(
      state_.Store3RegisterImm5Op_Strb_Rule_198_A1_P392_instance_)
  {}
};

class Store3RegisterOpTester_Strh_Rule_208_A1_P412_
    : public LoadStore3RegisterOpTester {
 public:
  Store3RegisterOpTester_Strh_Rule_208_A1_P412_()
    : LoadStore3RegisterOpTester(
      state_.Store3RegisterOp_Strh_Rule_208_A1_P412_instance_)
  {}
};

class StoreExclusive3RegisterDoubleOpTester_Strexd_Rule_204_A1_P404_
    : public StoreExclusive3RegisterDoubleOpTester {
 public:
  StoreExclusive3RegisterDoubleOpTester_Strexd_Rule_204_A1_P404_()
    : StoreExclusive3RegisterDoubleOpTester(
      state_.StoreExclusive3RegisterDoubleOp_Strexd_Rule_204_A1_P404_instance_)
  {}
};

class StoreExclusive3RegisterOpTester_Strex_Rule_202_A1_P400_
    : public StoreExclusive3RegisterOpTester {
 public:
  StoreExclusive3RegisterOpTester_Strex_Rule_202_A1_P400_()
    : StoreExclusive3RegisterOpTester(
      state_.StoreExclusive3RegisterOp_Strex_Rule_202_A1_P400_instance_)
  {}
};

class StoreExclusive3RegisterOpTester_Strexb_Rule_203_A1_P402_
    : public StoreExclusive3RegisterOpTester {
 public:
  StoreExclusive3RegisterOpTester_Strexb_Rule_203_A1_P402_()
    : StoreExclusive3RegisterOpTester(
      state_.StoreExclusive3RegisterOp_Strexb_Rule_203_A1_P402_instance_)
  {}
};

class StoreExclusive3RegisterOpTester_cccc00011110nnnndddd11111001tttt_
    : public StoreExclusive3RegisterOpTester {
 public:
  StoreExclusive3RegisterOpTester_cccc00011110nnnndddd11111001tttt_()
    : StoreExclusive3RegisterOpTester(
      state_.StoreExclusive3RegisterOp_cccc00011110nnnndddd11111001tttt_instance_)
  {}
};

class StoreRegisterListTester_Stm_Stmia_Stmea_Rule_189_A1_P374_
    : public LoadStoreRegisterListTester {
 public:
  StoreRegisterListTester_Stm_Stmia_Stmea_Rule_189_A1_P374_()
    : LoadStoreRegisterListTester(
      state_.StoreRegisterList_Stm_Stmia_Stmea_Rule_189_A1_P374_instance_)
  {}
};

class StoreRegisterListTester_Stmda_Stmed_Rule_190_A1_P376_
    : public LoadStoreRegisterListTester {
 public:
  StoreRegisterListTester_Stmda_Stmed_Rule_190_A1_P376_()
    : LoadStoreRegisterListTester(
      state_.StoreRegisterList_Stmda_Stmed_Rule_190_A1_P376_instance_)
  {}
};

class StoreRegisterListTester_Stmdb_Stmfd_Rule_191_A1_P378_
    : public LoadStoreRegisterListTester {
 public:
  StoreRegisterListTester_Stmdb_Stmfd_Rule_191_A1_P378_()
    : LoadStoreRegisterListTester(
      state_.StoreRegisterList_Stmdb_Stmfd_Rule_191_A1_P378_instance_)
  {}
};

class StoreRegisterListTester_Stmid_Stmfa_Rule_192_A1_P380_
    : public LoadStoreRegisterListTester {
 public:
  StoreRegisterListTester_Stmid_Stmfa_Rule_192_A1_P380_()
    : LoadStoreRegisterListTester(
      state_.StoreRegisterList_Stmid_Stmfa_Rule_192_A1_P380_instance_)
  {}
};

class StoreVectorRegisterTester_Vstr_Rule_400_A1_A2_P786_
    : public StoreVectorRegisterTester {
 public:
  StoreVectorRegisterTester_Vstr_Rule_400_A1_A2_P786_()
    : StoreVectorRegisterTester(
      state_.StoreVectorRegister_Vstr_Rule_400_A1_A2_P786_instance_)
  {}
};

class StoreVectorRegisterListTester_Vpush_355_A1_A2_P696_
    : public StoreVectorRegisterListTester {
 public:
  StoreVectorRegisterListTester_Vpush_355_A1_A2_P696_()
    : StoreVectorRegisterListTester(
      state_.StoreVectorRegisterList_Vpush_355_A1_A2_P696_instance_)
  {}
};

class StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784_
    : public StoreVectorRegisterListTester {
 public:
  StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784_()
    : StoreVectorRegisterListTester(
      state_.StoreVectorRegisterList_Vstm_Rule_399_A1_A2_P784_instance_)
  {}
};

class StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784_NotRnIsSp
    : public StoreVectorRegisterListTesterNotRnIsSp {
 public:
  StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784_NotRnIsSp()
    : StoreVectorRegisterListTesterNotRnIsSp(
      state_.StoreVectorRegisterList_Vstm_Rule_399_A1_A2_P784_instance_)
  {}
};

class Unary1RegisterBitRangeTester_Bfc_17_A1_P46_
    : public Unary1RegisterBitRangeTester {
 public:
  Unary1RegisterBitRangeTester_Bfc_17_A1_P46_()
    : Unary1RegisterBitRangeTester(
      state_.Unary1RegisterBitRange_Bfc_17_A1_P46_instance_)
  {}
};

class Unary1RegisterImmediateOpTester_Adr_Rule_10_A1_P32_
    : public Unary1RegisterImmediateOpTester {
 public:
  Unary1RegisterImmediateOpTester_Adr_Rule_10_A1_P32_()
    : Unary1RegisterImmediateOpTester(
      state_.Unary1RegisterImmediateOp_Adr_Rule_10_A1_P32_instance_)
  {}
};

class Unary1RegisterImmediateOpTester_Adr_Rule_10_A2_P32_
    : public Unary1RegisterImmediateOpTester {
 public:
  Unary1RegisterImmediateOpTester_Adr_Rule_10_A2_P32_()
    : Unary1RegisterImmediateOpTester(
      state_.Unary1RegisterImmediateOp_Adr_Rule_10_A2_P32_instance_)
  {}
};

class Unary1RegisterImmediateOpTester_Mov_Rule_96_A1_P194_NotRdIsPcAndS
    : public Unary1RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Unary1RegisterImmediateOpTester_Mov_Rule_96_A1_P194_NotRdIsPcAndS()
    : Unary1RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Unary1RegisterImmediateOp_Mov_Rule_96_A1_P194_instance_)
  {}
};

class Unary1RegisterImmediateOpTester_Mov_Rule_96_A2_P_194_RegsNotPc
    : public Unary1RegisterImmediateOpTesterRegsNotPc {
 public:
  Unary1RegisterImmediateOpTester_Mov_Rule_96_A2_P_194_RegsNotPc()
    : Unary1RegisterImmediateOpTesterRegsNotPc(
      state_.Unary1RegisterImmediateOp_Mov_Rule_96_A2_P_194_instance_)
  {}
};

class Unary1RegisterImmediateOpTester_Mvn_Rule_106_A1_P214_NotRdIsPcAndS
    : public Unary1RegisterImmediateOpTesterNotRdIsPcAndS {
 public:
  Unary1RegisterImmediateOpTester_Mvn_Rule_106_A1_P214_NotRdIsPcAndS()
    : Unary1RegisterImmediateOpTesterNotRdIsPcAndS(
      state_.Unary1RegisterImmediateOp_Mvn_Rule_106_A1_P214_instance_)
  {}
};

class Unary1RegisterSetTester_Mrs_Rule_102_A1_P206_Or_B6_10_
    : public Unary1RegisterSetTester {
 public:
  Unary1RegisterSetTester_Mrs_Rule_102_A1_P206_Or_B6_10_()
    : Unary1RegisterSetTester(
      state_.Unary1RegisterSet_Mrs_Rule_102_A1_P206_Or_B6_10_instance_)
  {}
};

class Unary1RegisterUseTester_Msr_Rule_104_A1_P210_
    : public Unary1RegisterUseTester {
 public:
  Unary1RegisterUseTester_Msr_Rule_104_A1_P210_()
    : Unary1RegisterUseTester(
      state_.Unary1RegisterUse_Msr_Rule_104_A1_P210_instance_)
  {}
};

class Unary2RegisterImmedShiftedOpTester_Asr_Rule_14_A1_P40_
    : public Unary2RegisterImmedShiftedOpTester {
 public:
  Unary2RegisterImmedShiftedOpTester_Asr_Rule_14_A1_P40_()
    : Unary2RegisterImmedShiftedOpTester(
      state_.Unary2RegisterImmedShiftedOp_Asr_Rule_14_A1_P40_instance_)
  {}
};

class Unary2RegisterImmedShiftedOpTester_Lsl_Rule_88_A1_P178_Imm5NotZero
    : public Unary2RegisterImmedShiftedOpTesterImm5NotZero {
 public:
  Unary2RegisterImmedShiftedOpTester_Lsl_Rule_88_A1_P178_Imm5NotZero()
    : Unary2RegisterImmedShiftedOpTesterImm5NotZero(
      state_.Unary2RegisterImmedShiftedOp_Lsl_Rule_88_A1_P178_instance_)
  {}
};

class Unary2RegisterImmedShiftedOpTester_Lsr_Rule_90_A1_P182_
    : public Unary2RegisterImmedShiftedOpTester {
 public:
  Unary2RegisterImmedShiftedOpTester_Lsr_Rule_90_A1_P182_()
    : Unary2RegisterImmedShiftedOpTester(
      state_.Unary2RegisterImmedShiftedOp_Lsr_Rule_90_A1_P182_instance_)
  {}
};

class Unary2RegisterImmedShiftedOpTester_Mvn_Rule_107_A1_P216_NotRdIsPcAndS
    : public Unary2RegisterImmedShiftedOpTesterNotRdIsPcAndS {
 public:
  Unary2RegisterImmedShiftedOpTester_Mvn_Rule_107_A1_P216_NotRdIsPcAndS()
    : Unary2RegisterImmedShiftedOpTesterNotRdIsPcAndS(
      state_.Unary2RegisterImmedShiftedOp_Mvn_Rule_107_A1_P216_instance_)
  {}
};

class Unary2RegisterImmedShiftedOpTester_Ror_Rule_139_A1_P278_Imm5NotZero
    : public Unary2RegisterImmedShiftedOpTesterImm5NotZero {
 public:
  Unary2RegisterImmedShiftedOpTester_Ror_Rule_139_A1_P278_Imm5NotZero()
    : Unary2RegisterImmedShiftedOpTesterImm5NotZero(
      state_.Unary2RegisterImmedShiftedOp_Ror_Rule_139_A1_P278_instance_)
  {}
};

class Unary2RegisterImmedShiftedOpRegsNotPcTester_Sxtb16_Rule_224_A1_P442_
    : public Unary2RegisterImmedShiftedOpRegsNotPcTester {
 public:
  Unary2RegisterImmedShiftedOpRegsNotPcTester_Sxtb16_Rule_224_A1_P442_()
    : Unary2RegisterImmedShiftedOpRegsNotPcTester(
      state_.Unary2RegisterImmedShiftedOpRegsNotPc_Sxtb16_Rule_224_A1_P442_instance_)
  {}
};

class Unary2RegisterImmedShiftedOpRegsNotPcTester_Sxtb_Rule_223_A1_P440_
    : public Unary2RegisterImmedShiftedOpRegsNotPcTester {
 public:
  Unary2RegisterImmedShiftedOpRegsNotPcTester_Sxtb_Rule_223_A1_P440_()
    : Unary2RegisterImmedShiftedOpRegsNotPcTester(
      state_.Unary2RegisterImmedShiftedOpRegsNotPc_Sxtb_Rule_223_A1_P440_instance_)
  {}
};

class Unary2RegisterOpTester_Mov_Rule_97_A1_P196_NotRdIsPcAndS
    : public Unary2RegisterOpTesterNotRdIsPcAndS {
 public:
  Unary2RegisterOpTester_Mov_Rule_97_A1_P196_NotRdIsPcAndS()
    : Unary2RegisterOpTesterNotRdIsPcAndS(
      state_.Unary2RegisterOp_Mov_Rule_97_A1_P196_instance_)
  {}
};

class Unary2RegisterOpTester_Rrx_Rule_141_A1_P282_
    : public Unary2RegisterOpTester {
 public:
  Unary2RegisterOpTester_Rrx_Rule_141_A1_P282_()
    : Unary2RegisterOpTester(
      state_.Unary2RegisterOp_Rrx_Rule_141_A1_P282_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcTester_Clz_Rule_31_A1_P72_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcTester_Clz_Rule_31_A1_P72_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPc_Clz_Rule_31_A1_P72_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcTester_Rbit_Rule_134_A1_P270_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcTester_Rbit_Rule_134_A1_P270_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPc_Rbit_Rule_134_A1_P270_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcTester_Revsh_Rule_137_A1_P276_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcTester_Revsh_Rule_137_A1_P276_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPc_Revsh_Rule_137_A1_P276_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcTester_Uxtb16_Rule_264_A1_P522_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcTester_Uxtb16_Rule_264_A1_P522_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPc_Uxtb16_Rule_264_A1_P522_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcTester_Uxtb_Rule_263_A1_P520_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcTester_Uxtb_Rule_263_A1_P520_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPc_Uxtb_Rule_263_A1_P520_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcTester_Uxth_Rule_265_A1_P524_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcTester_Uxth_Rule_265_A1_P524_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPc_Uxth_Rule_265_A1_P524_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Rev16_Rule_136_A1_P274_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Rev16_Rule_136_A1_P274_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPcNoCondUpdates_Rev16_Rule_136_A1_P274_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Rev_Rule_135_A1_P272_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Rev_Rule_135_A1_P272_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPcNoCondUpdates_Rev_Rule_135_A1_P272_instance_)
  {}
};

class Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Sxth_Rule_225_A1_P444_
    : public Unary2RegisterOpNotRmIsPcTester {
 public:
  Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Sxth_Rule_225_A1_P444_()
    : Unary2RegisterOpNotRmIsPcTester(
      state_.Unary2RegisterOpNotRmIsPcNoCondUpdates_Sxth_Rule_225_A1_P444_instance_)
  {}
};

class Unary2RegisterSatImmedShiftedOpTester_Ssat16_Rule_184_A1_P364_
    : public Unary2RegisterSatImmedShiftedOpTester {
 public:
  Unary2RegisterSatImmedShiftedOpTester_Ssat16_Rule_184_A1_P364_()
    : Unary2RegisterSatImmedShiftedOpTester(
      state_.Unary2RegisterSatImmedShiftedOp_Ssat16_Rule_184_A1_P364_instance_)
  {}
};

class Unary2RegisterSatImmedShiftedOpTester_Ssat_Rule_183_A1_P362_
    : public Unary2RegisterSatImmedShiftedOpTester {
 public:
  Unary2RegisterSatImmedShiftedOpTester_Ssat_Rule_183_A1_P362_()
    : Unary2RegisterSatImmedShiftedOpTester(
      state_.Unary2RegisterSatImmedShiftedOp_Ssat_Rule_183_A1_P362_instance_)
  {}
};

class Unary2RegisterSatImmedShiftedOpTester_Usat16_Rule_256_A1_P506_
    : public Unary2RegisterSatImmedShiftedOpTester {
 public:
  Unary2RegisterSatImmedShiftedOpTester_Usat16_Rule_256_A1_P506_()
    : Unary2RegisterSatImmedShiftedOpTester(
      state_.Unary2RegisterSatImmedShiftedOp_Usat16_Rule_256_A1_P506_instance_)
  {}
};

class Unary2RegisterSatImmedShiftedOpTester_Usat_Rule_255_A1_P504_
    : public Unary2RegisterSatImmedShiftedOpTester {
 public:
  Unary2RegisterSatImmedShiftedOpTester_Usat_Rule_255_A1_P504_()
    : Unary2RegisterSatImmedShiftedOpTester(
      state_.Unary2RegisterSatImmedShiftedOp_Usat_Rule_255_A1_P504_instance_)
  {}
};

class Unary3RegisterShiftedOpTester_Mvn_Rule_108_A1_P218_RegsNotPc
    : public Unary3RegisterShiftedOpTesterRegsNotPc {
 public:
  Unary3RegisterShiftedOpTester_Mvn_Rule_108_A1_P218_RegsNotPc()
    : Unary3RegisterShiftedOpTesterRegsNotPc(
      state_.Unary3RegisterShiftedOp_Mvn_Rule_108_A1_P218_instance_)
  {}
};

class VfpMrsOpTester_Vmrs_Rule_335_A1_P658_
    : public VfpMrsOpTester {
 public:
  VfpMrsOpTester_Vmrs_Rule_335_A1_P658_()
    : VfpMrsOpTester(
      state_.VfpMrsOp_Vmrs_Rule_335_A1_P658_instance_)
  {}
};

class VfpUsesRegOpTester_Vmsr_Rule_336_A1_P660_
    : public VfpUsesRegOpTester {
 public:
  VfpUsesRegOpTester_Vmsr_Rule_336_A1_P660_()
    : VfpUsesRegOpTester(
      state_.VfpUsesRegOp_Vmsr_Rule_336_A1_P660_instance_)
  {}
};

// Defines a gtest testing harness for tests.
class Arm32DecoderStateTests : public ::testing::Test {
 protected:
  Arm32DecoderStateTests() {}
};

// The following test each pattern specified in parse decoder tables.

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterBitRangeTester_Bfi_Rule_18_A1_P48_NotRnIsPc_cccc0111110mmmmmddddlllll001nnnn_Test) {
  Binary2RegisterBitRangeTester_Bfi_Rule_18_A1_P48_NotRnIsPc baseline_tester;
  NamedDefs12To15CondsDontCare_Bfi_Rule_18_A1_P48 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0111110mmmmmddddlllll001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterBitRangeNotRnIsPcTester_Sbfx_Rule_154_A1_P308__cccc0111101wwwwwddddlllll101nnnn_Test) {
  Binary2RegisterBitRangeNotRnIsPcTester_Sbfx_Rule_154_A1_P308_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Sbfx_Rule_154_A1_P308 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0111101wwwwwddddlllll101nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterBitRangeNotRnIsPcTester_Ubfx_Rule_236_A1_P466__cccc0111111mmmmmddddlllll101nnnn_Test) {
  Binary2RegisterBitRangeNotRnIsPcTester_Ubfx_Rule_236_A1_P466_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Ubfx_Rule_236_A1_P466 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0111111mmmmmddddlllll101nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmedShiftedTestTester_Cmn_Rule_33_A1_P76__cccc00010111nnnn0000iiiiitt0mmmm_Test) {
  Binary2RegisterImmedShiftedTestTester_Cmn_Rule_33_A1_P76_ baseline_tester;
  NamedDontCareInst_Cmn_Rule_33_A1_P76 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010111nnnn0000iiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmedShiftedTestTester_Cmp_Rule_36_A1_P82__cccc00010101nnnn0000iiiiitt0mmmm_Test) {
  Binary2RegisterImmedShiftedTestTester_Cmp_Rule_36_A1_P82_ baseline_tester;
  NamedDontCareInst_Cmp_Rule_36_A1_P82 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010101nnnn0000iiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmedShiftedTestTester_Teq_Rule_228_A1_P450__cccc00010011nnnn0000iiiiitt0mmmm_Test) {
  Binary2RegisterImmedShiftedTestTester_Teq_Rule_228_A1_P450_ baseline_tester;
  NamedDontCareInst_Teq_Rule_228_A1_P450 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010011nnnn0000iiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmedShiftedTestTester_Tst_Rule_231_A1_P456__cccc00010001nnnn0000iiiiitt0mmmm_Test) {
  Binary2RegisterImmedShiftedTestTester_Tst_Rule_231_A1_P456_ baseline_tester;
  NamedDontCareInst_Tst_Rule_231_A1_P456 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010001nnnn0000iiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Adc_Rule_6_A1_P14_NotRdIsPcAndS_cccc0010101unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Adc_Rule_6_A1_P14_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Adc_Rule_6_A1_P14 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0010101unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Add_Rule_5_A1_P22_NeitherRdIsPcAndSNorRnIsPcAndNotS_cccc001010011111ddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Add_Rule_5_A1_P22_NeitherRdIsPcAndSNorRnIsPcAndNotS baseline_tester;
  NamedDefs12To15_Add_Rule_5_A1_P22 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc001010011111ddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Add_Rule_5_A1_P22_NeitherRdIsPcAndSNorRnIsPcAndNotS_cccc0010100unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Add_Rule_5_A1_P22_NeitherRdIsPcAndSNorRnIsPcAndNotS baseline_tester;
  NamedDefs12To15_Add_Rule_5_A1_P22 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0010100unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_And_Rule_11_A1_P34_NotRdIsPcAndS_cccc0010000unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_And_Rule_11_A1_P34_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_And_Rule_11_A1_P34 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0010000unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Eor_Rule_44_A1_P94_NotRdIsPcAndS_cccc0010001unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Eor_Rule_44_A1_P94_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Eor_Rule_44_A1_P94 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0010001unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Orr_Rule_113_A1_P228_NotRdIsPcAndS_cccc0011100unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Orr_Rule_113_A1_P228_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Orr_Rule_113_A1_P228 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011100unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Rsb_Rule_142_A1_P284_NotRdIsPcAndS_cccc0010011unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Rsb_Rule_142_A1_P284_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Rsb_Rule_142_A1_P284 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0010011unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Rsc_Rule_145_A1_P290_NotRdIsPcAndS_cccc0010111unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Rsc_Rule_145_A1_P290_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Rsc_Rule_145_A1_P290 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0010111unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Sbc_Rule_151_A1_P302_NotRdIsPcAndS_cccc0010110unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Sbc_Rule_151_A1_P302_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Sbc_Rule_151_A1_P302 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0010110unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Sub_Rule_212_A1_P420_NeitherRdIsPcAndSNorRnIsPcAndNotS_cccc001001011111ddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Sub_Rule_212_A1_P420_NeitherRdIsPcAndSNorRnIsPcAndNotS baseline_tester;
  NamedDefs12To15_Sub_Rule_212_A1_P420 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc001001011111ddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary2RegisterImmediateOpTester_Sub_Rule_212_A1_P420_NeitherRdIsPcAndSNorRnIsPcAndNotS_cccc0010010unnnnddddiiiiiiiiiiii_Test) {
  Binary2RegisterImmediateOpTester_Sub_Rule_212_A1_P420_NeitherRdIsPcAndSNorRnIsPcAndNotS baseline_tester;
  NamedDefs12To15_Sub_Rule_212_A1_P420 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0010010unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Adc_Rule_2_A1_P16_NotRdIsPcAndS_cccc0000101unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Adc_Rule_2_A1_P16_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Adc_Rule_2_A1_P16 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000101unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Add_Rule_6_A1_P24_NotRdIsPcAndS_cccc0000100unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Add_Rule_6_A1_P24_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Add_Rule_6_A1_P24 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000100unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_And_Rule_7_A1_P36_NotRdIsPcAndS_cccc0000000unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_And_Rule_7_A1_P36_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_And_Rule_7_A1_P36 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000000unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Bic_Rule_20_A1_P52_NotRdIsPcAndS_cccc0001110unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Bic_Rule_20_A1_P52_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Bic_Rule_20_A1_P52 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001110unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Orr_Rule_114_A1_P230_NotRdIsPcAndS_cccc0001100unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Orr_Rule_114_A1_P230_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Orr_Rule_114_A1_P230 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001100unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Rsb_Rule_143_P286_NotRdIsPcAndS_cccc0000011unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Rsb_Rule_143_P286_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Rsb_Rule_143_P286 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000011unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Rsc_Rule_146_A1_P292_NotRdIsPcAndS_cccc0000111unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Rsc_Rule_146_A1_P292_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Rsc_Rule_146_A1_P292 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000111unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Sbc_Rule_152_A1_P304_NotRdIsPcAndS_cccc0000110unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Sbc_Rule_152_A1_P304_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Sbc_Rule_152_A1_P304 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000110unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Sub_Rule_213_A1_P422_NotRdIsPcAndS_cccc0000010unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Sub_Rule_213_A1_P422_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Sub_Rule_213_A1_P422 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000010unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpTester_Eor_Rule_45_A1_P96_NotRdIsPcAndS_cccc0000001unnnnddddiiiiitt0mmmm_Test) {
  Binary3RegisterImmedShiftedOpTester_Eor_Rule_45_A1_P96_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15CondsDontCare_Eor_Rule_45_A1_P96 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000001unnnnddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpRegsNotPcTester_Sxtab16_Rule_221_A1_P436_NotRnIsPcAndRegsNotPc_cccc01101000nnnnddddrr000111mmmm_Test) {
  Binary3RegisterImmedShiftedOpRegsNotPcTester_Sxtab16_Rule_221_A1_P436_NotRnIsPcAndRegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Sxtab16_Rule_221_A1_P436 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101000nnnnddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterImmedShiftedOpRegsNotPcTester_Pkh_Rule_116_A1_P234_RegsNotPc_cccc01101000nnnnddddiiiiit01mmmm_Test) {
  Binary3RegisterImmedShiftedOpRegsNotPcTester_Pkh_Rule_116_A1_P234_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Pkh_Rule_116_A1_P234 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101000nnnnddddiiiiit01mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpTester_Asr_Rule_15_A1_P42_RegsNotPc_cccc0001101u0000ddddmmmm0101nnnn_Test) {
  Binary3RegisterOpTester_Asr_Rule_15_A1_P42_RegsNotPc baseline_tester;
  NamedDefs12To15RdRmRnNotPc_Asr_Rule_15_A1_P42 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000ddddmmmm0101nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpTester_Lsl_Rule_89_A1_P180_RegsNotPc_cccc0001101u0000ddddmmmm0001nnnn_Test) {
  Binary3RegisterOpTester_Lsl_Rule_89_A1_P180_RegsNotPc baseline_tester;
  NamedDefs12To15RdRmRnNotPc_Lsl_Rule_89_A1_P180 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000ddddmmmm0001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpTester_Lsr_Rule_91_A1_P184_RegsNotPc_cccc0001101u0000ddddmmmm0011nnnn_Test) {
  Binary3RegisterOpTester_Lsr_Rule_91_A1_P184_RegsNotPc baseline_tester;
  NamedDefs12To15RdRmRnNotPc_Lsr_Rule_91_A1_P184 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000ddddmmmm0011nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpTester_Ror_Rule_140_A1_P280_RegsNotPc_cccc0001101u0000ddddmmmm0111nnnn_Test) {
  Binary3RegisterOpTester_Ror_Rule_140_A1_P280_RegsNotPc baseline_tester;
  NamedDefs12To15RdRmRnNotPc_Ror_Rule_140_A1_P280 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000ddddmmmm0111nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltATester_Mul_Rule_105_A1_P212_RegsNotPc_cccc0000000udddd0000mmmm1001nnnn_Test) {
  Binary3RegisterOpAltATester_Mul_Rule_105_A1_P212_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRmRnNotPc_Mul_Rule_105_A1_P212 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000000udddd0000mmmm1001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltATester_Smmul_Rule_176_P350_RegsNotPc_cccc01110101dddd1111mmmm00x1nnnn_Test) {
  Binary3RegisterOpAltATester_Smmul_Rule_176_P350_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRmRnNotPc_Smmul_Rule_176_P350 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110101dddd1111mmmm00x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltATester_Smuad_Rule_177_P352_RegsNotPc_cccc01110000dddd1111mmmm00x1nnnn_Test) {
  Binary3RegisterOpAltATester_Smuad_Rule_177_P352_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRmRnNotPc_Smuad_Rule_177_P352 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110000dddd1111mmmm00x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltATester_Smulwx_Rule_180_A1_P358_RegsNotPc_cccc00010010ddddzzzzmmmm1x10nnnn_Test) {
  Binary3RegisterOpAltATester_Smulwx_Rule_180_A1_P358_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRmRnNotPc_Smulwx_Rule_180_A1_P358 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010010ddddzzzzmmmm1x10nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltATester_Smulxx_Rule_178_P354_RegsNotPc_cccc00010110ddddzzzzmmmm1xx0nnnn_Test) {
  Binary3RegisterOpAltATester_Smulxx_Rule_178_P354_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRmRnNotPc_Smulxx_Rule_178_P354 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010110ddddzzzzmmmm1xx0nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltATester_Smusd_Rule_181_P360_RegsNotPc_cccc01110000dddd1111mmmm01x1nnnn_Test) {
  Binary3RegisterOpAltATester_Smusd_Rule_181_P360_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRmRnNotPc_Smusd_Rule_181_P360 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110000dddd1111mmmm01x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltATester_Usad8_Rule_253_A1_P500_RegsNotPc_cccc01111000dddd1111mmmm0001nnnn_Test) {
  Binary3RegisterOpAltATester_Usad8_Rule_253_A1_P500_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRmRnNotPc_Usad8_Rule_253_A1_P500 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01111000dddd1111mmmm0001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Sxtab_Rule_220_A1_P434_NotRnIsPcAndRegsNotPc_cccc01101010nnnnddddrr000111mmmm_Test) {
  Binary3RegisterOpAltBTester_Sxtab_Rule_220_A1_P434_NotRnIsPcAndRegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Sxtab_Rule_220_A1_P434 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101010nnnnddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qadd16_Rule_125_A1_P252_RegsNotPc_cccc01100010nnnndddd11110001mmmm_Test) {
  Binary3RegisterOpAltBTester_Qadd16_Rule_125_A1_P252_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qadd16_Rule_125_A1_P252 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100010nnnndddd11110001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qadd8_Rule_126_A1_P254_RegsNotPc_cccc01100010nnnndddd11111001mmmm_Test) {
  Binary3RegisterOpAltBTester_Qadd8_Rule_126_A1_P254_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qadd8_Rule_126_A1_P254 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100010nnnndddd11111001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qadd_Rule_124_A1_P250_RegsNotPc_cccc00010000nnnndddd00000101mmmm_Test) {
  Binary3RegisterOpAltBTester_Qadd_Rule_124_A1_P250_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qadd_Rule_124_A1_P250 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010000nnnndddd00000101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qasx_Rule_127_A1_P256_RegsNotPc_cccc01100010nnnndddd11110011mmmm_Test) {
  Binary3RegisterOpAltBTester_Qasx_Rule_127_A1_P256_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qasx_Rule_127_A1_P256 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100010nnnndddd11110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qdadd_Rule_128_A1_P258_RegsNotPc_cccc00010100nnnndddd00000101mmmm_Test) {
  Binary3RegisterOpAltBTester_Qdadd_Rule_128_A1_P258_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qdadd_Rule_128_A1_P258 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010100nnnndddd00000101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qdsub_Rule_129_A1_P260_RegsNotPc_cccc00010110nnnndddd00000101mmmm_Test) {
  Binary3RegisterOpAltBTester_Qdsub_Rule_129_A1_P260_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qdsub_Rule_129_A1_P260 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010110nnnndddd00000101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qsax_Rule_130_A1_P262_RegsNotPc_cccc01100010nnnndddd11110101mmmm_Test) {
  Binary3RegisterOpAltBTester_Qsax_Rule_130_A1_P262_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qsax_Rule_130_A1_P262 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100010nnnndddd11110101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qsub16_Rule_132_A1_P266_RegsNotPc_cccc01100010nnnndddd11110111mmmm_Test) {
  Binary3RegisterOpAltBTester_Qsub16_Rule_132_A1_P266_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qsub16_Rule_132_A1_P266 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100010nnnndddd11110111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qsub8_Rule_133_A1_P268_RegsNotPc_cccc01100010nnnndddd11111111mmmm_Test) {
  Binary3RegisterOpAltBTester_Qsub8_Rule_133_A1_P268_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qsub8_Rule_133_A1_P268 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100010nnnndddd11111111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Qsub_Rule_131_A1_P264_RegsNotPc_cccc00010010nnnndddd00000101mmmm_Test) {
  Binary3RegisterOpAltBTester_Qsub_Rule_131_A1_P264_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Qsub_Rule_131_A1_P264 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010010nnnndddd00000101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Sadd16_Rule_148_A1_P296_RegsNotPc_cccc01100001nnnndddd11110001mmmm_Test) {
  Binary3RegisterOpAltBTester_Sadd16_Rule_148_A1_P296_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Sadd16_Rule_148_A1_P296 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100001nnnndddd11110001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Sasx_Rule_150_A1_P300_RegsNotPc_cccc01100001nnnndddd11110011mmmm_Test) {
  Binary3RegisterOpAltBTester_Sasx_Rule_150_A1_P300_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Sasx_Rule_150_A1_P300 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100001nnnndddd11110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Sel_Rule_156_A1_P312_RegsNotPc_cccc01101000nnnndddd11111011mmmm_Test) {
  Binary3RegisterOpAltBTester_Sel_Rule_156_A1_P312_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Sel_Rule_156_A1_P312 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101000nnnndddd11111011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Ssad8_Rule_149_A1_P298_RegsNotPc_cccc01100001nnnndddd11111001mmmm_Test) {
  Binary3RegisterOpAltBTester_Ssad8_Rule_149_A1_P298_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Ssad8_Rule_149_A1_P298 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100001nnnndddd11111001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Ssax_Rule_185_A1_P366_RegsNotPc_cccc01100001nnnndddd11110101mmmm_Test) {
  Binary3RegisterOpAltBTester_Ssax_Rule_185_A1_P366_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Ssax_Rule_185_A1_P366 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100001nnnndddd11110101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Ssub16_Rule_186_A1_P368_RegsNotPc_cccc01100001nnnndddd11110111mmmm_Test) {
  Binary3RegisterOpAltBTester_Ssub16_Rule_186_A1_P368_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Ssub16_Rule_186_A1_P368 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100001nnnndddd11110111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Ssub8_Rule_187_A1_P370_RegsNotPc_cccc01100001nnnndddd11111111mmmm_Test) {
  Binary3RegisterOpAltBTester_Ssub8_Rule_187_A1_P370_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Ssub8_Rule_187_A1_P370 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100001nnnndddd11111111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uadd16_Rule_233_A1_P460_RegsNotPc_cccc01100101nnnndddd11110001mmmm_Test) {
  Binary3RegisterOpAltBTester_Uadd16_Rule_233_A1_P460_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uadd16_Rule_233_A1_P460 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100101nnnndddd11110001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uadd8_Rule_234_A1_P462_RegsNotPc_cccc01100101nnnndddd11111001mmmm_Test) {
  Binary3RegisterOpAltBTester_Uadd8_Rule_234_A1_P462_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uadd8_Rule_234_A1_P462 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100101nnnndddd11111001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uasx_Rule_235_A1_P464_RegsNotPc_cccc01100101nnnndddd11110011mmmm_Test) {
  Binary3RegisterOpAltBTester_Uasx_Rule_235_A1_P464_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uasx_Rule_235_A1_P464 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100101nnnndddd11110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uqadd16_Rule_247_A1_P488_RegsNotPc_cccc01100110nnnndddd11110001mmmm_Test) {
  Binary3RegisterOpAltBTester_Uqadd16_Rule_247_A1_P488_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uqadd16_Rule_247_A1_P488 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100110nnnndddd11110001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uqadd8_Rule_248_A1_P490_RegsNotPc_cccc01100110nnnndddd11111001mmmm_Test) {
  Binary3RegisterOpAltBTester_Uqadd8_Rule_248_A1_P490_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uqadd8_Rule_248_A1_P490 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100110nnnndddd11111001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uqasx_Rule_249_A1_P492_RegsNotPc_cccc01100110nnnndddd11110011mmmm_Test) {
  Binary3RegisterOpAltBTester_Uqasx_Rule_249_A1_P492_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uqasx_Rule_249_A1_P492 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100110nnnndddd11110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uqsax_Rule_250_A1_P494_RegsNotPc_cccc01100110nnnndddd11110101mmmm_Test) {
  Binary3RegisterOpAltBTester_Uqsax_Rule_250_A1_P494_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uqsax_Rule_250_A1_P494 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100110nnnndddd11110101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uqsub16_Rule_251_A1_P496_RegsNotPc_cccc01100110nnnndddd11110111mmmm_Test) {
  Binary3RegisterOpAltBTester_Uqsub16_Rule_251_A1_P496_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uqsub16_Rule_251_A1_P496 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100110nnnndddd11110111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Uqsub8_Rule_252_A1_P498_RegsNotPc_cccc01100110nnnndddd11111111mmmm_Test) {
  Binary3RegisterOpAltBTester_Uqsub8_Rule_252_A1_P498_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uqsub8_Rule_252_A1_P498 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100110nnnndddd11111111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Usax_Rule_257_A1_P508_RegsNotPc_cccc01100101nnnndddd11110101mmmm_Test) {
  Binary3RegisterOpAltBTester_Usax_Rule_257_A1_P508_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Usax_Rule_257_A1_P508 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100101nnnndddd11110101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Usub16_Rule_258_A1_P510_RegsNotPc_cccc01100101nnnndddd11110111mmmm_Test) {
  Binary3RegisterOpAltBTester_Usub16_Rule_258_A1_P510_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Usub16_Rule_258_A1_P510 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100101nnnndddd11110111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBTester_Usub8_Rule_259_A1_P512_RegsNotPc_cccc01100101nnnndddd11111111mmmm_Test) {
  Binary3RegisterOpAltBTester_Usub8_Rule_259_A1_P512_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Usub8_Rule_259_A1_P512 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100101nnnndddd11111111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Sxtah_Rule_222_A1_P438_NotRnIsPc_cccc01101011nnnnddddrr000111mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Sxtah_Rule_222_A1_P438_NotRnIsPc baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Sxtah_Rule_222_A1_P438 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101011nnnnddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uxtab_Rule_260_A1_P514_NotRnIsPc_cccc01101110nnnnddddrr000111mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uxtab_Rule_260_A1_P514_NotRnIsPc baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Uxtab_Rule_260_A1_P514 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101110nnnnddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uxtah_Rule_262_A1_P516_NotRnIsPc_cccc01101100nnnnddddrr000111mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uxtah_Rule_262_A1_P516_NotRnIsPc baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Uxtah_Rule_262_A1_P516 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101100nnnnddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uxtah_Rule_262_A1_P518_NotRnIsPc_cccc01101111nnnnddddrr000111mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uxtah_Rule_262_A1_P518_NotRnIsPc baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Uxtah_Rule_262_A1_P518 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101111nnnnddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Shadd16_Rule_159_A1_P318_RegsNotPc_cccc01100011nnnndddd11110001mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Shadd16_Rule_159_A1_P318_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Shadd16_Rule_159_A1_P318 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100011nnnndddd11110001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Shadd8_Rule_160_A1_P320_RegsNotPc_cccc01100011nnnndddd11111001mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Shadd8_Rule_160_A1_P320_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Shadd8_Rule_160_A1_P320 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100011nnnndddd11111001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Shasx_Rule_161_A1_P322_RegsNotPc_cccc01100011nnnndddd11110011mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Shasx_Rule_161_A1_P322_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Shasx_Rule_161_A1_P322 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100011nnnndddd11110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Shsax_Rule_162_A1_P324_RegsNotPc_cccc01100011nnnndddd11110101mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Shsax_Rule_162_A1_P324_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Shsax_Rule_162_A1_P324 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100011nnnndddd11110101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Shsub16_Rule_163_A1_P326_RegsNotPc_cccc01100011nnnndddd11110111mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Shsub16_Rule_163_A1_P326_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Shsub16_Rule_163_A1_P326 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100011nnnndddd11110111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Shsub8_Rule_164_A1_P328_RegsNotPc_cccc01100011nnnndddd11111111mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Shsub8_Rule_164_A1_P328_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Shsub8_Rule_164_A1_P328 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100011nnnndddd11111111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uhadd16_Rule_238_A1_P470_RegsNotPc_cccc01100111nnnndddd11110001mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhadd16_Rule_238_A1_P470_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uhadd16_Rule_238_A1_P470 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100111nnnndddd11110001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uhadd8_Rule_239_A1_P472_RegsNotPc_cccc01100111nnnndddd11111001mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhadd8_Rule_239_A1_P472_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uhadd8_Rule_239_A1_P472 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100111nnnndddd11111001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uhasx_Rule_240_A1_P474_RegsNotPc_cccc01100111nnnndddd11110011mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhasx_Rule_240_A1_P474_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uhasx_Rule_240_A1_P474 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100111nnnndddd11110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uhsax_Rule_241_A1_P476_RegsNotPc_cccc01100111nnnndddd11110101mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhsax_Rule_241_A1_P476_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uhsax_Rule_241_A1_P476 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100111nnnndddd11110101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uhsub16_Rule_242_A1_P478_RegsNotPc_cccc01100111nnnndddd11110111mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhsub16_Rule_242_A1_P478_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uhsub16_Rule_242_A1_P478 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100111nnnndddd11110111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterOpAltBNoCondUpdatesTester_Uhsub8_Rule_243_A1_P480_RegsNotPc_cccc01100111nnnndddd11111111mmmm_Test) {
  Binary3RegisterOpAltBNoCondUpdatesTester_Uhsub8_Rule_243_A1_P480_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRnRdRmNotPc_Uhsub8_Rule_243_A1_P480 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01100111nnnndddd11111111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterShiftedTestTester_Cmn_Rule_34_A1_P78_RegsNotPc_cccc00010111nnnn0000ssss0tt1mmmm_Test) {
  Binary3RegisterShiftedTestTester_Cmn_Rule_34_A1_P78_RegsNotPc baseline_tester;
  NamedDontCareInstRnRsRmNotPc_Cmn_Rule_34_A1_P78 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010111nnnn0000ssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterShiftedTestTester_Cmp_Rule_37_A1_P84_RegsNotPc_cccc00010101nnnn0000ssss0tt1mmmm_Test) {
  Binary3RegisterShiftedTestTester_Cmp_Rule_37_A1_P84_RegsNotPc baseline_tester;
  NamedDontCareInstRnRsRmNotPc_Cmp_Rule_37_A1_P84 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010101nnnn0000ssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterShiftedTestTester_Teq_Rule_229_A1_P452_RegsNotPc_cccc00010011nnnn0000ssss0tt1mmmm_Test) {
  Binary3RegisterShiftedTestTester_Teq_Rule_229_A1_P452_RegsNotPc baseline_tester;
  NamedDontCareInstRnRsRmNotPc_Teq_Rule_229_A1_P452 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010011nnnn0000ssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary3RegisterShiftedTestTester_Tst_Rule_232_A1_P458_RegsNotPc_cccc00010001nnnn0000ssss0tt1mmmm_Test) {
  Binary3RegisterShiftedTestTester_Tst_Rule_232_A1_P458_RegsNotPc baseline_tester;
  NamedDontCareInstRnRsRmNotPc_Tst_Rule_232_A1_P458 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010001nnnn0000ssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Mla_Rule_94_A1_P190_RegsNotPc_cccc0000001uddddaaaammmm1001nnnn_Test) {
  Binary4RegisterDualOpTester_Mla_Rule_94_A1_P190_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Mla_Rule_94_A1_P190 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000001uddddaaaammmm1001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Mls_Rule_95_A1_P192_RegsNotPc_cccc00000110ddddaaaammmm1001nnnn_Test) {
  Binary4RegisterDualOpTester_Mls_Rule_95_A1_P192_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Mls_Rule_95_A1_P192 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00000110ddddaaaammmm1001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Smlad_Rule_167_P332_NotRaIsPcAndRegsNotPc_cccc01110000ddddaaaammmm00x1nnnn_Test) {
  Binary4RegisterDualOpTester_Smlad_Rule_167_P332_NotRaIsPcAndRegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Smlad_Rule_167_P332 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110000ddddaaaammmm00x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Smlawx_Rule_171_A1_340_RegsNotPc_cccc00010010ddddaaaammmm1x00nnnn_Test) {
  Binary4RegisterDualOpTester_Smlawx_Rule_171_A1_340_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Smlawx_Rule_171_A1_340 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010010ddddaaaammmm1x00nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Smlaxx_Rule_166_A1_P330_RegsNotPc_cccc00010000ddddaaaammmm1xx0nnnn_Test) {
  Binary4RegisterDualOpTester_Smlaxx_Rule_166_A1_P330_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Smlaxx_Rule_166_A1_P330 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010000ddddaaaammmm1xx0nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Smlsd_Rule_172_P342_NotRaIsPcAndRegsNotPc_cccc01110000ddddaaaammmm01x1nnnn_Test) {
  Binary4RegisterDualOpTester_Smlsd_Rule_172_P342_NotRaIsPcAndRegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Smlsd_Rule_172_P342 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110000ddddaaaammmm01x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Smmla_Rule_174_P346_NotRaIsPcAndRegsNotPc_cccc01110101ddddaaaammmm00x1nnnn_Test) {
  Binary4RegisterDualOpTester_Smmla_Rule_174_P346_NotRaIsPcAndRegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Smmla_Rule_174_P346 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110101ddddaaaammmm00x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Smmls_Rule_175_P348_RegsNotPc_cccc01110101ddddaaaammmm11x1nnnn_Test) {
  Binary4RegisterDualOpTester_Smmls_Rule_175_P348_RegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Smmls_Rule_175_P348 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110101ddddaaaammmm11x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualOpTester_Usda8_Rule_254_A1_P502_NotRaIsPcAndRegsNotPc_cccc01111000ddddaaaammmm0001nnnn_Test) {
  Binary4RegisterDualOpTester_Usda8_Rule_254_A1_P502_NotRaIsPcAndRegsNotPc baseline_tester;
  NamedDefs16To19CondsDontCareRdRaRmRnNotPc_Usda8_Rule_254_A1_P502 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01111000ddddaaaammmm0001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualResultTester_Smlal_Rule_168_A1_P334_RegsNotPc_cccc0000111uhhhhllllmmmm1001nnnn_Test) {
  Binary4RegisterDualResultTester_Smlal_Rule_168_A1_P334_RegsNotPc baseline_tester;
  NamedDefs12To19CondsDontCareRdRmRnNotPc_Smlal_Rule_168_A1_P334 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000111uhhhhllllmmmm1001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualResultTester_Smlald_Rule_170_P336_RegsNotPc_cccc01110100hhhhllllmmmm00x1nnnn_Test) {
  Binary4RegisterDualResultTester_Smlald_Rule_170_P336_RegsNotPc baseline_tester;
  NamedDefs12To19CondsDontCareRdRmRnNotPc_Smlald_Rule_170_P336 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110100hhhhllllmmmm00x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualResultTester_Smlalxx_Rule_169_A1_P336_RegsNotPc_cccc00010100hhhhllllmmmm1xx0nnnn_Test) {
  Binary4RegisterDualResultTester_Smlalxx_Rule_169_A1_P336_RegsNotPc baseline_tester;
  NamedDefs12To19CondsDontCareRdRmRnNotPc_Smlalxx_Rule_169_A1_P336 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010100hhhhllllmmmm1xx0nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualResultTester_Smlsld_Rule_173_P344_RegsNotPc_cccc01110100hhhhllllmmmm01x1nnnn_Test) {
  Binary4RegisterDualResultTester_Smlsld_Rule_173_P344_RegsNotPc baseline_tester;
  NamedDefs12To19CondsDontCareRdRmRnNotPc_Smlsld_Rule_173_P344 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01110100hhhhllllmmmm01x1nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualResultTester_Smull_Rule_179_A1_P356_RegsNotPc_cccc0000110uhhhhllllmmmm1001nnnn_Test) {
  Binary4RegisterDualResultTester_Smull_Rule_179_A1_P356_RegsNotPc baseline_tester;
  NamedDefs12To19CondsDontCareRdRmRnNotPc_Smull_Rule_179_A1_P356 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000110uhhhhllllmmmm1001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualResultTester_Umaal_Rule_244_A1_P482_RegsNotPc_cccc00000100hhhhllllmmmm1001nnnn_Test) {
  Binary4RegisterDualResultTester_Umaal_Rule_244_A1_P482_RegsNotPc baseline_tester;
  NamedDefs12To19CondsDontCareRdRmRnNotPc_Umaal_Rule_244_A1_P482 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00000100hhhhllllmmmm1001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualResultTester_Umlal_Rule_245_A1_P484_RegsNotPc_cccc0000101uhhhhllllmmmm1001nnnn_Test) {
  Binary4RegisterDualResultTester_Umlal_Rule_245_A1_P484_RegsNotPc baseline_tester;
  NamedDefs12To19CondsDontCareRdRmRnNotPc_Umlal_Rule_245_A1_P484 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000101uhhhhllllmmmm1001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterDualResultTester_Umull_Rule_246_A1_P486_RegsNotPc_cccc0000100uhhhhllllmmmm1001nnnn_Test) {
  Binary4RegisterDualResultTester_Umull_Rule_246_A1_P486_RegsNotPc baseline_tester;
  NamedDefs12To19CondsDontCareRdRmRnNotPc_Umull_Rule_246_A1_P486 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000100uhhhhllllmmmm1001nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Eor_Rule_46_A1_P98_RegsNotPc_cccc0000001unnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Eor_Rule_46_A1_P98_RegsNotPc baseline_tester;
  NamedDefs12To15CondsDontCareRdRnRsRmNotPc_Eor_Rule_46_A1_P98 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000001unnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Adc_Rule_3_A1_P18_RegsNotPc_cccc0000101unnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Adc_Rule_3_A1_P18_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_Adc_Rule_3_A1_P18 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000101unnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Add_Rule_7_A1_P26_RegsNotPc_cccc0000100snnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Add_Rule_7_A1_P26_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_Add_Rule_7_A1_P26 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000100snnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_And_Rule_13_A1_P38_RegsNotPc_cccc0000000unnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_And_Rule_13_A1_P38_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_And_Rule_13_A1_P38 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000000unnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Bic_Rule_21_A1_P54_RegsNotPc_cccc0001110unnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Bic_Rule_21_A1_P54_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_Bic_Rule_21_A1_P54 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001110unnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Orr_Rule_115_A1_P212_RegsNotPc_cccc0001100unnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Orr_Rule_115_A1_P212_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_Orr_Rule_115_A1_P212 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001100unnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Rsb_Rule_144_A1_P288_RegsNotPc_cccc0000011snnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Rsb_Rule_144_A1_P288_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_Rsb_Rule_144_A1_P288 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000011snnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Rsc_Rule_147_A1_P294_RegsNotPc_cccc0000111unnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Rsc_Rule_147_A1_P294_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_Rsc_Rule_147_A1_P294 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000111unnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Sbc_Rule_153_A1_P306_RegsNotPc_cccc0000110unnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Sbc_Rule_153_A1_P306_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_Sbc_Rule_153_A1_P306 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000110unnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Binary4RegisterShiftedOpTester_Sub_Rule_214_A1_P424_RegsNotPc_cccc0000010unnnnddddssss0tt1mmmm_Test) {
  Binary4RegisterShiftedOpTester_Sub_Rule_214_A1_P424_RegsNotPc baseline_tester;
  NamedDefs12To15RdRnRsRmNotPc_Sub_Rule_214_A1_P424 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0000010unnnnddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       BinaryRegisterImmediateTestTester_Cmn_Rule_32_A1_P74__cccc00110111nnnn0000iiiiiiiiiiii_Test) {
  BinaryRegisterImmediateTestTester_Cmn_Rule_32_A1_P74_ baseline_tester;
  NamedDontCareInst_Cmn_Rule_32_A1_P74 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00110111nnnn0000iiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       BinaryRegisterImmediateTestTester_Cmp_Rule_35_A1_P80__cccc00110101nnnn0000iiiiiiiiiiii_Test) {
  BinaryRegisterImmediateTestTester_Cmp_Rule_35_A1_P80_ baseline_tester;
  NamedDontCareInst_Cmp_Rule_35_A1_P80 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00110101nnnn0000iiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       BinaryRegisterImmediateTestTester_Teq_Rule_227_A1_P448__cccc00110011nnnn0000iiiiiiiiiiii_Test) {
  BinaryRegisterImmediateTestTester_Teq_Rule_227_A1_P448_ baseline_tester;
  NamedDontCareInst_Teq_Rule_227_A1_P448 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00110011nnnn0000iiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       BranchImmediate24Tester_B_Rule_16_A1_P44__cccc1010iiiiiiiiiiiiiiiiiiiiiiii_Test) {
  BranchImmediate24Tester_B_Rule_16_A1_P44_ baseline_tester;
  NamedBranch_B_Rule_16_A1_P44 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc1010iiiiiiiiiiiiiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       BranchImmediate24Tester_Bl_Blx_Rule_23_A1_P58__cccc1011iiiiiiiiiiiiiiiiiiiiiiii_Test) {
  BranchImmediate24Tester_Bl_Blx_Rule_23_A1_P58_ baseline_tester;
  NamedBranch_Bl_Blx_Rule_23_A1_P58 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc1011iiiiiiiiiiiiiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       BranchToRegisterTester_Blx_Rule_24_A1_P60_RegsNotPc_cccc000100101111111111110011mmmm_Test) {
  BranchToRegisterTester_Blx_Rule_24_A1_P60_RegsNotPc baseline_tester;
  NamedBxBlx_Blx_Rule_24_A1_P60 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000100101111111111110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       BranchToRegisterTester_Bx_Rule_25_A1_P62__cccc000100101111111111110001mmmm_Test) {
  BranchToRegisterTester_Bx_Rule_25_A1_P62_ baseline_tester;
  NamedBxBlx_Bx_Rule_25_A1_P62 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000100101111111111110001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       BreakPointAndConstantPoolHeadTester_Bkpt_Rule_22_A1_P56__cccc00010010iiiiiiiiiiii0111iiii_Test) {
  BreakPointAndConstantPoolHeadTester_Bkpt_Rule_22_A1_P56_ baseline_tester;
  NamedBreakpoint_Bkpt_Rule_22_A1_P56 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010010iiiiiiiiiiii0111iiii");
}

TEST_F(Arm32DecoderStateTests,
       CondNopTester_Dbg_Rule_40_A1_P88__cccc001100100000111100001111iiii_Test) {
  CondNopTester_Dbg_Rule_40_A1_P88_ baseline_tester;
  NamedDontCareInst_Dbg_Rule_40_A1_P88 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc001100100000111100001111iiii");
}

TEST_F(Arm32DecoderStateTests,
       CondNopTester_Nop_Rule_110_A1_P222__cccc0011001000001111000000000000_Test) {
  CondNopTester_Nop_Rule_110_A1_P222_ baseline_tester;
  NamedDontCareInst_Nop_Rule_110_A1_P222 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011001000001111000000000000");
}

TEST_F(Arm32DecoderStateTests,
       CondNopTester_Yield_Rule_413_A1_P812__cccc0011001000001111000000000001_Test) {
  CondNopTester_Yield_Rule_413_A1_P812_ baseline_tester;
  NamedDontCareInst_Yield_Rule_413_A1_P812 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011001000001111000000000001");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vadd_Rule_271_A2_P536__cccc11100d11nnnndddd101sn0m0mmmm_Test) {
  CondVfpOpTester_Vadd_Rule_271_A2_P536_ baseline_tester;
  NamedVfpOp_Vadd_Rule_271_A2_P536 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11100d11nnnndddd101sn0m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vcmp_Vcmpe_Rule_292_A1_P572__cccc11101d110100dddd101se1m0mmmm_Test) {
  CondVfpOpTester_Vcmp_Vcmpe_Rule_292_A1_P572_ baseline_tester;
  NamedVfpOp_Vcmp_Vcmpe_Rule_292_A1_P572 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d110100dddd101se1m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vcmp_Vcmpe_Rule_292_A2_P572__cccc11101d110101dddd101se1000000_Test) {
  CondVfpOpTester_Vcmp_Vcmpe_Rule_292_A2_P572_ baseline_tester;
  NamedVfpOp_Vcmp_Vcmpe_Rule_292_A2_P572 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d110101dddd101se1000000");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vcvt_Rule_297_A1_P582__cccc11101d11101udddd101fx1i0iiii_Test) {
  CondVfpOpTester_Vcvt_Rule_297_A1_P582_ baseline_tester;
  NamedVfpOp_Vcvt_Rule_297_A1_P582 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d11101udddd101fx1i0iiii");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vcvt_Rule_297_A1_P582__cccc11101d11111udddd101fx1i0iiii_Test) {
  CondVfpOpTester_Vcvt_Rule_297_A1_P582_ baseline_tester;
  NamedVfpOp_Vcvt_Rule_297_A1_P582 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d11111udddd101fx1i0iiii");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vcvt_Rule_298_A1_P584__cccc11101d110111dddd101s11m0mmmm_Test) {
  CondVfpOpTester_Vcvt_Rule_298_A1_P584_ baseline_tester;
  NamedVfpOp_Vcvt_Rule_298_A1_P584 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d110111dddd101s11m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vcvt_Vcvtr_Rule_295_A1_P578__cccc11101d111000dddd101sp1m0mmmm_Test) {
  CondVfpOpTester_Vcvt_Vcvtr_Rule_295_A1_P578_ baseline_tester;
  NamedVfpOp_Vcvt_Vcvtr_Rule_295_A1_P578 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d111000dddd101sp1m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vcvt_Vcvtr_Rule_295_A1_P578__cccc11101d11110xdddd101sp1m0mmmm_Test) {
  CondVfpOpTester_Vcvt_Vcvtr_Rule_295_A1_P578_ baseline_tester;
  NamedVfpOp_Vcvt_Vcvtr_Rule_295_A1_P578 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d11110xdddd101sp1m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vcvtb_Vcvtt_Rule_300_A1_P588__cccc11101d11001pdddd1010t1m0mmmm_Test) {
  CondVfpOpTester_Vcvtb_Vcvtt_Rule_300_A1_P588_ baseline_tester;
  NamedVfpOp_Vcvtb_Vcvtt_Rule_300_A1_P588 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d11001pdddd1010t1m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vdiv_Rule_301_A1_P590__cccc11101d00nnnndddd101sn0m0mmmm_Test) {
  CondVfpOpTester_Vdiv_Rule_301_A1_P590_ baseline_tester;
  NamedVfpOp_Vdiv_Rule_301_A1_P590 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d00nnnndddd101sn0m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vm_la_ls_Rule_423_A2_P636__cccc11100d00nnnndddd101snpm0mmmm_Test) {
  CondVfpOpTester_Vm_la_ls_Rule_423_A2_P636_ baseline_tester;
  NamedVfpOp_Vm_la_ls_Rule_423_A2_P636 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11100d00nnnndddd101snpm0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vmov_Rule_326_A2_P640__cccc11101d11iiiidddd101s0000iiii_Test) {
  CondVfpOpTester_Vmov_Rule_326_A2_P640_ baseline_tester;
  NamedVfpOp_Vmov_Rule_326_A2_P640 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d11iiiidddd101s0000iiii");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vmov_Rule_327_A2_P642__cccc11101d110000dddd101s01m0mmmm_Test) {
  CondVfpOpTester_Vmov_Rule_327_A2_P642_ baseline_tester;
  NamedVfpOp_Vmov_Rule_327_A2_P642 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d110000dddd101s01m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vmul_Rule_338_A2_P664__cccc11100d10nnnndddd101sn0m0mmmm_Test) {
  CondVfpOpTester_Vmul_Rule_338_A2_P664_ baseline_tester;
  NamedVfpOp_Vmul_Rule_338_A2_P664 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11100d10nnnndddd101sn0m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vneg_Rule_342_A2_P672__cccc11101d110001dddd101s01m0mmmm_Test) {
  CondVfpOpTester_Vneg_Rule_342_A2_P672_ baseline_tester;
  NamedVfpOp_Vneg_Rule_342_A2_P672 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d110001dddd101s01m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vnm_la_ls_ul_Rule_343_A1_P674__cccc11100d01nnnndddd101snpm0mmmm_Test) {
  CondVfpOpTester_Vnm_la_ls_ul_Rule_343_A1_P674_ baseline_tester;
  NamedVfpOp_Vnm_la_ls_ul_Rule_343_A1_P674 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11100d01nnnndddd101snpm0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vnm_la_ls_ul_Rule_343_A2_P674__cccc11100d10nnnndddd101sn1m0mmmm_Test) {
  CondVfpOpTester_Vnm_la_ls_ul_Rule_343_A2_P674_ baseline_tester;
  NamedVfpOp_Vnm_la_ls_ul_Rule_343_A2_P674 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11100d10nnnndddd101sn1m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vsqrt_Rule_388_A1_P762__cccc11101d110001dddd101s11m0mmmm_Test) {
  CondVfpOpTester_Vsqrt_Rule_388_A1_P762_ baseline_tester;
  NamedVfpOp_Vsqrt_Rule_388_A1_P762 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11101d110001dddd101s11m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       CondVfpOpTester_Vsub_Rule_402_A2_P790__cccc11100d11nnnndddd101sn1m0mmmm_Test) {
  CondVfpOpTester_Vsub_Rule_402_A2_P790_ baseline_tester;
  NamedVfpOp_Vsub_Rule_402_A2_P790 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc11100d11nnnndddd101sn1m0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       DuplicateToVfpRegistersTester_Vdup_Rule_303_A1_P594__cccc11101bq0ddddtttt1011d0e10000_Test) {
  DuplicateToVfpRegistersTester_Vdup_Rule_303_A1_P594_ tester;
  tester.Test("cccc11101bq0ddddtttt1011d0e10000");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Bxj_Rule_26_A1_P64__cccc000100101111111111110010mmmm_Test) {
  ForbiddenCondNopTester_Bxj_Rule_26_A1_P64_ baseline_tester;
  NamedForbidden_Bxj_Rule_26_A1_P64 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000100101111111111110010mmmm");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Ldm_Rule_2_B6_A1_P5__cccc100pu1w1nnnn1rrrrrrrrrrrrrrr_Test) {
  ForbiddenCondNopTester_Ldm_Rule_2_B6_A1_P5_ baseline_tester;
  NamedForbidden_Ldm_Rule_2_B6_A1_P5 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc100pu1w1nnnn1rrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Ldm_Rule_3_B6_A1_P7__cccc100pu101nnnn0rrrrrrrrrrrrrrr_Test) {
  ForbiddenCondNopTester_Ldm_Rule_3_B6_A1_P7_ baseline_tester;
  NamedForbidden_Ldm_Rule_3_B6_A1_P7 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc100pu101nnnn0rrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Msr_Rule_B6_1_6_A1_PB6_12__cccc00110010ii011111iiiiiiiiiiii_Test) {
  ForbiddenCondNopTester_Msr_Rule_B6_1_6_A1_PB6_12_ baseline_tester;
  NamedForbidden_Msr_Rule_B6_1_6_A1_PB6_12 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00110010ii011111iiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Msr_Rule_B6_1_6_A1_PB6_12__cccc00110010ii1i1111iiiiiiiiiiii_Test) {
  ForbiddenCondNopTester_Msr_Rule_B6_1_6_A1_PB6_12_ baseline_tester;
  NamedForbidden_Msr_Rule_B6_1_6_A1_PB6_12 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00110010ii1i1111iiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Msr_Rule_B6_1_6_A1_PB6_12__cccc00110110iiii1111iiiiiiiiiiii_Test) {
  ForbiddenCondNopTester_Msr_Rule_B6_1_6_A1_PB6_12_ baseline_tester;
  NamedForbidden_Msr_Rule_B6_1_6_A1_PB6_12 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00110110iiii1111iiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Msr_Rule_B6_1_7_P14__cccc00010010mm01111100000000nnnn_Test) {
  ForbiddenCondNopTester_Msr_Rule_B6_1_7_P14_ baseline_tester;
  NamedForbidden_Msr_Rule_B6_1_7_P14 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010010mm01111100000000nnnn");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Msr_Rule_B6_1_7_P14__cccc00010010mm1m111100000000nnnn_Test) {
  ForbiddenCondNopTester_Msr_Rule_B6_1_7_P14_ baseline_tester;
  NamedForbidden_Msr_Rule_B6_1_7_P14 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010010mm1m111100000000nnnn");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Msr_Rule_B6_1_7_P14__cccc00010110mmmm111100000000nnnn_Test) {
  ForbiddenCondNopTester_Msr_Rule_B6_1_7_P14_ baseline_tester;
  NamedForbidden_Msr_Rule_B6_1_7_P14 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00010110mmmm111100000000nnnn");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Sev_Rule_158_A1_P316__cccc0011001000001111000000000100_Test) {
  ForbiddenCondNopTester_Sev_Rule_158_A1_P316_ baseline_tester;
  NamedForbidden_Sev_Rule_158_A1_P316 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011001000001111000000000100");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Smc_Rule_B6_1_9_P18__cccc000101100000000000000111mmmm_Test) {
  ForbiddenCondNopTester_Smc_Rule_B6_1_9_P18_ baseline_tester;
  NamedForbidden_Smc_Rule_B6_1_9_P18 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000101100000000000000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Stm_Rule_11_B6_A1_P22__cccc100pu100nnnnrrrrrrrrrrrrrrrr_Test) {
  ForbiddenCondNopTester_Stm_Rule_11_B6_A1_P22_ baseline_tester;
  NamedForbidden_Stm_Rule_11_B6_A1_P22 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc100pu100nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Wfe_Rule_411_A1_P808__cccc0011001000001111000000000010_Test) {
  ForbiddenCondNopTester_Wfe_Rule_411_A1_P808_ baseline_tester;
  NamedForbidden_Wfe_Rule_411_A1_P808 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011001000001111000000000010");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenCondNopTester_Wfi_Rule_412_A1_P810__cccc0011001000001111000000000011_Test) {
  ForbiddenCondNopTester_Wfi_Rule_412_A1_P810_ baseline_tester;
  NamedForbidden_Wfi_Rule_412_A1_P810 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011001000001111000000000011");
}

TEST_F(Arm32DecoderStateTests,
       ForbiddenUncondNopTester_Blx_Rule_23_A2_P58__1111101hiiiiiiiiiiiiiiiiiiiiiiii_Test) {
  ForbiddenUncondNopTester_Blx_Rule_23_A2_P58_ baseline_tester;
  NamedForbidden_Blx_Rule_23_A2_P58 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("1111101hiiiiiiiiiiiiiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm12OpTester_Ldr_Rule_58_A1_P120_NotRnIsPc_cccc010pd0w1nnnnttttiiiiiiiiiiii_Test) {
  Load2RegisterImm12OpTester_Ldr_Rule_58_A1_P120_NotRnIsPc baseline_tester;
  NamedLoadBasedImmedMemory_Ldr_Rule_58_A1_P120 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc010pd0w1nnnnttttiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm12OpTester_Ldr_Rule_59_A1_P122__cccc0101d0011111ttttiiiiiiiiiiii_Test) {
  Load2RegisterImm12OpTester_Ldr_Rule_59_A1_P122_ baseline_tester;
  NamedLoadBasedImmedMemory_Ldr_Rule_59_A1_P122 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0101d0011111ttttiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm12OpTester_Ldrb_Rule_62_A1_P128_NotRnIsPc_cccc010pd1w1nnnnttttiiiiiiiiiiii_Test) {
  Load2RegisterImm12OpTester_Ldrb_Rule_62_A1_P128_NotRnIsPc baseline_tester;
  NamedLoadBasedImmedMemory_Ldrb_Rule_62_A1_P128 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc010pd1w1nnnnttttiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm12OpTester_Ldrb_Rule_63_A1_P130__cccc0101d1011111ttttiiiiiiiiiiii_Test) {
  Load2RegisterImm12OpTester_Ldrb_Rule_63_A1_P130_ baseline_tester;
  NamedLoadBasedImmedMemory_Ldrb_Rule_63_A1_P130 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0101d1011111ttttiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm8DoubleOpTester_Ldrd_Rule_66_A1_P136_NotRnIsPc_cccc000pd1w0nnnnttttiiii1101iiii_Test) {
  Load2RegisterImm8DoubleOpTester_Ldrd_Rule_66_A1_P136_NotRnIsPc baseline_tester;
  NamedLoadBasedImmedMemoryDouble_Ldrd_Rule_66_A1_P136 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd1w0nnnnttttiiii1101iiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm8DoubleOpTester_Ldrd_Rule_67_A1_P138__cccc0001d1001111ttttiiii1101iiii_Test) {
  Load2RegisterImm8DoubleOpTester_Ldrd_Rule_67_A1_P138_ baseline_tester;
  NamedLoadBasedImmedMemoryDouble_Ldrd_Rule_67_A1_P138 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001d1001111ttttiiii1101iiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm8OpTester_Ldrh_Rule_74_A1_P152_NotRnIsPc_cccc000pd1w1nnnnttttiiii1011iiii_Test) {
  Load2RegisterImm8OpTester_Ldrh_Rule_74_A1_P152_NotRnIsPc baseline_tester;
  NamedLoadBasedImmedMemory_Ldrh_Rule_74_A1_P152 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd1w1nnnnttttiiii1011iiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm8OpTester_Ldrh_Rule_75_A1_P154__cccc0001d1011111ttttiiii1011iiii_Test) {
  Load2RegisterImm8OpTester_Ldrh_Rule_75_A1_P154_ baseline_tester;
  NamedLoadBasedImmedMemory_Ldrh_Rule_75_A1_P154 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001d1011111ttttiiii1011iiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm8OpTester_Ldrsb_Rule_78_A1_P160_NotRnIsPc_cccc000pd1w1nnnnttttiiii1101iiii_Test) {
  Load2RegisterImm8OpTester_Ldrsb_Rule_78_A1_P160_NotRnIsPc baseline_tester;
  NamedLoadBasedImmedMemory_Ldrsb_Rule_78_A1_P160 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd1w1nnnnttttiiii1101iiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm8OpTester_Ldrsh_Rule_82_A1_P168_NotRnIsPc_cccc000pd1w1nnnnttttiiii1111iiii_Test) {
  Load2RegisterImm8OpTester_Ldrsh_Rule_82_A1_P168_NotRnIsPc baseline_tester;
  NamedLoadBasedImmedMemory_Ldrsh_Rule_82_A1_P168 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd1w1nnnnttttiiii1111iiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm8OpTester_Ldrsh_Rule_83_A1_P170__cccc0001d1011111ttttiiii1111iiii_Test) {
  Load2RegisterImm8OpTester_Ldrsh_Rule_83_A1_P170_ baseline_tester;
  NamedLoadBasedImmedMemory_Ldrsh_Rule_83_A1_P170 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001d1011111ttttiiii1111iiii");
}

TEST_F(Arm32DecoderStateTests,
       Load2RegisterImm8OpTester_ldrsb_Rule_79_A1_162__cccc0001d1011111ttttiiii1101iiii_Test) {
  Load2RegisterImm8OpTester_ldrsb_Rule_79_A1_162_ baseline_tester;
  NamedLoadBasedImmedMemory_ldrsb_Rule_79_A1_162 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001d1011111ttttiiii1101iiii");
}

TEST_F(Arm32DecoderStateTests,
       Load3RegisterDoubleOpTester_Ldrd_Rule_68_A1_P140__cccc000pd0w0nnnntttt00001101mmmm_Test) {
  Load3RegisterDoubleOpTester_Ldrd_Rule_68_A1_P140_ baseline_tester;
  NamedLoadBasedOffsetMemoryDouble_Ldrd_Rule_68_A1_P140 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd0w0nnnntttt00001101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Load3RegisterImm5OpTester_Ldr_Rule_60_A1_P124__cccc011pd0w1nnnnttttiiiiitt0mmmm_Test) {
  Load3RegisterImm5OpTester_Ldr_Rule_60_A1_P124_ baseline_tester;
  NamedLoadBasedOffsetMemory_Ldr_Rule_60_A1_P124 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011pd0w1nnnnttttiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Load3RegisterImm5OpTester_Ldrb_Rule_64_A1_P132__cccc011pd1w1nnnnttttiiiiitt0mmmm_Test) {
  Load3RegisterImm5OpTester_Ldrb_Rule_64_A1_P132_ baseline_tester;
  NamedLoadBasedOffsetMemory_Ldrb_Rule_64_A1_P132 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011pd1w1nnnnttttiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Load3RegisterOpTester_Ldrh_Rule_76_A1_P156__cccc000pd0w1nnnntttt00001011mmmm_Test) {
  Load3RegisterOpTester_Ldrh_Rule_76_A1_P156_ baseline_tester;
  NamedLoadBasedOffsetMemory_Ldrh_Rule_76_A1_P156 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd0w1nnnntttt00001011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Load3RegisterOpTester_Ldrsb_Rule_80_A1_P164__cccc000pd0w1nnnntttt00001101mmmm_Test) {
  Load3RegisterOpTester_Ldrsb_Rule_80_A1_P164_ baseline_tester;
  NamedLoadBasedOffsetMemory_Ldrsb_Rule_80_A1_P164 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd0w1nnnntttt00001101mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Load3RegisterOpTester_Ldrsh_Rule_84_A1_P172__cccc000pd0w1nnnntttt00001111mmmm_Test) {
  Load3RegisterOpTester_Ldrsh_Rule_84_A1_P172_ baseline_tester;
  NamedLoadBasedOffsetMemory_Ldrsh_Rule_84_A1_P172 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd0w1nnnntttt00001111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       LoadExclusive2RegisterDoubleOpTester_Ldrexd_Rule_71_A1_P146__cccc00011011nnnntttt111110011111_Test) {
  LoadExclusive2RegisterDoubleOpTester_Ldrexd_Rule_71_A1_P146_ baseline_tester;
  NamedLoadBasedMemoryDouble_Ldrexd_Rule_71_A1_P146 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00011011nnnntttt111110011111");
}

TEST_F(Arm32DecoderStateTests,
       LoadExclusive2RegisterOpTester_Ldrex_Rule_69_A1_P142__cccc00011001nnnntttt111110011111_Test) {
  LoadExclusive2RegisterOpTester_Ldrex_Rule_69_A1_P142_ baseline_tester;
  NamedLoadBasedMemory_Ldrex_Rule_69_A1_P142 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00011001nnnntttt111110011111");
}

TEST_F(Arm32DecoderStateTests,
       LoadExclusive2RegisterOpTester_Ldrexb_Rule_70_A1_P144__cccc00011101nnnndddd111110011111_Test) {
  LoadExclusive2RegisterOpTester_Ldrexb_Rule_70_A1_P144_ baseline_tester;
  NamedLoadBasedMemory_Ldrexb_Rule_70_A1_P144 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00011101nnnndddd111110011111");
}

TEST_F(Arm32DecoderStateTests,
       LoadExclusive2RegisterOpTester_Ldrexh_Rule_72_A1_P148__cccc00011111nnnntttt111110011111_Test) {
  LoadExclusive2RegisterOpTester_Ldrexh_Rule_72_A1_P148_ baseline_tester;
  NamedLoadBasedMemory_Ldrexh_Rule_72_A1_P148 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00011111nnnntttt111110011111");
}

TEST_F(Arm32DecoderStateTests,
       LoadRegisterListTester_Ldm_Ldmia_Ldmfd_Rule_53_A1_P110__cccc100010w1nnnnrrrrrrrrrrrrrrrr_Test) {
  LoadRegisterListTester_Ldm_Ldmia_Ldmfd_Rule_53_A1_P110_ baseline_tester;
  NamedLoadMultiple_Ldm_Ldmia_Ldmfd_Rule_53_A1_P110 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc100010w1nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       LoadRegisterListTester_Ldmda_Ldmfa_Rule_54_A1_P112__cccc100000w1nnnnrrrrrrrrrrrrrrrr_Test) {
  LoadRegisterListTester_Ldmda_Ldmfa_Rule_54_A1_P112_ baseline_tester;
  NamedLoadMultiple_Ldmda_Ldmfa_Rule_54_A1_P112 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc100000w1nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       LoadRegisterListTester_Ldmdb_Ldmea_Rule_55_A1_P114__cccc100100w1nnnnrrrrrrrrrrrrrrrr_Test) {
  LoadRegisterListTester_Ldmdb_Ldmea_Rule_55_A1_P114_ baseline_tester;
  NamedLoadMultiple_Ldmdb_Ldmea_Rule_55_A1_P114 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc100100w1nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       LoadRegisterListTester_Ldmib_Ldmed_Rule_56_A1_P116__cccc100110w1nnnnrrrrrrrrrrrrrrrr_Test) {
  LoadRegisterListTester_Ldmib_Ldmed_Rule_56_A1_P116_ baseline_tester;
  NamedLoadMultiple_Ldmib_Ldmed_Rule_56_A1_P116 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc100110w1nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       LoadVectorRegisterTester_Vldr_Rule_320_A1_A2_P628__cccc1101ud01nnnndddd101xiiiiiiii_Test) {
  LoadVectorRegisterTester_Vldr_Rule_320_A1_A2_P628_ tester;
  tester.Test("cccc1101ud01nnnndddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       LoadVectorRegisterListTester_Vldm_Rule_318_A1_A2_P626__cccc11010d11nnnndddd101xiiiiiiii_Test) {
  LoadVectorRegisterListTester_Vldm_Rule_318_A1_A2_P626_ tester;
  tester.Test("cccc11010d11nnnndddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       LoadVectorRegisterListTester_Vldm_Rule_319_A1_A2_P626__cccc11001d01nnnndddd101xiiiiiiii_Test) {
  LoadVectorRegisterListTester_Vldm_Rule_319_A1_A2_P626_ tester;
  tester.Test("cccc11001d01nnnndddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       LoadVectorRegisterListTester_Vldm_Rule_319_A1_A2_P626_NotRnIsSp_cccc11001d11nnnndddd101xiiiiiiii_Test) {
  LoadVectorRegisterListTester_Vldm_Rule_319_A1_A2_P626_NotRnIsSp tester;
  tester.Test("cccc11001d11nnnndddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       LoadVectorRegisterListTester_Vpop_Rule_354_A1_A2_P694__cccc11001d111101dddd101xiiiiiiii_Test) {
  LoadVectorRegisterListTester_Vpop_Rule_354_A1_A2_P694_ tester;
  tester.Test("cccc11001d111101dddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       MaskedBinary2RegisterImmediateOpTester_Bic_Rule_19_A1_P50_NotRdIsPcAndS_cccc0011110unnnnddddiiiiiiiiiiii_Test) {
  MaskedBinary2RegisterImmediateOpTester_Bic_Rule_19_A1_P50_NotRdIsPcAndS baseline_tester;
  NamedMaskAddress_Bic_Rule_19_A1_P50 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011110unnnnddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       MaskedBinaryRegisterImmediateTestTester_Tst_Rule_230_A1_P454__cccc00110001nnnn0000iiiiiiiiiiii_Test) {
  MaskedBinaryRegisterImmediateTestTester_Tst_Rule_230_A1_P454_ baseline_tester;
  NamedTestIfAddressMasked_Tst_Rule_230_A1_P454 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00110001nnnn0000iiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       MoveVfpRegisterOpTester_Vmov_Rule_330_A1_P648__cccc11100000nnnntttt1010n0010000_Test) {
  MoveVfpRegisterOpTester_Vmov_Rule_330_A1_P648_ tester;
  tester.Test("cccc11100000nnnntttt1010n0010000");
}

TEST_F(Arm32DecoderStateTests,
       MoveVfpRegisterOpTester_Vmov_Rule_330_A1_P648__cccc11100001nnnntttt1010n0010000_Test) {
  MoveVfpRegisterOpTester_Vmov_Rule_330_A1_P648_ tester;
  tester.Test("cccc11100001nnnntttt1010n0010000");
}

TEST_F(Arm32DecoderStateTests,
       MoveVfpRegisterOpWithTypeSelTester_Vmov_Rule_328_A1_P644__cccc11100ii0ddddtttt1011dii10000_Test) {
  MoveVfpRegisterOpWithTypeSelTester_Vmov_Rule_328_A1_P644_ tester;
  tester.Test("cccc11100ii0ddddtttt1011dii10000");
}

TEST_F(Arm32DecoderStateTests,
       MoveVfpRegisterOpWithTypeSelTester_Vmov_Rule_329_A1_P646__cccc1110iii1nnnntttt1011nii10000_Test) {
  MoveVfpRegisterOpWithTypeSelTester_Vmov_Rule_329_A1_P646_ tester;
  tester.Test("cccc1110iii1nnnntttt1011nii10000");
}

TEST_F(Arm32DecoderStateTests,
       Store2RegisterImm12OpTester_Str_Rule_194_A1_P384__cccc010pd0w0nnnnttttiiiiiiiiiiii_Test) {
  Store2RegisterImm12OpTester_Str_Rule_194_A1_P384_ baseline_tester;
  NamedStoreBasedImmedMemory_Str_Rule_194_A1_P384 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc010pd0w0nnnnttttiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Store2RegisterImm12OpTester_Strb_Rule_197_A1_P390__cccc010pd1w0nnnnttttiiiiiiiiiiii_Test) {
  Store2RegisterImm12OpTester_Strb_Rule_197_A1_P390_ baseline_tester;
  NamedStoreBasedImmedMemory_Strb_Rule_197_A1_P390 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc010pd1w0nnnnttttiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Store2RegisterImm8DoubleOpTester_Strd_Rule_200_A1_P396__cccc000pd1w0nnnnttttiiii1111iiii_Test) {
  Store2RegisterImm8DoubleOpTester_Strd_Rule_200_A1_P396_ baseline_tester;
  NamedStoreBasedImmedMemoryDouble_Strd_Rule_200_A1_P396 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd1w0nnnnttttiiii1111iiii");
}

TEST_F(Arm32DecoderStateTests,
       Store2RegisterImm8OpTester_Strh_Rule_207_A1_P410__cccc000pd1w0nnnnttttiiii1011iiii_Test) {
  Store2RegisterImm8OpTester_Strh_Rule_207_A1_P410_ baseline_tester;
  NamedStoreBasedImmedMemory_Strh_Rule_207_A1_P410 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd1w0nnnnttttiiii1011iiii");
}

TEST_F(Arm32DecoderStateTests,
       Store3RegisterDoubleOpTester_Strd_Rule_201_A1_P398__cccc000pd0w0nnnntttt00001111mmmm_Test) {
  Store3RegisterDoubleOpTester_Strd_Rule_201_A1_P398_ baseline_tester;
  NamedStoreBasedOffsetMemoryDouble_Strd_Rule_201_A1_P398 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd0w0nnnntttt00001111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Store3RegisterImm5OpTester_Str_Rule_195_A1_P386__cccc011pd0w0nnnnttttiiiiitt0mmmm_Test) {
  Store3RegisterImm5OpTester_Str_Rule_195_A1_P386_ baseline_tester;
  NamedStoreBasedOffsetMemory_Str_Rule_195_A1_P386 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011pd0w0nnnnttttiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Store3RegisterImm5OpTester_Strb_Rule_198_A1_P392__cccc011pd1w0nnnnttttiiiiitt0mmmm_Test) {
  Store3RegisterImm5OpTester_Strb_Rule_198_A1_P392_ baseline_tester;
  NamedStoreBasedOffsetMemory_Strb_Rule_198_A1_P392 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011pd1w0nnnnttttiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Store3RegisterOpTester_Strh_Rule_208_A1_P412__cccc000pd0w0nnnntttt00001011mmmm_Test) {
  Store3RegisterOpTester_Strh_Rule_208_A1_P412_ baseline_tester;
  NamedStoreBasedOffsetMemory_Strh_Rule_208_A1_P412 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000pd0w0nnnntttt00001011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       StoreExclusive3RegisterDoubleOpTester_Strexd_Rule_204_A1_P404__cccc00011010nnnndddd11111001tttt_Test) {
  StoreExclusive3RegisterDoubleOpTester_Strexd_Rule_204_A1_P404_ baseline_tester;
  NamedStoreBasedMemoryDoubleRtBits0To3_Strexd_Rule_204_A1_P404 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00011010nnnndddd11111001tttt");
}

TEST_F(Arm32DecoderStateTests,
       StoreExclusive3RegisterOpTester_Strex_Rule_202_A1_P400__cccc00011000nnnndddd11111001tttt_Test) {
  StoreExclusive3RegisterOpTester_Strex_Rule_202_A1_P400_ baseline_tester;
  NamedStoreBasedMemoryRtBits0To3_Strex_Rule_202_A1_P400 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00011000nnnndddd11111001tttt");
}

TEST_F(Arm32DecoderStateTests,
       StoreExclusive3RegisterOpTester_Strexb_Rule_203_A1_P402__cccc00011100nnnndddd11111001tttt_Test) {
  StoreExclusive3RegisterOpTester_Strexb_Rule_203_A1_P402_ baseline_tester;
  NamedStoreBasedMemoryRtBits0To3_Strexb_Rule_203_A1_P402 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00011100nnnndddd11111001tttt");
}

TEST_F(Arm32DecoderStateTests,
       StoreRegisterListTester_Stm_Stmia_Stmea_Rule_189_A1_P374__cccc100010w0nnnnrrrrrrrrrrrrrrrr_Test) {
  StoreRegisterListTester_Stm_Stmia_Stmea_Rule_189_A1_P374_ tester;
  tester.Test("cccc100010w0nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       StoreRegisterListTester_Stmda_Stmed_Rule_190_A1_P376__cccc100000w0nnnnrrrrrrrrrrrrrrrr_Test) {
  StoreRegisterListTester_Stmda_Stmed_Rule_190_A1_P376_ tester;
  tester.Test("cccc100000w0nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       StoreRegisterListTester_Stmdb_Stmfd_Rule_191_A1_P378__cccc100100w0nnnnrrrrrrrrrrrrrrrr_Test) {
  StoreRegisterListTester_Stmdb_Stmfd_Rule_191_A1_P378_ tester;
  tester.Test("cccc100100w0nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       StoreRegisterListTester_Stmid_Stmfa_Rule_192_A1_P380__cccc100110w0nnnnrrrrrrrrrrrrrrrr_Test) {
  StoreRegisterListTester_Stmid_Stmfa_Rule_192_A1_P380_ tester;
  tester.Test("cccc100110w0nnnnrrrrrrrrrrrrrrrr");
}

TEST_F(Arm32DecoderStateTests,
       StoreVectorRegisterTester_Vstr_Rule_400_A1_A2_P786__cccc1101ud00nnnndddd101xiiiiiiii_Test) {
  StoreVectorRegisterTester_Vstr_Rule_400_A1_A2_P786_ tester;
  tester.Test("cccc1101ud00nnnndddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       StoreVectorRegisterListTester_Vpush_355_A1_A2_P696__cccc11010d101101dddd101xiiiiiiii_Test) {
  StoreVectorRegisterListTester_Vpush_355_A1_A2_P696_ tester;
  tester.Test("cccc11010d101101dddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784__cccc11001d00nnnndddd101xiiiiiiii_Test) {
  StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784_ tester;
  tester.Test("cccc11001d00nnnndddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784__cccc11001d10nnnndddd101xiiiiiiii_Test) {
  StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784_ tester;
  tester.Test("cccc11001d10nnnndddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784_NotRnIsSp_cccc11010d10nnnndddd101xiiiiiiii_Test) {
  StoreVectorRegisterListTester_Vstm_Rule_399_A1_A2_P784_NotRnIsSp tester;
  tester.Test("cccc11010d10nnnndddd101xiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Unary1RegisterBitRangeTester_Bfc_17_A1_P46__cccc0111110mmmmmddddlllll0011111_Test) {
  Unary1RegisterBitRangeTester_Bfc_17_A1_P46_ tester;
  tester.Test("cccc0111110mmmmmddddlllll0011111");
}

TEST_F(Arm32DecoderStateTests,
       Unary1RegisterImmediateOpTester_Adr_Rule_10_A1_P32__cccc001010001111ddddiiiiiiiiiiii_Test) {
  Unary1RegisterImmediateOpTester_Adr_Rule_10_A1_P32_ baseline_tester;
  NamedDefs12To15_Adr_Rule_10_A1_P32 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc001010001111ddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Unary1RegisterImmediateOpTester_Adr_Rule_10_A2_P32__cccc001001001111ddddiiiiiiiiiiii_Test) {
  Unary1RegisterImmediateOpTester_Adr_Rule_10_A2_P32_ baseline_tester;
  NamedDefs12To15_Adr_Rule_10_A2_P32 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc001001001111ddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Unary1RegisterImmediateOpTester_Mov_Rule_96_A1_P194_NotRdIsPcAndS_cccc0011101u0000ddddiiiiiiiiiiii_Test) {
  Unary1RegisterImmediateOpTester_Mov_Rule_96_A1_P194_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Mov_Rule_96_A1_P194 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011101u0000ddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Unary1RegisterImmediateOpTester_Mov_Rule_96_A2_P_194_RegsNotPc_cccc00110000iiiiddddIIIIIIIIIIII_Test) {
  Unary1RegisterImmediateOpTester_Mov_Rule_96_A2_P_194_RegsNotPc baseline_tester;
  NamedDefs12To15_Mov_Rule_96_A2_P_194 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc00110000iiiiddddIIIIIIIIIIII");
}

TEST_F(Arm32DecoderStateTests,
       Unary1RegisterImmediateOpTester_Mvn_Rule_106_A1_P214_NotRdIsPcAndS_cccc0011111u0000ddddiiiiiiiiiiii_Test) {
  Unary1RegisterImmediateOpTester_Mvn_Rule_106_A1_P214_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Mvn_Rule_106_A1_P214 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0011111u0000ddddiiiiiiiiiiii");
}

TEST_F(Arm32DecoderStateTests,
       Unary1RegisterSetTester_Mrs_Rule_102_A1_P206_Or_B6_10__cccc00010r001111dddd000000000000_Test) {
  Unary1RegisterSetTester_Mrs_Rule_102_A1_P206_Or_B6_10_ tester;
  tester.Test("cccc00010r001111dddd000000000000");
}

TEST_F(Arm32DecoderStateTests,
       Unary1RegisterUseTester_Msr_Rule_104_A1_P210__cccc00010010mm00111100000000nnnn_Test) {
  Unary1RegisterUseTester_Msr_Rule_104_A1_P210_ tester;
  tester.Test("cccc00010010mm00111100000000nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterImmedShiftedOpTester_Asr_Rule_14_A1_P40__cccc0001101u0000ddddiiiii100mmmm_Test) {
  Unary2RegisterImmedShiftedOpTester_Asr_Rule_14_A1_P40_ baseline_tester;
  NamedDefs12To15_Asr_Rule_14_A1_P40 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000ddddiiiii100mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterImmedShiftedOpTester_Lsl_Rule_88_A1_P178_Imm5NotZero_cccc0001101u0000ddddiiiii000mmmm_Test) {
  Unary2RegisterImmedShiftedOpTester_Lsl_Rule_88_A1_P178_Imm5NotZero baseline_tester;
  NamedDefs12To15_Lsl_Rule_88_A1_P178 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000ddddiiiii000mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterImmedShiftedOpTester_Lsr_Rule_90_A1_P182__cccc0001101u0000ddddiiiii010mmmm_Test) {
  Unary2RegisterImmedShiftedOpTester_Lsr_Rule_90_A1_P182_ baseline_tester;
  NamedDefs12To15_Lsr_Rule_90_A1_P182 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000ddddiiiii010mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterImmedShiftedOpTester_Mvn_Rule_107_A1_P216_NotRdIsPcAndS_cccc0001111u0000ddddiiiiitt0mmmm_Test) {
  Unary2RegisterImmedShiftedOpTester_Mvn_Rule_107_A1_P216_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Mvn_Rule_107_A1_P216 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001111u0000ddddiiiiitt0mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterImmedShiftedOpTester_Ror_Rule_139_A1_P278_Imm5NotZero_cccc0001101u0000ddddiiiii110mmmm_Test) {
  Unary2RegisterImmedShiftedOpTester_Ror_Rule_139_A1_P278_Imm5NotZero baseline_tester;
  NamedDefs12To15_Ror_Rule_139_A1_P278 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000ddddiiiii110mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterImmedShiftedOpRegsNotPcTester_Sxtb16_Rule_224_A1_P442__cccc011010001111ddddrr000111mmmm_Test) {
  Unary2RegisterImmedShiftedOpRegsNotPcTester_Sxtb16_Rule_224_A1_P442_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Sxtb16_Rule_224_A1_P442 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011010001111ddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterImmedShiftedOpRegsNotPcTester_Sxtb_Rule_223_A1_P440__cccc011010101111ddddrr000111mmmm_Test) {
  Unary2RegisterImmedShiftedOpRegsNotPcTester_Sxtb_Rule_223_A1_P440_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Sxtb_Rule_223_A1_P440 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011010101111ddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpTester_Mov_Rule_97_A1_P196_NotRdIsPcAndS_cccc0001101u0000dddd00000000mmmm_Test) {
  Unary2RegisterOpTester_Mov_Rule_97_A1_P196_NotRdIsPcAndS baseline_tester;
  NamedDefs12To15_Mov_Rule_97_A1_P196 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000dddd00000000mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpTester_Rrx_Rule_141_A1_P282__cccc0001101u0000dddd00000110mmmm_Test) {
  Unary2RegisterOpTester_Rrx_Rule_141_A1_P282_ baseline_tester;
  NamedDefs12To15_Rrx_Rule_141_A1_P282 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001101u0000dddd00000110mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcTester_Rbit_Rule_134_A1_P270__cccc011011111111dddd11110011mmmm_Test) {
  Unary2RegisterOpNotRmIsPcTester_Rbit_Rule_134_A1_P270_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Rbit_Rule_134_A1_P270 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011011111111dddd11110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcTester_Revsh_Rule_137_A1_P276__cccc011011111111dddd11111011mmmm_Test) {
  Unary2RegisterOpNotRmIsPcTester_Revsh_Rule_137_A1_P276_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Revsh_Rule_137_A1_P276 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011011111111dddd11111011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcTester_Uxtb16_Rule_264_A1_P522__cccc011011001111ddddrr000111mmmm_Test) {
  Unary2RegisterOpNotRmIsPcTester_Uxtb16_Rule_264_A1_P522_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Uxtb16_Rule_264_A1_P522 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011011001111ddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcTester_Uxtb_Rule_263_A1_P520__cccc011011101111ddddrr000111mmmm_Test) {
  Unary2RegisterOpNotRmIsPcTester_Uxtb_Rule_263_A1_P520_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Uxtb_Rule_263_A1_P520 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011011101111ddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcTester_Uxth_Rule_265_A1_P524__cccc011011111111ddddrr000111mmmm_Test) {
  Unary2RegisterOpNotRmIsPcTester_Uxth_Rule_265_A1_P524_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Uxth_Rule_265_A1_P524 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011011111111ddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcTester_Clz_Rule_31_A1_P72__cccc000101101111dddd11110001mmmm_Test) {
  Unary2RegisterOpNotRmIsPcTester_Clz_Rule_31_A1_P72_ baseline_tester;
  NamedDefs12To15RdRnNotPc_Clz_Rule_31_A1_P72 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc000101101111dddd11110001mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Rev16_Rule_136_A1_P274__cccc011010111111dddd11111011mmmm_Test) {
  Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Rev16_Rule_136_A1_P274_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Rev16_Rule_136_A1_P274 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011010111111dddd11111011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Rev_Rule_135_A1_P272__cccc011010111111dddd11110011mmmm_Test) {
  Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Rev_Rule_135_A1_P272_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Rev_Rule_135_A1_P272 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011010111111dddd11110011mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Sxth_Rule_225_A1_P444__cccc011010111111ddddrr000111mmmm_Test) {
  Unary2RegisterOpNotRmIsPcNoCondUpdatesTester_Sxth_Rule_225_A1_P444_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Sxth_Rule_225_A1_P444 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc011010111111ddddrr000111mmmm");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterSatImmedShiftedOpTester_Ssat16_Rule_184_A1_P364__cccc01101010iiiidddd11110011nnnn_Test) {
  Unary2RegisterSatImmedShiftedOpTester_Ssat16_Rule_184_A1_P364_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Ssat16_Rule_184_A1_P364 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101010iiiidddd11110011nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterSatImmedShiftedOpTester_Ssat_Rule_183_A1_P362__cccc0110101iiiiiddddiiiiis01nnnn_Test) {
  Unary2RegisterSatImmedShiftedOpTester_Ssat_Rule_183_A1_P362_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Ssat_Rule_183_A1_P362 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0110101iiiiiddddiiiiis01nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterSatImmedShiftedOpTester_Usat16_Rule_256_A1_P506__cccc01101110iiiidddd11110011nnnn_Test) {
  Unary2RegisterSatImmedShiftedOpTester_Usat16_Rule_256_A1_P506_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Usat16_Rule_256_A1_P506 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc01101110iiiidddd11110011nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Unary2RegisterSatImmedShiftedOpTester_Usat_Rule_255_A1_P504__cccc0110111iiiiiddddiiiiis01nnnn_Test) {
  Unary2RegisterSatImmedShiftedOpTester_Usat_Rule_255_A1_P504_ baseline_tester;
  NamedDefs12To15CondsDontCareRdRnNotPc_Usat_Rule_255_A1_P504 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0110111iiiiiddddiiiiis01nnnn");
}

TEST_F(Arm32DecoderStateTests,
       Unary3RegisterShiftedOpTester_Mvn_Rule_108_A1_P218_RegsNotPc_cccc0001111u0000ddddssss0tt1mmmm_Test) {
  Unary3RegisterShiftedOpTester_Mvn_Rule_108_A1_P218_RegsNotPc baseline_tester;
  NamedDefs12To15RdRmRnNotPc_Mvn_Rule_108_A1_P218 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc0001111u0000ddddssss0tt1mmmm");
}

TEST_F(Arm32DecoderStateTests,
       VfpMrsOpTester_Vmrs_Rule_335_A1_P658__cccc111011110001tttt101000010000_Test) {
  VfpMrsOpTester_Vmrs_Rule_335_A1_P658_ tester;
  tester.Test("cccc111011110001tttt101000010000");
}

TEST_F(Arm32DecoderStateTests,
       VfpUsesRegOpTester_Vmsr_Rule_336_A1_P660__cccc111011100001tttt101000010000_Test) {
  VfpUsesRegOpTester_Vmsr_Rule_336_A1_P660_ baseline_tester;
  NamedDontCareInstRdNotPc_Vmsr_Rule_336_A1_P660 actual;
  ActualVsBaselineTester a_vs_b_tester(actual, baseline_tester);
  a_vs_b_tester.Test("cccc111011100001tttt101000010000");
}

}  // namespace nacl_arm_test

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
