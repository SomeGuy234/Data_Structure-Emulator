#include <iostream>
#include <windows.h>
#include <list>
#include "classes.h"
#include "ConsoleColor.h"

using namespace std;

void main_menu();
void loading();

void list_menu()
{
    int list_choice;
    List lista;
    system("cls");
    do
    {
        lista.show();
        cout << "MENU LISTY:"<<endl;
        cout << "--------------------------------------------------------------"<< endl;
        cout << "1. Push_front (dodaje element na poczatek listy) "<< endl;
        cout << "2. Push_back (dodaje element na koniec listy) "<< endl;
        cout << "3. Pop_front (usuwa element z poczatku listy) "<< endl;
        cout << "4. Pop_back (usuwa element z konca listy) "<< endl;
        cout << "5. Size (podaje liczbe elementow w liscie) "<< endl;
        cout << "6. Max_size (podaje maksymalna liczbe elementow w liscie) "<< endl;
        cout << "7. Empty (sprawdza czy lista jest pusta) "<< endl;
        cout << "8. Remove (usuwa podana wartosc z listy i jej powtorzenia) "<< endl;
        cout << "9. Sort (sortuje liste) "<< endl;
        cout << "10. Reverse (odwraca kolejnosc) "<< endl;
        cout << "11. Menu glowne "<<endl;
        cout << "--------------------------------------------------------------"<< endl;
        cout << "    Wybor (zatwierdz enterem): ";
        cin >> list_choice;
        Sleep(100);
        switch (list_choice)
        {
        case 1:
            lista.push_front();
            break;

        case 2:
            lista.push_back();
            break;

        case 3:
            lista.pop_front();
            break;

        case 4:
            lista.pop_back();
            break;

        case 5:
            lista.size();
            break;

        case 6:
            lista.max_size();
            break;

        case 7:
            lista.empty();
            break;

        case 8:
            lista.remove();
            break;

        case 9:
            lista.sort();
            break;

        case 10:
            lista.reverse();
            break;

        case 11:
            main_menu();
            break;

        default:
            cout << "    Wybierz liczbe z zakresu 1-11!";
            Sleep(1000);
        }
    }while (list_choice != 11);
}

void List::show()
{
    system("cls");
    cout << red;
    cout << "------------------" << endl;
    cout << "ZAWARTOSC LISTY: " << endl;
    cout << "------------------" << endl;
    for(list<int>::iterator i = lista.begin(); i != lista.end(); i++)
            cout << *i << " ";
    cout << "\n------------------" << endl;
    cout << white;
}

void List::push_front()
{
    int number;
    cout << "    Podaj liczbe, ktora chcesz dodac na poczatek listy: ";
    cin >> number;
    lista.push_front(number);
    cout << "    Dodawanie";
    loading();
}

void List::push_back()
{
    int number;
    cout << "    Podaj liczbe, ktora chcesz dodac na koniec listy: ";
    cin >> number;
    lista.push_back(number);
    cout << "    Dodawanie liczby";
    loading();
}
void List::pop_front()
{
    if(lista.size() != 0)
    {
        cout << "    Usuniecie elementu z poczatku listy";
        lista.pop_front();
        loading();
    }
    else
    {
        cout << "    Lista pusta!";
        Sleep(700);
    }
}

void List::pop_back()
{
    if(lista.size() != 0)
    {
        cout << "    Usuniecie elementu z konca listy";
        lista.pop_back();
        loading();
    }
    else
    {
        cout << "    Lista pusta!";
        Sleep(700);
    }
}

void List::size()
{
    cout << "    Funkcja zwraca aktualny rozmiar listy, czyli " << lista.size();
    Sleep(1000);
}

void List::max_size()
{
    cout << "    Funkcja zwraca maksymalny rozmiar listy, czyli " << lista.max_size();
    Sleep(1000);
}

void List::empty()
{
    if(lista.empty() == 1)
        cout << "    Funkcja przyjmuje wartosc 'true'";
    else
        cout << "    Funkcja przyjmuje wartosc 'false'";
    Sleep(1000);
}

void List::remove()
{
    if(lista.size() == 0)
    {
        cout << "    Lista pusta!";
        Sleep(700);
    }
    else
    {
        int n;
        cout << "    Podaj, jaka liczbe chcesz usunac: ";
        cin >> n;
        for(list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        {
            if(n == *i)
            {
                cout << "    Usuwanie";
                loading();
                lista.remove(n);
                break;
            }
            else
                continue;
        }
    }
}

void List::sort()
{
    if(lista.size() == 0)
    {
        cout << "    Lista pusta!";
        Sleep(700);
    }
    else
    {
        cout << "    Sortowanie listy";
        loading();
        lista.sort();
    }
}

void List::reverse()
{
    if(lista.size() == 0)
    {
        cout << "    Lista pusta!";
        Sleep(700);
    }
    else
    {
        cout << "    Odwracanie listy";
        loading();
        lista.reverse();
    }
}

