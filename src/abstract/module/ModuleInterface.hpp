/**
 * @Author: Jakub Wysocki
 * @Project: Strategy Game Engine
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#pragma once

namespace module
{
    struct ModuleInterface
    {
        virtual void start() = 0;
        virtual void pause() = 0;
    };
}    // namespace module
