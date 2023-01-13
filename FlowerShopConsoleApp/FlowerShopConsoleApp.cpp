#include <iostream>
#include <fstream>
#include <ctime>
#include <locale>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
fstream clientele;

string data(string& str)
{
    string str1;
    str1 = str;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] == ',')
        {
            str1.resize(i);
            str = str.erase(0, i + 2);
        }
    }
    return str1;
}

void Menu() {
    cout << "Функции : \n \n 1) Вывести текущие заказы \n 2) Добавить заказ \n 3) Удалить заказ \n 4) Вывести список сотрудников \n 5) Выход \n\n";
}

void Order() {
    string str, s;
    clientele.open("order.txt", ios::binary | ios::in);
    if (!clientele.is_open())
    {
        cout << "Ошибка открытия файла" << endl;

    }
    if (!clientele.eof())
    {
        while (!clientele.eof())
        {
            getline(clientele, str);
            cout << str.substr(0, str.find(",")) << endl;
        }
    }
    clientele.close();
    cout << endl;
    system("pause");
}

void Add() {
    system("cls");
    string name, type, date;
    cin.ignore(32767, '\n');
    cout << "Введите имя заказа" << endl;
    getline(cin, name);
    cout << "Введите тип оплаты" << endl;
    getline(cin, type);
    cout << "Введите дату заказа" << endl;
    getline(cin, date);

    clientele.open("order.txt", ios::binary | ios::app);
    if (!clientele.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return;
    }

    clientele << endl;
    clientele << name << ", " << type << ", " << date;
    clientele.close();
    cout << endl;
    system("pause");
}

void Delete() {
    system("cls");
    string name, str;
    fstream clientele1;
    cin.ignore(32767, '\n');
    cout << "Введите имя заказа" << endl;
    getline(cin, name);

    clientele1.open("clientele1.txt", ios::binary | ios::out);
    if (!clientele1.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    clientele.open("order.txt", ios::binary | ios::in);
    if (!clientele.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }

    if (!clientele.eof())
    {
        while (!clientele.eof())
        {
            getline(clientele, str);
            if (str.find(name))
                clientele1 << str << endl;
        }
    }
    clientele.close();
    clientele1.close();


    clientele.open("order.txt", ios::binary | ios::out);
    if (!clientele.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    clientele1.open("clientele1.txt", ios::binary | ios::in);
    if (!clientele1.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    if (!clientele1.eof())
    {
        while (!clientele1.eof())
        {
            getline(clientele1, str);
            if (str.find(name))
                clientele << str << endl;
        }
    }

    clientele.close();
    clientele1.close();
    cout << endl;
    system("pause");
}

void List() {
    string str, s;
    clientele.open("list.txt", ios::binary | ios::in);
    if (!clientele.is_open())
    {
        cout << "Ошибка открытия файла" << endl;

    }
    if (!clientele.eof())
    {
        while (!clientele.eof())
        {
            getline(clientele, str);
            cout << str << endl;
        }
    }
    clientele.close();
    cout << endl;
    system("pause");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int variant=0;

    while (variant != 5)
    {
        Menu();
        cin >> variant;
        switch (variant)
        {
        case 1:
            Order();
            break;

        case 2:
            Add();
            break;

        case 3:
            Delete();
            break;

        case 4:
            List();
            break;

        case 5:
            break;
        }

    }
	
}


