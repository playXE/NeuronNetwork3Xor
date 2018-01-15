#include "siec.h"

// Konstruktor
Siec::Siec()
{
}

// Destruktor
Siec::~Siec()
{
}

// Funkcja uczaca siec
double Siec::learn(const double* array, double answer) 
{
	// Obliczam sygnal wyjscia sieci
	double y_1_1 = n1.count(array[0], array[1], array[2]);
	double y_1_2 = n2.count(array[0], array[1], array[2]);
	double y_2_1 = n3.count(array[0], y_1_1, y_1_2);

	// Obliczanie sygnalow bledu
	double sigma_2_1 = (answer - y_2_1) * (y_2_1 * (1.0 - y_2_1));
	double sigma_1_1 = sigma_2_1 * n3.getW1() * (y_1_1 * (1.0 - y_1_1));
	double sigma_1_2 = sigma_2_1 * n3.getW2() * (y_1_2 * (1.0 - y_1_2));

	// Uaktualnienie wag (neuron 1 warstwa 1)
	n1.updateW0(0.4 * sigma_1_1 * array[0]);
	n1.updateW1(0.4 * sigma_1_1 * array[1]);
	n1.updateW2(0.4 * sigma_1_1 * array[2]);

	// Uaktualnienie wag (neuron 2 warstwa 1)
	n2.updateW0(0.4 * sigma_1_2 * array[0]);
	n2.updateW1(0.4 * sigma_1_2 * array[1]);
	n2.updateW2(0.4 * sigma_1_2 * array[2]);

	// Uaktualnienie wag (neuron 1 warstwa 2)
	n3.updateW0(0.4 * sigma_2_1 * array[0]);
	n3.updateW1(0.4 * sigma_2_1 * array[1]);
	n3.updateW2(0.4 * sigma_2_1 * array[2]);

	// Obliczam i zwracam E(w)
	return 0.5 * (answer - y_2_1) * (answer - y_2_1);
}

// Obliczanie wartosci dla danych testowych
double Siec::count(const double* array)
{
	return n3.count(array[0], n1.count(array[0], array[1], array[2]), n2.count(array[0], array[1], array[2]));
}
