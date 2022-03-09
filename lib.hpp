#pragma once

#include <algorithm>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include <optional>
#include <numeric>

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
	return std::tuple(true, std::string_view(first, middle - first), std::string_view(middle + 1, last - (middle + 1)));
}

inline std::optional<int> atoi(std::string_view s)
{
	int sign = 1;
	auto it = std::begin(s);
	if (*it == '-')
	{
		sign = -1;
		++it;
	}
	const auto e = s.find_first_not_of("0123456789", std::distance(std::begin(s), it));
	if (e != std::string_view::npos)
	{
		return std::nullopt;
	}
	return sign * std::accumulate(it, std::end(s), 0, [](int r, char c){
		return 10*r + (c - '0');
	});
}

}

