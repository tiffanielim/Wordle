cmake_minimum_required(VERSION 3.26)
project(Wordle)

set(CMAKE_CXX_STANDARD 17)

add_executable(Wordle main.cpp
        Button.cpp
        Game.cpp
        GuessGrid.cpp
        HistogramBar.cpp
        HorizontalHistogram.cpp
        KeyboardWnd.cpp
        PlayHistory.cpp
        PostGameWnd.cpp
        PuzzleLetter.cpp
        PuzzleWnd.cpp
        SFMLGame.cpp
        WordDatabase.cpp)

target_link_libraries(Wordle sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
