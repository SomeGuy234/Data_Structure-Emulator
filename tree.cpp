#include <iostream>
#include <windows.h>
#include <conio.h>
#include "classes.h"
#include "ConsoleColor.h"

using namespace std;

void main_menu();
void loading();

void tree_menu()
{
    char tree_choice;
    Tree drzewo;
    for (int i = 0; i < 16; i++)
        drzewo.empty[i]=true;
    drzewo.root=NULL;
    do
    {
        system("cls");
        drzewo.show();
        cout << "\n\nMENU DRZEWA:"<<endl;
        cout << "------------------------------------------------------------------"<< endl;
        cout << "1. Add (dodaje element do drzewa) "<< endl;
        cout << "2. Find (znajduje podany element w drzewie i podaje numer wezla) "<< endl;
        cout << "3. Menu glowne "<< endl;
        cout << "------------------------------------------------------------------"<< endl;
        cout << "   Wybor (zatwierdz enterem): ";
        tree_choice = getch();
        Sleep(100);
        switch(tree_choice)
        {
        case '1':
            drzewo.add();
            break;
        case '2':
            drzewo.find();
            break;
        case '3':
            delete [] drzewo.numbers;
            main_menu();
            break;
        default:
            cout << "\n   Wybierz liczbe z zakresu 1-3!";
            Sleep(1000);
        }
    }while (tree_choice != 3);
}

void Tree::gotoxy(int x, int y)
{
    COORD C;
    C.X = x;
    C.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),C);
}

void Tree::show()
{
    cout << gray;
    gotoxy(40,1); if (empty[1] == true) cout << "_" ; else cout << numbers[1];
    gotoxy(20,4); if (empty[2] == true) cout << "_" ; else cout << numbers[2];
    gotoxy(60,4); if (empty[3] == true) cout << "_" ; else cout << numbers[3];
    gotoxy(10,6); if (empty[4] == true) cout << "_" ; else cout << numbers[4];
    gotoxy(30,6); if (empty[5] == true) cout << "_" ; else cout << numbers[5];
    gotoxy(50,6); if (empty[6] == true) cout << "_" ; else cout << numbers[6];
    gotoxy(70,6); if (empty[7] == true) cout << "_" ; else cout << numbers[7];
    gotoxy(5,10); if (empty[8] == true) cout << "_" ; else cout << numbers[8];
    gotoxy(15,10); if (empty[9] == true) cout << "_" ; else cout << numbers[9];
    gotoxy(25,10); if (empty[10] == true) cout << "_" ; else cout << numbers[10];
    gotoxy(35,10); if (empty[11] == true) cout << "_" ; else cout << numbers[11];
    gotoxy(45,10); if (empty[12] == true) cout << "_" ; else cout << numbers[12];
    gotoxy(55,10); if (empty[13] == true) cout << "_" ; else cout << numbers[13];
    gotoxy(65,10); if (empty[14] == true) cout << "_" ; else cout << numbers[14];
    gotoxy(75,10); if (empty[15] == true) cout << "_" ; else cout << numbers[15];
    cout << white;
}

void Tree::add()
{
    int num;
    cout << "\n   Podaj liczbe, ktora chcesz wprowadzic do drzewa: ";
    cin >> num;
    if (empty[1] == true)
    {
        cout << "   Dodawanie";
        loading();
        root = &numbers[1];
        *root = num;
        empty[1] = false;
    }
    else
    {
        bool foundPlace = false;
        int index = 1;
        while (foundPlace == false)
        {
            if (empty[index] == true)
            {
                cout << "   Dodawanie";
                loading();
                foundPlace = true;
                numbers[index] = num;
                empty[index]= false;
            }
            else if(num < numbers[index])
                index = 2 * index;
            else
                index = 2 * index + 1;
            if(index > 15)
            {
                cout<<"   Potrzebne byloby wieksze drzewo!";
                Sleep(1000);
                foundPlace=true;
            }
        }
    }

}

void Tree::find()
{
    int num;
    cout << "\n   Podaj liczbe, ktora chcesz odnalezc w drzewie: ";
    cin >> num;
    bool found = false;
    int index = 1;
    while (found == false)
    {
        if(num == numbers[index])
        {
            cout << "   Szukanie";
            loading();
            cout<<"\n   Znaleziono liczbe w wezle nr "<< index;
            Sleep(1500);
            found = true;
        }
        else if(num < numbers[index])
            index = 2 * index;
        else
            index = 2 * index + 1;
        if(index>15)
        {
            cout << "   Szukanie";
            loading();
            cout<<"\n   Nie znaleziono!";
            Sleep(1000);
            found = true;
        }
    }
}
