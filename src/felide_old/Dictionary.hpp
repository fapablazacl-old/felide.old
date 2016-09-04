
#pragma once

#ifndef __felide_dictionary_hpp__
#define __felide_dictionary_hpp__

#include <memory>

namespace felide {
    
    /**
     * @brief Map-like container for interface simplification, where the Key corresponds to the identity of the stored objects.
     */
    template<typename Key, typename Type>
    class Dictionary {
    public:
        virtual ~Dictionary() {}
        
        virtual std::size_t getCount() const = 0;
        
        virtual Key getKey(const int index) = 0;
        
        virtual const Type* getItem(const Key &key) const = 0;
        
        virtual Type* getItem(const Key &key) = 0;
        
        virtual void append(const Key &key, std::unique_ptr<Type> item) = 0;
        
        virtual std::unique_ptr<Type> remove(const Key &key) = 0;
    };
}

#endif 
