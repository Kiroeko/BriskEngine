#ifndef _SINGLETON_H_
#define _SINGLETON_H_
namespace CppToolBox {

template <typename T>
class Singleton
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