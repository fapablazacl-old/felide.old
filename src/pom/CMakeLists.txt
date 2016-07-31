
set (target pom)

set (sources 
	pom.hpp pom.cpp
	Builder.hpp Builder.cpp 
	BuilderGCC.hpp BuilderGCC.cpp 
	BuilderVC.hpp BuilderVC.cpp 

	Item.hpp Item.cpp 
	Language.hpp Language.cpp 
	Project.hpp Project.cpp 
	ProjectType.hpp ProjectType.cpp 
	Workspace.hpp Workspace.cpp 
)

add_executable (${target} ${sources})

target_link_libraries (${target} ${Boost_LIBRARIES})
