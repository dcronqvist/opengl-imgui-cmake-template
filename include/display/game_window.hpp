#include "display/base_window.hpp"

class GameWindow : public BaseWindow {
    public:
    GameWindow(int width, int height, std::string title) : BaseWindow(width, height, title) {};
    void Initialize();
    void LoadContent();
    void Update();
    void Render();
    void Unload();
};