#include <iostream>
#include "Node.h"
#include "BST.h"

#define SPACE 10
using namespace std;

int main() {
    BST tree;
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
        cout << "7. Is the tree empty" << endl;
        cout << "8. DFS traversals" << endl;
        cout << "9. BFS traversals" << endl;
        cout << "0. Exit Program" << endl;
        cin >> option;
        Node *node = new Node;
        switch (option) {
            case 0: {
                flag = false;
                break;
            }
            case 1: {
                // insert operation
                cout << "Enter value of node to insert:" << endl;
                int v;
                cin >> v;
                node->val = v;
//                tree.insert(node);
                tree.root = tree.insertRecursive(tree.root, node);
                break;
            }
            case 2: {
                // search operation
                int v;
                cout << "Enter data to search: ";
                cin >> v;
                Node *t{tree.search(tree.root, v)};
                if (t == nullptr)
                    cout << "Node not found" << endl;
                else
                    cout << "Node found at memory location " << t << endl;
                break;
            }
            case 3: {
                // delete operation
                int v;
                cout << "Enter the value of the node in BST to be deleted: ";
                cin >> v;
                Node *temp = tree.search(tree.root, v);
                if (temp == nullptr) {
                    tree.deleteNode(tree.root, v);
                    cout << "Node deleted" << endl;
                } else {
                    cout << "Node doesn't exist" << endl;
                }
                break;
            }
            case 4: {
                // print and traverse operation graphically
                tree.print(tree.root, SPACE);
                cout << endl;
                break;
            }
            case 5: {
                // height of tree operation
                cout << "Height of the binary tree is: " << tree.height(tree.root) << endl;
                break;
            }
            case 6: {
                // clear screen operation
                system("CLS");
                break;
            }
            case 7: {
                // is empty operation
                if (tree.isEmpty())
                    cout << "Tree is empty" << endl;
                else
                    cout << "Tree is not empty" << endl;
                break;
            }
            case 8: {
                // DFS traversals operation
                cout << "1. Preorder" << endl;
                cout << "2. Inorder" << endl;
                cout << "3. Postorder" << endl;
                int a;
                cin >> a;
                switch (a) {
                    case 1:
                        tree.preorder(tree.root);
                        cout << endl;
                        break;
                    case 2:
                        tree.inorder(tree.root);
                        cout << endl;
                        break;
                    case 3:
                        tree.postorder(tree.root);
                        cout << endl;
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                }
                break;
            }
            case 9: {
                // BFS traversals operation
                tree.printLevelOrderBFS(tree.root);
                cout << endl;
                break;
            }
            default:
                cout << "Invalid operation" << endl;
        }
    }
    return 0;
}
