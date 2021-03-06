#include "Learning.h"

int SimpleAdd(int a, int b)
{
	return 0;
}

double * CreateModel(int size)
{
	double * model = new double[size];
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
	///Fonction servant a obtenir un mod�le
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
	//double* res;
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

void LinearRegression(double ** inputs, int inputDimension, int inputSize, double * expects, double* W)
{
	Eigen::MatrixXd positionMatrix(inputSize, inputDimension + 1);
	for (int i = 0; i < inputSize; ++i)
	{
		positionMatrix(i, 0) = 1.0;
		for (int j = 0; j < inputDimension; ++j)
		{
			positionMatrix(i, j + 1) = inputs[i][j];
		}
	}
	Eigen::MatrixXd expectedMatrix(inputSize, 1 + 1);
	for (int i = 0; i < inputSize; ++i)
	{
		expectedMatrix(0) = 1.0;
		expectedMatrix(i) = expects[i];
	}

	Eigen::MatrixXd transformed = positionMatrix.transpose() * expectedMatrix;
	
	auto tmp = (transformed.inverse() * expectedMatrix.transpose())*expectedMatrix;
	for (int i = 0; i < 3; i++)
	{
		//W[i] = tmp[i];
	}
	
}

double randomNumber(double a, double b)
{
	srand(time(NULL));

	return (rand() / (double)RAND_MAX) * (b - a) + a;
	//return (b - a) * ((double)rand() / (double)RAND_MAX) + a;
}
