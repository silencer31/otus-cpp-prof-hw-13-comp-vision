#include "helpers.h"

#include <fstream>
#include <sstream>

namespace Helpers
{

    bool read_coefs(std::istream& stream, std::vector<float>& coefs)
    {
        std::string line;
        std::getline(stream, line);
        
        std::istringstream linestream{ line };
        float value;
        
        coefs.clear();
        while (linestream >> value) {
            coefs.push_back(value);
        }

        return stream.good();
    }

    bool read_features(std::istream& stream, std::vector<float>& features, int& target_class)
    {
        std::string line;
        std::getline(stream, line);

        std::istringstream linestream{ line };
        bool first = true;

        features.clear();
        for (std::string str; std::getline(linestream, str, ','); ) {
            if (first) {
                first = false;
                target_class = std::stoi(str);
            }
            else {
                features.push_back(static_cast<float>(std::stoi(str)));
            }
        }

        return stream.good();
    }

} // namespace Helpers
