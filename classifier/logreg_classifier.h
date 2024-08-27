#pragma once

#include "interface_classifier.h"

/**
* @brief Класс классификатор для логистической регрессии.
*/
class LogregClassifier : public IBinaryClassifier
{
public:
    using coefs_type = features_type;

    LogregClassifier(const coefs_type& coef);

    /**
    * 
    * @return 
    * @param feat 
    */
    float predict_probability(const features_type& feat) const override;

protected:
    coefs_type m_coef;
};