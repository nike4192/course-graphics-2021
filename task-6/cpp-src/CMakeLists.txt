cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(OpenGL VERSION 1.0)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glm)
add_subdirectory(lib/glad)
add_subdirectory(lib/glfw-3.3.4)
include_directories(lib/glfw-3.3.4)
include_directories(lib/glfw-3.3.4/deps)
include_directories(lib/glfw-3.3.4/include)

# set(GLAD "lib/glad/include/glad/glad.h"
#          "lib/glad/src/glad.c")
set(GETOPT "${GLFW_SOURCE_DIR}/deps/getopt.h"
           "${GLFW_SOURCE_DIR}/deps/getopt.c")
set(TINYCTHREAD "${GLFW_SOURCE_DIR}/deps/tinycthread.h"
                "${GLFW_SOURCE_DIR}/deps/tinycthread.c")

set(SOURCE_FILES src/main.cpp

                src/stb_image.h
                src/Shader.h src/Shader.cpp
                src/PerspectiveCamera.h src/PerspectiveCamera.cpp
                src/Object3D.h src/Object3D.cpp
                src/geometries/BufferGeometry.h src/geometries/BufferGeometry.cpp
                
                src/geometries/BoxGeometry.h src/geometries/BoxGeometry.cpp
                src/geometries/ConeGeometry.h src/geometries/ConeGeometry.cpp
                src/geometries/CylinderGeometry.h src/geometries/CylinderGeometry.cpp
                src/geometries/SphereGeometry.h src/geometries/SphereGeometry.cpp
                src/geometries/TorusGeometry.h src/geometries/TorusGeometry.cpp
                src/geometries/TorusKnotGeometry.h src/geometries/TorusKnotGeometry.cpp

                src/geometries/PolyhedronGeometry.h src/geometries/PolyhedronGeometry.cpp
                src/geometries/OctahedronGeometry.h src/geometries/OctahedronGeometry.cpp
                src/geometries/TetrahedronGeometry.h src/geometries/TetrahedronGeometry.cpp
                src/geometries/DodecahedronGeometry.h src/geometries/DodecahedronGeometry.cpp
                src/geometries/IcosahedronGeometry.h src/geometries/IcosahedronGeometry.cpp
                
                src/geometries/ConicalSpiralGeometry.h src/geometries/ConicalSpiralGeometry.cpp
                )

add_executable(main ${SOURCE_FILES} ${TINYCTHREAD} ${GETOPT} #[[${GLAD} lib/glad/src/glad.c]])

target_link_libraries(main glfw glad glm ${GLFW_LIBRARIES})
