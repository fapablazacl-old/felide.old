
#pragma once

#ifndef __felide_core_predef_hpp__
#define __felide_core_predef_hpp__

#if defined(_WINDOWS)
  #define FELIDE_API_EXPORT __declspec(dllexport)
  #define FELIDE_API_IMPORT __declspec(dllimport)
#else 
  #define FELIDE_API_EXPORT
  #define FELIDE_API_IMPORT
#endif

#if defined(FELIDE_SHARED)
  #if defined(FELIDE_BUILD)
    #define FELIDE_API FELIDE_API_EXPORT
  #else
    #define FELIDE_API FELIDE_API_IMPORT
  #endif
#else 
  #define FELIDE_API 
#endif

namespace felide { namespace core {

}}

#endif 
