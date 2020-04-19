#include<iostream>
using namespace std;

    // A class to create Nodes
    class Node{

        public:
            int key;
            int data;
            Node* next; // same class pointers

        //default constructor
        Node(){
            key = 0;
            data = 0;
            next = NULL;
        }

        //parametrized constructor
        Node(int k, int d){
            key = k;
            data = d;
        }
    };

    // Class to perform operations on the node
    class SinglyLinkedList{

        public:
            Node* head;

        SinglyLinkedList(){
            head = NULL;
        }

        // passing the argument by address
        SinglyLinkedList(Node *n){
            head=n;
        }

        //method to check whether a node is present or not (using key value)
        Node* nodeExist(int k){
            //iterating through the list from head to NULL (using ptr) (key should be unique)
            Node* temp = NULL;
            Node* ptr = head;

            while (ptr!=NULL){
                // only if the key value of the node which the current pointer
                // is pointing is equal to the key value we passed. (Node exists in that case)
                if(ptr->key==k){
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp; // it is either NULL or points to the Node whose key value is passed
        }

        // append a Node to the list (append is done at the end)
        void appendNode(Node *n){
            //we must traverse to the end of the List,
            // but first we check if the key value of the entered Node is unique
            if(nodeExist(n->key)!=NULL){
                cout << "Node already exist with key value, " << n->key << ". Try appending a different node with a different key value" << endl;
            }
            // Actual appending of the Node
            else{
                // In case this is the first append (head is pointing to NULL in that case)
                // No node initially in the List
                if(head==NULL){
                    head = n;
                    cout << "Node is appended." << endl;
                }
                // When the head is pointing to some node. (The case where there is atleast one node present)
                //Appending a Node is done at the end
                else{
                    //traversing to the end of the list(last Node) (using pointer ptr)
                    Node* ptr = head;
                    while(ptr->next!=NULL){
                        ptr = ptr->next;
                    }
                    //ptr has reached the last Node
                    ptr->next = n;
                    cout << "Node appended succesfully." << endl;
                }
            }
        }

        // prepend Node (attaching Node at the beginning)
        void prependNode(Node* n){
            // Ensure first that we donot have duplicate key values of multiple nodes
            if(nodeExist(n->key)!=NULL){
                cout << "Node already exist with key value, " << n->key << ". Try appending a different node with a different key value" << endl;
            }
            else{
                n->next=head;
                head = n;
                cout << "Node prepended succesfully." << endl;
            }
        }

        // Insert a Node after a particular node in the List.
        // Give key value of the node after which we want to insert node (n)
        void insertNode(int k, Node* n){
            Node* ptr = nodeExist(k);
            if (ptr==NULL){
                cout << "No node exist with the key value " << k << "." << endl;
            }
            else{
                if(nodeExist(n->key)!=NULL){
                    cout << "Node already exist with key value, " << n->key << ". Try appending a different node with a different key value" << endl;
                }
                else{
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node inserted successfully after key " << k << "." << endl;
                }
            }
        }

        //Delete node by specifying the unique key (tricky!!)
        void deleteNode(int k){
            if(head==NULL){
                cout << "List is empty. Cannot delete any node!" << endl;
            }
            else if(head!=NULL){
                // if the head node is required to delete
                if(head->key==k){
                    // the second Node (head->next) will become the head node
                    head = head->next;
                    cout << "Node with key value " << k << " is unlinked." << endl;
                }
                // deleting a node which is not the head node
                else{
                    // traverse to that node (two pointers required)
                    Node* temp = NULL;
                    Node* previous_ptr = head;
                    Node* current_ptr = head->next;
                    while(current_ptr!=NULL){
                        if(current_ptr->key==k){
                            temp = current_ptr;
                            current_ptr = NULL;
                        }
                        else{
                            previous_ptr = previous_ptr->next;
                            current_ptr = current_ptr->next;
                        }
                        if(temp!=NULL){
                            previous_ptr->next = temp->next;
                            cout << "Node with key value " << k << " is unlinked." << endl;
                        }
                        else{
                            cout << "Node with key value " << k << " does not exist." << endl;
                        }
                    }
                }
            }
        }

        // Update node: Access node with key value and update its data
        void updateNode(int k, int data){
            Node* ptr = nodeExist(k);
            if(ptr!=NULL){
                ptr->data = data;
                cout << "Node data updated successfully." << endl;
            }
            else{
                cout << "Node with key value " << k << " does not exist." << endl;
            }
        }

        //Printing the List. Traversing and printing
        void printList(){
            if(head==NULL){
                cout << "No nodes present." << endl;
            }
            else{
                Node* temp = head;
                cout << endl << "Singly Linked List:" << endl;
                cout << "key, data" << endl;
                while(temp!=NULL){
                    cout << temp->key << ", " << temp->data << endl;
                    temp = temp->next;
                }
            }
        }

    };


int main(){

    // Menu driven program

    SinglyLinkedList s;

    int option;
    int key_user, key_user_, data_user;
    do{
        cout << endl << endl << "Enter your option, select a number: " << endl;
        cout << "0: Exit" << endl;
        cout << "1: Add a node at the end (Appending)" << endl;
        cout << "2: Add a node at the beginning (Prepending)" << endl;
        cout << "3: Insert a node after a certain key node" << endl;
        cout << "4: Delete node of specific key" << endl;
        cout << "5: Update the data of a certain key node" << endl;
        cout << "6: Print the List" << endl;
        cout << "7: Clear screen" << endl;

        cin >> option;
        Node* n_user = new Node(); // dynamic memory allocation on heap

        switch(option){

            case 0:
                break;

            case 1:
                cout << "Enter (key,data) for a node, which you want to append." << endl;
                cin >> key_user;
                cin >> data_user;
                n_user->key = key_user;
                n_user->data = data_user;
                s.appendNode(n_user);
                break;

            case 2:
                cout << "Enter (key, data) for a node, which you want to prepend." << endl;
                cin >> key_user;
                cin >> data_user;
                n_user->key = key_user;
                n_user->data = data_user;
                s.prependNode(n_user);
                break;

            case 3:
                cout << "Enter key of an existing node, after which you want to insert." << endl;
                cin >> key_user_;
                cout << "Enter (key, data) for a node, which you want to insert." << endl;
                n_user->key = key_user;
                n_user->data = data_user;
                s.insertNode(key_user_, n_user);
                break;

            case 4:
                cout << "Enter the key value of the node you wish to delete." << endl;
                cin >> key_user_;
                s.deleteNode(key_user_);
                break;

            case 5:
                cout << "Enter key of an existing node, after which you want to update." << endl;
                cin >> key_user;
                cin >> data_user;
                s.updateNode(key_user, data_user);
                break;

            case 6:
                s.printList();
                break;

            case 7:
                system("clc");
                break;

            default:
                cout << "Enter a valid number." << endl;
        }
    }while(option!=0);

    return 0;

}


