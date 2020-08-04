

project(unittests)


include_directories(
	${CMAKE_SOURCE_DIR}/src/logging/include
	${CMAKE_SOURCE_DIR}/tests/unit-tests
	${CMAKE_SOURCE_DIR}/tests/unit-tests/include
)

set (HeaderFiles 
	pch.h
	main.h
		
)

set (SourceFiles 
	pch.cpp
	main.cpp
	
	tests/DummyTests.cpp
)


if(WIN32)
	# append windows tests
	list(APPEND  SourceFiles  
		
	)

	list(APPEND HeaderFiles 
		
	)

else()
	list(APPEND  SourceFiles  		
		
	)
endif()

add_executable (${PROJECT_NAME} ${HeaderFiles} ${SourceFiles})

# Include sub-projects.

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main logging)


if(WIN32)
	# set(CMAKE_CXX_FLAGS "-m32")

else ()
	# 
endif()

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
