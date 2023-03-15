find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(TEST_COROUTINE ./test_coroutine.cc)
set(TEST_HTTP_SERVER ./test_http_server.cc)
set(TEST_PB_SERVER ./test_tinypb_server.cc)
set(TEST_PB_SERVER_CLIENT ./test_tinypb_server_client.cc)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS test_tinypb_server.proto)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(test_coroutine ${TEST_COROUTINE})
target_link_libraries(test_coroutine ${PROJECT_NAME} pthread)

add_executable(test_http_server ${TEST_HTTP_SERVER} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(test_http_server ${PROJECT_NAME} pthread ${Protobuf_LIBRARIES})

add_executable(test_tinypb_server ${TEST_PB_SERVER} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(test_tinypb_server ${PROJECT_NAME} pthread ${Protobuf_LIBRARIES})

add_executable(test_tinypb_server_client ${TEST_PB_SERVER_CLIENT} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(test_tinypb_server_client ${PROJECT_NAME} pthread ${Protobuf_LIBRARIES})
