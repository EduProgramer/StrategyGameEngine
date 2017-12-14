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
        // TODO concretion
        struct DrawableInterface
        {
            virtual void draw() = 0;
        };
    }    // namespace DrawManager

}    // namespace platform
