#include "Header.h"

Container::Container() {
    Head = new Node();
    Head->Cont = NULL;
    Head->Next = NULL;
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
                Node* cur = Head;
                while (cur->Next != NULL)
                {
                    cur = cur->Next;
                }

                P = cur->Next;
                cur->Next = Temp;
                Temp->Next = P;
                cur = Temp;
                Len++;
            }
        }
    }
}

Storehouse* Storehouse::In(ifstream& ifst) {
    Storehouse* St;
    int K;
    ifst >> K;
    if (K == 1)
    {
        St = new Aphorism;
    }
    else if (K == 2)
    {
        St = new Proverb;
    }
    else
    {
        return 0;
    }

    St->In_Data(ifst);

    return St;
}

void Aphorism::In_Data(ifstream& ifst) {
    string Temp_El = ""; //Буфер для считывания строк

    //Считываем содержание афоризма
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Content += Temp_El + " ";
    }

    Content += Temp_El;

    //Считываем автора афоризма
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Author += Temp_El + " ";
    }

    Author += Temp_El;

    ifst >> Estimation;
}

void Proverb::In_Data(ifstream& ifst) {
    string Temp_El = ""; //Буфер для считывания строк

    //Считываем содержание
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Content += Temp_El + " ";
    }

    Content += Temp_El;

    //Считываем страну
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Country += Temp_El + " ";
    }

    Country += Temp_El;

    ifst >> Estimation;
}

void Container::Out(ofstream& ofst) {
    ofst << "Container contains " << Len
        << " elements." << endl;

    if (Head != NULL)
    {
        for (int i = 0; i < Len; i++)
        {
            ofst << i << ": ";
            Head->Cont->Out_Data(ofst);
            Head = Head->Next;
        }
    }
}

void Aphorism::Out_Data(ofstream& ofst) {
    ofst << "It's an Aphorism: " << Content << endl; //Выводим содержание
    ofst << "Aphorism's author is: " << Author << endl; //Выводим автора
    ofst << "Subjective estimation of the adage: " << Estimation << endl;
}

void Proverb::Out_Data(ofstream& ofst) {
    ofst << "It's a Proverb: " << Content << endl; //Выводим содержание
    ofst << "Proverbs's country is: " << Country << endl; //Выводим страну
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