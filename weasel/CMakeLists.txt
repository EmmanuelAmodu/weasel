add_library(Weasel Utils.cpp HttpMethod.cpp HttpStatus.cpp Request.cpp Response.cpp Router.cpp Server.cpp UrlParser.cpp)

include_directories(${CONAN_INCLUDE_DIRS_JSONCPP})
# set(jsoncpp_DIR "/home/emmanuel/weasle/build")
find_package(jsoncpp REQUIRED)

include_directories(${jsoncpp_INCLUDE_DIRS})

target_link_libraries(Weasel PRIVATE ${CONAN_LIBS})
target_link_libraries(Weasel PRIVATE JsonCpp::JsonCpp)
