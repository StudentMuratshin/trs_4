# CMakeList.txt : CMake project for trs_4, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (task_1 "task_1.cpp")
add_executable (task_2 "task_2.cpp")
add_executable (task_3 "task_3.cpp")
add_executable (task_4 "task_4.cpp")
add_executable (task_5 "task_5.cpp")
add_executable (test "test.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET task_1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
