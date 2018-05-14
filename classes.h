#include <iostream>
#include <windows.h>
#include <conio.h>
#include <list>

using namespace std;

void stack_menu();
void queue_menu();
void list_menu();
void tree_menu();

struct Stack
{
    int max_amount;
    int now_amount;
    int *numbers;

    void generate();
    void show();
    void push();
    void pop();
    void size();
    void empty();
};

struct Queue
{
    int max_amount;
    int now_amount;
    int head;
    int tail;
    int *numbers;

    void generate();
    void show();
    void push();
    void pop();
    void front();
    void back();
    void size();
    void empty();
};

struct List
{
    list<int>lista;

    void show();
    void push_front();
    void push_back();
    void pop_front();
    void pop_back();
    void size();
    void max_size();
    void empty();
    void remove();
    void sort();
    void reverse();
};

struct Tree
{
    int numbers[16];
    bool empty[16];
    int *root;

    void gotoxy(int x, int y);
    void show();
    void add();
    void find();
};
