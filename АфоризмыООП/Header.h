#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//����� �������� ������
class Storehouse {
public:
    static Storehouse* In(ifstream& ifst); //������� ����� ���������� � ������� ������
    virtual void In_Data(ifstream& ifst) = 0; //����� ����������� ������� ����� ����������
                                              //� �������, ��� ����� ���������� ���
                                              //������� ������ �������
    virtual void Out_Data(ofstream& ofst) = 0; //����� ����������� ������� ������ ����������
                                              //� �������, ��� ����� ���������� ���
                                              //������� ������ �������
    virtual int Amount() = 0;
    bool Compare(Storehouse* Other);
    virtual void Out_Only_Aphorism(ofstream& ofst);
protected:
    Storehouse() {};
};

//����� ���������
class Aphorism : public Storehouse {
    string Content; //���������� ��������
    string Author; //������ ��������
    int Estimation; //������������ ������ ���������
public:
    void In_Data(ifstream& ifst); //������� ����� ���������� �� ��������
    void Out_Data(ofstream& ofst); //������� ������ ���������� �� ��������
    int Amount();
    void Out_Only_Aphorism(ofstream& ofst);
    Aphorism() {};
};

//����� ��������� � ��������
class Proverb : public Storehouse {
    string Content; //���������� ��������� ��� ���������
    string Country; //������ ��������� ��� ���������
    int Estimation; //������������ ������ ���������
public:
    void In_Data(ifstream& ifst); //������� ����� ���������� � ��������� ��� ���������
    void Out_Data(ofstream& ofst); //������� ������ ���������� � ��������� ��� ���������
    int Amount();
    Proverb() {};
};

//����� �������
class Riddle : public Storehouse {
    string Content; //���������� 
    string Answer; //�����
    int Estimation; //������������ ������ ���������
public:
    void In_Data(ifstream& ifst); //������� ����� ���������� 
    void Out_Data(ofstream& ofst); //������� ������ ���������� 
    int Amount();
    Riddle() {};
};

//���� ����������
struct Node {
    Node* Next; //��������� �� ��������� ����
    Storehouse* Cont; //��������� �� ����� ��������
};

//���������
class Container {
    Node* Head; //��������� �� ������ ������
    int Len; //����������� ����������
public:
    void In(ifstream& ifst); //������� ����� �������� � ���������
    void Out(ofstream& ofst); //������� ������ �������� �� ����������
    void Clear(); //������� �������� ����������
    void Sort();
    void Out_Only_Aphorism(ofstream& ofst);
    Container(); //����������� (�� ���� ������������� ����������)
    ~Container() { Clear(); } //����������
};

#endif //HEADER_H