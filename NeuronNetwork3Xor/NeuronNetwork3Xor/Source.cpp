#include <cstdlib>
#include <iostream>
#include <ctime>
#include "siec.h"

using namespace std;

const double T[] = { 0.0, 1.0, 1.0, 0.0 };
const double P0[] = { 1.0, -1.0, -1.0 };
const double P1[] = { 1.0, -1.0, 1.0 };
const double P2[] = { 1.0, 1.0, -1.0 };
const double P3[] = { 1.0, 1.0, 1.0 };

int main(int argc, char *argv[]) {
	srand(time(NULL));
	Siec siec;

	double e = 0.0;
	do {
		e = 0.0;
		e += siec.learn(P0, T[0]);
		e += siec.learn(P1, T[1]);
		e += siec.learn(P2, T[2]);
		e += siec.learn(P3, T[3]);
		cout << e << endl;
	} while (e > 0.01);

	cout << " 0 xor 0 = " << siec.count(P0) << endl;
	cout << " 0 xor 1 = " << siec.count(P1) << endl;
	cout << " 1 xor 0 = " << siec.count(P2) << endl;
	cout << " 1 xor 1 = " << siec.count(P3) << endl;	

	return 0;
}
