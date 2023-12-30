#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

typedef float         f32;
typedef double        f64;
typedef uint8_t       u8;
typedef int8_t        i8;
typedef uint16_t      u16;
typedef int16_t       i16;
typedef uint32_t      u32;
typedef int32_t       i32;
typedef uint64_t      u64;
typedef int64_t       i64;
typedef unsigned int  uint;

int main() {

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    else
        std::cout << "GLFW Initialized" << std::endl;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Waffle's Simple Graphics Library", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    else
        std::cout << "Window created successfully" << std::endl;

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "GLEW failed to initialize" << std::endl;
    else
        std::cout << "GLEW Initialized" << std::endl;
    
    std::cout << "OpenGL Initialized" << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;

    f32 positions[6] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    uint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(f32), positions, GL_STATIC_DRAW);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
