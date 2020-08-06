#include "logging/LogLevels.h"

namespace Logging
{
    const LogLevel All = LogLevel("All", 0);
    const LogLevel Debug = LogLevel("Debug", 100);
    const LogLevel Info = LogLevel("Info", 200);
    const LogLevel Warn = LogLevel("Warn", 300);
    const LogLevel Error = LogLevel("Error", 400);
    const LogLevel Fatal = LogLevel("Fatal", 500);
    const LogLevel None = LogLevel("None", 99999);
}