
#include <felide/PreDef.hpp>

namespace felide {
    class FELIDE_CORE_API RefCounted {
    public:
        RefCounted();

        virtual ~RefCounted();

        void addRef();

        void release();

    private:
        int m_refCount = 0;
    };
}
