// lab5(20181692정찬진)

#include <iostream>
#include <fstream>


using namespace std;

typedef enum { lparen, rparen, times, divide, Plus, Minus, operand }precedence;
int isp[] = { 0,3,2,2,1,1,0 }; //top element의 priority
int icp[] = { 4,3,2,2,1,1,0 }; // 읽어 온 값의 priority
const int Size = 100;
char arr[100] = { 0 }; // 후위표기 저장 배열
void postfix(char buffer[]);
int eval(char arr[]);
ifstream infile("lab5.txt"); //파일 읽어오기

class STACK { //STACK class 생성
private:
    int stack[Size];
    int top;
public:
    STACK() { 
        top = -1;
    }

    int isEmpty() { 
        if (top == -1)
            return true;
        else return false;
    }

    void push(int val) { 
        ++top;
        stack[top] = val;
    }

    int pop() { 
        return(stack[top--]);
    }

    int getTop() { 
        return stack[top];
    }

    void displayStack() { 
        int sp;
        if (isEmpty()) cout << "Stack is empty!" << endl;
        else {
            sp = top;
            while (sp != -1) {
                cout << stack[sp]; --sp;
            }
        }
    }
};
STACK ST; // 연산자를 저장하는 stack
STACK RST; // 결과값을 계신하기 위한 식을 저장하는 stack
precedence getToken(char s) { // 연산자 = token
    switch (s) {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '*':
        return times;
    case '/':
        return divide;
    case '+':
        return Plus;
    case '-':
        return Minus;
    default:
        return operand;
    }

}
char getVal(precedence T) { //token -> 연산자
    switch (T) {
    case lparen:
        return '(';
    case rparen:
        return ')';
    case times:
        return '*';
    case divide:
        return '/';
    case Plus:
        return '+';
    case Minus:
        return '-';
    default:
        return '\0';
    }

}
precedence op;

int main() {

    char buffer[100];

    while (infile.getline(buffer, 100)) {

        cout << "Infix expression : " << buffer << "    ";
        cout << "The postfix conversion : ";
        postfix(buffer);
        cout << endl << "The final result : ";
        eval(arr);
        cout << endl;

    }
    return 0;

}

// postfix
// infix 형으로 받은 식을 postfix형으로 변형   
//      arr[]  후위표기 저장배열
//      buffer  파일에서 읽어온 값
//      temp arr 인덱스 값

void postfix(char buffer[]) { 
    int temp = 0;

    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9') { 
            arr[temp++] = buffer[i]; 
            cout << buffer[i]; 
        }
        else if (buffer[i] == '(') { 
            ST.push(lparen); 
        }
        else if (buffer[i] == ')') { 
            while ((op = (precedence)ST.pop()) != lparen) {
                arr[temp++] = getVal(op);
                cout << getVal(op); 

            }
        }
        else {
            while (!ST.isEmpty() && (icp[getToken(buffer[i])] <= isp[ST.getTop()])) {
                
                op = (precedence)ST.pop();
                arr[temp++] = getVal(op);
                cout << getVal(op);

            }
            ST.push(getToken(buffer[i]));
        }
    }
    while (!ST.isEmpty()) { //스택이 비어있지 않으면
        op = (precedence)ST.pop();
        cout << getVal(op);
        arr[temp++] = getVal(op);
    }
}

//postfix로 변형된 식을 계산하여 출력한다. 
//op2 - RST top에 있는 숫자 pop
//op1 - op2 저장 후 RST pop (infix 식에서 앞에 숫자)

int eval(char arr[]) {

    int op1, op2; //연산할 값들을 담는 변수
    int top = -1;
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] >= '0' && arr[i] <= '9') {
            RST.push(arr[i] - 48);
        }
        else {
            op2 = RST.pop();
            op1 = RST.pop();
            switch (arr[i]) {

            case '*':
                RST.push(op1 * op2);
                break;
            case '/':
                RST.push(op1 / op2);
                break;
            case '+':
                RST.push(op1 + op2);
                break;
            case '-':
                RST.push(op1 - op2);
                break;
            }
        }
    }
    cout << RST.pop(); 
    return 0;

}