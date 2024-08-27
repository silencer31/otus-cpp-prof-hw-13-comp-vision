#pragma once

#include "../helpers/helpers.h"
#include "../classifier/logreg_classifier.h"

/// @brief ����� ��������� ������ ������ ������������� ���������.
class ModelAnalysis
{
public:
	ModelAnalysis() = delete;

	/**
	* @brief �����������.
	* @param csvp ���� � CSV ����� � ��������� �������.
	* @param mdlp ���� � ����� � �������.
	*/
	explicit ModelAnalysis(const std::string& csvp, const std::string& mdlp)
		: csv_path(csvp), model_path(mdlp)
	{}

	/**
	* @return ������ ���� ���������� �������.
	*/
	float get_accuracy() const { return accuracy; }
	
	/**
	* @brief ��������� ������ ������.
	*/
	void read_model_data();

	/**
	* @brief ��������� ������ CSV ����� � ���������� ������ ���� ���������� �������.
	*/
	void calculate_accuracy();

private: // Data
	const std::string csv_path;
	const std::string model_path;

	// ���� ���������� �������.
	float accuracy{ 0 };

	// ��������� � ������� ������.
	std::vector<LogregClassifier> classifiers;

	
};