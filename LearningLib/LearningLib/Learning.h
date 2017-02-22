#pragma once
#include <Eigen\Dense>
#include <cmath>

extern "C" {
	__declspec(dllexport) int SimpleAdd(int a, int b);

	__declspec(dllexport) double* CreateModel();

	__declspec(dllexport) double* ComputeModel(double* model, double cX, double cY, double expected, double step);

	__declspec(dllexport) double LinearEstimation(double cX, double cY, double * model);

	//__declspec(dllexport) double* LinearClassification(double cX, double cY, double * model, double expected);

	__declspec(dllexport) double* linearSearch(double* model, double* inputs, int inputSize, double* expected, int expectedSize, double step);

	__declspec(dllexport) double* LinearClassification(double* inputs, int inputSize, double* model);

	__declspec(dllexport) double* RosenblattModel(double* model, double cX, double cY, double expected, double step);

	__declspec(dllexport) double* LinearRegression();

	double randomNumber(double a, double b);

	bool arrayCompare(double* a, int sizeA,  double* b, int sizeB);
}
