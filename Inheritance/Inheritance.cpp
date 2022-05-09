#include <iostream>
#include <cmath>

using namespace std;

class Square {

protected:

	double len;

public:

	void SetSquare(double len) {
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
		cout << "Side length of the square: " << len << endl;
		cout << "Diagonal of the square: " << Diagonal() << endl;
		cout << "Square area: " << Sq() << endl;
		cout << "Square perimeter: " << Perimeter() << endl;
	}
};

class SquarePrism : public Square {


private:

	double H;

public:

	void SetSquarePrism(double len, double H) {
		SetSquare(len);
		this->H = H;
	};

	double Volume() {
		return Sq() * H;
	};

	double Sq() {
		return 2 * Square::Sq() + 4 * H * len;
	};

	double Diagonal() {
		return sqrt(pow(H, 2) + pow(Square::Diagonal(), 2));
	}

	void Print() {
		cout << "Height length of the prism: " << H << endl;
		cout << "Priam diagonal " << Diagonal() << endl;
		cout << "Volume of the prism: " << Volume() << endl;
		cout << "Total surface area: " << Sq() << endl;
	}
};

pair<int, int>MaxSqDia(Square sq[], const int size1, SquarePrism pr[], const int size2) {
	int value1, value2;
	double max1 = 0;
	double max2 = 0;
	for (int i = 0; i < size1; i++) {
		if (max1 < sq[i].Sq()) {
			max1 = sq[i].Sq();
			value1 = i;
		};
	};
	for (int i = 0; i < size2; i++) {
		if (max2 < pr[i].Diagonal()) {
			max2 = pr[i].Diagonal();
			value2 = i;
		};
	};
	return pair<int, int>(value1, value2);
};

int main() {

	const int s1 = 2;
	const int s2 = 2;

	Square square[s1];
	SquarePrism prism[s2];

	cout << "Type square length: " << endl;

	for (int i = 0; i < s1; i++) {
		double buff;
		cin >> buff;
		square[i].SetSquare(buff);
		square[i].Print();
		cout << endl << endl;
	}

	cout << "Type prism length and height: " << endl;

	for (int i = 0; i < s2; i++) {
		double buff1, buff2;
		cin >> buff1 >> buff2;
		prism[i].SetSquarePrism(buff1, buff2);
		prism[i].Print();
		cout << endl << endl;
	}

	auto[m1, m2] = MaxSqDia(square, s1, prism, s2);
	cout << "Maximum square area: " << square[m1].Sq() << endl;
	cout << "Maximum prism diagonal: " << prism[m2].Diagonal() << endl;
	return 0;
};