#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <chrono>

int frameCount = 0;
double fps = 0.0;
std::chrono::time_point<std::chrono::steady_clock> lastTime = std::chrono::steady_clock::now();
auto currentTime = std::chrono::steady_clock::now();
std::chrono::duration<double> elapsedTime = currentTime - lastTime;

void ShowFPS(GLFWwindow* window)
{
    frameCount++;
    currentTime = std::chrono::steady_clock::now();
    elapsedTime = currentTime - lastTime;

    if (elapsedTime.count() >= 0.033) {
        fps = frameCount / elapsedTime.count();
        frameCount = 0;
        lastTime = currentTime;

        std::string title = "OpenGL FPS Example - FPS: " + std::to_string(fps);
        glfwSetWindowTitle(window, title.c_str());
    }
}

// camera
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

std::string shaderpath = std::filesystem::current_path().string() + "\\..\\Include\\";
std::string vspath = shaderpath + "3.3.shader.vs";
std::string fspath = shaderpath + "3.3.shader.fs";

std::string Resourcepath = std::filesystem::current_path().string() + "\\..\\Resource\\";
std::string ContainerImagepath = Resourcepath + "container.jpg";
std::string AwesomefaceImagepath = Resourcepath + "awesomeface.png";
std::string vspath_4_1 = shaderpath + "4.1.shader.vs";
std::string fspath_4_1 = shaderpath + "4.1.shader.fs";

std::string vspath_5_1 = shaderpath + "5.1.shader.vs";
std::string fspath_5_1 = shaderpath + "5.1.shader.fs";

std::string vspath_6_1 = shaderpath + "6.1.shader.vs";
std::string fspath_6_1 = shaderpath + "6.1.shader.fs";

std::string vspath_7_1 = shaderpath + "7.1.shader.vs";
std::string fspath_7_1 = shaderpath + "7.1.shader.fs";


std::string vspath_1_color = shaderpath + "1.colors.vs";
std::string fspath_1_color = shaderpath + "1.colors.fs";

std::string vspath_1_light_cube = shaderpath + "1.light_cube.vs";
std::string fspath_1_light_cube = shaderpath + "1.light_cube.fs";
