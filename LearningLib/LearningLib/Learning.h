#pragma once
#include <Eigen\Dense>
#include <cmath>
#include <time.h>

extern "C" {
	__declspec(dllexport) int SimpleAdd(int a, int b);

	__declspec(dllexport) double* CreateModel();

	__declspec(dllexport) void ComputeModel(double* model, double cX, double cY, double expected, double step);

	__declspec(dllexport) double LinearEstimation(double cX, double cY, double * model);

	//__declspec(dllexport) double* LinearClassification(double cX, double cY, double * model, double expected);

	__declspec(dllexport) double* LinearSearch(double * model, double * inputs, int inputSize, double * expected, int expectedSize, double step, int maxLoops);

	__declspec(dllexport) double* LinearClassification(double* inputs, int inputSize, double* model, int maxIterations);

	__declspec(dllexport) double* RosenblattModel(double* model, double cX, double cY, double expected, double step);

	__declspec(dllexport) void LinearRegression(double ** inputs, int inputSize, double ** expects, double* W);

	double randomNumber(double a, double b);

	bool arrayCompare(double* a, int sizeA,  double* b, int sizeB);
}
