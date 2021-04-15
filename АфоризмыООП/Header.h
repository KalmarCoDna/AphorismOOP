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
protected:
    Storehouse() {};
};

//����� ���������
class Aphorism : public Storehouse {
    string Content; //���������� ��������
    string Author; //������ ��������
public:
    void In_Data(ifstream& ifst); //������� ����� ���������� �� ��������
    void Out_Data(ofstream& ofst); //������� ������ ���������� �� ��������
    int Amount();
    Aphorism() {};
};

//����� ��������� � ��������
class Proverb : public Storehouse {
    string Content; //���������� ��������� ��� ���������
    string Country; //������ ��������� ��� ���������
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
public:
    void In_Data(ifstream& ifst); //������� ����� ���������� 
    void Out_Data(ofstream& ofst); //������� ������ ���������� 
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
    Container(); //����������� (�� ���� ������������� ����������)
    ~Container() { Clear(); } //����������
};

#endif //HEADER_H