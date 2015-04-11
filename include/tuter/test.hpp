
#ifndef TUTER_TEST_HPP
#define TUTER_TEST_HPP

namespace tuter
{

class test
{
public:
    test();
    virtual ~test();
    virtual void run_tests()=0;
};

}

#endif // TUTER_TEST_HPP

