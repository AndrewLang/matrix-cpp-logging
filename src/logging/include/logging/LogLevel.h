#include <string>

namespace Logging
{
    class LogLevel
    {
    private:        
        std::string name;
        int value;

    public:
        LogLevel(const std::string name, const int value);

        ~LogLevel();

        
    };

} // namespace Logging