
#include "common_fixture.h"

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(common_fixture, test_1) {

	time_t ts = obj_ptr->get_local_time();
	obj_ptr->work();
	const char *parsed_ts = obj_ptr->parse_local_time(ts);
	std::cout << "\n" << parsed_ts << "\n";
}
