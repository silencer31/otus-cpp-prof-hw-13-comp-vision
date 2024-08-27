#include "logreg_classifier.h"

#include <cassert>
#include <cmath>
#include <numeric>
#include <stdexcept>

namespace
{

    template<typename T>
    auto sigma(T x)
    {
        return 1 / (1 + std::exp(-x));
    }

}

LogregClassifier::LogregClassifier(const coefs_type& coef)
    : m_coef(coef)
{
    assert(!m_coef.empty());
}

float LogregClassifier::predict_probability(const features_type& feat) const
{
    if (feat.size() + 1 != m_coef.size()) {
        throw std::runtime_error("Feature vector size mismatch");
    }

    auto z = std::inner_product(feat.begin(), feat.end(), ++m_coef.begin(), m_coef.front());
    
    return sigma(z);
}
