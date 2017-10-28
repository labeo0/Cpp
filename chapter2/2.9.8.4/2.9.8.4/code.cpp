#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
	double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
	double ArithmeticMean =0, HarmonicMean= 0, GeometricMean = 1, RootMeanSquare=0, temp=0;
	//arthimetic
	for(int i = 0; i < n; i++)
	{
		ArithmeticMean+=vector[i];
	}
	ArithmeticMean/=n;
	//harmonic
	for(int i = 0; i< n; i++)
	{
		temp+=1/vector[i];
	}
	HarmonicMean = n/temp;
	//Geom
	for(int i = 0; i < n; i++)
	{
		GeometricMean*=vector[i];
	}
	GeometricMean=pow(GeometricMean,1.0/(double)n);
	//rootmean
	for(int i = 0; i < n; i++)
	{
		RootMeanSquare+=vector[i]*vector[i];
	}
	RootMeanSquare=sqrt(RootMeanSquare/n);

	cout << "Arithmetic Mean = " << ArithmeticMean << endl;
	cout << "Harmonic Mean = " << HarmonicMean << endl;
	cout << "Geometric Mean = " << GeometricMean << endl;
	cout << "RootMean Square = " << RootMeanSquare << endl;

	system("pause");
	cout << endl;
	return 0;
}