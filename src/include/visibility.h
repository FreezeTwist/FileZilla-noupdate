#ifndef FILEZILLA_ENGINE_VISIBILITY_HEADER
#define FILEZILLA_ENGINE_VISIBILITY_HEADER

#include <libfilezilla/visibility_helper.hpp>

// Symbol visibility. There are two main cases: Building FileZilla and using it
#ifdef BUILDING_FILEZILLA
  #define FZC_PUBLIC_SYMBOL FZ_EXPORT_PUBLIC
  #define FZC_PRIVATE_SYMBOL FZ_EXPORT_PRIVATE
#else
  #if FZC_USING_DLL
    #define FZC_PUBLIC_SYMBOL FZ_IMPORT_SHARED
  #else
    #define FZC_PUBLIC_SYMBOL FZ_IMPORT_STATIC
  #endif
  #define FZC_PRIVATE_SYMBOL
#endif

#endif
