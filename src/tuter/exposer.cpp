
#include <iostream>
#include "tuter/exposer.hpp"

tuter::exposer*
tuter::exposer::_instance = NULL;

tuter::exposer::exposer()
{

}

tuter::exposer::~exposer()
{
    delete exposer::_instance;
    exposer::_instance = NULL;
}

tuter::exposer*
tuter::exposer::get_instance()
{
    if(NULL == _instance)
        _instance = new exposer;

    return _instance;
}
