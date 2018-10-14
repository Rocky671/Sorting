#pragma once
#include<iostream>
#include<memory>

using namespace std;

// template to include all data types
template <typename T>
class LinkedList
{
public:
	// Data holder class
	class DataHolder 
	{
		// anything from this list can be accessed by LinkedList due to friend class
		friend class LinkedList;
		// pointer to the nextData, which will start NULL
		shared_ptr<DataHolder> nextData = NULL;
		// pointer to previousData, which will start NULL
		shared_ptr<DataHolder> previousData = NULL;

	public:
		// T data type will allow any data type
		T data;
		// passing in data when you call this constructor will set list data to the new data
		DataHolder(T newData) 
		{
			data = newData;
		}
		shared_ptr<DataHolder> getNextData() {
			return nextData;
		}
		shared_ptr<DataHolder> getPreviousData() {
			return previousData;
		}
	};
	
	void insert(T data)
	{
		numberOfElements++;
		// tempData holds a new Node to insert to the list
		shared_ptr<DataHolder> tempData = make_shared<DataHolder>(data);

		// if the list is NULL
		if (frontData == NULL)
		{
			// frontData will equal to tempData
			frontData = tempData;
			return;
		}

		// end data is equal to front data
		shared_ptr<DataHolder> endData = frontData;
		// while there is still data left in the list
		while (endData->nextData != NULL)
		{
			// endData will equal to the nextData
			endData = endData->nextData;
		}

		// sets the last node next data pointer to new node that was created
		endData->nextData = tempData;
		// sets the new created nodes previous node pointer to the current last node
		tempData->previousData = endData;
	}

	shared_ptr<DataHolder> find(T data)
	{
		// tempPtr will point to the frontData
		shared_ptr<DataHolder> tempPtr = frontData;
		// while the tempPtr isn't NULL
		while (tempPtr != NULL)
		{
			// if the tempPtr equals to the variable being passed through
			if (tempPtr->data == data)
			{
				// return the tempPtr
				return tempPtr;
			} 
			
			// tempPtr will move on to the next node
			tempPtr = tempPtr->nextData;
		}
		// if none of the data in the list equals to the variable entered, return NULL
		return NULL;
	}

	void remove(shared_ptr<DataHolder> tempRemove)
	{
		// if the previousData isn't NULL
		if (tempRemove->previousData != NULL)
		{
			// the variable will point to the previous data and then to the next data
			tempRemove->previousData->nextData = tempRemove->nextData;
		}
		// if the next data isn't NULL
		if (tempRemove->nextData != NULL)
		{
			// the variable will point to the next data then to the previous data
			tempRemove->nextData->previousData = tempRemove->previousData;
		}
		
		// if the first node is equal to the variable
		if (frontData == tempRemove)
		{
			// the first node will point to the next data
			frontData = tempRemove->nextData;
		}

		numberOfElements--;
	}
	
	// minimum function
	T min()
	{
		// tempValue will hold the first node
		shared_ptr<DataHolder> tempValue = frontData;
		// value will take the data in the list and use any data type
		T value = tempValue->data;
		// while list is not NULL
		while (tempValue != NULL)
		{
			// if the value in the list is less than the entered value
			if (tempValue->data < value)
			{
				// change value to that value
				value = tempValue->data;
			}
			// tempValue will be the next node in the lsit
			tempValue = tempValue->nextData;
		}
		// return the value
		return value;
	}

	T max()
	{
		// tempValue will hold the first node
		shared_ptr<DataHolder> tempValue = frontData;
		// value will take the data in the list and use any data type
		T value = tempValue->data;
		// while list is not NULL
		while (tempValue != NULL)
		{
			// if the value in the list is less than the entered value
			if (tempValue->data > value)
			{
				// change value to that value
				value = tempValue->data;
			}
			// tempValue will be the next node in the lsit
			tempValue = tempValue->nextData;
		}
		// return the value
		return value;
	}

	void display()
	{
		// tempPtr will point to the frontData
		shared_ptr<DataHolder> tempPtr = frontData;
		// while the tempPtr isn't NULL
		while (tempPtr != NULL)
		{
			// display the data
			cout << tempPtr->data << "\n";
			// tempPtr will move on to the next node
			tempPtr = tempPtr->nextData;
		}
	}

	int size()
	{
		return numberOfElements;
	}

	shared_ptr<DataHolder> operator[](int index)
	{
		// tempPtr will point to the frontData
		shared_ptr<DataHolder> tempPtr = frontData;

		for (int i = 0; i < numberOfElements; i++)
		{
			if (i == index)
			{
				return tempPtr;
			}

			// tempPtr will move on to the next node
			tempPtr = tempPtr->nextData;
		}

		return NULL;
	}

private:
	// frontData will start empty
	shared_ptr<DataHolder> frontData = NULL;
	int numberOfElements = 0;
};
