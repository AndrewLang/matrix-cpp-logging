#include "common/FileLoadException.h"

namespace Logging
{
	using std::string;

	FileLoadException::FileLoadException(const string fileName)
		: mFileName(fileName)
	{
	}

	string FileLoadException::buildMessage() const
	{
		TextFormatter formatter;
		return formatter.format("Load file '", mFileName, "' failed.");
	}
}