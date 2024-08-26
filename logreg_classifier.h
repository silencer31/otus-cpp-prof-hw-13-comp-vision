#pragma once

#include "interface_classifier.h"

class LogregClassifier : public IBinaryClassifier
{
public:
    using coefs_type = features_type;

    LogregClassifier(const coefs_type& coef);

    float predict_probability(const features_type& feat) const override;

protected:
    coefs_type m_coef;
};