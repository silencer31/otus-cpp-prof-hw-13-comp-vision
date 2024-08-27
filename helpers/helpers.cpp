#include "helpers.h"

#include <fstream>
#include <sstream>

namespace Helpers
{

    bool read_model_string(std::istream& stream, std::vector<float>& coefficients)
    {
        std::string line;
        std::getline(stream, line);
        
        std::istringstream linestream{ line };
        float value;
        
        coefficients.clear();
        while (linestream >> value) {
            coefficients.push_back(value);
        }

        return stream.good();
    }

    bool read_csv_data_string(std::istream& stream, std::vector<float>& pixels, int& image_class)
    {
        std::string line;
        std::getline(stream, line);

        std::istringstream linestream{ line };
        
        // Читаем номер класса
        std::string class_str;
        std::getline(linestream, class_str, ',');
        image_class = std::stoi(class_str);

        // Читаем пиксели изображения.
        pixels.clear();
        for (std::string str; std::getline(linestream, str, ','); ) {
            pixels.push_back(static_cast<float>(std::stoi(str)));
        }

        return stream.good();
    }

} // namespace Helpers
