
#define BOOST_TEST_MAIN test_main
#include <boost/test/included/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include "cube.cpp"

namespace {
	using sakura::cube;
	using namespace boost::unit_test;
	BOOST_AUTO_TEST_CASE(test_cube) { // test case name
		BOOST_CHECK(cube(2) == 8); // basic check, place expected right of ==
		// throw errors on purpuise // DONT DO THIS IN REAL PROJECT
		BOOST_CHECK_EQUAL(cube(1), 2); // wrong
		BOOST_WARN_EQUAL(cube(0), 2);
		//BOOST_REQUIRE_EQUALS(cube(0, 2);
		BOOST_CHECK_LT(cube(5), 5);
		BOOST_CHECK_CLOSE(3.00000000001, 3.0, 0.01); // DANGEROUS, WATCH OUT FOR FLOAT!

	}
}
