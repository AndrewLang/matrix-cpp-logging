#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogMessageLayout : public LogLayout
	{
	public:
		LogMessageLayout();
		~LogMessageLayout();

		virtual std::string layout(const LogMessage& message) override;

	private:

	};

}