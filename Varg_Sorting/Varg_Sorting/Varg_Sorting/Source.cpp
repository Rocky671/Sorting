/*
Rocky Vargas
20171105
Sorting Algo's
*/

#include <iostream>
#include "LinkedList.h"
#include "Sorting.h"

using namespace std;

int main()
{
	LinkedList<int> list;
	list.insert(5);
	list.insert(6);
	list.insert(1);
	list.insert(3);
	list.insert(2);
	list.insert(10);
	list.insert(15);
	list.insert(4);
	list.insert(17);
	//list.insert(0);

	list.display();

	cout << endl << endl;
	//selectionSort<int>(list);
	quickSort<int>(list);

	cout << endl << endl;
	list.display();

	cout << endl;

	system("pause");
	return 0;
}