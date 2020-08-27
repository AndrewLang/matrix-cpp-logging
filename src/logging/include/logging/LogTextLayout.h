#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogTextLayout : public LogLayout
	{
	public:
		LogTextLayout();
		LogTextLayout(const std::string& text);
		~LogTextLayout();

		virtual std::string layout(const LogMessage& message) override;

	private:
		std::string content;
	};

}