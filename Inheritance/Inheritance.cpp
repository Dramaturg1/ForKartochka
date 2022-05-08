#include <iostream>
#include <cmath>

using namespace std;

class Square {

private:

	double len;

public:

	Square(double len) {
		this->len = len;
	};

	double GetLen() {
		return len;
	};

	double Sq() {
		return len * len;
	};

	double Perimeter() {
		return 4 * len;
	};

	double Diagonal() {
		return len * sqrt(2);
	};

	void Print() {
		cout << "Side length of the square: " << GetLen() << endl;
		cout << "Diagonal of the square: " << Diagonal() << endl;
		cout << "Square area: " << Sq() << endl;
		cout << "Square perimeter: " << Perimeter() << endl;
	}
};

class SquarePrism : Square {


private:

	double H;

public:

	SquarePrism(double H, double len) :Square(len) {
		this->H = H;
	};



};

int main() {
	return 0;
};