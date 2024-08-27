#include "options_reader/options_reader.h"
#include "model_analysis/model_analysis.h"

#include <boost/filesystem/operations.hpp>

#include <memory>
#include <iostream>

int main(int args_number, char const** args)
{
    // ������ ��� ������ ���������� - ���������� ���������.
    const std::unique_ptr<OptionsReader> opt_reader_ptr = std::make_unique<OptionsReader>();

    // ����� ���������� - ���������� ���������.
    const Parameters parameters = opt_reader_ptr->read_arguments(args_number, args);

    if (parameters.show_help) {
        std::cerr << parameters.help_text << std::endl;
        return 0;
    }

    // ���������, ���������� �� CSV ���� � ��������� �������.
    if (!boost::filesystem::exists(parameters.csv_path)) {
        std::cerr << "Provided file doesn't exist! " << parameters.csv_path << std::endl;;
        return -1;
    }

    // ���������, �� ������ �� CSV ����.
    if (boost::filesystem::is_empty(parameters.csv_path)) {
        std::cerr << "Provided file is empty! " << parameters.csv_path << std::endl;;
        return -1;
    }

    // ���������, ���������� �� ���� � �������.
    if (!boost::filesystem::exists(parameters.model_path)) {
        std::cerr << "Provided file doesn't exist! " << parameters.model_path << std::endl;;
        return -1;
    }

    // ���������, �� ������ �� ���� � �������.
    if (boost::filesystem::is_empty(parameters.model_path)) {
        std::cerr << "Provided file is empty! " << parameters.model_path << std::endl;;
        return -1;
    }

    ModelAnalysis model_analysis(parameters.csv_path, parameters.model_path);
    model_analysis.read_model_data();
    model_analysis.calculate_accuracy();

    std::cout << model_analysis.get_accuracy() << std::endl;

    return 0;
}
