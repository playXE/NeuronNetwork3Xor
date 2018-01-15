#include <iostream>
#include <cmath>

using namespace std;

class Neuron {
public:
	// Konstruktor
	Neuron();

	// Destruktor
	~Neuron();

	// Obliczanie wartosci dla danych testowych
	double count(double x0, double x1, double x2);

	// Zwraca wartosc wagi w0
	double getW0();

	// Zwraca wartosc wagi w1
	double getW1();

	// Zwraca wartosc wagi w2
	double getW2();

	// Ustawia wartosc wagi w0
	void updateW0(double w);

	// Ustawia wartosc wagi w1
	void updateW1(double w);

	// Ustawia wartosc wagi w2
	void updateW2(double w);

private:
	// Wagi
	double w0;
	double w1;
	double w2;
};
