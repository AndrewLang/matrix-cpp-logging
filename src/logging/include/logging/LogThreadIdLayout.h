#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogThreadIdLayout : public LogLayout
	{
	public:
		std::string prefix;

		LogThreadIdLayout(const std::string prefix = "Thread: ");
		~LogThreadIdLayout();

		virtual std::string layout(const LogMessage& message) override;

	private:

	};

}