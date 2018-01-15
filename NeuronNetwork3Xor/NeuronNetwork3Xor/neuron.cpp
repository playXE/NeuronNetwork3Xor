#include "neuron.h"

Neuron::Neuron()
{
	//Jeden to 1, 0 to -1;
	w0 = ((rand() % 10000) * ((rand() & 1) ? 1 : -1)) / 10000.0;
	w1 = ((rand() % 10000) * ((rand() & 1) ? 1 : -1)) / 10000.0;
	w2 = ((rand() % 10000) * ((rand() & 1) ? 1 : -1)) / 10000.0;
}

// Destruktor
Neuron::~Neuron() 
{
}

// Obliczanie wartosci dla danych testowych
double Neuron::count(double x0, double x1, double x2)
{
	double net = w0 * x0 + w1 * x1 + w2 * x2;
	return 1.0 / (1.0 + exp(-net));
}

// Zwraca wartosc wagi w0
double Neuron::getW0()
{
	return w0;
}

// Zwraca wartosc wagi w1
double Neuron::getW1() 
{
	return w1;
}

// Zwraca wartosc wagi w2
double Neuron::getW2()
{
	return w2;
}

// Ustawia wartosc wagi w0
void Neuron::updateW0(double w)
{
	w0 += w;
}

// Ustawia wartosc wagi w1
void Neuron::updateW1(double w) 
{
	w1 += w;
}

// Ustawia wartosc wagi w2
void Neuron::updateW2(double w)
{
	w2 += w;
}


