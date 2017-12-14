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
        // TODO concretion
        struct DrawManagerInterface
        {
            using DrawableVector =
                std::vector< std::unique_ptr< DrawableInterface > >;
            virtual void DrawVector( DrawableVector vec ) = 0;
        };
    }    // namespace DrawManager
}    // namespace platform
