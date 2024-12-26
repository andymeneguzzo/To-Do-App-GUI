cmake_minimum_required(VERSION 3.14)

project(ToDoListApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova Qt
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Includi le directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Aggiungi le sottocartelle se necessario
# add_subdirectory(gui)

# Definisci le fonti
set(SOURCES
    main.cpp
    Task.cpp
    ToDoList.cpp
    gui/MainWindow.cpp
)

set(HEADERS
    Task.h
    ToDoList.h
    gui/MainWindow.h
)

set(UI
    gui/MainWindow.ui
)

# Genera i file UI
qt6_wrap_ui(UI_HEADERS ${UI})

# Aggiungi l'eseguibile
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
)

# Collega le librerie di Qt
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)