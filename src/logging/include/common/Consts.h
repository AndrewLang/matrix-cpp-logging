#pragma once
#include <string>

namespace Logging
{
	struct Consts
	{
		static constexpr const int Padding = 25;
		static constexpr const char PaddingChar = ' ';

		static const std::string NewLine ;
		static const std::string Tab;
		static const std::string Space;
		static const std::string Empty;
	};
	
}