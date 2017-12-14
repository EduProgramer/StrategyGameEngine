/**
 * @Author: Jakub Wysocki
 * @Project: Strategy Game Engine
 * @License: MIT License
 * @Copyright: Copyright (c) 2017
 */

#pragma once

#include "Texture.h"

namespace platform
{
    namespace resources
    {
        namespace Repository
        {
            // TODO concretion
            struct TextureRepositoryInterface
            {
                virtual Texture getTextureById( int id ) = 0;
                virtual Texture getTextureByName( std::string name ) = 0;
            };
        }    // namespace Repository
    }        // namespace resources
}    // namespace platform
