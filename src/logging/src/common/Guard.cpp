#include "common/Guard.h"
#include "common/StringExtensions.h"

namespace Logging
{
	using std::string;


	void Guard::notEmpty(const string & value, const string& name)
	{
		if (Strings::isNullOrEmpty(value))
			throw ArgumentNullException(name);
	}
}