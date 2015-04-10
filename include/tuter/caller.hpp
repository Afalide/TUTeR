
#ifndef TUTER_CALLER_HPP
#define TUTER_CALLER_HPP

#include <vector>

namespace tuter
{

template <typename test_class>
class caller
{
public:
    typedef void (test_class::*test_function)();

private:
    std::vector<test_function>* _functions;
    test_class* _tc;

public:
	caller();
	virtual ~caller();
	void add_function(test_function);
	void run_functions();
};

template <typename test_class>
caller<test_class>::caller()
{
	_tc = new test_class;
	_functions = new std::vector<test_function>();
}

template <typename test_class>
caller<test_class>::~caller()
{
	delete _tc;
	delete _functions;
}

template <typename test_class>
void
caller<test_class>::add_function(test_function tf)
{
    _functions->push_back(tf);
}

template <typename test_class>
void
caller<test_class>::run_functions()
{
    typename std::vector<test_function>::iterator it = _functions->begin();
	for(; it!=_functions->end(); it++)
	{
		test_function fn = *it;
		(_tc->*fn)();
	}
}

}



#endif // TUTER_CALLER_HPP
