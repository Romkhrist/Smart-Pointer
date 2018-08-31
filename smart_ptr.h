#include <iostream>
#include <cstddef>  //size_t

template<typename T>
class smart_ptr
{
    std::size_t *counter;
    T           *ptr;
public:
    smart_ptr()
        :counter(new std::size_t(1)), ptr(nullptr) {}
    
    explicit smart_ptr(T *ptr)
        :counter(new std::size_t(1)), ptr(ptr) {}
    
    smart_ptr(smart_ptr& ptr);
    
    smart_ptr& operator=(smart_ptr& ptr);
    T&         operator*() const;
    
    ~smart_ptr();
    
    //deleted members
    smart_ptr(smart_ptr&& ptr) = delete;
    smart_ptr& operator=(smart_ptr&& ptr) = delete;
};

template<typename T>
smart_ptr<T>::smart_ptr(smart_ptr<T>& ptr)
    :counter(new std::size_t(1))
{
    this->ptr = ptr.ptr;
    
    if(*counter == 1)
    {
        delete counter;
    }
    
    ++*ptr.counter;
    counter = ptr.counter;
}

template<typename T>
smart_ptr<T>& smart_ptr<T>::operator=(smart_ptr<T>& ptr)
{
    this->ptr = ptr.ptr;
    
    if(*counter == 1)
    {
        delete counter;
    }
    
    ++*ptr.counter;
    counter = ptr.counter;
    
    return *this;
}

template<typename T>
inline T& smart_ptr<T>::operator*() const
{
    return *ptr;
}

template<typename T>
smart_ptr<T>::~smart_ptr()
{
    //debug cout to check value of the counter
    std::cout << "counter: " << *counter << std::endl;
    
    --*counter;
    
    if(*counter == 0)
    {
        delete ptr;
        delete counter;
        
        ptr     = nullptr;
        counter = nullptr;
    }
    
    std::cout << ((ptr) ? "not null" : "null") << std::endl;
}
