/*
Прежде чем писать мне в VK "НЕКИТА У ТИБЯ АШИПКИ В КОДЕ СОСИ!!!1!", просто поменяй
стандарт языка с++. Как это сделать:
Верхняя панель->Отладка->Свойства отладки для проекта Class3->C/C++->Язык->Стандарт языка С++->в всплывающем меню ставь 20й стандарт

Если ты пытаешься отладить Class3, но у тебя почему-то отлаживается другой код,
то наведи курсор на нужный проект, ПКМ, назначить в качестве запускаемого проекта
*/

#define PI 3.14159          //Макрос. Если кратко, то когда компилятор встречает PI, то он просто вместо PI подставляет значение справа
                            //имена в define пишутся ВСЕГДА КАПСОМ

#include <iostream>
#include <tuple>            //библиотека, позволяющая функции выводить несколько значений
#include <cmath>            //библиотека, чтобы юзать тригоноиетрию и всякие другие математические штуковины
#include <limits>           //библиотека для использования методов, позволяющих получить максимальное значение диапазона какого-либо типа (ну например int или double) 

using namespace std;
// Создаем класс Point
class Point {

private:

    int x, y;               //поля класса (координаты точки)

public:

    void Set(int x, int y) {    //сеттер класса Point
        this->x = x;            //служебное слово this-> нужно, чтобы обратиться к полям ЭТОГО класса
        this->y = y;            //здесь я его использовал, т.к. в функцию передаются аргументы, одноименные с полями класса, т. е. для избежания конфликта имен переменных
    };

    int GetX() {                //геттер для икса
        return x;
    };

    int GetY() {                //геттер для игрика
        return y;
    };

};

class RectangularTriangle {

private:

    Point point1;               //создаем три поля типа Point
    Point point2;               //таким образом у нас получается класс в классе, но ничего страшного нет, это удобно
    Point point3;
    int count;

public:

    void Set(int x1, int y1, int x2, int y2, int x3, int y3, int count) {       //сеттер для класса RectangularTriangle
        point1.Set(x1, y1);
        point2.Set(x2, y2);
        point3.Set(x3, y3);
        this->count = count;
    };

    tuple<double, double, double> GetLength() {                                 //метод для получения длин сторон треугольника. принцип работы класса tuple загугли
        double a, b, c;
        a = round((sqrt(pow(point2.GetX() - point1.GetX(), 2) + pow(point2.GetY() - point1.GetY(), 2))) * 100) / 100;
        b = round((sqrt(pow(point3.GetX() - point2.GetX(), 2) + pow(point3.GetY() - point2.GetY(), 2))) * 100) / 100;
        c = round((sqrt(pow(point1.GetX() - point3.GetX(), 2) + pow(point1.GetY() - point3.GetY(), 2))) * 100) / 100;
        return { a, b, c };
    };

    bool Existance() {                              //метод проверки существования треугольника
        auto [a, b, c] = GetLength();
        if ((a + b > c) && (a + c > b) && (b + c > a)) {
            return true;
        }
        else {
            return false;
        }
    };

    bool IsRect() {                                 //метод проверки на ортогональность
        if (Existance() == true) {
            auto [A, B, C] = Angle();
            if ((A == 90) || (B == 90) || (C == 90)) {
                return true;
            }
            else {
                return false;
            };
        };
    };

    double Perimeter() {                        //без комментариев
        if (Existance() == true) {
            auto [a, b, c] = GetLength();
            return round((a + b + c) * 100) / 100;
        }
        else {
            return 0;
        };
    };

    double Square() {                           //считаем площадб через формулу Герона
        if (Existance() == true) {
            auto [a, b, c] = GetLength();
            int p = Perimeter() / 2;
            return round((sqrt(p * (p - a) * (p - b) * (p - c))) * 100) / 100;
        }
        else {
            return 0;
        }
    };

    tuple<double, double, double> Angle() {     //считаем углы по формуле косинусов
        if (Existance() == true) {
            auto [a, b, c] = GetLength();
            double angleA, angleB, angleC;
            angleA = round(acos((b * b + c * c - a * a) / (2 * b * c)) * (180.0 / PI));
            angleB = round(acos((a * a + c * c - b * b) / (2 * a * c)) * (180.0 / PI));
            angleC = 180 - angleA - angleB;
            return { angleA, angleB, angleC };
        }
        else {
            return { 0, 0, 0 };
        };

    };
        
    void Print() {                              //выводим инфу
        cout << "The first point: (" << point1.GetX() << "," << point1.GetY() << ")" << endl;
        cout << "The second point: (" << point2.GetX() << "," << point2.GetY() << ")" << endl;
        cout << "The third point: (" << point3.GetX() << "," << point3.GetY() << ")" << endl;
        cout << "The number of triangle: " << count << endl;
        cout << "Does this triangle exist? " << Existance() << endl;
        if (Existance() == true) {
            auto [a, b, c] = GetLength();
            cout << "Sides of the triangle: " << a << ", " << b << ", " << c << endl;
            auto [A, B, C] = Angle();
            cout << "Angles of the triangle: " << A << ", " << B << ", " << C << endl;
            cout << "Triangle's perimeter: " << Perimeter() << endl;
            cout << "Triangle's square: " << Square() << endl;
        };


    };

};

int main() {
    RectangularTriangle triangle[100];                      //заводим массив классов. Заводим сразу на 100, ибо мы не знаем, сколько треугольников введет пользователь. Пустые элементы массива просто останутся неинициализированными. Можно было динамический массив сделать, но опять же, мне впадлу и ТЗ этого не просило
    cout << "How many triangles do you want to input?" << endl;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2, x3, y3;
        cout << "Input 3 points: " << endl;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        triangle[i].Set(x1, y1, x2, y2, x3, y3, i);
        triangle[i].Print();
        cout << endl;
    };

    long double maxS, minS, minI, maxI;
    minI = 0;
    maxI = 0;
    maxS = -1;
    minS = numeric_limits<long double>::max();              //та самая функция для получения максимального значения диапазона
    for (int i = 0; i < N; i++) {
        if ((triangle[i].Existance() == true) && (triangle[i].IsRect() == true)) {
            if (triangle[i].Square() > maxS) {
                maxS = triangle[i].Square();
                maxI = i;
            };
            if (triangle[i].Square() < minS) {
                minS = triangle[i].Square();
                minI = i;
            };
        };
    };

    for (int i = 0; i < N; i++) {
        if (i == maxI) {
            cout << "Maximum square has a triangle with number " << i << ": " << triangle[i].Square() << endl;
        };
        if (i == minI) {
            cout << "Minimum square has a triangle with mumber " << i << ": " << triangle[i].Square() << endl;
        };
    };

    return 0;
}