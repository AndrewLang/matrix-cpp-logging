#pragma once 

#include "LogLayout.h"

namespace Logging
{
    class LogTimestampLayout: public LogLayout
    {
    private:
        /* data */
    public:
        LogTimestampLayout(/* args */);
        ~LogTimestampLayout();
      
		virtual std::string layout(const LogMessage& message) override;
    };
}