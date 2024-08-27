#pragma once

#include <vector>

/**
* @brief Класс интерфейс классификатора объекта.
*/
class IBinaryClassifier
{
public:
    using pixels_vector = std::vector<float>;

    virtual ~IBinaryClassifier() {}

    virtual float predict_probability(const pixels_vector&) const = 0;
};