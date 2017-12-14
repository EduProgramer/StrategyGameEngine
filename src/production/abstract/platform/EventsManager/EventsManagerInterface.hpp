/**
 * @Author: Jakub Wysocki
 * @Project: Strategy Game Engine
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#pragma once

namespace platform
{
    namespace EventsManager
    {
        // TODO concretion
        struct EventsManagerInterface
        {
            virtual void poll() = 0;

            // TODO args observer, Event, function ptr?
            virtual void addObserver() = 0;
        };
    }    // namespace EventsManager
}    // namespace platform
