SET(PROJECT_VERSION_MAJOR 0)
SET(PROJECT_VERSION_MINOR 1)
SET(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})

SET(DATA_DIR ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}-${PROJECT_VERSION})

ADD_DEFINITIONS(-DDATA_DIR="${DATA_DIR}")

ADD_DEFINITIONS(-DWEBCORE_NAVIGATOR_VENDOR="Research In Motion, Ltd.")
ADD_DEFINITIONS(-DBUILDING_BLACKBERRY__)
ADD_DEFINITIONS(-DBUILD_WEBKIT)

# Workaround for now so that SK_DEBUG isn't defined in SkPreConfig.h
ADD_DEFINITIONS(-DSK_RELEASE)

# TODO: Make this build-time configurable
SET(WTF_USE_PTHREADS 1)
ADD_DEFINITIONS(-DWTF_USE_PTHREADS=1)
SET(WTF_USE_OPENTYPE_SANITIZER 1)
ADD_DEFINITIONS(-DWTF_USE_OPENTYPE_SANITIZER=1)

IF (ENABLE_GLES2)
    SET(WTF_USE_ACCELERATED_COMPOSITING 1)
    ADD_DEFINITIONS(-DWTF_USE_ACCELERATED_COMPOSITING=1)
    ADD_DEFINITIONS(-DBLACKBERRY_PLATFORM_GRAPHICS_EGL=1)
    ADD_DEFINITIONS(-DBLACKBERRY_PLATFORM_EXPORT_WEBDOM=1)
ENDIF ()

IF (ADDITIONAL_SYSTEM_INCLUDE_PATH)
    SET(CMAKE_INCLUDE_SYSTEM_FLAG_C "-Wp,-isystem")
    SET(CMAKE_INCLUDE_SYSTEM_FLAG_CXX "-Wp,-isystem")
    FOREACH (directory ${ADDITIONAL_SYSTEM_INCLUDE_PATH})
        INCLUDE_DIRECTORIES(SYSTEM ${directory})
    ENDFOREACH ()
    IF(ENABLE_WEBGL)
        INCLUDE_DIRECTORIES(SYSTEM ${THIRDPARTY_DIR}/ANGLE/include) #As system so as to be lower-priority than actual system headers
    ENDIF ()
ENDIF ()

IF (PUBLIC_BUILD)
    ADD_DEFINITIONS(-DPUBLIC_BUILD=1)
    message("*** PUBLIC BUILD ***")
ELSE (PUBLIC_BUILD)
    message("*** DRT is ENABLED ***")
ENDIF ()

ADD_DEFINITIONS(-D__QNXNTO__)
ADD_DEFINITIONS(-D_FILE_OFFSET_BITS=64)
ADD_DEFINITIONS(-D_LARGEFILE64_SOURCE)
ADD_DEFINITIONS(-DWTF_USE_LEGACY_VIEWPORT_ADAPTION=1)

# Find a library only in the staging directory (which is the CMAKE_INSTALL_PATH)
# TODO: CMAKE_INSTALL_PATH may not be staging directory.
MACRO(FIND_STAGING_LIBRARY _var _libname)
  FIND_LIBRARY(${_var} ${_libname}
    PATHS "${CMAKE_INSTALL_PREFIX}"
    ENV "QNX_TARGET"
    PATH_SUFFIXES "${CMAKE_SYSTEM_PROCESSOR}/usr/lib" "${CMAKE_SYSTEM_PROCESSOR}/usr/lib/torch-webkit" "${CMAKE_SYSTEM_PROCESSOR}/lib"
    NO_DEFAULT_PATH)
ENDMACRO()

