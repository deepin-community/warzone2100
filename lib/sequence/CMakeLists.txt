file(GLOB HEADERS "*.h")
file(GLOB SRC "*.cpp")

find_package(OpenAL REQUIRED)
find_package(OggVorbis REQUIRED)
find_package(Theora REQUIRED)

add_library(sequence STATIC ${HEADERS} ${SRC})
set_property(TARGET sequence PROPERTY FOLDER "lib")
include(WZTargetConfiguration)
WZ_TARGET_CONFIGURATION(sequence)
target_compile_definitions(sequence PRIVATE "AL_LIBTYPE_STATIC")
target_include_directories(sequence PRIVATE "${OPENAL_INCLUDE_DIR}" ivis-opengl "${OGGVORBIS_INCLUDE_DIR}")
target_link_libraries(sequence PRIVATE framework ${OGGVORBIS_LIBRARIES} theora::dec)
