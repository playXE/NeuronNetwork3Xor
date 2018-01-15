#include <iostream>
#include <cmath>
#include "neuron.h"

using namespace std;

class Siec {
public:
	// Konstruktor
	Siec();

	// Destruktor
	~Siec();

	// Funkcja uczaca neuron
	double learn(const double* array, double answer);

	// Obliczanie wartosci dla danych testowych
	double count(const double* array);

private:
	// Neurony
	Neuron n1;
	Neuron n2;
	Neuron n3;
};
