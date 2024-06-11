cmake_minimum_required(VERSION 3.27)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

project(zControl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt6_add_resources(Z_RESOURCES_TARGET demo.qrc)

qt_add_executable(appzControl
    main.cpp
    ZButtonMdelInfo.cpp
    ZButtonMdelInfo.h
    ${Z_RESOURCES_TARGET}
)

qt_add_qml_module(appzControl
    URI zControl
    VERSION 1.0
    QML_FILES Main.qml
    QML_FILES ZButton.qml
    QML_FILES ZRowButton.qml
    QML_FILES ZColumnButton.qml
    RESOURCES demo.qrc
    SOURCES   ZTwoDimension.h ZTwoDimension.cpp
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

include(GNUInstallDirs)
install(TARGETS appzControl
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set_target_properties(appzControl PROPERTIES VS_GLOBAL_VcpkgEnabled true)
