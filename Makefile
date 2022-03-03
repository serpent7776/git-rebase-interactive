CXXFLAGS += -std=c++20 -O2 -Wall -Wextra -pedantic

run_tests: test
	./test

test: tests.o tests_main.o
	${CXX} ${LDFLAFS} -o $@ $>

tests.o: lib.hpp
