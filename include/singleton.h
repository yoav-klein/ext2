#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

/*
  Project: singleton.h
  Date: 17.11.19
  
  Singleton is a version of singleton, only that it 
  supports a dynamic loading of shared libraries.
  the trick is to instantiate the desired singleton instances
  i.e.: std::atomic<T*> s_instance's, in a different .cpp file, and 
  make it a shared object, and then to link the application file with this
  shared object, do the same for the explicitly loaded shared object, and then
  you have the symbol shared for the app and for the explicitly loaded shared object.
  
*/

#include <iostream> // std::cout 

#include <mutex>    // std::mutex
#include <atomic>   // std::atomic
#include <memory>   // std::unique


#define InitSingleton(type)\
template<>\
std::atomic<type*> Singleton<type>::s_instance(nullptr);\
template<>\
std::mutex Singleton<type>::s_mutex{};

namespace filesystems
{

template<typename T>
class Singleton
{
public:
    static T* get_instance();

    Singleton() = delete;
    ~Singleton() = delete;

    Singleton(Singleton& other) = delete; 
    Singleton& operator=(Singleton& other) = delete; 

    Singleton(Singleton&& other) = delete; 
    Singleton&& operator=(Singleton&& other) = delete; 

private:
    static std::atomic<T*> s_instance;
    static std::mutex s_mutex;
};


template<typename T>
T* Singleton<T>::get_instance()
{
    static std::unique_ptr<T> destroyer;

    T* temp = s_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);

    if (temp == nullptr) 
    {
        std::lock_guard<std::mutex> lock(s_mutex);
        temp = s_instance.load(std::memory_order_relaxed);/* read current status of s_instance */
        if (temp == nullptr) 
        {
            temp = new T;
           	
            destroyer.reset(temp);
            std::atomic_thread_fence(std::memory_order_release);
            s_instance.store(temp, std::memory_order_relaxed);
        }
    }
	
    return temp;
}

template<typename T>
std::atomic<T*> Singleton<T>::s_instance;

template<typename T>
std::mutex Singleton<T>::s_mutex{};



}//namepsace filesystems


#endif //__SINGLETON_HPP__
