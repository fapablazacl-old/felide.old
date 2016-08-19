
#pragma once

#ifndef __felide_collection_hpp__
#define __felide_collection_hpp__

namespace felide {
    /**
     * @brief Set-like container polymorphic container.
     *
     * Because we want a streamlined internal interface - based design, it is needed this kind of templated, polymorphic class for a set - like container.
     * Many interfaces has the concecpt of object container as a attribute (workspaces contains projects, and projects constains items, for example), so 
     * trough the use of this interface we can simplify the other interfaces a lot.
     *
     */
    template<typename Type>
    class Collection {
    public:
        virtual ~Collection() {}
        
        /**
         * @brief Get the amount of elements.
         */
        virtual std::size_t getCount() const = 0;
        
        /**
         * @brief Get corresponding item at the index
         */
        virtual const Type* getItem(const int index) const = 0;
        
        virtual Type* getItem(const int index) = 0;
        
        virtual void append(Type item) = 0;
        
        virtual std::unique_ptr<Type> remove(const int index) = 0;
    };
}

#endif 
