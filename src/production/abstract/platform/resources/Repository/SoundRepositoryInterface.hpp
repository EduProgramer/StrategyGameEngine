/**
 * @Author: Jakub Wysocki
 * @Project: Strategy Game Engine
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#pragma once

#include "Sound.hpp"

namespace platform
{
    namespace resources
    {
        namespace Repository
        {
            // TODO concretion
            struct SoundRepositoryInterface
            {
                virtual Sound getSoundById( int id ) = 0;
                virtual Sound getSoundByName( std::string name ) = 0;
            };
        }    // namespace Repository
    }        // namespace resources
}    // namespace platform
