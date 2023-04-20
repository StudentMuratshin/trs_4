# CMakeList.txt : CMake project for trs_4, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (trs_2_1 "task_2_1.cpp" "trs_4.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET trs_2_1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