FIND_STAGING_LIBRARY(Skia_LIBRARY grskia)
FIND_STAGING_LIBRARY(Skia_QNX_LIBRARY skia-qnx)
FIND_STAGING_LIBRARY(JPEG_LIBRARY jpeg)
FIND_STAGING_LIBRARY(PNG_LIBRARY png)
FIND_STAGING_LIBRARY(XML2_LIBRARY xml2)
FIND_STAGING_LIBRARY(XSLT_LIBRARY xslt)
FIND_STAGING_LIBRARY(SQLITE3_LIBRARY sqlite3)
FIND_STAGING_LIBRARY(M_LIBRARY m)
FIND_STAGING_LIBRARY(NBUTIL_LIBRARY nbutil)
FIND_STAGING_LIBRARY(FREETYPE_LIBRARY freetype)
FIND_STAGING_LIBRARY(ICUData_LIBRARY icudata)
FIND_STAGING_LIBRARY(ICUI18N_LIBRARY icui18n)
FIND_STAGING_LIBRARY(ICUUC_LIBRARY icuuc)
FIND_STAGING_LIBRARY(Iconv_LIBRARY iconv)
FIND_STAGING_LIBRARY(INTL_LIBRARY intl)
FIND_STAGING_LIBRARY(Z_LIBRARY z)
FIND_STAGING_LIBRARY(Socket_LIBRARY socket)
FIND_STAGING_LIBRARY(CURL_LIBRARY curl)
FIND_STAGING_LIBRARY(SSL_LIBRARY ssl)
FIND_STAGING_LIBRARY(Crypto_LIBRARY crypto)
FIND_STAGING_LIBRARY(WebKitPlatform_LIBRARY webkitplatform)
FIND_STAGING_LIBRARY(UUID_LIBRARY uuid-browser)
FIND_STAGING_LIBRARY(Screen_LIBRARY screen)
FIND_STAGING_LIBRARY(MMR_LIBRARY mmrndclient)
FIND_STAGING_LIBRARY(PPSCache_LIBRARY ppscache)
FIND_STAGING_LIBRARY(MD_LIBRARY md)
FIND_STAGING_LIBRARY(AOI_LIBRARY aoi)
FIND_STAGING_LIBRARY(CLIPBOARD_LIBRARY clipboard)
FIND_STAGING_LIBRARY(EGL_LIBRARY EGL)
FIND_STAGING_LIBRARY(GLESv2_LIBRARY GLESv2)
FIND_STAGING_LIBRARY(STRM_LIBRARY strm)
FIND_STAGING_LIBRARY(HARFBUZZ_LIBRARY harfbuzz)
FIND_STAGING_LIBRARY(FONTCONFIG_LIBRARY fontconfig)
FIND_STAGING_LIBRARY(PROFILING_LIBRARY profilingS)
FIND_STAGING_LIBRARY(LIB_INPUT_UTILITIES input_utilities)
FIND_STAGING_LIBRARY(OTS_LIBRARY ots)

# Show unresolved symbols when doing the final shared object link
IF (PROFILING)
    SET(BLACKBERRY_LINK_FLAGS "-Wl,-z,defs -Wl,-zrelro -Wl,-E")
ELSE (PROFILING)
    SET(BLACKBERRY_LINK_FLAGS "-Wl,-z,defs -Wl,-zrelro")
ENDIF ()

# Set custom CFLAGS for our port
IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_CXX_FLAGS "-fstack-protector -fno-rtti -Wformat -Wformat-security -Werror=format-security ${CMAKE_CXX_FLAGS}")
    SET(CMAKE_C_FLAGS "-fstack-protector -fno-rtti -Wformat -Wformat-security -Werror=format-security ${CMAKE_C_FLAGS}")
    SET(JSC_LINK_FLAGS "-N1024K")
ENDIF ()

IF (PROFILING)
    SET(CMAKE_CXX_FLAGS "-finstrument-functions -g ${CMAKE_CXX_FLAGS}")
    SET(CMAKE_C_FLAGS "-finstrument-functions -g ${CMAKE_C_FLAGS}")
ENDIF ()

# FIXME: Make this more elegant
IF (TARGETING_PLAYBOOK)
    SET(CMAKE_CXX_FLAGS "-mfpu=vfpv3 -mthumb -mthumb-interwork ${CMAKE_CXX_FLAGS}")
    SET(CMAKE_C_FLAGS "-mfpu=vfpv3 -mthumb -mthumb-interwork ${CMAKE_C_FLAGS}")
