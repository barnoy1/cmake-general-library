


#include "test_configuration.h"

// Global static pointer used to ensure a single instance of the class.
std::unique_ptr<configuration> configuration::instance_ = nullptr;


std::unique_ptr<configuration>& configuration::get_instance()
{
	if (instance_ == nullptr)
	{
		instance_ = std::unique_ptr<configuration>(new configuration());
	}

	return instance_;
}

void configuration::set_configuration_file(json j)
{
	conf_file_ = j;
}

const json configuration::get_json_config() const
{
	return conf_file_;
}
