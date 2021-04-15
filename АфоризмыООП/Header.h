#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Класс кладезей знаний
class Storehouse {
public:
    static Storehouse* In(ifstream& ifst); //Функция ввода информации о кладезе знаний
    virtual void In_Data(ifstream& ifst) = 0; //Чисто вирутальная функция ввода информации
                                              //о кладезе, она будет определена для
                                              //каждого класса кладезя
    virtual void Out_Data(ofstream& ofst) = 0; //Чисто вирутальная функция вывода информации
                                              //о кладезе, она будет определена для
                                              //каждого класса кладезя
    virtual int Amount() = 0;
    bool Compare(Storehouse* Other);
protected:
    Storehouse() {};
};

//Класс афоризмов
class Aphorism : public Storehouse {
    string Content; //Содержание афоризма
    string Author; //Автора афоризма
public:
    void In_Data(ifstream& ifst); //Функция ввода информации об афоризме
    void Out_Data(ofstream& ofst); //Функция вывода информации об афоризме
    int Amount();
    Aphorism() {};
};

//Класс поговорок и пословиц
class Proverb : public Storehouse {
    string Content; //Содержание пословицы или поговорки
    string Country; //Страна пословицы или поговорки
public:
    void In_Data(ifstream& ifst); //Функция ввода информации о поговорке или пословице
    void Out_Data(ofstream& ofst); //Функция вывода информации о поговорке или пословице
    int Amount();
    Proverb() {};
};

//Класс загадок
class Riddle : public Storehouse {
    string Content; //Содержание 
    string Answer; //Ответ
public:
    void In_Data(ifstream& ifst); //Функция ввода информации 
    void Out_Data(ofstream& ofst); //Функция вывода информации 
    Riddle() {};
};

//Узел контейнера
struct Node {
    Node* Next; //Указатель на следующий узел
    Storehouse* Cont; //Указатель на класс кладезей
};

//Контейнер
class Container {
    Node* Head; //Указатель на начало списка
    int Len; //Размерность контейнера
public:
    void In(ifstream& ifst); //Функция ввода элемента в контейнер
    void Out(ofstream& ofst); //Функция вывода элемента из контейнера
    void Clear(); //Функция очищения контейнера
    void Sort();
    Container(); //Конструктор (по сути инициализатор контейнера)
    ~Container() { Clear(); } //Деструктор
};

#endif //HEADER_H