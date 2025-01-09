file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_library(${TARGET_CORE} STATIC ${SRCS})

target_include_directories(${TARGET_CORE} PUBLIC ${FFMPEG_INCLUDE_DIRS}
                                                 ${SDL2_INCLUDE_DIRS})
target_include_directories(${TARGET_CORE} PUBLIC include)
target_link_libraries(${TARGET_CORE} PUBLIC ${FFMPEG_LIBRARIES} SDL2::SDL2main
                                            SDL2::SDL2 fmt::fmt)
