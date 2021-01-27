#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogThreadIdLayout : public LogLayout
	{
	public:		
		LogThreadIdLayout(const std::string prefix = "Thread: ");
		~LogThreadIdLayout();

		virtual std::string layout(const LogMessage& message) override;

		std::string getPrefix();

		void setPrefix(const std::string value);
	private:
		std::string mPrefix;
	};

}