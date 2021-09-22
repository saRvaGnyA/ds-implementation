#include <iostream>
#include "MinHeap.h"

using namespace std;

int main() {
    int size;
    cin >> size;
    MinHeap m(size);
    bool flag{true};
    while (flag) {
        int option;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cin >> option;
        switch (option) {
            case 0:
                flag = false;
                break;
            case 1: {
                cout << "Enter value: ";
                int val;
                cin >> val;
                m.insert(val);
            }
                break;
            case 2: {
                int val;
                cout << "Enter value: ";
                cin >> val;
                m.linear_search(val);
            }
            case 4:
                cout << m.arr[0] << endl;
                break;
            case 6:
                cout << m.height() << endl;
                break;
            case 7:
                m.print();
                break;
            case 8:
                system("CLS");
                break;
            default:
                cout << "Invalid" << endl;
        }
        cout << endl;
    }
    return 0;
}
