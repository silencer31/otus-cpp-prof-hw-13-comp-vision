#pragma once

#include "interface_classifier.h"

/**
* @brief Класс классификатор для логистической регрессии.
*/
class LogregClassifier : public IBinaryClassifier
{
public:
    // На самом деле набор пикселей состоит из целых положительных чисел и так приходится делать из-за
    // использования функции std::inner_product
    using coefficients_vector = pixels_vector;

    LogregClassifier(const coefficients_vector& coefs);

    /**
    * Функция делает расчет для набора коэффициентов логистической регрессии и набора пикселей одного изображения.
    * @return Результат расчета.
    * @param pixels Коллекция с набором пикселей изображения.
    */
    float predict_probability(const pixels_vector& pixels) const override;

protected:
    // Набор коэффициентов логистической регрессии
    coefficients_vector lg_coefficients;
};