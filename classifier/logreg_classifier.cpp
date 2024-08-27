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

LogregClassifier::LogregClassifier(const coefficients_vector& coefs)
    : lg_coefficients(coefs)
{
    assert(!lg_coefficients.empty());
}

float LogregClassifier::predict_probability(const pixels_vector& pixels) const
{
    if (pixels.size() + 1 != lg_coefficients.size()) {
        return -1;
    }

    auto z = std::inner_product(pixels.begin(), pixels.end(), ++lg_coefficients.begin(), lg_coefficients.front());
    
    return sigma(z);
}
