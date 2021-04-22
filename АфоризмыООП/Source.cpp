#include "Header.h"

Container::Container() {
    Head = new Node();
    Head->Cont = NULL;
    Head->Next = Head;
}

void Container::In(ifstream& ifst) {
    Node* Temp, * P;

    while (!ifst.eof())
    {
        Temp = new Node();

        if (Len == 0)
        {
            if ((Head->Cont = Storehouse::In(ifst)) != 0)
            {
                Len++;
            }
        }
        else
        {
            if ((Temp->Cont = Storehouse::In(ifst)) != 0)
            {
                P = Head->Next;
                Head->Next = Temp;
                Temp->Next = P;
                Head = Temp;
                Len++;
            }
        }
    }
}

Storehouse* Storehouse::In(ifstream& ifst) {
    Storehouse* St;

    string Temp = "";

    getline(ifst, Temp);

    int K = atoi(Temp.c_str());

    if (K == 1)
    {
        St = new Aphorism;
    }
    else if (K == 2)
    {
        St = new Proverb;
    }
    else if (K == 3)
    {
        St = new Riddle;
    }
    else
    {
        return 0;
    }

    getline(ifst, St->Content);

    St->In_Data(ifst);

    getline(ifst, Temp);

    St->Estimation = atoi(Temp.c_str());

    return St;
}

void Aphorism::In_Data(ifstream& ifst) {
    getline(ifst, Author);
}

void Proverb::In_Data(ifstream& ifst) {
    getline(ifst, Country);
}

void Riddle::In_Data(ifstream& ifst) {
    getline(ifst, Answer);
}

void Container::Out(ofstream& ofst) {
    ofst << "Container contains " << Len
        << " elements." << endl << endl;

    if (Head != NULL)
    {
        for (int i = 0; i < Len; i++)
        {
            ofst << i << ": ";
            Head->Cont->Out_Data(Head->Cont->Get_Content(), Head->Cont->Get_Estimation(), ofst);
            ofst << "Amount of punctuation marks in the content of storehouse = " << Head->Cont->Amount() << endl;
            Head = Head->Next;
        }
    }
}

void Aphorism::Out_Data(string Content, int Estimation, ofstream& ofst) {
    ofst << "It's an Aphorism: " << Content << endl; //Выводим содержание
    ofst << "Aphorism's author is: " << Author << endl; //Выводим автора
    ofst << "Subjective estimation of the adage: " << Estimation << endl;
}

void Proverb::Out_Data(string Content, int Estimation, ofstream& ofst) {
    ofst << "It's a Proverb: " << Content << endl; //Выводим содержание
    ofst << "Proverbs's country is: " << Country << endl; //Выводим страну
    ofst << "Subjective estimation of the adage: " << Estimation << endl;
}

void Riddle::Out_Data(string Content, int Estimation, ofstream& ofst) {
    ofst << "It's a Riddle: " << Content << endl; //Выводим содержание
    ofst << "Riddle's answer is: " << Answer << endl;
    ofst << "Subjective estimation of the adage: " << Estimation << endl;
}

void Container::Clear() {
    if (Head != NULL)
    {
        while (Len > 0)
        {
            free(Head->Cont);
            Head = Head->Next;
            Len--;
        }
        Head = NULL;
    }
}

int Storehouse::Amount() {
    string Alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
    int Amount = 0;

    for (int i = 0; i < Content.size(); i++)
    {
        bool Check = false;

        for (int j = 0; j < Alph.size(); j++)
        {
            if (Content[i] == Alph[j])
            {
                Check = true;
                break;
            }
        }

        if (!Check)
        {
            Amount++;
        }
    }

    return Amount;
}

bool Storehouse::Compare(Storehouse* other) {
    return Amount() > other->Amount();
}

void Container::Sort() {
    if (Len > 1)
    {
        Node* First = Head;
        Node* Second = Head->Next;

        Node* Temp = new Node;

        for (int i = 0; i < Len - 1; i++)
        {
            for (int j = 0; j < Len - i - 1; j++)
            {
                if (First->Cont->Compare(Second->Cont))
                {
                    Temp->Cont = First->Cont;
                    First->Cont = Second->Cont;
                    Second->Cont = Temp->Cont;
                }

                Second = Second->Next;
            }

            First = First->Next;
            Second = First->Next;
        }
    }
}

void Container::Out_Only_Aphorism(ofstream& ofst) {
    ofst << endl << "Only Aphorisms." << endl;

    for (int i = 0; i < Len; i++)
    {
        ofst << i << ": ";
        Head->Cont->Out_Only_Aphorism(Head->Cont->Get_Content(), Head->Cont->Get_Estimation(), ofst);
        Head = Head->Next;
    }
}

void Storehouse::Out_Only_Aphorism(string Content, int Estimation, ofstream& ofst) {
    ofst << endl;
}

void Aphorism::Out_Only_Aphorism(string Content, int Estimation, ofstream& ofst) {
    Out_Data(Content, Estimation, ofst);
}

void Container::Set_Head(Node* _Head)
{
    Head = _Head;
}

void Container::Set_Len(int _Len)
{
    Len = _Len;
}

Node* Container::Get_Head()
{
    return Head;
}

int Container::Get_Len()
{
    return Len;
}

void Storehouse::Set_Content(string _Content)
{
    Content = _Content;
}

void Storehouse::Set_Estimation(int _Estimation)
{
    Estimation = _Estimation;
}

string Storehouse::Get_Content()
{
    return Content;
}

int Storehouse::Get_Estimation()
{
    return Estimation;
}

void Aphorism::Set_Author(string _Author)
{
    Author = _Author;
}

string Aphorism::Get_Author()
{
    return Author;
}

void Proverb::Set_Country(string _Country)
{
    Country = _Country;
}

string Proverb::Get_Country()
{
    return Country;
}

void Riddle::Set_Answer(string _Answer)
{
    Answer = _Answer;
}

string Riddle::Get_Answer()
{
    return Answer;
}