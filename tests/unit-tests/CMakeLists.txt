

project(unittests)


include_directories(
	${CMAKE_SOURCE_DIR}/src/logging/include
	${CMAKE_SOURCE_DIR}/tests/unit-tests
	${CMAKE_SOURCE_DIR}/tests/unit-tests/include
)

set (HeaderFiles 
	pch.h
	main.h

	include/Circle.h
	include/Rectangle.h
	include/Shape.h
	Include/ShapeContainer.h

)

set (SourceFiles 
	pch.cpp
	main.cpp
	
	src/Circle.cpp
	src/Rectangle.cpp
	src/Shape.cpp
	src/ShapeContainer.cpp

	tests/DummyTests.cpp

	
	tests/common/ArgumentNullExceptionTests.cpp
	tests/common/GuardTests.cpp
	tests/common/ObjectMapTests.cpp
	tests/common/MapExtensionsTests.cpp
	tests/common/StopwatchTests.cpp
	tests/common/StringExtensionsTests.cpp
	tests/common/TextFormatterTests.cpp
	tests/common/VectorExtensionsTests.cpp

	tests/logging/ConsoleLoggerProviderTests.cpp
	tests/logging/ConsoleLoggerTests.cpp
	tests/logging/InternalLoggerTests.cpp
	tests/logging/LoggerFactoryTests.cpp
	tests/logging/LogLevelConverterTests.cpp
	tests/logging/LogLevelTests.cpp
	tests/logging/VsOutputLogger.cpp
	tests/logging/VsOutputLoggerProviderTests.cpp
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
