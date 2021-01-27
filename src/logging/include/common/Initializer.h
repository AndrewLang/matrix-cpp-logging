#pragma once

namespace Logging
{
	template<typename T>
	struct Initializer
	{
		T t;
		Initializer() : t() {}
	};
}