#include "Learning.h"

int SimpleAdd(int a, int b)
{
	return 0;
}

double * CreateModel(int size)
{

	double model[size];
	for (int k = 0; k<size; k++)
		model[k] = randomNumber(0, 1) * (randomNumber(0, 1) > 0.5 ? 1 : -1);

	return model;
}

void ComputeModel(double * model, double cX, double cY, double expected, double step)
{
	model[0] += step*expected;
	model[1] += step*expected*cX;
	model[2] += step*expected*cY;
}

double LinearEstimation(double cX, double cY, double * model)
{
	return (cX * model[1] + cY * model[2] + model[0]) < 0 ? -1 : 1;
}

double linear_regression(double * model, double *input, int inputSize)
{
	double biai = model[0];
	for (int i = 0, j = 1; i < inputSize; i++, j++)
	{
		biai += model[j] * input[i];
	}
	
	return biai;
}

double * LinearSearch(double * model, double * inputs, int inputSize, double * expected, int expectedSize, double step, int maxLoops)
{
	///Fonction servant a obtenir un modèle
	int k = 0;
	for (int a=0;a < maxLoops; a++)
	{
		k = 0;
		for (int i = 0; i < inputSize; i+=2)
		{
			if (LinearEstimation(inputs[i], inputs[i + 1], model) != expected[k])
			{
				ComputeModel(model, inputs[i], inputs[i + 1], expected[k], step);
			}
			k++;
		}
	}
	return model;
}

double * LinearClassification(double * inputs, int inputSize, double * model, int maxIterations)
{
	double* res;
	for (int i = 0; i < inputSize; i+=2)
	{
		//inputs[i];
		if (LinearEstimation(inputs[i], inputs[i + 1], model) < 1)
		{
			//Ajouter le resultat au tableau de retour
		}
		else
		{

		}
	}
	return model;
}

double * RosenblattModel(double * model, double cX, double cY, double expected, double step)
{
	return nullptr;
}

void LinearRegression(double ** inputs, double ** expects, double* W)
{
	Eigen::Matrix4d X;
	Eigen::Matrix4d Y;
	
	double* tmp = ((X.transpose * X).inverse * X.transpose)*Y;
	for (int i = 0; i < 3; i++)
	{
		W[i] = tmp[i];
	}
	
}

double randomNumber(double a, double b)
{
	srand(time(NULL));

	return (rand() / (double)RAND_MAX) * (b - a) + a;
	//return (b - a) * ((double)rand() / (double)RAND_MAX) + a;
}
