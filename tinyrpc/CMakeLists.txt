file(GLOB_RECURSE SRC_LIST *.cpp *.cc *.h *.hpp *.S)
add_library(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} pthread tinyxml protobuf dl mysqlclient)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
)
