#include <istream>
#include <vector>

namespace Helpers
{
    /**
    * @brief ������ ������������� ������������� ���������.
    * @return ������� �� ���������
    * @param stream ����� ������ ����� � ��������������
    * @param coefs ��������� ��� �������������
    */
	bool read_coefs(std::istream& stream, std::vector<float>& coefs);
	
	
	bool read_features(std::istream& stream, std::vector<float>& features, int& targetClass);

} // namespace Helpers