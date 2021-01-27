#pragma once
#include "ArgumentNullException.h"

namespace Logging
{
	class Guard
	{
	public:
		template<typename TKey>
		static void notNull(TKey arg, const std::string& name);

		static void notEmpty(const std::string& value, const std::string& name);
	};

	template<typename TKey>
	inline void Guard::notNull(TKey arg, const std::string& name)
	{	
		if(arg == NULL)
			throw ArgumentNullException(name);
	}
}
