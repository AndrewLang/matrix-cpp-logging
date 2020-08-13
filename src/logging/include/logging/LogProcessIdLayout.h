#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogProcessIdLayout : public LogLayout
	{
	public:
		std::string prefix;

		LogProcessIdLayout(const std::string prefix = "Thread: ");
		~LogProcessIdLayout();

		virtual std::string layout(const LogMessage& message) override;

	private:

	};

}