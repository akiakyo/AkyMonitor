cmake_minimum_required(VERSION 3.20)

project(AkyMonitor)


set(
    CMAKE_CXX_STANDARD 23
)


find_package(
    Qt6 REQUIRED COMPONENTS Widgets
)


qt_standard_project_setup()



add_executable(
    AkyMonitor

    src/main.cpp
    src/MainWindow.cpp
    src/CpuMonitor.cpp
    src/MemoryMonitor.cpp
)


target_include_directories(
    AkyMonitor
    PRIVATE
    include
)


target_link_libraries(
    AkyMonitor
    PRIVATE
    Qt6::Widgets
)