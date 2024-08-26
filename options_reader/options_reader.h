#pragma once

#include <string>

struct Parameters
{
    std::string csv_path;
    std::string model_path;

    bool show_help{ false };
    std::string help_text;
};

/**
* @brief ����� ��������� ������ ���������� ���������.
*/
class OptionsReader {
public:

    /**
    * @brief ��������� ���������, � �������� ���� �������� ���������.
    * @param argc ���-�� ����������.
    * @param argv ���������.
    * @return ��������� � ������������ �����������.
    */
    Parameters read_arguments(int argc, const char* argv[]);
};