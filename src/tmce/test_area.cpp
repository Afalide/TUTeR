
#include "tuter/test_area.hpp"

tuter::test_area::test_area()
{
    _test_ptrs = new std::vector<test_fn_t>();
}

tuter::test_area::~test_area()
{
    delete _test_ptrs;
}

void
tuter::test_area::add_test(test_fn_t p)
{
    _test_ptrs->push_back(p);
}

void
tuter::test_area::clear_tests()
{
    _test_ptrs->clear();
}

void
tuter::test_area::run_tests()
{
    std::vector<test_fn_t>::iterator it = _test_ptrs->begin();
    for(; it!=_test_ptrs->end(); it++)
    {
        test_fn_t fn = *it;
        (this->*fn)();
    }
}
