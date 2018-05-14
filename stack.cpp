#include <iostream>
#include <windows.h>
#include <conio.h>
#include "classes.h"
#include "ConsoleColor.h"

using namespace std;

void main_menu();
void loading();

void stack_menu()
{
    char stack_choice;
    Stack stos;
    stos.generate();
    system("cls");
    do
    {
        stos.show();
        cout << "MENU STOSU:"<<endl;
        cout << "-------------------------------------------"<<endl;
        cout << "1. Push (dodaje element na szczyt stosu) "<<endl;
        cout << "2. Pop (usuwa element ze szczytu stosu) "<<endl;
        cout << "3. Size (podaje liczbe elementow na stosie) "<<endl;
        cout << "4. Empty (sprawdza czy stos jest pusty) "<<endl;
        cout << "5. Menu glowne "<<endl;
        cout << "-------------------------------------------"<<endl;
        cout << "   Wybor: ";
        stack_choice = getch();
        Sleep(100);

        switch (stack_choice)
        {
        case '1':
            stos.push();
            break;

        case '2':
            stos.pop();
            break;

        case '3':
            stos.size();
            break;

        case '4':
            stos.empty();
            break;

        case '5':
            delete stos.numbers;
            main_menu();
            break;

        default:
            cout << "Wybierz liczbe z zakresu 1-5!";
            Sleep(1000);
        }
    } while (stack_choice != 5);
}

void Stack::generate()
{
    do
    {
        cout << "\n   Przed utworzeniem stosu, podaj maksymalna liczbe elementow: ";
        cin >> max_amount;
    }
    while(max_amount <= 0);
    numbers = new int[max_amount];
    now_amount = 0;
}

void Stack::show()
{
    system("cls");
    cout << yellow;
    cout << "------------------" << endl;
    cout << "ZAWARTOSC STOSU: " << endl;
    cout << "------------------" << endl;
    if(now_amount == 0)
        cout << "pusty" << endl;
    else
        for(int i = now_amount-1; i >= 0; i--)
            cout << numbers[i] << endl;
    cout << "------------------" << endl;
    cout << white;
}

void Stack::push()
{
    if(now_amount < max_amount)
    {
        cout << "\n   Podaj liczbe, ktora chcesz dodac do stosu: ";
        cin >> numbers[now_amount];
        now_amount++;
        cout << "   Dodawanie";
        loading();
    }
    else
    {
        cout << "\n   Stos pelny!";
        Sleep(700);
    }
}

void Stack::pop()
{
    if(now_amount > 0)
    {
        cout << "\n   Usuwanie liczby " << numbers[now_amount-1];
        loading();
        now_amount--;
    }
    else
    {
        cout << "\n   Stos pusty!";
        Sleep(1000);
    }
}

void Stack::size()
{
    cout << "\n   Funkcja zwraca aktualny rozmiar stosu, czyli " << now_amount;
    Sleep(1000);
}

void Stack::empty()
{
    if(now_amount == 0)
        cout << "\n   Funkcja przyjmuje wartosc 'true'";
    else
        cout << "\n   Funkcja przyjmuje wartosc 'false'";
    Sleep(1000);
}
