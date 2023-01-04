#include <iostream>
using namespace std;
void merge(int arr[], int mid, int left, int right)
{
	int i, j, k, arr1[100];
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
			arr1[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			arr1[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		arr1[k] = arr[i];
		i++;
		k++;
	}
	while (j <= right)
	{
		arr1[k] = arr[j];
		j++;
		k++;
	}
	for (i = left; i <= right; i++)
	{
		arr[i] = arr1[i];
	}
}
void mergesort(int arr[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid+1,right);
		merge(arr, mid, left, right);
	}
}
void display(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
}
int main()
{
	int arr[] = { 9, 14, 4, 8, 7, 5, 6 };
	int n = 7;
	cout << "Merge Sort" << endl;
	cout << "Un-Sorted array: \n";
	display(arr, n);
	mergesort(arr, 0, 6);
	cout << "Sorted array: \n";
	display(arr, n);
	system("pause");
	return 0;
}
