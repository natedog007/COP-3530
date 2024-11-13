#include <iostream>
using namespace std;
struct dlinklist {
    int data;
    struct dlinklist* next;
    struct dlinklist* prev;
};

typedef struct dlinklist node;
node* start = NULL;  


node* get_node();
void display();
void delete_at_mid();
void createlist(int n);
int countnode(node* start);

int main() {
    int number;
    cout << "Number of Nodes: ";
    cin >> number;
    
    createlist(number);
    display();
    delete_at_mid();
    display();  

    return 0;
}

node* get_node(){

}
void display(){
    
}
void delete_at_mid(){

}
void createlist(int n){

}
int countnode(node* start){
    
}