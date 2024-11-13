#include <iostream>
using namespace std;

// Define the doubly linked list node structure
struct dlinklist {
    int data;
    struct dlinklist* next;
    struct dlinklist* prev;
};

typedef struct dlinklist node;
node* start = NULL;  // Start pointer to the beginning of the list

// Function Prototypes
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

// Function to create a new node and get user input for data
node* get_node() {
    node* newnode = new node();
    cout << "\nEnter Data: ";
    cin >> newnode->data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Function to create a doubly linked list with 'n' nodes
void createlist(int n) {
    node* newnode;
    node* temp;
    for (int i = 0; i < n; i++) {
        newnode = get_node();
        if (start == NULL) {
            start = newnode;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;  // Set the previous pointer of the new node
        }
    }
}

// Function to delete a node at a specific position in the middle of the list
void delete_at_mid() {
    int pos, nodectr;
    node* temp;
    if (start == NULL) {
        cout << "\nEmpty List";
        return;
    }

    cout << "\nEnter position to delete: ";
    cin >> pos;

    nodectr = countnode(start);
    if (pos > nodectr || pos <= 0) {
        cout << "\nInvalid Position";
        return;
    }

    temp = start;
    if (pos == 1) {  // Special case for deleting the first node
        start = start->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        delete temp;
        cout << "\nNode Deleted at Position " << pos;
        return;
    }

    // Traverse to the node at position `pos`
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    // Unlink the node to be deleted
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    cout << "\nNode Deleted at Position " << pos;
}

// Function to display the list from start to end
void display() {
    node* temp = start;
    cout << "\nList: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to count the number of nodes in the list
int countnode(node* start) {
    int c = 0;
    node* temp = start;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}
