#!/bin/bash

# @Author: Jakub Wysocki
# @Date:   2017-11-24T20:09:47+01:00
# @Project: Strategy Game Engine
# @Last modified by:   Jakub Wysocki
# @Last modified time: 2017-11-24T21:35:01+01:00
# @License: MIT License
# @Copyright: Copyright (c) 2017

rm SGE/SGE
cmake . -G Ninja
ninja
