/**
 * @Author: Jakub Wysocki
 * @Date:   2017-11-24T20:39:46+01:00
 * @Project: Strategy Game Engine
 * @Last modified by:   jakub
 * @Last modified time: 2017-12-03T19:55:12+01:00
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#include "gtest/gtest.h"

namespace tests
{
    int main( int argc, char** argv )
    {
        ::testing::InitGoogleTest( &argc, argv );
        return RUN_ALL_TESTS();
    }
}    // namespace tests
