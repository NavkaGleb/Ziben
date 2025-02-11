set(TARGET ZibenRenderer)

add_compile_definitions(STB_IMAGE_IMPLEMENTATION)

file(GLOB HEADER_FILES
    ${PROJECT_SOURCE_DIR}/ZibenEngine/Include/Ziben/Renderer/*.hpp
    ${PROJECT_SOURCE_DIR}/ZibenEngine/Source/Renderer/*.hpp
)

file(GLOB SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/ZibenEngine/Source/Renderer/*.cpp
)

add_library(${TARGET} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(${TARGET}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/ZibenEngine/External/glew-cmake/include
    PRIVATE
        # stb library
        ${PROJECT_SOURCE_DIR}/ZibenEngine/External/stb

        ${PROJECT_SOURCE_DIR}/ZibenEngine/Include/Ziben/Renderer
        ${PROJECT_SOURCE_DIR}/ZibenEngine/Include/
)

target_link_libraries(${TARGET} PUBLIC ZibenSystem ZibenProfiling libglew_static glm EnTT::EnTT)
#target_link_libraries(${TARGET} PUBLIC OpenGL::OpenGL OpenGL::EGL)

#-lglut32 -lglu32 -lopengl32

target_precompile_headers(${TARGET} PUBLIC RendererPch.hpp)