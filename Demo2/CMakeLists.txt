
project(Demo2 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
aux_source_directory(./ A)
qt_add_executable(Demo2
    ${A}
)

qt_add_qml_module(Demo2
    URI zControl
    VERSION 1.0
    RESOURCES app.qrc
)

target_link_libraries(Demo2 PRIVATE Qt6::Gui PRIVATE Qt6::Qml PRIVATE Qt6::Quick)
