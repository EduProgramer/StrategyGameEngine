/**
 * @Author: Jakub Wysocki
 * @Project: Strategy Game Engine
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#pragma once

#include <string>

namespace platform
{
    namespace resources
    {
        namespace Repository
        {
            // TODO concretion
            struct TextRepositoryInterface
            {
                virtual std::string getTextById( int id ) = 0;
                virtual std::string getTextByName( std::string name ) = 0;
            };
        }    // namespace Repository
    }        // namespace resources
}    // namespace platform
