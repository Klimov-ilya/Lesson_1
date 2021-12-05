#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

int x = 777;

namespace Lesson_2 {
    class Date {
    private:
        // ѕол€
        int day;
        int month;
        int year;
        static int count;
    public:
        Date() : day(1), month(2), year(2000) { // конструктор по умолчанию, через зап€тую мы можем даже обновить константу в конструкторе, можем извне пробросить константу (список инициализации членов класа)
            cout << "Date" << endl;
            count++;
        }

        Date(int d, int m, int y) : day(d), month(m), year(y) {
            cout << "Date" << endl;
            count++;
        }

        // ƒеструктор
        ~Date() {
            cout << "destructor" << endl;
            count--; 
        }

        static int getCount() {
            return count;
        }

        // ћетоды
        void toString() const {
            cout << day << "." << month << "." << year << endl;
        }

        // —еттеры
        Date& setDay(int day);

        Date& setMonth(int month) {
            this->month = month;
            return *this;
        }

        Date setYear(int year) {
            this->year = year;
            return *this;
        }

        // √еттеры
        int getDay() const {
            return this->day;
        }

        int getMonth() const {
            return this->month;
        }

        int getYear() const {
            return this->year;
        }

    };

    int Date::count = 0;

    Date& Date::setDay(int d) {
        this->day = day;
        return *this;
    }

    void foo() {
        int x = 0;
        x++;
        cout << "local: " << x << endl;
        cout << "global: " << ::x << endl;
    }

    class Human {
    protected:
        string name;
        int age;
    public:
        Human(string n, int a) : name(n), age(a) { }
        string getName() const {
            return this->name;
        }
        int getAge() const {
            return this->age;
        }
    };

    class Employee : public Human {
    private:
        int salary;
    public:
        Employee(string n, int a, int s) : salary(s), Human(n, a) { }
        int getSalary() const {
            return salary;
        }
        void print() {
            cout << name << " " << age << " " << salary << endl;
        }
        friend void increase_salary(Employee& employee);
    };

    void increase_salary(Employee& employee) {
        employee.salary *= 2;
    }

    void lesson() {
        Date date;
        date.setDay(10).setMonth(8).setYear(1996);
        date.toString();

        const Date birthday(12, 12, 2012);
        // birthday.setDay(12);
        birthday.toString();

        cout << "count: " << Date::getCount() << endl;
        cout << "count: " << birthday.getCount() << endl;
        
        foo();
    }

    class Person {
    private: 
        string name;
        int age;
        float weight;
        static int count;
    public:
        Person(string name, int age, float weight) : name(name), age(age), weight(weight) {
            count++;
        }

        Person() : name("unknown"), age(0), weight(0.0f) {
            count++;
        }

        ~Person() {
            count--;
        }

        string getName() const {
            return this->name;
        }

        int getAge() const {
            return this->age;
        }

        float getWeight() const {
            return this->weight;
        }

        static int getCount() {
            return count;
        }

        void setName(string name) {
            this->name = name;
        }

        void setAge(int age) {
            this->age = age;
        }

        void setWeight(float weight) {
            this->weight = weight;
        }

    };

    class Student : public Person {
    private:
        int studyYear;
    public:
        Student(string name, int age, float weight, int studyYear) : studyYear(studyYear), Person(name, age, weight) { }
        void setStudyYear(int year) {
            this->studyYear = year;
        }
        int getStudyYear() const {
            return this->studyYear;
        }
    };

    int Person::count = 0;

    class Fruit {
    private:
        string name, color;
    protected:
        void setName(string name) {
            this->name = name;
        }
    public:
        Fruit(string name, string color) : name(name), color(color) {}
        string getName() const {
            return this->name;
        }
        string getColor() const {
            return this->color;
        }
    };

    class Apple : public Fruit {
    public:
        Apple(string color) : Fruit("Apple", color) {}
    };

    class Banana : public Fruit {
    public:
        Banana() : Fruit("Banana", "yellow") {}
    };

    class GrannySmith : public Apple {
    public:
        GrannySmith() : Apple("green") {
            setName("Granny Smith apple");
        }
    };

    void hometask() {
        Student student1("Alex", 19, 84.2, 2015);
        Student student2("Tom", 21, 74.1, 2013);
        Student student3("Phiby", 18, 58, 2014);
        
        cout << Student::getCount() << endl;
    
        Apple a("red");
        Banana b;
        GrannySmith c;

        cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
        cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
        cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    
    }

    /*
        Black jack
        ћинимум:
            - ƒолжен быть класс самой игры, у которой есть игроки (список игроков), там может быть поле состо€ни€ игры, победитель, список карт в машинке, игрок который ходит ...
            -  ласс человека, у которого есть дочерние - диллер и простой игрок, по скольку дл€ диллера и игрока правила рассчета победы считаютс€ по разному
            - ” класса игры есть один диллер и список игроков
            - ” диллера и у игроков есть карты на руке (список карт), количество очков
            -  ласс карты, у которой есть определенный номинал (Ћибо сделать через перечисление)
        
    */

}

