#include "helpers.h"
#include "logreg_classifier.h"
#include "options_reader/options_reader.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <boost/filesystem/operations.hpp>

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

    // Проверяем, существует ли файл CSV
    if (!boost::filesystem::exists(parameters.csv_path)) {
        std::cerr << "Provided file doesn't exist! " << parameters.csv_path << std::endl;;
        return -1;
    }

    // Проверяем, не пустой ли CSV файл.
    if (boost::filesystem::is_empty(parameters.csv_path)) {
        std::cerr << "Provided file is empty! " << parameters.csv_path << std::endl;;
        return -1;
    }

    // Проверяем, существует ли файл Model
    if (!boost::filesystem::exists(parameters.model_path)) {
        std::cerr << "Provided file doesn't exist! " << parameters.model_path << std::endl;;
        return -1;
    }

    // Проверяем, не пустой ли Model файл.
    if (boost::filesystem::is_empty(parameters.model_path)) {
        std::cerr << "Provided file is empty! " << parameters.model_path << std::endl;;
        return -1;
    }

    std::vector<LogregClassifier> classifiers;
    LogregClassifier::coefs_type coefs;

    std::ifstream model_coef_stream(parameters.model_path);
    
    while (true) {
        if (!Helpers::read_coefs(model_coef_stream, coefs)) {
            break;
        }

        classifiers.emplace_back(LogregClassifier(coefs));
    }

    model_coef_stream.close();

    std::ifstream dataInput(parameters.csv_path);

    LogregClassifier::features_type features;
    
    int targetClass;
    int totalCount = 0;
    int rightAnswersCount = 0;

    while (true) {
        if (!Helpers::read_features(dataInput, features, targetClass)) {
            break;
        }

        totalCount++;

        float maxResult = -1;
        size_t maxResultClass = 0;

        for (size_t i = 0; i < classifiers.size(); i++)
        {
            auto result = classifiers[i].predict_probability(features);
            if (result > maxResult)
            {
                maxResult = result;
                maxResultClass = i;
            }
        }

        if (maxResultClass == targetClass)
            rightAnswersCount++;
    }

    float accuracy = 0;
    if (totalCount > 0)
    {
        accuracy = float(rightAnswersCount) / totalCount;
    }

    std::cout << accuracy << std::endl;

    return 0;
}
