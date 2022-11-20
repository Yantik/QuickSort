#include <iostream>
using namespace std;

void QSort(int arr[],int minIn,int MaxIn);

int GetPivot(int arr[], int minIn, int MaxIn);

int main()
{
	const int lenght = 10;
	int arr[lenght] = {3,1,5,1,6,9,6,12,1,2};
	cout << "unsorted" << endl;
	for (int i = 0;  i < lenght; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "sorted" << endl;
	QSort(arr,0, lenght-1);
	for (int i = 0; i < lenght; i++)
	{
		cout << arr[i] << endl;
	}
}

void QSort(int arr[], int minIn, int MaxIn)
{
	int flag = 0;
	if (minIn >= MaxIn)
	{
		flag = 1;
	}
	if (flag == 0)
	{
		int pivot = GetPivot(arr,minIn,MaxIn);

		QSort(arr, pivot + 1, MaxIn);

		QSort(arr, minIn, pivot - 1);
	}
}

int GetPivot(int arr[], int minIn, int MaxIn)
{
	int pivot = minIn - 1;
	for (int i = minIn; i <= MaxIn; i++)
	{
		if (arr[i] < arr[MaxIn])
		{
			pivot++;
			swap(arr[pivot], arr[i]);
		}
	}
	pivot++;
	swap(arr[pivot], arr[MaxIn]);
	return pivot;
}