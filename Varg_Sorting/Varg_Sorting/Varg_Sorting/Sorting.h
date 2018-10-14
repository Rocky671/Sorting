#pragma once

#include <iostream>
#include "LinkedList.h"

using namespace std;

	// pass in something to my function
template <typename T>
void selectionSort(LinkedList<T> list)
{
	// iterates through the list n - 1 times
	for (int i = 0; i < list.size() - 1; i++)
	{
		// stores pointers to I and J for efficiency
		shared_ptr<LinkedList<T>::DataHolder> valueOfI = list[i];
		shared_ptr<LinkedList<T>::DataHolder> valueOfJ = NULL;

		// create a variable to hold minimum int
		shared_ptr<LinkedList<T>::DataHolder> tempMin = valueOfI;

		// iterates through the list
		for (int j = i; j < list.size(); j++)
		{
			// sets valueofJ pointer to node at position j
			valueOfJ = list[j];
			// checks if current node we're on is less than the previous min
			if (valueOfJ->data < tempMin->data)
			{
				// if so, set it to new min
				tempMin = valueOfJ;
			}
		}

		//cout << "Minimum found this pass: " << tempMin->data << endl;

		// stores the first value found
		T oldMin = valueOfI->data;

		// sets actual data to min
		valueOfI->data = tempMin->data;

		//cout << "Swapping " << oldMin << " with " << tempMin->data << endl;

		// puts the old first value where the real min was found
		tempMin->data = oldMin;
	}
}

template <typename T>
int partition(LinkedList<T> list, int bottomIndex, int topIndex)
{
	T pivot = list[topIndex]->data;
	int i = bottomIndex - 1;

	for (int j = bottomIndex; j < topIndex; j++)
	{
		if (list[j]->data < pivot)
		{
			i++;

			// stores the first value found
			T oldJValue = list[j]->data;

			// sets actual data to min
			list[j]->data = list[i]->data;

			// puts the old first value where the real min was found
			list[i]->data = oldJValue;
		}
	}

	// stores the first value found
	T oldIValue = list[topIndex]->data;

	// sets actual data to min
	list[topIndex]->data = list[i + 1]->data;

	// puts the old first value where the real min was found
	list[i + 1]->data = oldIValue;

	return i + 1;
}

// pass in something to my function
template <typename T>
void quickSort(LinkedList<T> list, int bottomIndex = 0, int topIndex = 0)
{
	cout << "Sorting between index " << bottomIndex << " and " << topIndex << endl;
	if (bottomIndex == 0 && topIndex == 0)
	{
		topIndex = list.size() - 1;
	}

	if (bottomIndex < topIndex)
	{
		int partitionIndex = partition(list, bottomIndex, topIndex);

		quickSort(list, bottomIndex, partitionIndex - 1);
		quickSort(list, partitionIndex + 1, topIndex);
	}
}