cmake_minimum_required(VERSION 3.21)
project(DragonGame)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/SDL2/include)
set(SDL2_LIB_DIR C:/SDL2/lib/x64)

set(SDL2_INCLUDE_DIR1 C:/SDL2_ttf/include)
set(SDL2_LIB_DIR2 C:/SDL2_ttf/lib/x64)

set(SDL2_INCLUDE_DIR3 C:/SDL2_image/include)
set(SDL2_LIB_DIR4 C:/SDL2_image/lib/x64)

include_directories(${SDL2_INCLUDE_DIR1})
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR3})
link_directories(${SDL2_LIB_DIR2})
link_directories(${SDL2_LIB_DIR})
link_directories(${SDL2_LIB_DIR4})

add_executable(DragonGame main.cpp Game.cpp Game.h TextureManager.cpp TextureManager.h GameObject.h Player.cpp Player.h Buildings.cpp Buildings.h LoaderParams.h SDLGameObject.cpp SDLGameObject.h Vector2D.h InputHandler.cpp InputHandler.h GameState.h MenuState.cpp MenuState.h PlayState.cpp PlayState.h GameStateMachine.cpp GameStateMachine.h MenuButton.cpp MenuButton.h PauseState.cpp PauseState.h FontManager.cpp FontManager.h Timer.cpp Timer.h GameOverState.cpp GameOverState.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2test SDL2_ttf SDL2_image)