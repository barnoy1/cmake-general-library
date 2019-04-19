
#include <iostream>
#include <fstream>

#include "gtest/gtest.h"
#include "json_fixture.h"
#include "test_configuration.h"


int main(int argc, char **argv) {
  std::cout << "Executing tests\n";
  
  testing::InitGoogleTest(&argc, argv);
  configuration::get_instance()->set_configuration_file("path/to/json");  
  return RUN_ALL_TESTS();
}
