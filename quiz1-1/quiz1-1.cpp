//20181692 정찬진
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Node {
    int data;
    Node* next; //노드 생성
    Node(int value) {
        data = value;
        next = 0;
    }
};
/*isEmpty() 연결리스트가 비었는지의 여부 검사
  push 스택에 저장
  pop 제거*/
class linkedStack {
private:
    Node* head;
public:
    linkedStack() { head = 0; }
    ~linkedStack();
    void push(int data);
    int pop();
    int isEmpty();
    void disStack();


};


linkedStack::~linkedStack() {

}

void linkedStack::push(int data) {
    Node* temp = new Node(data);
    if (head == 0) head = temp;
    else { temp->next = head; head = temp; }
}

int linkedStack::pop() {
    Node* p;
    int num;
    num = head->data;
    p = head;
    head = head->next;
    delete p;
    return num;
}

int linkedStack::isEmpty() {
    if (head == 0) return 1;
    else return 0;
}


void linkedStack::disStack() {
    Node* p;
    if (!isEmpty()) {
        p = head;
        while (p) {
            cout << p->data << " "; p = p->next;
            cout << endl;
        }
    }
    else { cout << "Stack empty"; }
    
}
/*enqueu 큐에 저장
* dequeue 큐에서 제거
*/
class linkedQueue {
private:
    Node* front;
    Node* rear;
public:
    linkedQueue() { front = 0; rear = 0; }
    ~linkedQueue();
    void enqueue(int data);
    int dequeue();
    int isEmpty();
    void disQueue();

};
linkedQueue::~linkedQueue() {
    Node* p;
    while (rear != 0) {
        p = front;
        front = front->next;
        delete p;
    }
}

int linkedQueue::isEmpty() {
    if (front == 0) return 1;
    else return 0;
}

