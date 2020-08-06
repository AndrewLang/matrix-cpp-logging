#include <string>

namespace Logging
{
    class LogLevel
    {
    private:        
        std::string mName;
        int mValue;

    public:    
        LogLevel(const std::string name, const int value);

		LogLevel() = delete;

        ~LogLevel();

        std::string getName();

        int getValue();
    };

    

} // namespace Logging