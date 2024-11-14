/*
Nathan Boyden
COP 3530
Assignmnet 3
11/14/2024
*/

#include <iostream>
using namespace std;

//Struct that contains one data item and a next pointer
struct slinklist{
    //Stores the data for a given node
    int data;
    //Points to the address of the next node in the list
    struct slinklist* next;
};

//Allows other functions to use and manipulate the struct
typedef struct slinklist node;
//Forces the start varible to be NULL meaning the list is empty by default
node* start = NULL;


//Function Prototypes 
node* getnode();
void transverse();
void detele_at_mid();
void insert_in_mid(node* newnode);
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
    detele_at_mid();
    transverse();
    
    //Adds new element from getnode to the existing list instead of making a new one
    node* existingNode = getnode();
    
    //Inserts the new element then displays it
    insert_in_mid(existingNode);
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
    newnode -> next = NULL;
    
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
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            //This then links the last node to the new last node
            temp -> next = newnode;
        }
    }
}


void detele_at_mid(){
    int ctr = 1, pos, nodectr;
    node *temp, *prev;
    
    //Checks if list is empty
    if(start==NULL){
        cout << "\nEmpty List";
        return;
    }
    //If not it actually executes
    else{
        //Sets position for deletion
        cout << "\nEnter postion to delete: ";
        cin >> pos;
        
        //A counter
        nodectr = countnode(start);
        
        //If the position is greater than the list length prints error
        if (pos > nodectr){
            cout << "\nNode doesn't exist";
        }
        //If the postion is within the list length then execute
        if(pos > 1 && pos < nodectr){
            //Sets both temp and prev to start of the list 
            temp = prev = start;
            //While position is greater than the counter, execute
            while(ctr < pos){
                //Set prev to temp and temp to the next node
                prev = temp;
                temp = temp -> next;
                ctr++;
            }
            //Once the position is found 
            prev -> next = temp -> next;
            //Delete position
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
    //Print the data of each node then set the pointer to the next node
    else{
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
}    


//Counts length of list (node count)
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
    
    //User gives postion 
    cout << "\nEnter position: ";
    cin >> pos;
    
    //Gets length of list
    nodectr = countnode(start);
    
    //If position exists in the list
    if(pos > 1 && pos < nodectr){
        //Set of prev and temp to start
        temp = prev = start;
        
        //While position isnt found yet, set prev to temp and temp to the next node
        while(ctr < pos){
            prev = temp;
            temp = temp -> next;
            ctr++;
        }
        //Once its found insert newnode from the main into the position in the list 
        prev -> next = newnode;
        newnode -> next = temp;
    }
    else{
        cout << pos << "is not a middle postion.";
    }

}
