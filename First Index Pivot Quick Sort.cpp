#include <iostream>
using namespace std;
void display(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
}
int Partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low + 1;
	int j = high;
	int temp;
	do
	{
		while (arr[i] <= pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

	} while (i < j);

	temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	return j;
}
void QuickSort(int arr[], int low, int high)
{
	int PartitionIndex = 0;
	if (low < high)
	{
		PartitionIndex = Partition(arr, low, high);
		QuickSort(arr, low, PartitionIndex - 1);
		QuickSort(arr, PartitionIndex + 1, high);
	}

}
int main()
{
	int arr[] = { 3, 5, 2, 13, 12, 3, 2, 13, 45 };
	int n = 9;
	cout << "Quick Sort with 1st element pivot" << endl;
	cout << "Un-Sorted array: \n";
	display(arr, n);
	QuickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	display(arr, n);
	display(arr, n);
	system("pause");
	return 0;
}
