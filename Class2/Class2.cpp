#define USD 0			//3 макроса для визуального удобства при работе с массивом, где хранятся валюты
#define EUR 1
#define RUB 2

#include <iostream>
#include <string>
#include <cctype>		//2 библиотеки, чтобы использовать функцию изменения регистра 
#include <algorithm>

using namespace std;

const double currency[3][3]{ {1, 0.9485, 67.00}, {1.0543, 1, 68.794}, {0.0149, 0.0142, 1} };	//двумерный константный массив с валютами

class PriceChecker {

private:

	string curr;
	double price;

public:

	PriceChecker(string curr, double price) {
		transform(curr.begin(), curr.end(), curr.begin(), tolower);			//как бы пользователь не ввел данные, эта команда приведет строку к нижнему регистру во избежании еботни с кодом
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

	void CurrSwitch(string curr) {								//небольшой спагетти код, ибо я целый день думал, как бы это сделать красивее и компактнее, но ничего лучще в голову мне не пришло, увы
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
	try {				// это исключения. советую загуглить их сначала. но принцип довольно прост. Ты просто в блок try помещаешь код, где может вылезти какая-то ошибка, в данном случае, некорректный ввод
		cin >> buff >> price;
		if ((buff != "usd") && (buff != "eur") && (buff != "rub")) {		//вот здесь хочу проверить, правильно ли пользователь ввел валюту
			throw 1;	// если пользователь долбаеб, то я "ловлю" это исключение
		}
	}
	catch (int i) {		//если ты его поймал, то выполняется код в блоке catch. В данном случае он выводит ошибку и прекращает работу программы
		cout << "Error: your input is incorrect.";
		return 0;
	}
	PriceChecker product(buff, price);
	buff = "";
	product.Print();
	cout << "Type the currency you want to switch to (USD, EUR or RUB): ";
	try {				//аналогичная ситуация, только тут еще пользователь может ввести валюту, которая и так введена
		cin >> buff;
		if ((buff == product.GetCurr()) || ((buff != "usd") && (buff != "eur") && (buff != "rub"))) {
			throw 2;
		};
	}
	catch (int i) {
		cout << "Error: you typed the same currency or the input is incorrect.";
		return 0;
	};
	//возможно ты спросишь, а нахуя это все? можно было же просто if'ами обойтись
	//но я отвечу
	//я еблан
	//но в свое оправдание скажу, что здесть просто маленькая прога. Когда срок 1000+, то умение пользоваться исключениями приветствуется, тем более что я довольно примитивно их использовал, у них большой функционал
	product.CurrSwitch(buff);
	product.Print();
	product.PriceComparison();
	return 0;
}
