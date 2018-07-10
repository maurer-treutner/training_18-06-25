cmake_minimum_required(VERSION 3.1)

include(GNUInstallDirs)

message(STATUS "CMake build system for C++ examples")

# find package uses demolibConfig in usr/share/demolib
# set(BOOST_ROOT "C:/Program Files/boost/boost_1_66_0")
# find_package(Boost 1.66.0 REQUIRED)
# include_directories(${Boost_INCLUDE_DIRS})

if(COMPONENT_TEST)
	enable_testing()
	set(GTEST_ROOT ${EXT_DIR_PREFIX})
    find_package(GTest REQUIRED COMPONENTS timer)
	find_package(Threads)
endif()

add_subdirectory(E0_ValRef)
add_subdirectory(E1_RValue)
add_subdirectory(E2_PerfFor)
add_subdirectory(E3_RetValOpt)
add_subdirectory(E4_TypeDeduction)
add_subdirectory(E5_UniquePtr)
add_subdirectory(E6_SharedPtr)
add_subdirectory(E7_WeakPtr)
add_subdirectory(E8_Array)
add_subdirectory(E9_Vector)
add_subdirectory(E10_List)
add_subdirectory(E11_Lambda)
add_subdirectory(E12_Future)
add_subdirectory(E13_Promise)
add_subdirectory(E14_ThreadTask)
#add_subdirectory(E15_Atomic)
#add_subdirectory(E16_StreamOp)

