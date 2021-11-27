#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

class Time {
private:
    int hour, minute;
public:
    Time() {

    }
    ~Time() {

    }
};

class Date {
private: 
    // Поля
    int day;
    int month;
    const int year;
    Time time;
public:
    Date() : day(1), month(2), year(2000) { // конструктор по умолчанию, через запятую мы можем даже обновить константу в конструкторе, можем извне пробросить константу (список инициализации членов класа)
        // day = 1;
        // month = 1;
        // year = 2000;
    }

    Date(int d, int m, int y) : day(d), month(m), year(y) {
        // day = d;
        // month = m;
        // year = y;
    }

    // Деструктор
    ~Date() {
        cout << "destructor" << endl;
    }

    // Методы
    void toString() {
        cout << day << "." << month << "." << year << endl;
    }

    // Сеттеры
    void setDay(int d) {
        day = d;
    }

    void setMonth(int m) {
        month = m;
    }

    // void setYear(int y) {
    //     year = y;
    // }

    // Геттеры
    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

};

void lesson() {
    // Date today; // Объект || Экземпляр класса
    // today.toString();
    // today.setDay(25);
    // today.setMonth(11);
    // today.setYear(2021);
    // today.toString();

    // Создаеться на стеке, после выхода, то автоматически очистится
    Date today(5, 4, 1996);
    today.toString();

    Date* pToday = new Date(5, 4, 1996);
    pToday->toString();
    delete pToday;

}

// TASK 1
class Power {
private:
    float first = 2, second = 2;
public:
    Power(float a, float b) {
        first = a;
        second = b;
    }

    void setFirst(float a) {
        first = a;
    }

    void setSecond(float b) {
        second = b;
    }

    float getFirst() {
        return first;
    }

    float getSecond() {
        return second;
    }

    float calculate() {
        return pow(first, second);
    }

};

// TASK 2
class RGBA {
private:
    uint8_t m_red, m_green, m_blue, m_alpha;

public: 
    RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {}
    RGBA(uint8_t red, int8_t green, int8_t blue, int8_t alpha) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}

    void print() {
        cout << "RGBA(" << unsigned(m_red) << ", " << unsigned(m_green) << ", " << unsigned(m_blue) << ", " << unsigned(m_alpha) << ");" << endl;
    }
};

class Stack {
private: 
    const size_t SIZE = 10;
    int pArr[10] = { 0 };
    size_t currentIndex = -1;
public:
    void reset() {
        for (size_t i = 0; i <= currentIndex; i++) {
            pArr[i] = 0;
        }
        currentIndex = -1;
    }

    bool push(int value) {
        if (currentIndex == SIZE) {
            return false;
        }
        currentIndex++;
        pArr[currentIndex] = value;
        return true;
    }

    int pop() {
        int value = pArr[currentIndex];
        pArr[currentIndex] = 0;
        --currentIndex;
        return value;
    }

    void print() {
        if (currentIndex == -1) {
            cout << "( )" << endl;
            return;
        }
        cout << "(";
        for (size_t i = 0; i < SIZE - 1; i++) {
            if (i <= currentIndex) {
                cout << " " << pArr[i];
            }
        }
        cout << " )" << endl;
    }

};

int main()
{
    //Power power;
    Power power(3, 3);
    cout << "result: " << power.calculate() << endl;

    RGBA color(10, 20, 30, 1);
    color.print();

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();



    return 0;
}