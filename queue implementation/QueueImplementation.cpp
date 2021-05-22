/*
 * Queue Implementation
 */

#include "Queue.h"
#include <iostream>
#include <String>
using namespace std;
int main()
{
	Queue q;
	bool flag{ true };
	int input_option{};

	do {
		cout << "Select one of the following options" << endl;
		cout << "1 - Enqueue \n2 - Dequeue \n3 - Check Empty \n4 - Check Full " << endl;
		cout << "5 - Count \n6 - Display elements \n7 - Clear Console \nAny other - exit" << endl;
		cin >> input_option;
		switch (input_option) {
		case 1:
			int val;
			cout << "Enter the value you want to add: ";
			cin >> val;
			q.enq(val);
			break;
		case 2:
		{
			int removed{ q.deq() };
			cout << "The element removed was: " << removed << endl;
		}
			break;
		case 3:
			if (q.is_empty())
				cout << "The queue is empty" << endl;
			else
				cout << "The queue is not empty" << endl;
			break;
		case 4:
			if (q.is_full())
				cout << "The queue is full" << endl;
			else
				cout << "The queue is not full" << endl;
			break;
		case 5:
		{
			int count{ q.count() };
			cout << "The size of the queue is: " << count << endl;
		}
			break;
		case 6:
			q.display();
			break;
		case 7:
			system("CLS");
			break;
		default:
			flag = false;
			break;
		}
	} while (flag);
	cout << "The queue has been cleared" << endl;
	return 0;
}


