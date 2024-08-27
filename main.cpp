#include "options_reader/options_reader.h"
#include "model_analysis/model_analysis.h"

#include <boost/filesystem/operations.hpp>

#include <memory>
#include <iostream>

int main(int args_number, char const** args)
{
    // Объект для чтения параметров - аргументов программы.
    const std::unique_ptr<OptionsReader> opt_reader_ptr = std::make_unique<OptionsReader>();

    // Набор аргументов - параметров программы.
    const Parameters parameters = opt_reader_ptr->read_arguments(args_number, args);

    if (parameters.show_help) {
        std::cerr << parameters.help_text << std::endl;
        return 0;
    }

    // Проверяем, существует ли CSV файл с тестовыми данными.
    if (!boost::filesystem::exists(parameters.csv_path)) {
        std::cerr << "Provided CSV file doesn't exist! " << parameters.csv_path << std::endl;;
        return -1;
    }

    // Проверяем, не пустой ли CSV файл.
    if (boost::filesystem::is_empty(parameters.csv_path)) {
        std::cerr << "Provided CSV file is empty! " << parameters.csv_path << std::endl;;
        return -1;
    }

    // Проверяем, существует ли файл с моделью.
    if (!boost::filesystem::exists(parameters.model_path)) {
        std::cerr << "Provided model file doesn't exist! " << parameters.model_path << std::endl;;
        return -1;
    }

    // Проверяем, не пустой ли файл с моделью.
    if (boost::filesystem::is_empty(parameters.model_path)) {
        std::cerr << "Provided model file is empty! " << parameters.model_path << std::endl;;
        return -1;
    }

    std::cout << "CSV file: "   << parameters.csv_path << std::endl;
    std::cout << "Model file: " << parameters.model_path << std::endl;

    ModelAnalysis model_analysis(parameters.csv_path, parameters.model_path);
    model_analysis.read_model_data();
    model_analysis.calculate_accuracy();

    std::cout << "Accuracy: " << model_analysis.get_accuracy() << std::endl;

    return 0;
}
