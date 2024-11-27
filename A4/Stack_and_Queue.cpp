/*
Nathan Boyden 
COP 3530
Assignment 4
11/26/24
*/

#include <stdio.h>
#include <iostream>
//Defines max size of stack and where the top is (the bottom by default)
#define MAX 6
int stack[MAX];
int top = 0;

using namespace std;

//Prototypes
int menu();
void display();
void pop();
void push();


int main(){
    return 0;
}

//Display a menu and returns that menu value to the main where that process can occur
int menu(){
    int ch;
    cout << "\n 1. Push\n 2. Pop\n 3. Display\n 4. Quit";
    cin >> ch;
    return ch;
}

//Displays whats currently in the stack and displays nothing if empty
void display(){
    int i;
    if(top == 0){
        cout << "\n Stack is empty";
        return;
    
    }
}

void pop(){


}

void push(){

    
}