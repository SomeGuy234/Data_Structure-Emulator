#include <iostream>
#include <windows.h>
#include <conio.h>
#include "classes.h"
#include "ConsoleColor.h"

using namespace std;

void main_menu();

int main()
{
    main_menu();
    return 0;
}

void main_menu()
{
    char choice;
    system("cls");
    do
    {
        cout << violet;
        cout << "=========================" << endl;
        cout << "EMULATOR STRUKTUR DANYCH" << endl;
        cout << "=========================" << endl;
        cout << white;
        cout << "MENU GLOWNE:" << endl;
        cout << "--------------------" << endl;
        cout << "1. Stos" << endl;
        cout << "2. Kolejka" << endl;
        cout << "3. Lista" << endl;
        cout << "4. Drzewo binarne" << endl;
        cout << "5. Wyjscie" << endl;
        cout << "--------------------" << endl;
        cout << "   Wybor: ";
        choice = getch();
        switch(choice)
        {
        case '1':
            stack_menu();
            break;
        case '2':
            queue_menu();
            break;
        case '3':
            list_menu();
            break;
        case '4':
            tree_menu();
            break;
        case '5':
            exit(0);
            break;
        default:
            cout << "\n   Wybierz liczbe z zakresu 1-5!";
            Sleep(1000);
            system("cls");
            break;
        }
    }while(choice != 5);
}

void loading()
{
    for(int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(250);
    }
}
