#pragma once

#include "glad.h"
#include "glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <string>

class BaseWindow {
    public:
    int windowWidth, windowHeight;
    std::string windowTitle;
    GLFWwindow* windowHandle;

    public:
    BaseWindow();
    BaseWindow(int width, int height, std::string title);
    int Run();

    protected:
    virtual void Initialize() = 0;
    virtual void LoadContent() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Unload() = 0;
};