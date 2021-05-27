#include "display/game_window.hpp"
#include "shaders/shader.hpp"
#include <iostream>

Shader s;
unsigned int VAO;
unsigned int VBO;
unsigned int EBO;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void GameWindow::Initialize() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void GameWindow::LoadContent() {
    glfwSetFramebufferSizeCallback(this->windowHandle, framebuffer_size_callback);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(this->windowHandle, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    std::cout << "INFO::IMGUI::SUCCESSFULLY_INITIALIZED" << std::endl;

    s = Shader::LoadShader("../resources/shaders/testing.vs", "../resources/shaders/testing.fs");

    float vertices[] = {
    0.5f,  0.5f, 0.0f,  // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    // Create Vertex Array object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO); // And bind it

    // Create Vertex Buffer object
    glGenBuffers(1, &VBO);
    // And bind it (this also includes it into the VAO)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Fill the VBO with vertex data, simply positions
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // layout = 0 should contain these positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); // Enable that shit

    // Create index buffer
    glGenBuffers(1, &EBO);
    // And bind it (also included in VAO)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // Fill with indices!
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void GameWindow::Update() {
    s.ReloadFromFile();
}

void GameWindow::Render() {
    glBindVertexArray(VAO);
    glUseProgram(s.programID);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // UI
    ImGui::ShowDemoWindow();
    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(this->windowHandle);
    glfwPollEvents();
}

void GameWindow::Unload() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}