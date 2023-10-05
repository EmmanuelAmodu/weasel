cmake_minimum_required(VERSION 3.10)

# Name of the project
project(Weasel)

# Use C++17 (You can select the version you want)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all the .cpp and .h files in the src directory to the build
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.h")
find_package(Boost 1.70 REQUIRED COMPONENTS system) # 'system' is a direct dependency for Asio

target_include_directories(my_project PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(my_project ${Boost_LIBRARIES})

# Create the main executable from source files
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# If you have dependencies in the libs folder, add them
add_subdirectory(libs/some_dependency)

# Link the dependency libraries to your main executable if needed
target_link_libraries(${PROJECT_NAME} some_dependency)

# Optional: If you have tests, enable testing and add them
enable_testing()
add_subdirectory(tests)
add_executable(my_project main.cpp)
