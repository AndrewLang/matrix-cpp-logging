#pragma once 

#include "LogLayout.h"

namespace Logging
{
	class LogIndentLayout : public LogLayout
	{
	public:
		LogIndentLayout();
		~LogIndentLayout();

		virtual std::string layout(const LogMessage& message) override;

	private:
		static constexpr const char* Indent = "\t";
	};

}