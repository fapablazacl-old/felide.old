
#ifndef __felide_pom_projecttype__
#define __felide_pom_projecttype__

namespace felide { namespace pom {
    struct ProjectType {
        enum Enum {
            WindowsExecutable,
            ConsoleExecutable,
            StaticLibrary,
            DynamicLibrary
        };
    };
}}

#endif
