#include <iostream>
#include <string>

using namespace std;

class Animal {
private:

    string name;
    int cage_num;
    string fav_food;
    string satiety;

public:

    void SetSatiety(string valueS) {        //сеттер для сытости
        satiety = valueS;
    };

    string GetSatiety() {           //геттер для сытости
        return satiety;
    };

    void Set(string valueN, int valueCN, string valueFF, string valueS) {   //сеттер для класса Animal
        name = valueN;
        cage_num = valueCN;
        fav_food = valueFF;
        satiety = valueS;
    };

    void Print() {                                          //вывод информации
        cout << "THe animal type: " << name << endl;
        cout << "The cage number: " << cage_num << endl;
        cout << name << "'s favourite food: " << fav_food << endl;
        cout << "Is the animal fed? " << satiety << endl;
    };
};

class Zoo {
private:

    int an_num;
    Animal animal;
    string work_hours;
    string address;
    string keeper_name;

public:

    Zoo(int valueAN, string valueWH, string valueA, string valueKN) {   //конструктор класса Zoo
        an_num = valueAN;
        animal.Set("Pig", 7, "carrot", "no");       //вызываем сеттер класса animal, который инициализирует его
        work_hours = valueWH;
        address = valueA;
        keeper_name = valueKN;
    };

    void Feed() {                           //меняем значение сытости через сеттер класса Animal
        if (animal.GetSatiety() == "no") {
            animal.SetSatiety("yes");
        }
        else {
            cout << "The animal is fed" << endl;
        };
    };

    void SwitchKeeper(string new_keeper) {      //меняем фамилию охранника
        keeper_name = new_keeper;
    };

    void Print() {                                              //вывод информации о классе Zoo
        cout << "The number of animals: " << an_num << endl;
        animal.Print();                                         //используем существующий метод вывода информации о классе Animal
        cout << "Zoo's working hours: " << work_hours << endl;
        cout << "Zoo's address: " << address << endl;
        cout << "Keeper's name: " << keeper_name << endl;
    };
};

int main() {
    Zoo zoo(12, "10.00 - 20.00", "Abbey road 75", "Johnson");
    zoo.Print();
    cout << "Do you want to feed an animal? (Y or N)" << endl;
    string ans;
    cin >> ans;
    if (ans == "Y" || ans == "y") {
        zoo.Feed();
    };
    cout << "Do you want to switch the zoo's keeper? (Y or N)" << endl;
    cin >> ans;
    if (ans == "Y" || ans == "y") {
        cout << "Who should I switch the keeper for?" << endl;
        cin >> ans;
        zoo.SwitchKeeper(ans);
    };
    zoo.Print();
    return 0;
}