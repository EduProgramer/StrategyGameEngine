#!/bin/bash

# @Author: Jakub Wysocki
# @Date:   2017-11-24T20:09:47+01:00
# @Project: Strategy Game Engine
# @Last modified by:   Jakub Wysocki
# @Last modified time: 2017-11-24T21:35:01+01:00
# @License: MIT License
# @Copyright: Copyright (c) 2017

rm SGE/SGE

case "$1" in
        Release)
            cmake . -G Ninja -DCMAKE_BUILD_TYPE=Release
            ;;

        Debug)
            cmake . -G Ninja -DCMAKE_BUILD_TYPE=Debug
            ;;

        Test)
            cmake . -G Ninja -DCMAKE_BUILD_TYPE=Test
            ;;
        *)
            cmake . -G Ninja

esac

ninja
stat --printf="%s" SGE/SGE
