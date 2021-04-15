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
    else if (K == 3)
    {
        St = new Riddle;
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
}

void Riddle::In_Data(ifstream& ifst) {
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
        Answer += Temp_El + " ";
    }

    Answer += Temp_El;
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
            ofst << "Amount of punctuation marks in the content of storehouse = " << Head->Cont->Amount() << endl;
            Head = Head->Next;
        }
    }
}

void Aphorism::Out_Data(ofstream& ofst) {
    ofst << "It's an Aphorism: " << Content << endl; //Выводим содержание
    ofst << "Aphorism's author is: " << Author << endl; //Выводим автора
}

void Proverb::Out_Data(ofstream& ofst) {
    ofst << "It's a Proverb: " << Content << endl; //Выводим содержание
    ofst << "Proverbs's country is: " << Country << endl; //Выводим страну
}

void Riddle::Out_Data(ofstream& ofst) {
    ofst << "It's a Riddle: " << Content << endl; //Выводим содержание
    ofst << "Riddle's answer is: " << Answer << endl;
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

int Aphorism::Amount() {
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

int Proverb::Amount() {
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