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
    string Temp_El = ""; //????? ??? ?????????? ?????

    //????????? ?????????? ????????
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Content += Temp_El + " ";
    }

    Content += Temp_El;

    //????????? ?????? ????????
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Author += Temp_El + " ";
    }

    Author += Temp_El;
}

void Proverb::In_Data(ifstream& ifst) {
    string Temp_El = ""; //????? ??? ?????????? ?????

    //????????? ??????????
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Content += Temp_El + " ";
    }

    Content += Temp_El;

    //????????? ??????
    while (!(ifst >> Temp_El) || (ifst.peek() != '\n'))
    {
        Country += Temp_El + " ";
    }

    Country += Temp_El;
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
    ofst << "It's an Aphorism: " << Content << endl; //??????? ??????????
    ofst << "Aphorism's author is: " << Author << endl; //??????? ??????
}

void Proverb::Out_Data(ofstream& ofst) {
    ofst << "It's a Proverb: " << Content << endl; //??????? ??????????
    ofst << "Proverbs's country is: " << Country << endl; //??????? ??????
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