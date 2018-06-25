set(TARGETNAME "pmeas")
set(TEST_NAME "test_${TARGETNAME}")

add_library(${TARGETNAME} INTERFACE)

# message("----> Test")

target_include_directories(${TARGETNAME} INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

if(COMPONENT_TEST)
	add_executable(${TEST_NAME}
		test/RuntimeTimer_test.cpp
        test/RuntimeMeasurement_test.cpp
	)	

#	message(DEBUG " GTEST_BOTH_LIBRARIES = ${GTEST_BOTH_LIBRARIES} ${GTEST_INCLUDE_DIRS}")

	target_link_libraries(${TEST_NAME}
 		${GTEST_BOTH_LIBRARIES}
 		${GMOCK_LIBS}
 		${CMAKE_THREAD_LIBS_INIT}
		${TARGETNAME}
	)	

	add_test(${TEST_NAME} ${TEST_NAME})

	target_include_directories(${TEST_NAME} PRIVATE ${GTEST_INCLUDE_DIRS})
endif(COMPONENT_TEST)


install(TARGETS ${TARGETNAME} EXPORT "${TARGETNAME}Config"
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}) 

install(DIRECTORY include/pmeas DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT ${TARGETNAME}Config DESTINATION share/${LIB_NAME}/cmake)

export(TARGETS ${TARGETNAME} FILE "${TARGETNAME}Config.cmake")



