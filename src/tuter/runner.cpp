
#include "tuter/runner.hpp"
#include "tuter/expose.hpp"

#include <iostream>
#include <windows.h>

tuter::runner::runner()
{
}

tuter::runner::~runner()
{
}

void
tuter::runner::run_all(const char* so_path)
{
    if(NULL == so_path)
        return;

    std::cout << "opening object: " << so_path << std::endl;

    HMODULE dll = NULL;
    expose_tests_fn expose_tests = NULL;

    dll = LoadLibrary(so_path);
    if(NULL == dll)
    {
        std::cout << "failed to open object " << so_path << std::endl;
        return ;
    }

    expose_tests = (expose_tests_fn) GetProcAddress(dll, TUTER_EXPOSE_FN_QUOTES);
    if(NULL == expose_tests)
    {
        std::cout << "failed to load " << TUTER_EXPOSE_FN_QUOTES << " function" << std::endl;
        return;
    }

    std::vector<tuter::test*> vec = expose_tests ();
    std::cout << "found " << vec.size() << " tests, now running..." << std::endl;

    std::vector<tuter::test*>::iterator it = vec.begin();
    for(;it!=vec.end();it++)
    {
        tuter::test* t = *it;
        t->run_tests();
        delete t;
    }

    //don't forget to free the library

    FreeLibrary(dll);
}
