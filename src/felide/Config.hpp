/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014-2015 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __felide_config_hpp__
#define __felide_config_hpp__

#if defined (FELIDE_BUILD)
#  define FELIDE_API __declspec(dllexport)
#else 
#  define FELIDE_API __declspec(dllimport)
#endif

#endif	// __felide_config_hpp__
