
#include <felide/core/PreDef.hpp>

namespace felide { namespace core {
    class FELIDE_CORE_API RefCounted {
    public:
        RefCounted();

        virtual ~RefCounted();

        void addRef();

        void release();

    private:
        int m_refCount = 0;
    };
}}
