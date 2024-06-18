# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(zControls LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "ZControls")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/qml/zControls")

find_package(Qt6 REQUIRED COMPONENTS Qml Quick)

qt_add_executable(zControls
    main.cpp
)

set_target_properties(zControls PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(zControls PRIVATE
    Qt6::Qml
    Qt6::Quick
)

qt_add_qml_module(zControls
    URI ChartsApp
    QML_FILES app.qml
    NO_RESOURCE_TARGET_PATH
)

install(TARGETS zControls
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

add_subdirectory(ZControls)
