
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

# qt_add_qml_module(zControls
#     URI zControls
#     QML_FILES app.qml
#     NO_RESOURCE_TARGET_PATH
# )

