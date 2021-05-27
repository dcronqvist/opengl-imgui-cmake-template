#include "display/game_window.hpp"

int main() {
    // Create the game window with the specified size and title
    GameWindow gw = GameWindow{ 800, 600, "opengl-imgui-cmake-template by @dcronqvist" };
    return gw.Run();
}