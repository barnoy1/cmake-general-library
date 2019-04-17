
#ifndef __FW_FIXTURE__
#define __FW_FIXTURE__

#include <iostream>
#include "gtest/gtest.h"

#include "general_lib.h"
#include "test_configuration.h"

// The fixture for testing class Project1. From google test primer.
class base_fixture : public ::testing::Test
{
	
	protected:

		base_fixture()
		{
			json j = configuration::get_instance()->get_json_config();

			// even easier with structured bindings (C++17)
			for (const auto&[key, value] : j.items()) {
				std::cout << key << " : " << value << "\n";
			}
		}

		virtual ~base_fixture()
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