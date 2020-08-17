#include <string>
#include <type_traits>
using namespace std;

//member function reflection
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
    struct HasMemberFunc_##func_return_type##_##func_name : public decltype(HasMemberFuncInspector_##func_return_type##_##func_name::Check<T>(0)){};

//member reflection
#define GEN_MEMBER_CHECK_CLASS(member_type, member_name) \
    struct HasMemberInspector_##member_type##_##member_name { \
        template < \
            typename T, \
            typename U = typename std::decay_t<decltype(T::member_name)>, \
            typename = typename std::enable_if_t<std::is_same_v<member_type, U>> \
        > \
        static std::true_type Check(int); \
        template <typename> \
        static std::false_type Check(...); \
    }; \
    template <typename T> \
    struct HasMember_##member_type##_##member_name : public decltype(HasMemberInspector_##member_type##_##member_name::Check<T>(0)){};



//test case
struct A {
    std::string print(bool b, int i) { return "A"; }
};

struct B {
    int print = 0;
};

GEN_MEMBER_FUNC_CHECK_CLASS(string, print, false, 0)
GEN_MEMBER_CHECK_CLASS(int, print)

int main() {
    HasMemberFunc_string_print<A> a;
    a.value;            //true
    HasMember_int_print<B> b;
    b.value;            //true

    return 0;
}