cmake_minimum_required(VERSION 3.22)
project(LinkedList)

set(CMAKE_CXX_STANDARD 11)

set(INC inc/Singly.h inc/Doubly.h inc/ILinkedList.h inc/Common.h inc/ListFactory.h)
set(SRC src/Singly.cpp src/Doubly.cpp src/ListFactory.cpp inc/SinglyLLNode.h)

add_executable(ApplicationX ${INC} ${SRC} src/main.cpp)
