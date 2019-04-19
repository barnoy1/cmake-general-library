
#include <iostream>
#include <fstream>

#include "gtest/gtest.h"
#include "json_fixture.h"
#include "test_configuration.h"


int main(int argc, char **argv) {
  std::cout << "Executing tests\n";
  
  testing::InitGoogleTest(&argc, argv);

 
  
  json j;
  j["file_name"] = "data.txt";
  j["counter"] = 1;

  configuration::get_instance()->set_configuration_file(j);  
  return RUN_ALL_TESTS();
}
