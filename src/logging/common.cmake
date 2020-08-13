
# header files
SET(HeaderFiles 
    pch.h	
    
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

	include/logging/ConsoleLogger.h
	include/logging/ConsoleLoggerProvider.h
	include/logging/ILogger.h
	include/logging/ILoggerFactory.h
	include/logging/ILoggerProvider.h
	include/logging/InternalLogger.h
	include/logging/LogLevel.h
	include/logging/LogLevels.h
	include/logging/LogMessage.h
	include/logging/LogLayout.h
	include/logging/LogNameLayout.h
	include/logging/LogTimestampLayout.h
	include/logging/LogLevelLayout.h
	include/logging/LogIndentLayout.h
	include/logging/LogMessageLayout.h
	include/logging/LoggerBase.h
	include/logging/LoggerFactory.h
	include/logging/LogLevelConverter.h
	include/logging/LogMessageName.h
	include/logging/VsOutput.h
	include/logging/VsOutputLogger.h
	include/logging/VsOutputLoggerProvider.h
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

	src/logging/ConsoleLogger.cpp
	src/logging/ConsoleLoggerProvider.cpp
	src/logging/InternalLogger.cpp
	src/logging/LoggerBase.cpp
	src/logging/LoggerFactory.cpp
	src/logging/LogLevelConverter.cpp
	src/logging/LogLevel.cpp
	src/logging/LogLevels.cpp
	src/logging/LogMessage.cpp	
	src/logging/LogNameLayout.cpp
	src/logging/LogTimestampLayout.cpp
	src/logging/LogLevelLayout.cpp
	src/logging/LogIndentLayout.cpp
	src/logging/LogMessageLayout.cpp
	src/logging/VsOutput.cpp
	src/logging/VsOutputLogger.cpp
	src/logging/VsOutputLoggerProvider.cpp
)

# if(WIN32)
#     list(APPEND SourceFiles )
#     list(APPEND HeaderFiles )
# else ()
#     list(APPEND SourceFiles )
#     list(APPEND HeaderFiles )
# elseif()