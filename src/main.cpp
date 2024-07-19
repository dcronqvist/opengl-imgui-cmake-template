// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main() {
  // Initialize GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For MacOS
#endif

  // Create a GLFWwindow object
  GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  const auto primaryMonitor = glfwGetPrimaryMonitor();
  const auto videoMode = glfwGetVideoMode(primaryMonitor);
  glfwSetWindowPos(window, (videoMode->width - 800) / 2,
                   (videoMode->height - 600) / 2);

  GLFWimage image;
  image.width = 2;
  image.height = 2;
  const auto pixels = new unsigned char[16]{
      0,   0,   0,
      255, // Black
      255, 0,   0,
      255, // Red
      0,   255, 0,
      255, // Green
      0,   0,   255,
      255, // Blue
  };
  image.pixels = pixels;
  glfwSetWindowIcon(window, 1, &image);

  glfwShowWindow(window);

  // Initialize GLAD
  if (!gladLoadGL(glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glfwSwapInterval(2); // Enable vsync

  // Render loop
  while (!glfwWindowShouldClose(window)) {
    // Input
    processInput(window);

    // Rendering commands here
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Set clear color to blue
    glClear(GL_COLOR_BUFFER_BIT);

    // Check and call events and swap the buffers
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  // glfw: terminate, clearing all previously allocated GLFW resources.
  glfwTerminate();
  return 0;
}

// Process all input: query GLFW whether relevant keys are pressed/released this
// frame and react accordingly
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // Make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}
