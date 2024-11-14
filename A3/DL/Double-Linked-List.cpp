/*
Nathan Boyden
COP 3530
Assignmnet 3
11/14/2024
*/

#include <iostream>
using namespace std;

// Most things are the same but next is replaced with right
//Struct that contains one data item and a next pointers
struct dlinklist{
    //Stores the data for a given node
    int data;

    //Points to the address of the right node in the list
    struct dlinklist* right;

    //Points to the address of the left node in the list
    struct dlinklist* left;
};

//Allows other functions to use and manipulate the struct
typedef struct dlinklist node;
//Forces the start varible to be NULL meaning the list is empty by default
node* start = NULL;


//Function Prototypes 
node* getnode();
void transverse();
void delete_at_end();
void insert_in_beg();
void createlist(int n);
int countnode(node* start);

int main(){

    //Size of list
    int number;
    cout << "Number of Nodes: ";
    cin >> number;
    
    //Creates list then displays it
    createlist(number);
    transverse();
    
    //Deletes element then displays it 
    delete_at_end();
    transverse();
    
    //Inserts the new element then displays it
    insert_in_beg();
    transverse();
    

    return 0;
}

node* getnode(){
    //A newnode is create and added to memory
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    
    //Ask user for data inside of list
    cout << "\nEnter Data: ";
    cin >> newnode -> data;
    
    //Assigns the newest data to NULL meaning it's the end of the list 
    newnode -> left = NULL;
    newnode -> right = NULL;
    
    //Then returns the pointer to the new node so the next node can point to the previous
    return newnode;
}


void createlist(int n){
    
    int i;
    node* newnode;
    node* temp;
    
    //Loops for the length of the list 
    for(i = 0; i < n; i++){
        //Creates new node (with a pointer to the previous)
        newnode = getnode();
        //If list is empty fill it 
        if(start == NULL){
            start = newnode;
        }
        //If the list isnt empty 
        else{
            //Sets temp to the start of the list
            temp = start;
            //Goes through the list until is reaches the last node
            while(temp -> right){
                temp = temp -> right;
            }
            //This then links the last node to the new last node and the left node to the previous node
            temp -> right = newnode;
            newnode -> left = temp;
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
    //Print the data of each node then set the pointer to the next node
    else{
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> right;
        }
    }
}    


//Counts length of list (node count)
int countnode(node* start) {
    int c = 0;
    node* temp = start;
    while (temp != NULL) {
        c++;
        temp = temp-> right;
    }
    return c;
}

void delete_in_end(){
    node *temp;
    
    //Checks if list is empty
    if(start==NULL){
        cout << "\nEmpty List";
        return;
    }
    else{
        temp = start;
        //To to end of list
        while(temp -> right){
            //Shift for one position
            temp = temp -> right;
        }
        //Sets temp to the last node
        temp -> left -> right = NULL;
        //Deletes node
        free(temp);
    }
}

void insert_in_beg(){
    //Gets a new node
    node* newnode;
    newnode = getnode();

    //Checks if list is empty
    if(start==NULL){
        cout << "\nEmpty List";
        return;
    }
    else{
        newnode -> right = start;
        start-> left = newnode;
        start = newnode;
    }


}