#pragma once

#include <algorithm>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>

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

inline std::tuple<bool, std::string_view, std::string_view> split(char sep, std::string_view str)
{
	const auto first = std::begin(str);
	const auto last = std::end(str);
	const auto middle = std::find(first, last, sep);
	if (middle == std::end(str))
	{
		return {false, {}, {}};
	}
	return std::tuple(true, std::string_view(first, middle), std::string_view(middle + 1, last));
}

}
