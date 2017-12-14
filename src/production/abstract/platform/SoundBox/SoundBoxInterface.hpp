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
        // TODO concretion
        struct SoundBoxInterface
        {
            // TODO args
            void playSound();
            // TODO args, rethink
            void playTheme();
        };
    }    // namespace SoundBox
}    // namespace platform
