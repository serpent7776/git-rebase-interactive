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

TEST_CASE("split splits on separator")
{
	const auto [ok, left, right] = str::split(':', "foo:bar");
	REQUIRE(ok);
	REQUIRE(left == "foo");
	REQUIRE(right == "bar");
}

TEST_CASE("split string with no right part")
{
	const auto [ok, left, right] = str::split(':', "1234:");
	REQUIRE(ok);
	REQUIRE(left == "1234");
	REQUIRE(right == "");
}

TEST_CASE("split string with no left part")
{
	const auto [ok, left, right] = str::split(':', ":7890");
	REQUIRE(ok);
	REQUIRE(left == "");
	REQUIRE(right == "7890");
}

TEST_CASE("split string with neither left nor right part")
{
	const auto [ok, left, right] = str::split(':', ":");
	REQUIRE(ok);
	REQUIRE(left == "");
	REQUIRE(right == "");
}

TEST_CASE("split string that does not contain separator")
{
	const auto [ok, left, right] = str::split(',', "foobar");
	REQUIRE(not ok);
	REQUIRE(left == "");
	REQUIRE(right == "");
}

TEST_CASE("split an empty string")
{
	const auto [ok, left, right] = str::split(',', "");
	REQUIRE(not ok);
	REQUIRE(left == "");
	REQUIRE(right == "");
}
