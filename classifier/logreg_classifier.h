#pragma once

#include "interface_classifier.h"

/**
* @brief ����� ������������� ��� ������������� ���������.
*/
class LogregClassifier : public IBinaryClassifier
{
public:
    // �� ����� ���� ����� �������� ������� �� ����� ������������� ����� � ��� ���������� ������ ��-��
    // ������������� ������� std::inner_product
    using coefficients_vector = pixels_vector;

    LogregClassifier(const coefficients_vector& coefs);

    /**
    * ������� ������ ������ ��� ������ ������������� ������������� ��������� � ������ �������� ������ �����������.
    * @return ��������� �������.
    * @param pixels ��������� � ������� �������� �����������.
    */
    float predict_probability(const pixels_vector& pixels) const override;

protected:
    // ����� ������������� ������������� ���������
    coefficients_vector lg_coefficients;
};