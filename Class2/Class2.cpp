#define USD 0
#define EUR 1
#define RUB 2

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

const double currency[3][3]{ {1, 0.9485, 67.00}, {1.0543, 1, 68.794}, {0.0149, 0.0142, 1} };

class PriceChecker {

private:

	string curr;
	double price;

public:

	PriceChecker(string curr, double price) {
		transform(curr.begin(), curr.end(), curr.begin(), tolower);
		this->curr = curr;
		this->price = price;
	}

	double GetPrice() {
		return price;
	}

	string GetCurr() {
		return curr;
	}

	void SetCurr(string curr) {
		this->curr = curr;
	};

	void SetPrice(double price) {
		this->price = price;
	};

	void CurrSwitch(string curr) {
		transform(curr.begin(), curr.end(), curr.begin(), tolower);
		if ((curr == "rub") && (GetCurr() != curr) && (GetCurr() == "eur")) {
			SetPrice(GetPrice() * currency[EUR][RUB]);
			SetCurr(curr);
		};
		if ((curr == "usd") && (GetCurr() != curr) && (GetCurr() == "eur")) {
			SetPrice(GetPrice() * currency[EUR][USD]);
			SetCurr(curr);
		};
		if ((curr == "eur") && (GetCurr() != curr) && (GetCurr() == "usd")) {
			SetPrice(GetPrice() * currency[USD][EUR]);
			SetCurr(curr);
		};
		if ((curr == "rub") && (GetCurr() != curr) && (GetCurr() == "usd")) {
			SetPrice(GetPrice() * currency[USD][RUB]);
			SetCurr(curr);
		};
		if ((curr == "eur") && (GetCurr() != curr) && (GetCurr() == "rub")) {
			SetPrice(GetPrice() * currency[RUB][EUR]);
			SetCurr(curr);
		};
		if ((curr == "usd") && (GetCurr() != curr) && (GetCurr() == "rub")) {
			SetPrice(GetPrice() * currency[RUB][USD]);
			SetCurr(curr);
		};

	};


	void Print() {
		cout << "The price of the product: " << GetPrice() << " " << GetCurr() << endl;

	};
};

int main() {
	
	return 0;
}