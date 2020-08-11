#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogLevelLayout : public LogLayout
	{
	public:
		LogLevelLayout();
		~LogLevelLayout();

		virtual std::string layout(const LogMessage& message) override;

	private:

	};

}