cmake_minimum_required(VERSION 3.27)
project(2324L_40_s31026_PS)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS FALSE)


include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)
FetchContent_MakeAvailable(SFML)

add_executable(2324L_40_s31026_PS main.cpp
        AllButtonsItems/menuItems.cpp
        AllButtonsItems/menuItems.h
        Controller/mouseController.cpp
        Controller/mouseController.h
        AllButtonsItems/gForPointsItems.cpp
        AllButtonsItems/gForPointsItems.h
        AllButtonsItems/gameItems.cpp
        AllButtonsItems/gameItems.h
        GameHeart/ClassForGame.cpp
        GameHeart/ClassForGame.h
        Controller/keyboardController.cpp
        Controller/keyboardController.h
        GameHeart/MethodsForGame.cpp
        GameHeart/MethodsForGame.h
        AllButtonsItems/fontItems.cpp
        AllButtonsItems/fontItems.h
        AllButtonsItems/arcadeItems.cpp
        AllButtonsItems/arcadeItems.h)

target_link_libraries(2324L_40_s31026_PS fmt)
target_link_libraries(2324L_40_s31026_PS sfml-graphics)
