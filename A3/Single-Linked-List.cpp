#include <iostream>
using namespace std;


struct slinklist{
    int data;
    struct slinklist* next;
};

typedef struct slinklist node;
node* start = NULL;


//Function Prototypes 
node* getnode();
void transverse();
void detele_at_mid();
void insert_in_mid(node* newnode);
void createlist(int n);
int countnode(node* start);

int main(){

    int number;
    cout << "Number of Nodes: ";
    cin >> number;
    
    createlist(number);
    transverse();
    detele_at_mid();
    transverse();
    node* existingNode = getnode();
    insert_in_mid(existingNode);
    transverse();
    

    return 0;
}


node* getnode(){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    cout << "\nEnter Data: ";
    cin >> newnode -> data;
    newnode -> next = NULL;
    return newnode;
}

void createlist(int n){
    int i;
    node* newnode;
    node* temp;
    for(i = 0; i < n; i++){
        newnode = getnode();
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

void detele_at_mid(){
    int ctr = 1, pos, nodectr;
    node *temp, *prev;
    if(start==NULL){
        cout << "\nEmpty List";
        return;
    }
    else{
        cout << "\nEnter postion to delete: ";
        cin >> pos;
        nodectr = countnode(start);
        if (pos > nodectr){
            cout << "\nNode doesn't exist";
        }
        if(pos > 1 && pos < nodectr){
            temp = prev = start;
            while(ctr < pos){
                prev = temp;
                temp = temp -> next;
                ctr++;
            }
            prev -> next = temp -> next;
            free(temp);
            cout << "\nNode Deleted";
        }
        else{
            cout << "\nInvalid Postion";
        }
    }

}


void transverse(){
    node* temp; 
    temp = start;
    cout << "\nList: ";
    if(start == NULL){
        cout << "Empty List";
    }       
    else{
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
}    

int countnode(node* start) {
    int c = 0;
    node* temp = start;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

void insert_in_mid(node* newnode){
    node *temp, *prev;
    int pos, nodectr, ctr = 1;
    cout << "\nEnter position: ";
    cin >> pos;
    nodectr = countnode(start);
    if(pos > 1 && pos < nodectr){
        temp = prev = start;
        while(ctr < pos){
            prev = temp;
            temp = temp -> next;
            ctr++;
        }
        prev -> next = newnode;
        newnode -> next = temp;
    }
    else{
        cout << pos << "is not a middle postion.";
    }

}
