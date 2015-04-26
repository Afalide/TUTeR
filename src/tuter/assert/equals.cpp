
#include <cstring>
#include "tuter/assert/equals.hpp"

namespace tuter
{

template <> bool equals <const char*> (const char* value
                                      ,const char* should_be)
{
    if(0 != strcmp(value, should_be))
        return false;

    return true;
}

} //namespace tuter
