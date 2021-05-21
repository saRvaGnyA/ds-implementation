//Stack implementation

#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack s;
    bool flag{true};
    int option;
    do {
        cout << "Enter any one of the following options: " << endl;
        cout << "1 - Push \n2 - Pop \n3 - Check Empty \n4 - Check Full \n5 - Count" << endl;
        cout << "6 - Peek \n7 - Change \n8 - Display \n9- Clear \nAny other - Exit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                int no;
                cout << "Enter the number to push: ";
                cin >> no;
                s.push(no);
                break;
            case 2:
                int top;
                top = s.pop();
                cout << "Top element before popping was " << top << endl;
                break;
            case 3:
                if (s.is_empty())
                    cout << "The stack is empty" << endl;
                else
                    cout << "The stack isn't empty" << endl;
                break;
            case 4:
                if (s.is_full())
                    cout << "The stack is full" << endl;
                else
                    cout << "The stack isn't full" << endl;
                break;
            case 5:
                cout << "Count of elements currently in the stack is " << s.count() << endl;
                break;
            case 6:
                int p;
                cout << "Enter the position you want to peek: ";
                cin >> p;
                s.peek(p);
                break;
            case 7:
                int p1, val;
                cout << "Enter the position and value (resp.) you want to change: " << endl;
                cin >> p1 >> val;
                s.change(p1, val);
                break;
            case 8:
                s.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                flag = false;
        }
    } while (flag);

    cout << "The stack has been cleared" << endl;

    return 0;
}
