#pragma once

#include <string>
#include <string_view>

namespace str
{

inline std::string to_string(const char* s)
{
	return std::string(s);
}

template <typename String, typename ...Strings>
std::string join(char sep, String&& head, Strings&& ...rest)
{
	using std::to_string;
	using str::to_string;
	std::string result = to_string(head);
	(result.append(sep + to_string(rest)), ...);
	return result;
}

}
