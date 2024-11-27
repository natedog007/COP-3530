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
    int ch;
    do{
        ch = menu();
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
        
    }
    while(1);
    return 0;
}

//Display a menu and returns that menu value to the main where that process can occur
int menu(){
    int ch;
    cout << "\n 1. Push\n 2. Pop\n 3. Display\n 4. Quit\n ";
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
    else{
        cout << "\n Element/s in Stack: ";
        for(i = 0; i < top; i++){
            cout << stack[i] << " ";
        }
    }
}

//Checks if empty if not removed the top and moves the top to the next element 
void pop(){
    if(top == 0){
        cout << "\n ... ";
        return;
    }
    else{
        cout << "\n ..." << stack[--top];
        
    }

}

//Checks if empty if not takes user data and adds to stack then makes new data the top
void push(){
    int data;
    if(top == MAX){
        cout << "\n Stack Overflow";
        return;
    }
    else{
        cout << "\n Enter Data: ";
        cin >> data;
        stack[top] = data;
        ++top;
        cout << "\n Data pushed into the stack";
    }
    
}