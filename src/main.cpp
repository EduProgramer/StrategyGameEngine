/**
 * @Author: Jakub Wysocki
 * @Date:   2017-11-24T20:39:46+01:00
 * @Project: Strategy Game Engine
 * @Last modified by:   Jakub Wysocki
 * @Last modified time: 2017-11-24T21:57:20+01:00
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#include "staticHeader.hpp"
#include <iostream>

int main() try
{
    std::cout << "hello world" << std::endl;
    sayHello();
    std::cout << std::endl;
    return 0;
}
catch ( ... )
{
    /* error */
}
