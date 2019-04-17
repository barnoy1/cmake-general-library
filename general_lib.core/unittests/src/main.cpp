
#include <iostream>
#include <fstream>

#include "gtest/gtest.h"
#include "general_lib.h"
#include "base_fixture.h"
#include "test_configuration.h"


int main(int argc, char **argv) {
  std::cout << "Executing tests\n";
  
  testing::InitGoogleTest(&argc, argv);

  std::string path = "D:/Repo/cmake-general-library/build/bin/Debug/example.json";

  std::ifstream input_file(path.c_str());
  
  json j;
  input_file >> j;

  configuration::get_instance()->set_configuration_file(j);  
  return RUN_ALL_TESTS();
}
