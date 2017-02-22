// MyMachineLearning.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "MyMachineLearning.h"

extern "C" {

	double * UpdateModel(double* W, double alpha, double yk, double xk1, double xk2)
	{
		//biais
		W[0] = W[0] + alpha*yk*1;
		//X
		W[1] = W[1] + alpha*yk*xk1;
		//Y
		W[2] = W[2] + alpha*yk*xk2;
		
		return W;
	}


	double Classify(double pointsX, double pointsZ, double* W)
	{
		if ((pointsX * W[1]) + (pointsZ * W[2]) + W[0] < 0)
			return -1;
		else
			return 1;
	}

	double* PositionDepuisDroite(double pointsX, double pointsZ, double* W, double expect, double alpha)
	{
		bool ok = false;

		while (!ok)
		{
			if (Classify(pointsX, pointsZ, W) != expect)
			{
				W = Model(W, alpha, expect, pointsX, pointsZ);
			}
			else
			{
				ok = true;
			}
		}

		return W;
	}
}
