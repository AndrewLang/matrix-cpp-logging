#include "common/Guard.h"
#include "common/StringExtensions.h"

namespace Logging
{
	using std::string;


	void Guard::notEmpty(const string & value, const string& name)
	{
		if (StringExtensions::isNullOrEmpty(value))
			throw ArgumentNullException(name);
	}
}