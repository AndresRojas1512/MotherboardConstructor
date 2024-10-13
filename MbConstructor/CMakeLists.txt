cmake_minimum_required(VERSION 3.5)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

project(MbConstructor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui)

# Enable AUTOMOC, AUTOUIC, and AUTORCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add source files
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mathelements.cpp
)

# Add header files
set(PROJECT_HEADERS
    mainwindow.h
    mathelements.hpp
    addmotherboard.hpp
)

# Add UI files
set(PROJECT_UIS
    mainwindow.ui
    addmotherboard.ui
)

# Define target executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MbConstructor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_UIS}
        addmotherboard.ui
        addmotherboard.hpp
        facade.hpp
        components.hpp

    )
else()
    add_executable(MbConstructor
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_UIS}
    )
endif()

# Link libraries
target_link_libraries(MbConstructor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)

# Deployment/installation rules, analogous to qmake's INSTALLS
if(UNIX AND NOT ANDROID)
    set_target_properties(MbConstructor PROPERTIES
        INSTALL_RPATH_USE_LINK_PATH TRUE
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "/opt/$${TARGET}/bin"
    )
    install(TARGETS MbConstructor RUNTIME DESTINATION "/opt/$${TARGET}/bin")
endif()

# Finalization code for Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MbConstructor)
endif()
