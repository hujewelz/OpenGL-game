add_library(Beetle 
    Scene/scene.cpp
    Shader/shader.cpp
    Sprite/spriterenderer.cpp
    Texture/texture.cpp
    Window/window.cpp
    Window/resourcemanager.cpp
    Vendored/stb_image/stb_image.cpp
)

target_include_directories(Beetle 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Shader/
    ${CMAKE_CURRENT_SOURCE_DIR}/Sprite/
    ${CMAKE_CURRENT_SOURCE_DIR}/Texture/
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendored/glm/
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendored/stb_image/
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/
    ${CMAKE_CURRENT_SOURCE_DIR}/Window/
    /usr/local/include
)
target_link_directories(Beetle PUBLIC "/usr/local/lib")
target_link_libraries(Beetle GLEW glfw.3.3)
if (APPLE)
  target_link_libraries(Beetle "-framework OpenGL")
endif()