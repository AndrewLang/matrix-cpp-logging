#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogProcessIdLayout : public LogLayout
	{
	public:	
		LogProcessIdLayout(const std::string prefix = "Thread: ");
		~LogProcessIdLayout();

		virtual std::string layout(const LogMessage& message) override;

		std::string getPrefix();

		void setPrefix(const std::string value);

	private:
		std::string mPrefix;
	};

}