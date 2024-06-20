cmake_minimum_required(VERSION 3.27)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

project(zControl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON) 

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX "d")

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Gui Qml)

qt_standard_project_setup(REQUIRES 6.5)

include_directories(ZControls inc inc/os)

qt6_add_resources(Z_RESOURCES_TARGET demo.qrc)

add_subdirectory(widgetQML)
add_subdirectory(ZControls)
add_subdirectory(demo2)

set(QML_IMPORT_NAME "ZControl")
set(QML_IMPORT_VERSION 1.0)

aux_source_directory(./ A)


qt_add_executable(appzControl
    ${A}
    ${Z_RESOURCES_TARGET}
)

qt_add_qml_module(appzControl
    URI zControl
    VERSION 1.0
    RESOURCES demo.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appzControl PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appzControl
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appzControl
    PRIVATE Qt6::Quick
)

target_link_libraries(appzControl  PRIVATE Qt6::Gui PRIVATE Qt6::Qml PRIVATE Qt6::Quick)

include(GNUInstallDirs)
# install(TARGETS appzControl
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# install(TARGETS ZControls
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

set_target_properties(appzControl PROPERTIES VS_GLOBAL_VcpkgEnabled true)

