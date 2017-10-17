this shows including external build library

in this example we will link (exteranl_build/test_dll.lib).

Three modifications required in CMakeLists.txt file

(1) LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/externalBuild)
(2) INCLUDE_DIRECTORIES(externalBuild)
(3) TARGET_LINK_LIBRARIES(
 test_dll_client
 test_dll
)

note:- .lib is not included in target_link_libraries api.
