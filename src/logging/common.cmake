
# header files
SET(HeaderFiles 
    pch.h	
    
    include/logger.h

    include/common/ArgumentNullException.h
	include/common/BaseException.h
	include/common/FileLoadException.h
	include/common/FileNotExistsException.h
	include/common/Guard.h
	include/common/MapValueDescriptor.h
	include/common/MapExtensions.h
	include/common/ObjectMap.h
	include/common/Platform.h
	include/common/Stopwatch.h
	include/common/StringExtensions.h	
	include/common/TextFormatter.h
	include/common/VectorExtensions.h
)

# source files
SET(SourceFiles 
    pch.cpp
    
    src/common/ArgumentNullException.cpp
	src/common/BaseException.cpp
	src/common/FileLoadException.cpp
	src/common/FileNotExistsException.cpp
	src/common/Guard.cpp
	src/common/Platform.cpp
	src/common/Stopwatch.cpp
	src/common/StringExtensions.cpp
	src/common/TextFormatter.cpp
)

# if(WIN32)
#     list(APPEND SourceFiles )
#     list(APPEND HeaderFiles )
# else ()
#     list(APPEND SourceFiles )
#     list(APPEND HeaderFiles )
# elseif()