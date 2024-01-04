#include <iostream>

#include <boost/program_options.hpp>

#include "cc/my_lib/my_lib.hpp"

int main(int argc, char *argv[]) {
  using namespace boost::program_options;

  options_description desc{"Options"};
  desc.add_options()("help,h", "Help")("value", value<int>()->default_value(21),
                                       "Value to print");

  variables_map vm;
  store(parse_command_line(argc, argv, desc), vm);
  notify(vm);

  if (vm.count("help")) {
    std::cout << desc << std::endl;
    return -1;
  }

  const auto value = vm["value"].as<int>();

  std::cout << value << "*2: " << add(value, value) << std::endl;

  return EXIT_SUCCESS;
}
