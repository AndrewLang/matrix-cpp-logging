#pragma once 

#include "LogLayout.h"

namespace Logging
{
    class LogTimestampLayout: public LogLayout
    {    
    public:
        LogTimestampLayout();
        ~LogTimestampLayout();
      
		virtual std::string layout(const LogMessage& message) override;
    };
}