
#ifndef TUTER_TEST_AREA_HPP
#define TUTER_TEST_AREA_HPP

#include <vector>

namespace tuter
{

class test_area
{
protected:
//    typedef void (*test_fn)();
    typedef void (test_area::*test_fn_t)();

private:
    std::vector<test_fn_t>* _test_ptrs;

public:
    test_area();
    virtual ~test_area();
    virtual void add_test(test_fn_t p);
    virtual void clear_tests();
    virtual void run_tests();
};

}

#endif // TUTER_TEST_AREA_HPP
