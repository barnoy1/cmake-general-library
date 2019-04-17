
#ifndef __COMMON_FIXTURE__
#define __COMMON_FIXTURE__

#include "base_fixture.h"

// The fixture for testing class Project1. From google test primer.
class common_fixture : public ::base_fixture
{
protected:
	// You can remove any or all of the following functions if its body
	// is empty.
	
	core::properties properties = {};
	std::unique_ptr<core::general_lib> obj_ptr;
	
	common_fixture()
	{
		// You can do set-up work for each test here.
		json j = configuration::get_instance()->get_json_config();

		std::string s = j["size"];

		properties.file_name = s.c_str();
		properties.counter = 1;

		obj_ptr = std::make_unique<core::general_lib>(properties);
	}

	virtual ~common_fixture()
	{
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() 
	{
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() 
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

};

#endif // __COMMON_FIXTURE__