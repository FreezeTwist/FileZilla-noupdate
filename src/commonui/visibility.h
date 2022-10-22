#ifndef FILEZILLA_COMMONUI_VISIBILITY_HEADER
#define FILEZILLA_COMMONUI_VISIBILITY_HEADER

#include <libfilezilla/visibility_helper.hpp>

// Symbol visibility. There are two main cases: Building FileZilla and using it
#ifdef BUILDING_FZ_COMMONUI
  #define FZCUI_PUBLIC_SYMBOL FZ_EXPORT_PUBLIC
  #define FZCUI_PRIVATE_SYMBOL FZ_EXPORT_PRIVATE
#else
  #if FZCUI_USING_DLL
    #define FZCUI_PUBLIC_SYMBOL FZ_IMPORT_SHARED
  #else
    #define FZCUI_PUBLIC_SYMBOL FZ_IMPORT_STATIC
  #endif
  #define FZCUI_PRIVATE_SYMBOL
#endif

#endif
