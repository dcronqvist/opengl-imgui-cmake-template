#include "display/base_window.hpp"
#include <iostream>

BaseWindow::BaseWindow() {

}

BaseWindow::BaseWindow(int width, int height, std::string title) {
    this->windowWidth = width;
    this->windowHeight = height;
    this->windowTitle = title;
}

int BaseWindow::Run() {
    // Iniialize GLFW
    glfwInit();

    // Run initialisation logic
    Initialize();

    // Create GLFW Window
    windowHandle = glfwCreateWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str(), NULL, NULL);
    if (windowHandle == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set opengl context
    glfwMakeContextCurrent(windowHandle);

    // Attempt to load using glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    std::cout << "INFO::WINDOW::SUCCESSFULLY_INITIALIZED" << std::endl;

    // Runs load content which might include stuff that requires an opengl context
    LoadContent();

    // Main game loop
    while (!glfwWindowShouldClose(windowHandle)) {
        Update();
        Render();
    }

    // Unload and destroy 
    Unload();
    glfwDestroyWindow(windowHandle);
    glfwTerminate();
    return 0;
}