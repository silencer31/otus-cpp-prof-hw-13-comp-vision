#include <istream>
#include <vector>

namespace Helpers
{
    /**
    * @brief Чтение коэффициентов логистической регрессии.
    * @return Удалось ли прочитать
    * @param stream Поток чтения файла с коэффициентами
    * @param coefs Коллекция для коэффициентов
    */
	bool read_coefs(std::istream& stream, std::vector<float>& coefs);
	
	
	bool read_features(std::istream& stream, std::vector<float>& features, int& targetClass);

} // namespace Helpers