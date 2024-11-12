#include <iostream>
using namespace std;

//Creating a struct to hold data and a address pointer 
struct slinklist{
    int data;
    struct slinklist* node;
};

//Creating the node type and creating a starting address of NULL
typedef struct slinklist node;
node* start = NULL;



node* get_node();


int main(){

    
    node* newNode = get_node();
    cout << "Data entered: " << newNode->data << endl;
    
    delete newNode;  

    return 0;
}

//Creates 
node* get_node(){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    cout << "Enter Data: " << endl;
    cin >> newnode -> data;
    newnode -> node = NULL;
    return newnode;

}