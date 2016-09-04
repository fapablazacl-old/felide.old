
#pragma once

#ifndef __felide_core_predef_hpp__
#define __felide_core_predef_hpp__

#if defined(_WINDOWS)
  #define FELIDE_CORE_API_EXPORT __declspec(dllexport)
  #define FELIDE_CORE_API_IMPORT __declspec(dllimport)
#else 
  #define FELIDE_CORE_API_EXPORT
  #define FELIDE_CORE_API_IMPORT
#endif

#if defined(FELIDE_CORE_SHARED)
  #if defined(FELIDE_CORE_BUILD)
    #define FELIDE_CORE_API FELIDE_CORE_API_EXPORT
  #else
    #define FELIDE_CORE_API FELIDE_CORE_API_IMPORT
  #endif
#else 
  #define FELIDE_CORE_API 
#endif

namespace felide { namespace core {

}}

#endif 
