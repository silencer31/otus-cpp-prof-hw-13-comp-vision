#pragma once

#include "interface_classifier.h"

/**
* @brief Класс классификатор для логистической регрессии.
*/
class LogregClassifier : public IBinaryClassifier
{
public:
    // Тип для коэффициентов логистической регрессии.
    using coefficients_vector = pixels_vector;

    LogregClassifier(const coefficients_vector& coefs);

    /**
    * 
    * @return 
    * @param feat 
    */
    float predict_probability(const pixels_vector& pixels) const override;

protected:
    coefficients_vector lg_coefficients;
};