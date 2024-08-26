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
* @brief Класс реализует чтение параметров программы.
*/
class OptionsReader {
public:

    /**
    * @brief Прочитать аргументы, с которыми была запущена программа.
    * @param argc кол-во аргументов.
    * @param argv аргуметны.
    * @return Структура с прочитанными параметрами.
    */
    Parameters read_arguments(int argc, const char* argv[]);
};