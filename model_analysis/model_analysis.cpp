#include "model_analysis.h"

#include <fstream>
#include <iostream>

void ModelAnalysis::read_model_data()
{
    std::vector<float> coefficients;

    // Чтение коэффициентов скалярного произведения модели данных.
    std::ifstream model_coef_stream(model_path);

    // Чтение коэффициентов скалярного произведения
    while (true) {
        if (!Helpers::read_model_string(model_coef_stream, coefficients)) {
            break;
        }

        classifiers.emplace_back(LogregClassifier(coefficients));
    }

    model_coef_stream.close();
}


void ModelAnalysis::calculate_accuracy()
{
    std::cout << "Calculation started..." << std::endl;

    // Чтение данных из csv файла.
    std::ifstream csv_data_stream(csv_path);

    std::vector<float> image_pixels;

    int image_class;
    int total_count = 0;
    int right_answers_number = 0;
  
    while (true) {
        if (!Helpers::read_csv_data_string(csv_data_stream, image_pixels, image_class)) {
            break;
        }
        
        total_count++;

        float max_result = -1;
        size_t max_result_class = 0;
       
        for (size_t i = 0; i < classifiers.size(); i++)
        {
            auto result = classifiers[i].predict_probability(image_pixels);
            
            // Сравниваем полученный результат с имеющимся максимальным.
            if (result > max_result) {
                max_result = result;
                max_result_class = i;
            }
        }

        if (max_result_class == static_cast<size_t>(image_class)) {
            right_answers_number++;
        }
    }

    if (total_count > 0) {
        accuracy = float(right_answers_number) / total_count;
    }

    std::cout << "Calculation finished" << std::endl;
}