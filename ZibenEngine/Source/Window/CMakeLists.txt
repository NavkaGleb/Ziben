set(TARGET ZibenWindow)

file(GLOB HEADER_FILES
    ${PROJECT_SOURCE_DIR}/ZibenEngine/Include/Ziben/Window/*.hpp
    ${PROJECT_SOURCE_DIR}/ZibenEngine/Source/Window/*.hpp
)

file(GLOB SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/ZibenEngine/Source/Window/*.cpp
)

add_library(${TARGET} STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(${TARGET}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/ZibenEngine/Include/Ziben/Window
        ${PROJECT_SOURCE_DIR}/ZibenEngine/Include/
)

target_link_libraries(${TARGET} PUBLIC ZibenScene)

target_precompile_headers(${TARGET} PUBLIC WindowPch.hpp)