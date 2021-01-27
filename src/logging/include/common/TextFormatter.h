#pragma once

#include "Consts.h"

#include <sstream>


namespace Logging
{	
	class TextFormatter
	{
	public:
		
		TextFormatter(const std::string& separatorString = Consts::Space);
		
		template< typename TKey >
		std::string format(const TKey& text)
		{
			std::stringstream stream;
			stream << text << mSeparator;
			return stream.str();
		}

		template< typename TKey, typename ... Args >
		std::string format(const TKey& first, Args ... args)
		{
			return format(first) + format(args...);
		}
		
	private:
		std::string mSeparator = Consts::Space;
	};
}