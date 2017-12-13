/**
 * @Author: Jakub Wysocki
 * @Project: Strategy Game Engine
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#pragma once

#include "DrawableInterface.hpp"
#include <memory>
#include <vector>

namespace platform
{
    namespace DrawManager
    {
        struct DrawManagerInterface    // TODO concretion
        {
            using DrawableVector =
                std::vector< std::unique_ptr< DrawableInterface > >;
            void DrawVector( DrawableVector vec );
        };
    }    // namespace DrawManager
}    // namespace platform
