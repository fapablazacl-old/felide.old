
/*
 * Felipe's Integrated Development Environment.
 *
 * Copyright (c) 2014 Felipe Apablaza.
 *
 * This file and its source code is licensed under the GPLv3 license.
 * For details, see the LICENSE file included in this software distribution.
 */

#ifndef __FELIDE_PROJECTS_WORKSPACEMANAGER_HPP__
#define __FELIDE_PROJECTS_WORKSPACEMANAGER_HPP__

#include <felide/projects/Project.hpp>
#include <felide/projects/Workspace.hpp>

/*
 * This class is used to be as a abtraction over the managment of the workspaces and projects.
 * 
 * For now, I recognice two different management options:
 *  
 *  - Management inside the IDE (like Visual Studio does).
 *  - CMake - based management.
 *
 * 
 */
namespace felide { namespace projects {
    /**
     * @brief Abstract workspace manager.
     */
    class WorkspaceManager  {
    public:
        WorkspaceManager();
        virtual ~WorkspaceManager() = 0;
        
    };
}}

#endif  // __FELIDE_PROJECTS_WORKSPACEMANAGER_HPP__
