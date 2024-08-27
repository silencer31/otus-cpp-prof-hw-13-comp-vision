#include <istream>
#include <vector>

namespace Helpers
{
    /**
    * @brief ������ ����� ������ ������ - ������������� ���������� ������������.
    * @return ���� �� ��� ������ ��� ������
    * @param stream ����� ������ ����� � ��������������
    * @param coefs ��������� ��� �������������
    */
	bool read_model_string(std::istream& stream, std::vector<float>& coefficients);
	
    /**
    * @brief ������ ����� ������ �������� ������ - ������ �������� �����������.
    * @return ���� �� ��� ������ ��� ������
    * @param stream ����� ������ ����� � ��������� �������
    * @param pixels ��������� ��� �������� �����������
    * @param image_class ����� ������ �����������
    */
	bool read_csv_data_string(std::istream& stream, std::vector<float>& pixels, int& image_class);

} // namespace Helpers