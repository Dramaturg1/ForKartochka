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
		if ((curr == "rub") && (GetCurr() == "eur")) {
			SetPrice(GetPrice() * currency[EUR][RUB]);
			SetCurr(curr);
		};
		if ((curr == "usd") && (GetCurr() == "eur")) {
			SetPrice(GetPrice() * currency[EUR][USD]);
			SetCurr(curr);
		};
		if ((curr == "eur") && (GetCurr() == "usd")) {
			SetPrice(GetPrice() * currency[USD][EUR]);
			SetCurr(curr);
		};
		if ((curr == "rub") && (GetCurr() == "usd")) {
			SetPrice(GetPrice() * currency[USD][RUB]);
			SetCurr(curr);
		};
		if ((curr == "eur") && (GetCurr() == "rub")) {
			SetPrice(GetPrice() * currency[RUB][EUR]);
			SetCurr(curr);
		};
		if ((curr == "usd") && (GetCurr() == "rub")) {
			SetPrice(GetPrice() * currency[RUB][USD]);
			SetCurr(curr);
		};

	};

	void PriceComparison() {
		cout << "USD" << "\t" << "EUR" << "\t" << "RUB" << endl;
		CurrSwitch("usd");
		cout << GetPrice() << "\t";
		CurrSwitch("eur");
		cout << GetPrice() << "\t";
		CurrSwitch("rub");
		cout << GetPrice() << endl;
	};

	void Print() {
		cout << "The price of the product: " << GetPrice() << " " << GetCurr() << endl;

	};
};

int main() {

	string buff;
	double price;
	cout << "Print the currency (USD, EUR or RUB) and the price of the product: " << endl;
	try {
		cin >> buff >> price;
		if ((buff != "usd") && (buff != "eur") && (buff != "rub")) {
			throw 1;
		}
	}
	catch (int i) {
		cout << "Error: your input is incorrect.";
		return 0;
	}
	PriceChecker product(buff, price);
	buff = "";
	product.Print();
	cout << "Type the currency you want to switch to (USD, EUR or RUB): ";
	try {
		cin >> buff;
		if ((buff == product.GetCurr()) || ((buff != "usd") && (buff != "eur") && (buff != "rub"))) {
			throw 2;
		};
	}
	catch (int i) {
		cout << "Error: you typed the same currency or the input is incorrect.";
		return 0;
	};
	product.CurrSwitch(buff);
	product.Print();
	product.PriceComparison();
	return 0;
}
