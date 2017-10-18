cmake_minimum_required (VERSION 2.6)
project (Tutorial_flag)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )

  # add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# should we use our own math functions?
option (USE_MY_FLAG 
        "Use tutorial provided my flag" ON) 



# add the executable
add_executable(Tutorial tutorial.cxx)
add_definitions(-DUSE_MY_FLAG)

#set_target_properties(Tutorial PROPERTIES COMPILE_FLAGS "-DUSE_MY_FLAG")
