file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS *.cpp)

add_executable(${TARGET_TESTS} ${SRCS})

target_include_directories(${TARGET_TESTS} PUBLIC ${TARGET_CORE})
target_link_libraries(${TARGET_TESTS} PUBLIC ${TARGET_CORE})
