//20181692 정찬진
#include <iostream>
#include <cmath>

using namespace std;

class Heap {
private:
    int max_size;
    int index;
    int* heap;

public:
    Heap(int size) {
        max_size = size;
        index = 0;
        heap = new int[max_size + 1];
    }

    bool isfull() {
        if (index == 12) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isempty() {
        if (index == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void insertHeap(int item) {
        int i;
        if (isfull()) {
            cout << "heap is full" << endl;
            return;
        }
        i = ++index;
        while ((i != 1) && item > heap[i / 2]) {
            heap[i] = heap[i / 2];
            i = i / 2;
        }
        heap[i] = item;
    }

    int deleteHeap() {
        if (isempty()) {
            cout << "heap is empty" << endl;
            return 0;
        }
        int parent, child, temp, item;
        item = heap[1];
        temp = heap[index--];
        parent = 1;
        child = 2;
        while (child <= index) {
            if ((child <= index) && heap[child] < heap[child + 1]) {
                child++;
            }
            if (temp >= heap[child]) {
                break;
            }
            heap[parent] = heap[child];
            parent = child;
            child = child * 2;
        }
        heap[parent] = temp;
        return item;
    }

    void printHeap() {
        cout << "Heap : ";
        for (int i = 1; i < index + 1; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void searchHeap(int n) {
        bool find = false;
        for (int i = 1; i < index + 1; i++) {
            if (heap[i] == n) {
                find = true;
            }
        }

        if (find) {
            cout << n << " is found" << endl;
        }
        else {
            cout << "Not found" << endl;
        }
    }

    int leveltest() {
        return int(log2(index) + 1);
    }

    void makeHeap() {
        for (int i = index / 2; i > 0; i--) {
            int child, j, temp;
            child = 2 * i;
            temp = heap[i];
            while (index >= child) {
                if (index >= child && heap[child] < heap[child + 1]) {
                    child++;
                }
                if (temp >= heap[child]) {
                    break;
                }
                j = child / 2;
                heap[j] = heap[child];
                child = child * 2;
            }
            j = child / 2;
            heap[j] = temp;
        }
        cout << "Heap transit :   ";
        printHeap();
    }

    void sortHeap() {
        for (int i = index - 1; i > 0; i--) {
            int a = heap[1];
            heap[1] = heap[i + 1];
            heap[i + 1] = a;
            int child, j, temp;
            child = 2;
            temp = heap[1];
            while (i >= child) {
                if (i > child && heap[child] < heap[child + 1]) {
                    child++;
                }
                if (temp >= heap[child]) {
                    break;
                }
                j = child / 2;
                heap[j] = heap[child];
                child = child * 2;
            }
            j = child / 2;
            heap[j] = temp;
        }
        cout << "sort result : ";
        printHeap();
    }

    void InsertTree(int item) {
        int i;
        i = ++index;
        heap[i] = item;
    }
};

int main() {
    Heap maxheap(11);

    int tree[10] = { 26, 5, 77, 1, 61, 11, 59, 15, 48, 19 };
    for (int i = 0; i < sizeof(tree) / sizeof(int); i++) {
        maxheap.InsertTree(tree[i]);
    }

    int menu = 0;
    int num;

    while (menu != 8) {
        cout << "Enter Command : (1. print 2. search 3. leveltest 4. makeheap 5. heapsort 6. delete 7. insert 8. Quit) : ";
        cin >> menu;

        switch (menu) {
        case 1:
            maxheap.printHeap();
            cout << endl;
            break;

        case 2:
            if (maxheap.isempty()) {
                cout << "Heap is empty!" << endl;
                break;
            }
            else {
                cout << "Enter a number to search : ";
                cin >> num;
                maxheap.searchHeap(num);
                cout << endl;
                break;
            }

        case 3:
            cout << "Level of Heap is ";
            cout << maxheap.leveltest() << endl << endl;
            break;

        case 4:
            maxheap.makeHeap();
            cout << endl;
            break;

        case 5:
            maxheap.sortHeap();
            cout << endl;
            break;

        case 6:
            if (maxheap.isempty()) {
                cout << "Heap is empty!" << endl;
                break;
            }
            else {
                maxheap.deleteHeap();
                maxheap.printHeap();
                cout << endl;
                break;
            }

        case 7:
            cout << "Enter a number to insert : ";
            cin >> num;
            maxheap.insertHeap(num);
            maxheap.printHeap();
            cout << endl;
            break;

        case 8:
            break;
        }
    }

}