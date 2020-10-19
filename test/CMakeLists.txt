cmake_minimum_required(VERSION 3.10.0)

project (tqueue_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  set_source_files_properties(test.c PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra -Werror -std=c89"
  )
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
  set_source_files_properties(test.c PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra -Weverything -Werror -std=c89"
  )
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
  set_source_files_properties(test.c PROPERTIES
    COMPILE_FLAGS "/Wall /WX /wd4514"
  )
else()
  message(WARNING "Unknown compiler '${CMAKE_C_COMPILER_ID}'!")
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set_source_files_properties(test.cpp PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra -Werror"
  )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set_source_files_properties(test.cpp PROPERTIES
    COMPILE_FLAGS "-Wall -Wextra -Weverything -Werror"
  )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set_source_files_properties(test.cpp PROPERTIES
    COMPILE_FLAGS "/Wall /WX /wd4514"
  )
else()
  message(WARNING "Unknown compiler '${CMAKE_C_COMPILER_ID}'!")
endif()

add_executable(${PROJECT_NAME} 
    ../tqueue.h
    main.cpp
    utest.h
    tqueue_test.cpp
)
