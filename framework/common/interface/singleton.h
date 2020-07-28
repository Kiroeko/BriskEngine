#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include "common/interface/interface.h"
namespace BriskEngine {

template <typename T>
Interface Singleton
{
public:
    ~Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static T& getInstance() {
        static T instance;
        return instance;
    }
protected:
    Singleton() {}
};

}
#endif