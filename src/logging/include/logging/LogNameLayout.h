#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogNameLayout: public LogLayout
	{
	public:
		LogNameLayout();
		~LogNameLayout();

		virtual std::string layout(const LogMessage& message) override;

	private:

	};

}