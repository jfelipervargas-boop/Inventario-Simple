cmake_minimum_required(VERSION 3.16)

project(Inventario_Simple VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql Gui)

qt_add_executable(Proyecto_Final
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    Component.h

    DatabaseManager.h
    DatabaseManager.cpp

    InventoryManager.h
    InventoryManager.cpp

    addcomponentwindow.h
    addcomponentwindow.cpp
    addcomponentwindow.ui

    editcomponentwindow.h
    editcomponentwindow.cpp
    editcomponentwindow.ui

    confirmdeletedialog.h
    confirmdeletedialog.cpp
    confirmdeletedialog.ui
)

target_link_libraries(Proyecto_Final
    PRIVATE Qt6::Widgets
    PRIVATE Qt6::Sql
    PRIVATE Qt6::Gui
)

set_target_properties(Proyecto_Final PROPERTIES
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Proyecto_Final
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(Proyecto_Final)
