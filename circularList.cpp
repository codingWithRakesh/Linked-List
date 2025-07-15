#include <iostream>
using namespace std;

class Node{
public :
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularList{
    Node* head;
    Node* tail;

public:
    CircularList(){
        head = tail = NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead(){
        if(head == NULL) return;
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* tmp = head;
            head = head->next;
            tail->next = head;

            tmp->next = NULL;
            delete tmp;
        }
    }

    void deleteAtTail(){
        if(head == NULL) return;
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* tmp = tail;
            Node* pre = head;
            while(pre->next != tail){
                pre = pre->next;
            }

            tail = pre;
            tail->next = head;

            tmp->next = NULL;
            delete tmp;
        }
    }

    void printData(){
        if(head == NULL) return;

        cout << head->data << "->";
        Node* tmp = head->next;

        while(tmp != head){
            cout << tmp->data << "->";
            tmp = tmp->next;
        }

        cout << tmp->data;;
    }
};

int main(){
    CircularList cll;

    cll.insertAtHead(1);
    cll.insertAtHead(0);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    cll.deleteAtHead();
    cll.deleteAtTail();

    cll.printData();

    return 0;
}