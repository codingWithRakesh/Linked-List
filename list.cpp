#include <iostream>
#include <list>
using namespace std;

class Node{
public :
    int data;
    Node* next;

    Node(){
        cout << "default" << endl;
    }

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public :
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout << "LL is empty" << endl;
            return;
        }

        Node* tmp = head;
        while(tmp->next != tail){
            tmp = tmp->next;
        }

        tmp->next = NULL;
        delete tail;
        tail = tmp;
    }

    void insert(int val, int pos){
        if(pos < 0){
            cout << "invalid" << endl;
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        Node* tmp = head;
        for(int i = 0; i < pos -1; i++){
            if(tmp == NULL){
                cout << "invalid post" << endl;
                return;
            }
            tmp = tmp->next;
        }

        Node* newNote = new Node(val);
        newNote->next = tmp->next;
        tmp->next = newNote;
    }

    int search(int key){
        Node* tmp = head;
        int idx = 0;

        while(tmp != NULL){
            if(tmp->data == key){
                return idx;
            }
            tmp = tmp->next;
            idx++;
        }

        return -1;
    }

    void printList(){
        Node* tmp = head;
        while(tmp != NULL){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

class Coordinate{
public :
    int x;
    int y;
    Coordinate(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int main(){
    int n;
    cout << "input array : ";
    cin >> n;
    Coordinate* positionsArr[n];
    int x,y;
    for(int i = 0; i < n; i++){
        cout << "input x , y : ";
        cin >> x >> y;
        Coordinate* c1 = new Coordinate(x,y);
        positionsArr[i] = c1;
    }


    for(int i = 0; i < n; i++){
        cout << positionsArr[i]->x << " " << positionsArr[i]->y << endl;
    }
    cout << "last " << endl;
    
    List li;
    li.push_front(1);

    li.push_front(2);
    li.push_front(3);

    li.push_back(4);

    cout << "search Value = " << li.search(2) << endl;

    // li.pop_front();

    // li.pop_back();

    li.insert(7,1);

    li.printList();

    return 0;
}