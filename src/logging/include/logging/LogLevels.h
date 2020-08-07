#include "LogLevel.h"

namespace Logging
{
	class LogLevels
	{
	private:

	public:
		static const std::shared_ptr<LogLevel> All;
		static const std::shared_ptr<LogLevel> Debug;
		static const std::shared_ptr<LogLevel> Info;
		static const std::shared_ptr<LogLevel> Warn;
		static const std::shared_ptr<LogLevel> Error;
		static const std::shared_ptr<LogLevel> Fatal;
		static const std::shared_ptr<LogLevel> None;
	};

	const std::shared_ptr<LogLevel> LogLevels::All = std::make_shared<LogLevel>("All", 0);
	const std::shared_ptr<LogLevel> LogLevels::Debug = std::make_shared<LogLevel>("Debug", 100); 
	const std::shared_ptr<LogLevel> LogLevels::Info = std::make_shared<LogLevel>("Info", 200);
	const std::shared_ptr<LogLevel> LogLevels::Warn = std::make_shared<LogLevel>("Warn", 300);
	const std::shared_ptr<LogLevel> LogLevels::Error = std::make_shared<LogLevel>("Error", 400);
	const std::shared_ptr<LogLevel> LogLevels::Fatal = std::make_shared<LogLevel>("Fatal", 500);
	const std::shared_ptr<LogLevel> LogLevels::None = std::make_shared<LogLevel>("None", 99999);
}