cmake_minimum_required(VERSION 3.14)

project(
  design_patterns
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Adds given pattern
# skips if pattern doesn't have a main.cpp file
function(add_pattern name)
  set(main_file "${CMAKE_SOURCE_DIR}/src/${name}/main.cpp")   

  if(EXISTS "${main_file}")
    add_executable(${name} ${main_file})

    target_include_directories(${name} PRIVATE
      ${CMAKE_SOURCE_DIR}/include/${name}
    )

    target_compile_options(${name} PRIVATE -Wall)

    message(STATUS "Adding pattern: ${name}")
  else()
    message(STATUS "Skipping pattern: ${name} (no main.cpp)")
  endif()
endfunction()

message("\n")

add_pattern(observer)
add_pattern(decorator)

