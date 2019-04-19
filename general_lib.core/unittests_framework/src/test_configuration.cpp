


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

void configuration::set_configuration_file(std::string)
{
	configuration::get_instance()->config_json = {};
	config_json["file_name"] = "file.txt";
	config_json["counter"] = 1;
}

const json configuration::get_json_config() const
{
	return config_json;
}
