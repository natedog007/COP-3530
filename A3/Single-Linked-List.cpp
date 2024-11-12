#include <iostream>
using namespace std;


struct slinklist{
    int data;
    struct slinklist* next;
};


typedef struct slinklist node;
node* start = NULL;


node* get_node();
void  createlist();


int main(){

    int number;
    get_node();
    createlist(number);  

    return 0;
}


node* get_node(){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    cout << "Enter Data: " << endl;
    cin >> newnode -> data;
    newnode -> next = NULL;
    return newnode;
}

void createlist(int n){
    int i;
    node* newnode;
    node* temp;
    for(i=0;i<n;i++){
        newnode = get_node();
        if(start == NULL){
            start = newnode;
        }
        else{
            temp = start;
            while(temp-> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newnode;
        }
    }
}