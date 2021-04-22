#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Класс кладезей знаний
class Storehouse {
    string Content; //Содержание 
    int Estimation; //Субъективная оценка
public:
    string Get_Content();
    void Set_Content(string _Content);

    int Get_Estimation();
    void Set_Estimation(int _Estimation);

    static Storehouse* In(ifstream& ifst); //Функция ввода информации о кладезе знаний
    virtual void In_Data(ifstream& ifst) = 0; //Чисто вирутальная функция ввода информации
                                              //о кладезе, она будет определена для
                                              //каждого класса кладезя
    virtual void Out_Data(string Content, int Estimation, ofstream& ofst) = 0; //Чисто вирутальная функция вывода информации
                                              //о кладезе, она будет определена для
                                              //каждого класса кладезя
    int Amount();
    bool Compare(Storehouse* Other);
    virtual void Out_Only_Aphorism(string Content, int Estimation, ofstream& ofst);
protected:
    Storehouse() {};
};

//Класс афоризмов
class Aphorism : public Storehouse {
    string Author; //Автора афоризма
public:
    string Get_Author();
    void Set_Author(string _Author);

    void In_Data(ifstream& ifst); //Функция ввода информации об афоризме
    void Out_Data(string Content, int Estimation, ofstream& ofst); //Функция вывода информации об афоризме
    void Out_Only_Aphorism(string Content, int Estimation, ofstream& ofst);
    Aphorism() {};
};

//Класс поговорок и пословиц
class Proverb : public Storehouse {
    string Country; //Страна пословицы или поговорки
public:
    string Get_Country();
    void Set_Country(string _Country);

    void In_Data(ifstream& ifst); //Функция ввода информации о поговорке или пословице
    void Out_Data(string Content, int Estimation, ofstream& ofst); //Функция вывода информации о поговорке или пословице
    Proverb() {};
};

//Класс загадок
class Riddle : public Storehouse {
    string Answer; //Ответ
public:
    string Get_Answer();
    void Set_Answer(string _Answer);

    void In_Data(ifstream& ifst); //Функция ввода информации 
    void Out_Data(string Content, int Estimation, ofstream& ofst); //Функция вывода информации 
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
    Node* Get_Head();
    void Set_Head(Node* _Head);

    int Get_Len();
    void Set_Len(int _Len);

    void In(ifstream& ifst); //Функция ввода элемента в контейнер
    void Out(ofstream& ofst); //Функция вывода элемента из контейнера
    void Clear(); //Функция очищения контейнера
    void Sort();
    void Out_Only_Aphorism(ofstream& ofst);
    Container(); //Конструктор (по сути инициализатор контейнера)
    ~Container() { Clear(); } //Деструктор
};

#endif //HEADER_H