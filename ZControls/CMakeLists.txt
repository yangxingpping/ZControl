
project(zControls LANGUAGES CXX)


find_package(Qt6 REQUIRED COMPONENTS Qml Quick)

# set_target_properties(zControls PROPERTIES
#     WIN32_EXECUTABLE TRUE
#     MACOSX_BUNDLE TRUE
# )




aux_source_directory(. A)
qt_add_library(zControls SHARED ${A})

target_link_libraries(zControls PRIVATE
    Qt6::Qml
    Qt6::Quick
)

include(GenerateExportHeader)
generate_export_header(zControls EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/../inc/os/${CMAKE_SYSTEM_NAME}/export_flags/${PROJECT_NAME}Export.h)

# qt_add_qml_module(zControls
#     URI zControls
#     QML_FILES Controls/ZButton.qml
#     NO_RESOURCE_TARGET_PATH
# )

qt_add_qml_module(${PROJECT_NAME}
            PLUGIN_TARGET ${PLUGIN_TARGET_NAME}
            OUTPUT_DIRECTORY ${FLUENTUI_QML_PLUGIN_DIRECTORY}
            VERSION 1.0
            URI "zControls"
            #修改qmltypes文件名称。默认fluentuiplugin.qmltypes，使用默认名称有时候import FluentUI 1.0会爆红，所以修改成plugins.qmltypes
            TYPEINFO "plugins.qmltypes"
            SOURCES ${sources_files} ${FLUENTUI_VERSION_RC_PATH}
            QML_FILES ${qml_files}
            RESOURCES ${resource_files}
            RESOURCE_PREFIX "/qt/qml"
    )

