/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_PROJECTITEM_HPP__
#define __FELIDE_PROJECTITEM_HPP__

#include <string>
#include <boost/scoped_ptr.hpp>

namespace felide { namespace projects {
	class ProjectItem {
	public:
		ProjectItem(const std::string &file);
		~ProjectItem();
		
		std::string getFile() const;
		void setFile(const std::string &file);
		
        bool hasValidFile() const;
        
	private:
		class Private;
		boost::scoped_ptr<Private> impl;
	};
}}

#endif	//__FELIDE_PROJECTITEM_HPP__
