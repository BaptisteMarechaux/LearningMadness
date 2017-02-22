#pragma once

extern "C" {
	//model = calcul du W
	__declspec(dllimport) double* Model(double* W, double alpha, double yk, double xk1, double xk2);
	__declspec(dllimport) double Classify(double pointsX, double pointsZ, double* W);
	__declspec(dllimport) double* PositionDepuisDroite(double pointsX, double pointsZ, double* W, double expect, double alpha);

}