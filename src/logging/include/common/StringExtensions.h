#pragma once
#include "Consts.h"
#include "Initializer.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <locale>
#include <cctype>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <iomanip>
#include <chrono>
#include <limits>
#include <time.h>


namespace Logging
{
	class StringExtensions
	{
	public:
		static std::vector<std::string> split(const std::string& value, const char& delimiter = ' ');

		static std::vector<std::string> split(const std::string& value, const std::vector<std::string> delimiters);

		static std::string replace(const std::string& original, const std::string& toBeReplace, const std::string& value);

		static bool compareIgnoreCase(const std::string& first, const std::string& second);

		static bool compareTrimIgnoreCase(const std::string& first, const std::string& second, const char trimChars[] = " ");

		static bool isNullOrEmpty(const std::string& value);

		static bool notNullOrEmpty(const std::string& value);

		static int indexOf(const std::string& text, const char& value);

		static int indexOf(const std::string& text, const std::string& value);

		static bool contains(const std::string& text, const std::string& value, bool ignoreCase = true);

		static std::string textBetween(const std::string& text, const char& start, const char& end);

		static std::string literalString(const std::string& value);

		static std::string toLower(const std::string& value);

		static std::string toUpper(const std::string& value);

		static int parseHex(const std::string& value);

		template<typename TKey>
		static TKey convertTo(const std::string & value)
		{
			std::istringstream stream(value);
			Initializer<TKey>  target;

			if (typeid(TKey) == typeid(std::string))
			{
				for (size_t i = 0; i < StringExtensions::split(value).size(); i++)
				{
					Initializer<TKey> tempValue;
					stream >> tempValue.t;
					if (i > 0)
						target.t += ' ';
					target.t += tempValue.t;
				}
			}
			else
			{
				stream >> target.t;
			}

			return target.t;
		}

		
		static std::wstring toWString(const std::string& value);

		static std::string toString(const std::wstring& value);

		static bool endsWith(const std::string& full, const std::string& end);

		static bool endsWith(const std::string& full, const char& end);

		static bool startsWith(const std::string& full, const std::string& start);

		static bool startsWith(const std::string& full, const char& start);

		static std::string paddingString(const std::string& value, const char& paddingChar = Consts::PaddingChar, const int& padding = Consts::Padding);

		static std::string wrapBySquare(const std::string& value);

		static std::string getTimestamp();

		static std::string trimStart(const std::string& value, const char trimChars[] = " ");

		static std::string trimEnd(const std::string& value, const char trimChars[] = " ");

		static std::string trim(const std::string& value, const char trimChars[] = " ");

		static std::string toHex(const int value);

		static std::string toString(const std::vector<char> chars);

	private:
		static bool compareChar(unsigned char first, unsigned char second);
};

	using Strings = StringExtensions;
}