void linkedQueue::enqueue(int data) {
    Node* temp = new Node(data);
    if (front == 0) {
        front = temp;
        rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

int linkedQueue::dequeue() {
    Node* p; int num;
    num = front->data;
    p = front;

    if (front == rear) {
        front = 0;
        rear = 0;
    }
    else front = front->next;

    delete p;
    return num;
}

void linkedQueue::disQueue() {
    Node* p;

    if (!isEmpty()) {
        p = front;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else cout << "Queue is empty!\n";
}
/*InsertNode() 연결리스트에 노드를 삽입
  traverse() 연결리스트의 노드들의 내용을 출력
  invert() 순서를 바꿔줌
  removeMax() 최댓값을 제거해줌
*/
class List {
private:
    Node* head;
public:
    List() { head = NULL; }
    bool isEmpty();
    void InsertNode(int data);
    void traverse();
    void concentenation(linkedStack& a, linkedQueue& b);
    void invert();
    int pop();
    void removeMax();
    ~List();

};
List::~List() {
    Node* p; //포인터 지정
    while (head != 0) {
        p = head; // 처음노드
        head = head->next;
        delete p;
    }
}
int List::pop(){ 
    Node* p;
    int num;
    num = head->data;
    p = head;
    head = head->next;
    delete p;
    return num;
}
void List::removeMax() {
    Node* p, * q;
    int max = 0;
    if (!isEmpty()) {
        p = head;
        while (p) {
            if (max < p->data) max = p->data;
            p = p->next;
        }if (head->data == max) {
            p = head;
            head = head->next;
            delete p;
        }
        else {
            q = head;
            p = head;
            while (p != 0 && p->data != max) {
                q = p;
                p = p->next;
            }if (p != 0) {
                q->next = p->next;

            }
        }
    }
    else cout << "List is empty!\n";
}
bool List::isEmpty() {
    if (head == NULL) return true;
    else return false;//현재 연결리스트가 비어있으면 1을 아니면 0을 반환
}

void List::InsertNode(int data) {
    Node* temp = new Node(data);
    Node* p, * q;
    p = q = NULL;

    if (head == NULL) {
        temp->data = data;
        head = temp;
    }
    else if (temp->data < head->data) {
        temp->next = head;
        head = temp;
    }
    else {
        p = head;
        while (p != NULL && temp->data > p->data) {
            q = p;
            p = p->next;
        }
        if (p != NULL) {
            temp->next = p;
            q->next = temp;
        }
        else {
            q->next = temp;
        }
    }

}
void List::concentenation(linkedStack& a, linkedQueue& b) {

    while (!a.isEmpty())
    {
        InsertNode(a.pop());
    }
    while (!b.isEmpty())
    {
        InsertNode(b.dequeue());
    }

}

void List::invert() {
    Node* p = head, * q = 0, * r;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}


void List::traverse() {
    Node* p;
    if (!isEmpty()) {
        p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        cout << "List is empty!\n";
}
class Stack {
private:
    char stack[80];
public:

    int top;

    void createStack() {
        top = -1;
    }

    void push(char data) {
        if (top == 79) exit(-1);
        stack[++top] = data;
    }

    char pop() {
        if (top == -1) exit(-1);
        return stack[top--];
    }

    void printStack() {
        int sp; sp = top;
        while (sp != -1) cout << stack[sp--];
        cout << endl;
    }


};


int main() {
    linkedStack List1;
    linkedQueue List2;
    List List3;
    cout << "quiz 1-1 : linked stack and que" << endl;
    while (1) {
        int a;
        
        cout << "MENU: (1.Push  2.Enque 3.MakeList 4.Invert 5.RemoveMax 6.quit) : ";
        cin >> a;
        switch (a) {
        case 1: {
            int data;
            cout << "Enter an integer to push : ";
            cin >> data;
            List1.push(data);

            if (List1.isEmpty()) { cout << "Stack is Empty" << endl; break; }
            else {
                cout << "Stack : "<< endl;
                List1.disStack();
                
                break;
            }
        }

        case 2: {
            int data;
            cout << "Enter an integer to enque : ";
            cin >> data;
            List2.enqueue(data);
            if (List2.isEmpty()) { cout << "Que is Empty" << endl; break; }
            else {
                cout << "Queue : \n";
                List2.disQueue();

                break;
            }
        }

        case 3: {
            cout << "List:  ";
            List3.concentenation(List1, List2);
            List3.traverse();
            break;
        }

        case 4: {
            cout << "List:  ";
            List3.invert();
            List3.traverse();
            break;
        }

        case 5: {
            cout << "List:  ";
            List3.removeMax(); // 최댓값 제거
            List3.traverse();
            break;
        }
        case 6: {
            cout << endl;
            cout << "quiz 1-2 : palindrome" << endl;
            Stack s;
            s.createStack();

            ifstream infile("quiz.txt");
            if (!infile.is_open()) { //파일이 없을 때
                cout << "file not exits";
            }

            char buffer[80];

            while (infile.getline(buffer, 80)) { //한줄씩 buffer에 넣어줌
                int i = 0;
                int j = 0;
                int check = 1;
                int length = strlen(buffer); //string 의 길이,글자수


                if (length % 2 == 0) { //length가 짝수이면

                    while (i < (length / 2)) { //length의 반만큼 push
                        s.push(buffer[i]);
                        i++; j++;
                    }
                }

                else if (length % 2 != 0) {//length가 홀수이면
                    while (i < (length / 2)) {
                        s.push(buffer[i]);
                        i++; j++;
                    }
                    i++; j++; //홀수 건너뜀
                }
                //스택에서 pop한 데이터와 buffer 비교, 다르면 not palin
                while (buffer[j] != '\0') {
                    if (buffer[i] != s.pop())
                        check = 0;
                    i++; j++;
                }

                if (check) cout << "palindrome" << endl;
                else cout << "NOT palindrome" << endl;
                
            }
            return 0;
        }

        
        }
    }


}



