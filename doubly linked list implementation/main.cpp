#include <iostream>
#include "doublyLinkedList.h"
#include "Node.h"

using namespace std;

int main() {
    doublyLinkedList obj;
    int option;
    int key1, k1, data1;
    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;
        Node *n1 = new Node();

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                obj.append_node(n1);
                break;

            case 2:
                cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                obj.prepend_node(n1);
                break;

            case 3:
                cout
                        << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: "
                        << endl;
                cin >> k1;
                cout << "Enter key & data of the New Node first: " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;

                obj.insert_node(n1, k1);
                break;

            case 4:

                cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
                cin >> k1;
                obj.delete_node(k1);

                break;
            case 5:
                cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
                cin >> key1;
                cin >> data1;
                obj.update_by_key(key1, data1);

                break;
            case 6:
                obj.print();

                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}