ENDIF ()

ADD_DEFINITIONS(-DRESOURCE_PATH="/usr/share/webkit-owb/resources/")
INCLUDE_DIRECTORIES(${CMAKE_INCLUDE_PATH})

SET(JSC_EXECUTABLE_NAME jsc)

SET(WTF_LIBRARY_NAME wtf)
SET(JavaScriptCore_LIBRARY_NAME javascriptcore)
SET(WebCore_LIBRARY_NAME webcore)
SET(WebKit_LIBRARY_NAME webkit)
SET(WebKit_DRT_LIBRARY_NAME webkit_DRT)

WEBKIT_OPTION_BEGIN()

WEBKIT_OPTION_DEFINE(ENABLE_EVENT_MODE_METATAGS "Enable meta-tag touch and mouse events" ON)
WEBKIT_OPTION_DEFINE(ENABLE_VIEWPORT_REFLOW "Enable viewport reflow" ON)

WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ANIMATION_API ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ASSEMBLER_WX_EXCLUSIVE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_BATTERY_STATUS ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_BLOB ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CUSTOM_SCHEME_HANDLER ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_DEVICE_ORIENTATION ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_DRAG_SUPPORT OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_DOWNLOAD_ATTRIBUTE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FILE_SYSTEM ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FILTERS ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FULLSCREEN_API ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_GEOLOCATION ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_IMAGE_DECODER_DOWN_SAMPLING ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_INPUT_TYPE_COLOR ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_LEGACY_NOTIFICATIONS ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_LEGACY_WEBKIT_BLOB_BUILDER ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_STREAM ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MICRODATA ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_NOTIFICATIONS ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ORIENTATION_EVENTS ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_PAGE_POPUP ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_PAGE_VISIBILITY_API ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_REGISTER_PROTOCOL_HANDLER ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_REPAINT_THROTTLING ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_REQUEST_ANIMATION_FRAME ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_SHARED_WORKERS ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_SMOOTH_SCROLLING ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_STYLE_SCOPED ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_TOUCH_EVENTS ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_VIBRATION ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_VIDEO ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEB_TIMING ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WORKERS ON)

IF (ENABLE_GLES2)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_3D_RENDERING ON)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ACCELERATED_2D_CANVAS ON)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_FILTERS ON)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_SHADERS ON)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBGL ON)
ELSE ()
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_3D_RENDERING OFF)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ACCELERATED_2D_CANVAS OFF)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_FILTERS OFF)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_SHADERS OFF)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBGL OFF)
ENDIF ()

IF (CMAKE_SYSTEM_PROCESSOR MATCHES x86)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_JIT OFF)
ELSE ()
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_JIT ON)
ENDIF ()

WEBKIT_OPTION_END()

ADD_DEFINITIONS(-DENABLE_BLACKBERRY_CREDENTIAL_PERSIST=1)

# Some of our files, such as platform/graphics/chromium/ComplexTextControllerLinux.cpp, require a
# newer ICU version than the version associated with the headers in {WebCore, JavaScriptCore}/icu.
# Because of <https://bugs.webkit.org/show_bug.cgi?id=70913> we can't directly reference these newer
# ICU headers within the QNX system header directory. As a workaround, we copy these newer ICU headers
# from the QNX system header directory to a third-party directory under the CMake binary tree.
#
# FIXME: Make this mechanism more general purpose. Maybe accept a list or directories/files to copy
# instead of individual variables. Generalizing this solution may allow us to fix <https://bugs.webkit.org/show_bug.cgi?id=70913>.
SET(BLACKBERRY_THIRD_PARTY_DIR "${CMAKE_BINARY_DIR}/ThirdPartyBlackBerry")
FILE(COPY ${THIRD_PARTY_ICU_DIR} DESTINATION "${BLACKBERRY_THIRD_PARTY_DIR}/icu")
FILE(COPY ${THIRD_PARTY_UNICODE_FILE} DESTINATION ${BLACKBERRY_THIRD_PARTY_DIR})
