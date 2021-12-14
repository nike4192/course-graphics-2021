
#define _USE_MATH_DEFINES

#include <math.h>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Shader.h"
#include "PerspectiveCamera.h"

#include "geometries/BoxGeometry.h"
#include "geometries/ConeGeometry.h"
#include "geometries/SphereGeometry.h"
#include "geometries/CylinderGeometry.h"
#include "geometries/TorusGeometry.h"
#include "geometries/TorusKnotGeometry.h"

#include "geometries/OctahedronGeometry.h"
#include "geometries/TetrahedronGeometry.h"
#include "geometries/DodecahedronGeometry.h"
#include "geometries/IcosahedronGeometry.h"

#include "geometries/ConicalSpiralGeometry.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);


// settings
unsigned int SCR_WIDTH = 600;
unsigned int SCR_HEIGHT = 600;

int DRAW_MODE = 0;
bool WIREFRAME_MODE = false;

PerspectiveCamera camera(50, SCR_WIDTH / SCR_HEIGHT, 0.1, 2000.0);

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthMask(GL_TRUE);


    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    // TorusKnotGeometry geometry = TorusKnotGeometry(1, 0.1, 200, 40, 5, 3);
    SphereGeometry geometry = SphereGeometry(1, 128, 64, 0, 2 * M_PI, 0, M_PI);
    // ConeGeometry geometry = ConeGeometry(1, 2, 40, 3, false, 0, 2 * M_PI);
    // CylinderGeometry geometry = CylinderGeometry(0.5, 0.8, 1, 50, 10, false, 0, 2 * M_PI);
    // TorusGeometry geometry = TorusGeometry(1, 0.4, 50, 20, 2 * M_PI);
    // TetrahedronGeometry geometry = TetrahedronGeometry(1, 0);
    // OctahedronGeometry geometry = OctahedronGeometry(1, 0);
    // DodecahedronGeometry geometry = DodecahedronGeometry(1, 0);
    // IcosahedronGeometry geometry = IcosahedronGeometry(1, 0);
    // ConicalSpiralGeometry geometry = ConicalSpiralGeometry(1, 0.3, 2, 100, 20, 3);
    // BoxGeometry geometry = BoxGeometry(1, 1, 1, 20, 20, 20);
    geometry.computeFaceNormals();

    std::vector<glm::vec3> vertices = geometry.vertices;
    std::vector<glm::vec3> normals = geometry.normals;
    std::vector<int> indices = geometry.indices;

    int buffer_size = 8 * indices.size();
    float buffer [buffer_size];
    geometry.fillBuffer(buffer);

    // float normal_size = 0.1;
    // int normals_buffer_size = 2 * 3 * indices.size();
    // float normals_buffer [normals_buffer_size];

    // for (int i = 0; i < indices.size(); i++)
    // {
    //     int index = indices[i];

    //     glm::vec3 vertex = vertices[index];
    //     glm::vec3 normal = normals[i];

    //     normals_buffer[6 * i] = vertex.x;
    //     normals_buffer[6 * i + 1] = vertex.y;
    //     normals_buffer[6 * i + 2] = vertex.z;

    //     normals_buffer[6 * i + 3] = vertex.x + normal.x * normal_size;
    //     normals_buffer[6 * i + 4] = vertex.y + normal.y * normal_size;
    //     normals_buffer[6 * i + 5] = vertex.z + normal.z * normal_size;
    // }

    unsigned int VAO, VBO;

    // Set VAO before VBO and optionaly EBO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), buffer, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.


    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Shader ourShader("src/shaders/main.vs", "src/shaders/main.fs");
    Shader normalShader("src/shaders/normals.vs", "src/shaders/normals.fs");

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("src/images/2k_earth_daymap.jpg", &width, &height, &nrChannels, 0); 

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);    

	// glm::mat4 trans = glm::mat4(1.0f);
    camera.position.z = -5;

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.use();

        if (WIREFRAME_MODE)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        else
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

		// trans = glm::rotate(trans, glm::radians(1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 Projection = camera.getProjectionMatrix();
        glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.0f), camera.position);
        glm::mat4 ViewRotateX = glm::rotate(ViewTranslate, camera.rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 ViewRotateY = glm::rotate(ViewRotateX, camera.rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 View = glm::rotate(ViewRotateY, camera.rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 Model = glm::scale(glm::mat4(1.0f), camera.scale);

        glm::mat4 MVP = Projection * View * Model;

        ourShader.setMatrix4("transform", MVP);

        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, indices.size());
        // glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time 
 

        // normalShader.use();
        // normalShader.setMatrix4("u_world", MVP);
        // glBindVertexArray(VAO2);
        // glDrawArrays(GL_LINES, 0, 2 * indices.size());

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(ourShader.ID);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

bool SPACE_PRESSED = false;
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float step = 0.01;
    
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        step = 0.1;

    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        step = 1;

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        SPACE_PRESSED = true;

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
    {
        if (SPACE_PRESSED)
        {
            WIREFRAME_MODE = !WIREFRAME_MODE;
            SPACE_PRESSED = false;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.position.z += step;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.position.z -= step;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.position.x += step;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.position.x -= step;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        camera.position.y += step;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        camera.position.y -= step;

    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) DRAW_MODE = 0;
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) DRAW_MODE = 1;
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) DRAW_MODE = 2;
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) DRAW_MODE = 3;
}



// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
    camera.setAspect((float)width / height);
    camera.updateProjectionMatrix();
}

glm::vec2 lastMousePos;
bool firstMouseDown = true;

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    float sensetive = 0.01;
    int mouseLeftButtonState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

    if (mouseLeftButtonState == GLFW_PRESS) {
        if (firstMouseDown)
        {
            lastMousePos = glm::vec2(xpos, ypos);
            firstMouseDown = false;
        }
        else
        {
            glm::vec2 currentMousePos = glm::vec2(xpos, ypos);
            glm::vec2 movementVector = currentMousePos - lastMousePos;

            camera.rotation.x += movementVector.y * sensetive;
            camera.rotation.y += movementVector.x * sensetive;

            lastMousePos = currentMousePos;
        }
    }
    else if(mouseLeftButtonState == GLFW_RELEASE)
    {
        firstMouseDown = true;
    }
    // std::cout << "pos x=" << xpos << " y=" << ypos << std::endl;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.setFov(camera.getFov() - (float)yoffset);
    camera.updateProjectionMatrix();
    std::cout << "fov: " << camera.getFov() << std::endl;
}
