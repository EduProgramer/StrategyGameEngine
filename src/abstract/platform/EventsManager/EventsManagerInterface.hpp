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
        struct EventsManagerInterface    // TODO concretion
        {
            void poll();
            void addObserver();    // TODO args observer, Event, function ptr?
        };
    }    // namespace EventsManager
}    // namespace platform
