#include <iostream>
#include "Node.h"

using namespace std;

int main() {
    bool flag{true};
    int option;
    while (flag) {
        cout << "What operation do you want to perform? " << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cin >> option;
        switch (option) {
            case 0: {
                flag = false;
                break;
            }
            case 1: {
                // insert operation
                break;
            }
            case 2: {
                // search operation
                break;
            }
            case 3: {
                // delete operation
                break;
            }
            case 4: {
                // print and traverse operation
                break;
            }
            case 5: {
                // clear screen operation
                system("CLS");
                break;
            }
            default:
                cout << "Invalid operation" << endl;
        }
    }
    return 0;
}
