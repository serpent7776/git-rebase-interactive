#include "lib.hpp"

#include "lib/catch.hpp"

TEST_CASE("variadic join works for 2 strings")
{
	const auto result = str::join(',', "foo", "bar");
	REQUIRE(result == "foo,bar");
}

TEST_CASE("variadic join works for 3 strings")
{
	const auto result = str::join(':', "foo", "bar", "baz");
	REQUIRE(result == "foo:bar:baz");
}
