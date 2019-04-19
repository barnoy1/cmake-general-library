
#ifndef __TEST_CONFIGURATION__
#define __TEST_CONFIGURATION__

#include <memory>
#include "json.hpp"

#include "unittests_framework_EXPORT.h"

using json = nlohmann::json;


// enable C / C++ linkage
#ifdef __cplusplus
extern "C" {
#endif


class UNITTESTS_FRAMEWORK_EXPORT configuration
{

public:
	
	// static access method.
	static std::unique_ptr<configuration>& get_instance();
	json config_json;

	void set_configuration_file(std::string);

	// const member function that return const json file
	const json get_json_config() const;

private:
	// here will be the instance stored.
	static std::unique_ptr<configuration> instance_;

	// private constructor to prevent instancing.
	configuration() {};
};


#ifdef __cplusplus
}
#endif


#endif // !__TEST_CONFIGURATION__
