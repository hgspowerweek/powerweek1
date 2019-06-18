#include <iostream>
#include <boost/bind.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

void show_help(po::options_description desc)
{
  std::cout << "Hope it helps:" << std::endl;
  std::cout << desc;
}

int main(int argc, const char **argv) {
  // Declare the supported options.
  po::options_description desc("Allowed options");
  desc.add_options()
      ("help", "produce help message")
      ("compression", po::value<int>(), "set compression level")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
      std::cout << desc << "\n";
      return 1;
  }

  if (vm.count("compression")) {
      std::cout << "Compression level was set to "
   << vm["compression"].as<int>() << ".\n";
  } else {
      std::cout << "Compression level was not set.\n";
  }
}
