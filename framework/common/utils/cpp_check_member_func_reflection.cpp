#include <string>
#include <type_traits>
using namespace std;

#define GEN_MEMBER_FUNC_CHECK_CLASS(func_return_type, func_name, ...) \
    struct HasMemberFuncInspector_##func_return_type##_##func_name { \
        template < \
            typename T, \
            typename U = typename std::decay_t<decltype(std::declval<T>().func_name(__VA_ARGS__))>, \
            typename = typename std::enable_if_t<std::is_same_v<func_return_type, U>> \
        > \
        static std::true_type Check(int); \
        template <typename> \
        static std::false_type Check(...); \
    }; \
    template <typename T> \
    struct HasMember_##func_return_type##_##func_name : public decltype(HasMemberFuncInspector_##func_return_type##_##func_name::Check<T>(0)){};

//test case
struct A {
    std::string print() { return "A"; }
};

struct B {
    std::string print(bool a, int b) { return "B"; }
};

struct C {
    bool print(bool a, int b) { return true; }
};

struct D {};

GEN_MEMBER_FUNC_CHECK_CLASS(string, print, false, 0)

int main() {
    HasMember_string_print<A> a;
    a.value;                   //false
    HasMember_string_print<B> b;
    b.value;                   //true
    HasMember_string_print<C> c;
    c.value;                   //false
    HasMember_string_print<D> d;
    d.value;                   //false

    return 0;
}