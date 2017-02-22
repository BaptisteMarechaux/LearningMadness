#include "Learning.h"

int SimpleAdd(int a, int b)
{
	return 0;
}

double * ComputeModel(double * model, double cX, double cY, double expected, double step)
{
	model[0] += step*expected;
	model[1] += step*expected*cX;
	model[2] += step*expected*cY;

	return model;
}

double LinearEstimation(double cX, double cY, double * model)
{
	
	return (cX * model[1] + cY * model[2] + model[0]) < 0 ? -1 : 1;
}

bool arrayCompare(double * a, int sizeA, double * b, int sizeB)
{
	return false;
}

double * LinearClassification(double cX, double cY, double * model, double expected)
{
	bool ok = false;

	while (!ok)
	{
		if (LinearEstimation(cX, cY, model) !=  expected)
		{
			model = ComputeModel(model, cX, cY, expected, 0.1);
		}
		else
		{
			ok = true;
		}
	}

	return model;
}

double * linearSearch(double * model, double * inputs, int inputSize, double * expected, int expectedSize, double step, int maxLoops)
{
	for (int a=0;a < maxLoops; a++)
	{
		
	}
	return nullptr;
}

double * linearSearch(double * model, double * inputs, int inputSize, double * expected, int expectedSize, double step)
{
	return nullptr;
}

double * LinearClassification(double * inputs, int inputSize, double * model)
{
	double* res;
	for (int i = 0; i < inputSize; i+=2)
	{
		//inputs[i];
		if (LinearEstimation(inputs[i], inputs[i + 1], model))
		{
			//Ajouter le resultat au tableau de retour
		}
	}
	return res;
}

double * RosenblattModel(double * model, double cX, double cY, double expected, double step)
{
	return nullptr;
}

double * LinearRegression()
{
	Eigen::Matrix4d W;
	Eigen::Matrix4d X;
	Eigen::Matrix4d Y;
	//W = ((X.transpose * X).inverse * X.transpose)*Y;

	return nullptr;
}
