/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */


#ifndef __FELIDE_TOOLCHAINS_TOOLCHAIN_HPP__
#define __FELIDE_TOOLCHAINS_TOOLCHAIN_HPP__

#include <list>
#include <boost/scoped_ptr.hpp>

#include <felide/toolchains/Compiler.hpp>

namespace felide { namespace toolchains {
	
	typedef std::list<Compiler*> 	CompilerList;
	typedef CompilerList::iterator 	CompilerListIt;
	
	/**
	 * @brief
	 *
	 *
	 */
	class Toolchain {
	public:
		Toolchain();
		virtual ~Toolchain();
		
		std::string getName() const;
		void setName(const std::string &name);
		
	private:
		class Private;
		boost::scoped_ptr<Private> impl;
	};
}}

#endif	//__FELIDE_TOOLCHAINS_TOOLCHAIN_HPP__
