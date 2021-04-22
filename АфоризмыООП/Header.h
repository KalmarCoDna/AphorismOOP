#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//����� �������� ������
class Storehouse {
    string Content; //���������� 
    int Estimation; //������������ ������
public:
    string Get_Content();
    void Set_Content(string _Content);

    int Get_Estimation();
    void Set_Estimation(int _Estimation);

    static Storehouse* In(ifstream& ifst); //������� ����� ���������� � ������� ������
    virtual void In_Data(ifstream& ifst) = 0; //����� ����������� ������� ����� ����������
                                              //� �������, ��� ����� ���������� ���
                                              //������� ������ �������
    virtual void Out_Data(string Content, int Estimation, ofstream& ofst) = 0; //����� ����������� ������� ������ ����������
                                              //� �������, ��� ����� ���������� ���
                                              //������� ������ �������
    int Amount();
    bool Compare(Storehouse* Other);
    virtual void Out_Only_Aphorism(string Content, int Estimation, ofstream& ofst);
protected:
    Storehouse() {};
};

//����� ���������
class Aphorism : public Storehouse {
    string Author; //������ ��������
public:
    string Get_Author();
    void Set_Author(string _Author);

    void In_Data(ifstream& ifst); //������� ����� ���������� �� ��������
    void Out_Data(string Content, int Estimation, ofstream& ofst); //������� ������ ���������� �� ��������
    void Out_Only_Aphorism(string Content, int Estimation, ofstream& ofst);
    Aphorism() {};
};

//����� ��������� � ��������
class Proverb : public Storehouse {
    string Country; //������ ��������� ��� ���������
public:
    string Get_Country();
    void Set_Country(string _Country);

    void In_Data(ifstream& ifst); //������� ����� ���������� � ��������� ��� ���������
    void Out_Data(string Content, int Estimation, ofstream& ofst); //������� ������ ���������� � ��������� ��� ���������
    Proverb() {};
};

//����� �������
class Riddle : public Storehouse {
    string Answer; //�����
public:
    string Get_Answer();
    void Set_Answer(string _Answer);

    void In_Data(ifstream& ifst); //������� ����� ���������� 
    void Out_Data(string Content, int Estimation, ofstream& ofst); //������� ������ ���������� 
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
    Node* Get_Head();
    void Set_Head(Node* _Head);

    int Get_Len();
    void Set_Len(int _Len);

    void In(ifstream& ifst); //������� ����� �������� � ���������
    void Out(ofstream& ofst); //������� ������ �������� �� ����������
    void Clear(); //������� �������� ����������
    void Sort();
    void Out_Only_Aphorism(ofstream& ofst);
    Container(); //����������� (�� ���� ������������� ����������)
    ~Container() { Clear(); } //����������
};

#endif //HEADER_H