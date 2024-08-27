#include <istream>
#include <vector>

namespace Helpers
{
    /**
    * @brief Чтение одной строки модели - коэффициентов скалярного произведения.
    * @return Есть ли ещё данные для чтения
    * @param stream Поток чтения файла с коэффициентами
    * @param coefs Коллекция для коэффициентов
    */
	bool read_model_string(std::istream& stream, std::vector<float>& coefficients);
	
    /**
    * @brief Чтение одной строки тестовых данных - наборы пикселей изображений.
    * @return Есть ли ещё данные для чтения
    * @param stream Поток чтения файла с тестовыми данными
    * @param pixels Коллекция для пикселей изображения
    * @param image_class номер класса изображения
    */
	bool read_csv_data_string(std::istream& stream, std::vector<float>& pixels, int& image_class);

} // namespace Helpers