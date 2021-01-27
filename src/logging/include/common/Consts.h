#pragma once
#include <string>

namespace Logging
{
	class Consts
	{
	public:
		static constexpr const int Padding = 25;
		static constexpr const char PaddingChar = ' ';

		inline static const std::string NewLine = "\n";
		inline static const std::string Tab = "\t";
		inline static const std::string Space = " ";
		inline static const std::string Empty = "";
	};
	
}