#include <iostream>
#include <windows.h>
#include <conio.h>
#include "classes.h"
#include "ConsoleColor.h"

using namespace std;

void main_menu();
void loading();

void queue_menu()
{
    char queue_choice;
    Queue kolejka;
    kolejka.generate();
    system("cls");
    do
    {
        kolejka.show();
        cout << "MENU KOLEJKI:"<<endl;
        cout << "---------------------------------------------"<<endl;
        cout << "1. Push (dodaje element na koniec kolejki) "<<endl;
        cout << "2. Pop (usuwa glowe kolejki) "<<endl;
        cout << "3. Size (podaje liczbe elementow w kolejce) "<<endl;
        cout << "4. Front (pokazuje pierwszy element kolejki) "<<endl;
        cout << "5. Back (pokazuje ostatni element kolejki) "<<endl;
        cout << "6. Empty (sprawdza czy kolejka jest pusta) "<<endl;
        cout << "7. Menu glowne "<<endl;
        cout << "---------------------------------------------"<<endl;
        cout << "   Wybor: ";
        queue_choice = getch();
        Sleep(100);

        switch (queue_choice)
        {
        case '1':
            kolejka.push();
            break;
        case '2':
            kolejka.pop();
            break;
        case '3':
            kolejka.size();
            break;
        case '4':
            kolejka.front();
            break;
        case '5':
            kolejka.back();
            break;
        case '6':
            kolejka.empty();
            break;
        case '7':
            delete kolejka.numbers;
            main_menu();
            break;
        default:
            cout << "Wybierz liczbe z zakresu 1-7!";
            Sleep(1000);
        }
    }
    while (queue_choice != 6);
}

void Queue::generate()
{
    do
    {
        cout << "\n   Przed utworzeniem kolejki, podaj maksymalna liczbe elementow: ";
        cin >> max_amount;
    }
    while(max_amount <= 0);
    numbers = new int[max_amount];
    now_amount = 0;
    head = 0;
    tail = 0;
}

void Queue::show()
{
    system("cls");
    cout << green;
    cout << "------------------" << endl;
    cout << "ZAWARTOSC KOLEJKI: " << endl;
    cout << "------------------" << endl;
    if(now_amount == 0)
    {
        cout << "pusta" << endl;
        head = 0;
        tail = 0;
    }
    else
    {
        for(int i = now_amount-1; i >= 0; i--)
            cout << numbers[i] << " ";
        cout << endl;
    }
    cout << "------------------" << endl;
    cout << white;
}

void Queue::push()
{
    if(now_amount < max_amount)
    {
        cout << "\n   Podaj liczbe, ktora chcesz dodac do kolejki: ";
        cin >> numbers[now_amount];
        head = numbers[0];
        now_amount++;
        cout << "   Dodawanie";
        loading();
        tail = numbers[now_amount-1];
    }
    else
    {
        cout << "\n   Kolejka pelna!";
        Sleep(800);
    }
}

void Queue::pop()
{
    if(now_amount > 0)
    {
        cout << "\n   Usuwanie glowy kolejki, czyli liczby " << head;
        loading();
        for(int i = 0; i < now_amount; i++)
            swap(numbers[i],numbers[i+1]);
        now_amount--;
        head = numbers[0];
    }
    else
    {
        cout << "\n   Kolejka pusta!";
        Sleep(800);
    }
}

void Queue::size()
{
    cout << "\n   Funkcja zwraca aktualny rozmiar kolejki, czyli " << now_amount;
    Sleep(1000);
}

void Queue::front()
{
    if(head != 0)
        cout << "\n   Pierwszy element w kolejce to " << head;
    else
        cout << "\n   Kolejka pusta!";
    Sleep(800);
}

void Queue::back()
{
    if(head != 0)
        cout << "\n   Ostatni element w kolejce to " << tail;
    else
        cout << "\n   Kolejka pusta!";
    Sleep(800);
}

void Queue::empty()
{
    if(now_amount == 0)
        cout << "\n   Funkcja przyjmuje wartosc 'true'";
    else
        cout << "\n   Funkcja przyjmuje wartosc 'false'";
    Sleep(1000);
}
