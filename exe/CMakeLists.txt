# in exe directory

set(TEST_EXE
    test
)

# for now put the executables in the build root
# for compatibility with existing scripts
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

foreach(exe ${TEST_EXE})
  add_executable(${exe} ${exe}.cpp ${sources} ${headers})
  target_include_directories(${exe} PRIVATE ${ROOT_INCLUDE_DIRS})
  target_link_libraries(${exe} myProject ROOT::Core ROOT::Gpad ROOT::Hist ROOT::Tree)
endforeach()

#include_directories(include)
message(STATUS "Target Executable: ${TEST_EXE}")
