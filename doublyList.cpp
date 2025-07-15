#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "unAuthorize" << endl;
        }

        Node* tmp = head;
        head = head->next;

        if(head != NULL){
            head->prev = NULL;
        }

        tmp->next = NULL;
        delete tmp;
    }

    void pop_back(){
        if(head == NULL){
            cout << "unAuthorize" << endl;
        }

        Node* tmp = tail;
        tail = tail->prev;

        if(tail != NULL){
            tail->next = NULL;
        }

        tmp->prev = NULL;
        delete tmp;
    }

    void printData(){
        Node* tmp = head;
        while(tmp != NULL){
            cout << tmp->data << " <=> ";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }
};


int main(){
    DoublyLinkedList dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_front(0);
    dll.push_front(-1);

    dll.pop_back();
    dll.pop_front();

    dll.printData();

    return 0;
}