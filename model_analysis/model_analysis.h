#pragma once

#include "../helpers/helpers.h"
#include "../classifier/logreg_classifier.h"

/// @brief Класс реализует анализ модели логистической регрессии.
class ModelAnalysis
{
public:
	ModelAnalysis() = delete;

	/**
	* @brief Конструктор.
	* @param csvp Путь к CSV файлу с тестовыми данными.
	* @param mdlp Путь к файлу с моделью.
	*/
	explicit ModelAnalysis(const std::string& csvp, const std::string& mdlp)
		: csv_path(csvp), model_path(mdlp)
	{}

	/**
	* @return Узнать долю правильных ответов.
	*/
	float get_accuracy() const { return accuracy; }
	
	/**
	* @brief Прочитать данные модели.
	*/
	void read_model_data();

	/**
	* @brief Прочитать данные CSV файла и произвести расчет доли правильных ответов.
	*/
	void calculate_accuracy();

private: // Data
	const std::string csv_path;
	const std::string model_path;

	// Доля правильных ответов.
	float accuracy{ 0 };

	// Коллекция с данными модели.
	std::vector<LogregClassifier> classifiers;

	
};