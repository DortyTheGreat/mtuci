# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\second_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\second_autogen.dir\\ParseCache.txt"
  "second_autogen"
  )
endif()
