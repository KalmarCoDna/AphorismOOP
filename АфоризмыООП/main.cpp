// 1lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command in_file out_file"
            << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "Start" << endl;

    Container c;

    c.In(ifst);
    ofst << "Filled container. " << endl;
    c.Out(ofst);

    c.Clear();
    ofst << "Empty container. " << endl;
    c.Out(ofst);

    cout << "Stop" << endl;
    system("pause");
    return 0;
}