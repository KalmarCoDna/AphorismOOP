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
    string Temp_El = ""; //����� ��� ���������� �����

    //��������� ���������� ��������
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Content += Temp_El + " ";
    }

    Content += Temp_El;

    //��������� ������ ��������
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Author += Temp_El + " ";
    }

    Author += Temp_El;

    ifst >> Estimation;
}

void Proverb::In_Data(ifstream& ifst) {
    string Temp_El = ""; //����� ��� ���������� �����

    //��������� ����������
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Content += Temp_El + " ";
    }

    Content += Temp_El;

    //��������� ������
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Country += Temp_El + " ";
    }

    Country += Temp_El;

    ifst >> Estimation;
}

void Riddle::In_Data(ifstream& ifst) {
    string Temp_El = ""; //����� ��� ���������� �����

    //��������� ����������
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Content += Temp_El + " ";
    }

    Content += Temp_El;

    //��������� ������
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Answer += Temp_El + " ";
    }

    Answer += Temp_El;

    ifst >> Estimation;
}

void Container::Out(ofstream& ofst) {
    ofst << "Container contains " << Len
        << " elements." << endl << endl;

    if (Head != NULL)
    {
        Node* cur = Head;
        for (int i = 0; i < Len; i++)
        {
            ofst << i << ": ";
            cur->Cont->Out_Data(ofst);
            ofst << "Amount of punctuation marks in the content of storehouse = " << cur->Cont->Amount() << endl;
            cur = cur->Next;
        }
    }
}

void Aphorism::Out_Data(ofstream& ofst) {
    ofst << "It's an Aphorism: " << Content << endl; //������� ����������
    ofst << "Aphorism's author is: " << Author << endl; //������� ������
    ofst << "Subjective estimation of the adage: " << Estimation << endl;
}

void Proverb::Out_Data(ofstream& ofst) {
    ofst << "It's a Proverb: " << Content << endl; //������� ����������
    ofst << "Proverbs's country is: " << Country << endl; //������� ������
    ofst << "Subjective estimation of the adage: " << Estimation << endl;
}

void Riddle::Out_Data(ofstream& ofst) {
    ofst << "It's a Riddle: " << Content << endl; //������� ����������
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

int Riddle::Amount() {
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
        //ofst << i << ": ";
        Head->Cont->Out_Only_Aphorism(ofst);
        Head = Head->Next;
    }
}

void Storehouse::Out_Only_Aphorism(ofstream& ofst) {
    //ofst << endl;
}

void Aphorism::Out_Only_Aphorism(ofstream& ofst) {
    Out_Data(ofst);
}