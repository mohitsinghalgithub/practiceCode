cmake_minimum_required(VERSION 3.10)
project(PracticeTest CXX)
add_executable(PracticeTest PracticeTest.cpp
                            singleTon.cpp
                            readerWriterSharedLock.cpp
                            ThreadSafeStack.cpp)
