/**
 * @Author: Jakub Wysocki
 * @Project: Strategy Game Engine
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#pragma once

namespace platform
{
    namespace DrawManager
    {
        struct DrawableInterface    // TODO concretion
        {
            void draw();
        };
    }    // namespace DrawManager

}    // namespace platform
