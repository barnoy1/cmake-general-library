
#ifndef __TEST_CONFIGURATION__
#define __TEST_CONFIGURATION__

#include <memory>
#include "json.hpp"

using json = nlohmann::json;

class configuration
{

public:
	
	// static access method.
	static std::unique_ptr<configuration>& get_instance();

	void set_configuration_file(json j);

	// const member function that return const json file
	const json get_json_config() const;

private:
	// here will be the instance stored.
	static std::unique_ptr<configuration> instance_;

	// private constructor to prevent instancing.
	configuration() {};

	json conf_file_;
};


#endif // !__TEST_CONFIGURATION__
