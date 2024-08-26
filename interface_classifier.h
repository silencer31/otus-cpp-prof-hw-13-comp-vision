#pragma once

#include <vector>

/**
* @brief Класс интерфейс классификатора объекта.
*/
class IBinaryClassifier
{
public:
    using features_type = std::vector<float>;

    virtual ~IBinaryClassifier() {}

    virtual float predict_probability(const features_type&) const = 0;
};