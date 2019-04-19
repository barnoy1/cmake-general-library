
#ifndef __FW_FIXTURE__
#define __FW_FIXTURE__

#include <iostream>
#include "gtest/gtest.h"

#include "test_configuration.h"

// The fixture for testing class Project1. From goggle test primer.
class json_fixture : public ::testing::Test
{
	
	protected:

		json_fixture()
		{
			json j = configuration::get_instance()->get_json_config();

			// needed to compile with (C++17)
			for (const auto&[key, value] : j.items()) {
				std::cout << key << " : " << value << "\n";
			}

		}

		virtual ~json_fixture()
		{
	
		}


		virtual void SetUp()
		{
	
		}

		virtual void TearDown()
		{
	
		}

};

#endif // __FW_FIXTURE__