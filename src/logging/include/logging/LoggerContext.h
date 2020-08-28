#pragma once
#include "Configuration.h"
#include "ILoggerFactory.h"
#include "LogLayoutRepository.h"

namespace Logging
{
	class LoggerContext
	{
	public:
		LoggerContext();
		~LoggerContext();

		std::shared_ptr<Configuration> configuration;
		std::shared_ptr<ILoggerFactory> factory;
		std::shared_ptr<LogLayoutRepository> layoutRepo;

	private:

	};

}