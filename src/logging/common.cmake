
# header files
SET(HeaderFiles 
	pch.h	
)

# source files
SET(SourceFiles 
    pch.cpp
    
)

if(WIN32)
    list(APPEND SourceFiles )
    list(APPEND HeaderFiles )
else ()
    list(APPEND SourceFiles )
    list(APPEND HeaderFiles )
elseif()