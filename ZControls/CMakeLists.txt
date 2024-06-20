# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt6_policy(SET QTP0001 NEW)
qt6_add_qml_module(ZControlplugin
    URI "ZControl"
    PLUGIN_TARGET ZControlplugin
    DEPENDENCIES QtQuick
)

target_sources(ZControlplugin PRIVATE
    piechart.cpp piechart.h
    pieslice.cpp pieslice.h
)

target_link_libraries(ZControlplugin PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

if(QT6_IS_SHARED_LIBS_BUILD AND APPLE)
    get_target_property(is_bundle ZControl-plugins MACOSX_BUNDLE)
    if(is_bundle)
        # The application's main.cpp adds an explicit QML import path to look for qml modules under
        # a PlugIns subdirectory in a macOS bundle.
        # Copy the qmldir and shared library qml plugin.

        set(ZControl_dir "$<TARGET_FILE_DIR:ZControlplugin>")
        set(chars_qmldir_file "${ZControl_dir}/qmldir")
        set(app_dir "$<TARGET_FILE_DIR:ZControl-plugins>")
        set(bundle_ZControl_dir "${app_dir}/../PlugIns/ZControl")

        add_custom_command(TARGET ZControlplugin POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory ${bundle_ZControl_dir}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:ZControlplugin> ${bundle_ZControl_dir}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${chars_qmldir_file} ${bundle_ZControl_dir}
            VERBATIM
        )
    endif()
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLEDIR}/ZControl")
install(TARGETS ZControlplugin
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/qmldir
    DESTINATION "${INSTALL_EXAMPLEDIR}")

set_target_properties(ZControlplugin PROPERTIES VS_GLOBAL_VcpkgEnabled true)
