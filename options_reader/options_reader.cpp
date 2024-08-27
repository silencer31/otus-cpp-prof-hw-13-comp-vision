#include "options_reader.h"

#include <boost/program_options.hpp>
#include <boost/any.hpp>
#include <iostream>

using namespace std;
namespace po = boost::program_options;

Parameters OptionsReader::read_arguments(int argc, const char* argv[])
{
    po::options_description desc("MapReduce app. Parameters");

    desc.add_options()
        ("help,h", "Outputs help information")
        ("csv,c",
            po::value<string>()->default_value("test.csv"),
            "Path to file with csv data.")
        ("model,m",
            po::value<string>()->default_value("logreg_coef.txt"),
            "Path to file with model coef.")
        ;
    
    po::variables_map vm;
    
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    }
    catch (const std::exception& e) {
        std::cerr << "Unable to parse parameters: " << e.what() << std::endl;
    }
    
    notify(vm);
    
    stringstream help;
    help << desc << endl;

    Parameters parameters;

    parameters.help_text = help.str();
    parameters.show_help = vm.count("help");
    
    if (parameters.show_help) {
        return parameters;
    }
    
    // Путь к файлу.
    parameters.csv_path = vm["csv"].as<string>();
    
    // Количество потоков для работы отображения.
    parameters.model_path = vm["model"].as<string>();
    
    return parameters;
}