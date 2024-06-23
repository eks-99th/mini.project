cmake_minimum_required(VERSION 3.20)
project(CGPA_CALCULATOR VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_library(COMPONENT ftxui-component HINTS /usr/local/lib)
find_library(SCREEN ftxui-screen HINTS /usr/local/lib)
find_library(DOM ftxui-dom HINTS /usr/local/lib)

find_library(CRYPTO botan-3 REQUIRED)
set(BOTAN_INCLUDE_DIR "/usr/local/include/botan-3")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(course STATIC
    src/course.cpp    
    src/gpa_calc.cpp
    include/course.hpp
)

add_library(user_interface STATIC
    src/user_interface.cpp    
    include/user_interface.hpp
    include/main.hpp
)

target_link_libraries(user_interface
    PRIVATE ${COMPONENT}
    PRIVATE ${SCREEN}
    PRIVATE ${DOM}
    PRIVATE ${CRYPTO}
)

target_include_directories(user_interface PRIVATE ${BOTAN_INCLUDE_DIR})


add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} 
    PRIVATE user_interface
    PRIVATE course
    )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

enable_testing()
add_subdirectory(tests)