#include "common/StringExtensions.h"

namespace Logging
{
	std::vector<std::string> StringExtensions::split(const std::string& value, const char& delimiter)
	{
		std::vector<std::string> result;

		std::stringstream stream(value);
		std::string segment;
		while (std::getline(stream, segment, delimiter))
		{
			result.push_back(segment);
		}
		return result;
	}

	std::vector<std::string> StringExtensions::split(const std::string& value, const std::vector<std::string> delimiters)
	{
		std::vector<std::string> result;

		std::string remain = value;
		size_t pos = std::string::npos;

		auto findFirstDelimiter = [](const std::string& text, const std::vector<std::string> splitters) {
			size_t pos = SIZE_MAX;
			std::tuple<size_t, std::string> posInfo;


			for (const auto& spliter : splitters)
			{
				size_t temp = text.find(spliter);
				if (temp >= 0 && temp < pos)
				{
					pos = temp;
					posInfo = std::make_tuple(pos, spliter);
				}
			}
			return posInfo;
		};

		do
		{
			auto posInfo = findFirstDelimiter(remain, delimiters);
			pos = std::get<0>(posInfo);
			if (pos > 0)
			{
				auto part = remain.substr(0, pos);
				result.push_back(part);

				remain.erase(0, pos + std::get<1>(posInfo).length());
			}
			else
			{
				result.push_back(remain);
			}

		} while (pos > 0);

		return result;
	}

	std::string StringExtensions::replace(const std::string& original, const std::string& toBeReplace, const std::string& value)
	{
		std::string result = original;
		size_t pos = result.find(toBeReplace);

		while (pos != std::string::npos)
		{
			result.replace(pos, toBeReplace.size(), value);
			pos = result.find(toBeReplace, pos + value.size());
		}
		return result;
	}

	bool StringExtensions::compareIgnoreCase(const std::string& first, const std::string& second)
	{
		if (first.length() == second.length())
		{
			return std::equal(second.begin(), second.end(), first.begin(), compareChar);
		}
		else
		{
			return false;
		}
	}

	bool StringExtensions::compareTrimIgnoreCase(const std::string& first, const std::string& second, const char trimChars[])
	{
		std::string part1 = trim(first, trimChars);
		std::string part2 = trim(second, trimChars);

		if (part1.length() == part2.length())
		{
			return std::equal(part2.begin(), part2.end(), part1.begin(), compareChar);
		}
		else
		{
			return false;
		}
	}

	bool StringExtensions::isNullOrEmpty(const std::string& value)
	{
		return value.length() <= 0;
	}

	bool StringExtensions::notNullOrEmpty(const std::string& value)
	{
		return value.length() > 0;
	}

	int StringExtensions::indexOf(const std::string& text, const char& value)
	{
		return static_cast<int>(text.find_first_of(value, 0));
	}

	int StringExtensions::indexOf(const std::string& text, const std::string& value)
	{
		return static_cast<int>(text.find(value, 0));
	}

	bool StringExtensions::contains(const std::string& text, const std::string& value, bool ignoreCase)
	{
		if (ignoreCase)
		{
			return indexOf(toLower(text), toLower(value)) >= 0;
		}
		else
		{
			return indexOf(text, value) >= 0;
		}
	}


	std::string StringExtensions::textBetween(const std::string& text, const char& start, const char& end)
	{
		int startIndex = indexOf(text, start);
		int endIndex = indexOf(text, end);
		return text.substr(startIndex + 1, endIndex - startIndex - 1);
	}

	std::string StringExtensions::literalString(const std::string& value)
	{
		if (isNullOrEmpty(value))
			return value;

		return replace(value, "\\", R"(\\)");
	}

	std::string StringExtensions::toLower(const std::string& value)
	{
		if (isNullOrEmpty(value))
			return value;

		std::string literal = value;
		std::string result;
		result.resize(literal.size());
		std::transform(literal.begin(), literal.end(), result.begin(), [](unsigned char c) {
			return std::tolower(c);
			});

		return result;
	}

	std::string StringExtensions::toUpper(const std::string& value)
	{
		if (isNullOrEmpty(value))
			return value;

		std::string result;
		result.resize(value.size());
		std::transform(value.begin(), value.end(), result.begin(), [](unsigned char c) {
			return std::toupper(c);
			});

		return result;
	}

	int StringExtensions::parseHex(const std::string& value)
	{
		std::stringstream stream;
		stream << std::hex << value;

		int result;
		stream >> result;
		return result;
	}

	std::wstring StringExtensions::toWString(const std::string& value)
	{
		std::wstringstream stream;
		stream << value.c_str();
		return stream.str();
	}

	std::string StringExtensions::toString(const std::wstring& value)
	{
		std::string result(value.begin(), value.end());
		return result;
	}

	bool StringExtensions::endsWith(const std::string& full, const std::string& end)
	{
		if (full.length() >= end.length()) {
			return (0 == full.compare(full.length() - end.length(), end.length(), end));
		}
		else {
			return false;
		}
	}

	bool StringExtensions::endsWith(const std::string& full, const char& end)
	{
		return endsWith(full, std::string(1, end));
	}

	bool StringExtensions::startsWith(const std::string& full, const std::string& start)
	{
		if (full.length() >= start.length()) {
			return std::equal(start.begin(), start.end(), full.begin());
		}
		else {
			return false;
		}
	}

	bool StringExtensions::startsWith(const std::string& full, const char& start)
	{
		return startsWith(full, std::string(1, start));
	}

	std::string StringExtensions::paddingString(const std::string& value, const char& paddingChar, const int& padding)
	{
		std::stringstream stream;
		stream << std::left << std::setfill(paddingChar) << std::setw(padding) << value;

		return stream.str();
	}

	std::string StringExtensions::wrapBySquare(const std::string& value)
	{
		return "[" + value + "]";
	}

	std::string StringExtensions::getTimestamp()
	{
		std::time_t rawtime = std::time(0);
		static char result[20];


#if defined (__linux__)	
		struct tm* timeinfo = std::localtime(&rawtime);
		strftime(result, sizeof(result), "%Y-%m-%d %H:%M:%S", timeinfo);
#elif defined(_WIN32)			
		struct tm timeinfo;
		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);
		strftime(result, sizeof(result), "%Y-%m-%d %H:%M:%S", &timeinfo);
#endif



		return result;
	}

	std::string  StringExtensions::trimStart(const std::string& value, const char trimChars[])
	{
		std::string result = value;
		result.erase(0, result.find_first_not_of(trimChars));
		return result;
	}

	std::string StringExtensions::trimEnd(const std::string& value, const char trimChars[])
	{
		std::string result = value;
		result.erase(result.find_last_not_of(trimChars) + 1);
		return result;
	}

	std::string StringExtensions::trim(const std::string& value, const char trimChars[])
	{
		std::string result = trimStart(value, trimChars);
		return trimEnd(result, trimChars);
	}

	std::string StringExtensions::toHex(const int value)
	{
		std::stringstream stream;
		stream << std::hex << value;

		return stream.str();
	}

	std::string StringExtensions::toString(const std::vector<char> chars)
	{
		std::stringstream stream;

		for (auto& c : chars)
		{
			if (c == '\0')
				continue;
			stream << c;
		}

		return stream.str();
	}

	bool StringExtensions::compareChar(unsigned char first, unsigned char second)
	{
		return std::tolower(first) == std::tolower(second);
	}
}