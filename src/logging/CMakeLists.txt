
cmake_minimum_required (VERSION 3.12)

include(common.cmake)

if(WIN32)
	#[[
		Export all symbold on windows
		see https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
	]]   
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)   
endif(WIN32)


include_directories(
	${CMAKE_SOURCE_DIR}/src/logging
	${CMAKE_SOURCE_DIR}/src/logging/include
)


project(logging VERSION 0.0.1 )

set(DEFAULT_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /doc")

# add library definition
add_library( ${PROJECT_NAME} SHARED ${SourceFiles} ${HeaderFiles})

add_definitions(-DEXPMODULE)


add_precompiled_header(${PROJECT_NAME} pch.h SOURCE_CXX pch.cpp FORCEINCLUDE)

# 
target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR}/include )


if(WIN32)		
	# add_definitions(-DCMAKE_GENERATOR_PLATFORM=x86)			
else ()
	# 
endif()

set_target_properties( ${PROJECT_NAME} PROPERTIES 
	VERSION ${PROJECT_VERSION}
	PUBLIC_HEADER "${HeaderFiles}"
	OUTPUT_NAME "logging"
)
