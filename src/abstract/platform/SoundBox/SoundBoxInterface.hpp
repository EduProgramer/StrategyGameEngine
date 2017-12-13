/**
 * @Author: Jakub Wysocki
 * @Project: Strategy Game Engine
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#pragma once

namespace platform
{
    namespace SoundBox
    {
        struct SoundBoxInterface    // TODO concretion
        {
            void playSound();    // TODO args
            void playTheme();    // TODO args, rethink
        };
    }    // namespace SoundBox
}    // namespace platform
