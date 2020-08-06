#include "LogLevel.h"

namespace Logging
{
    class LogLevels
    {
    private:
        /* data */
    public:
        static const LogLevel All;
        static const LogLevel Debug;
        static const LogLevel Info;
        static const LogLevel Warn;
        static const LogLevel Error;
        static const LogLevel Fatal;
        static const LogLevel None;
    };

}