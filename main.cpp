
//#include <iostream>
//
//class A
//{
//private:
//    float _val;
//
//public:
//
//    typedef int (A::*memberfn) (float);
//
//    A(float);
//    ~A();
//    int say_hello(float);
//    void do_stuff();
//};
//
//A::A(float f)
//{
//    _val = f;
//}
//
//A::~A()
//{
//}
//
//void A::do_stuff()
//{
//    memberfn fn = &A::say_hello;
//    (this->*fn)(_val);
//}
//
//int A::say_hello(float f)
//{
//    std::cout << "hello " << f << std::endl;
//    return 2;
//}
//
//int main()
//{
//    A a1(1.23);
//    a1.do_stuff();
//
//    A a2(4.56);
//    a2.do_stuff();
//
//    return 0;
//}

/////////////////////////////


#include <iostream>
#include "tuter/macros.hpp"

class my_test: public tuter::test_area
{
public:
    my_test();
    void some_test();
    void some_other_test();
};

my_test::my_test()
{
//    test_fn fn = &some_test;
//    add_test(this->some_test);
//    test_fn_t fn = &tuter::test_area::clear_tests;
     test_fn_t fn = &my_test::some_test;
}

void
my_test::some_test()
{
    std::cout << "some test" << std::endl;
}

void
my_test::some_other_test()
{
    std::cout << "some other test" << std::endl;
}

namespace myns
{
    class B: public tuter::test_area{};
}

TUTER_DECLARE_TESTS_BEGIN

    TUTER_DECLARE(my_test)

TUTER_DECLARE_TESTS_END

int main()
{
    std::vector<tuter::test_area*> vec = TUTER_DECLARE_FN_NAME ();
    return 0;
}
