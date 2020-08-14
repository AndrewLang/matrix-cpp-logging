#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogNoneLayout : public LogLayout
	{
	public:
		LogNoneLayout();
		~LogNoneLayout();

		virtual std::string layout(const LogMessage& message) override;

	private:

	};

}