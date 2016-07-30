
#ifndef __felide_pom_language__
#define __felide_pom_language__

namespace felide { namespace pom {
    struct Item;
    class Language {
    public:
        bool isItemCompilable(const Item *item) const;
    };
}}

#endif
