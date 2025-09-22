#include<stdio.h>
#include<stdlib.h>

void GetNumbers(int arr[], int iSize);
void Display(int arr[], int iSize);
void Insert_At_Sorting_Position(int arr[], int iSize);
void Call_Insertion_Sort(int arr[], int iSize);

int main()
{
	int iSize = 0;
	int* a = 0;

	printf("Enter the size of the array you want : \n");
	scanf("%d", &iSize);

	a = (int*)malloc(sizeof(int) * iSize);

	if (a == NULL)
	{
		printf("Out of Memory\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the elements of the array you want : \n");
	GetNumbers(a, iSize);
	printf("Elements of the array before sorting are : \n");
	Display(a, iSize);

	//Insert_At_Sorting_Position(a, iSize);
	Call_Insertion_Sort(a, iSize);
	printf("Elements of the array after sorting are : \n");
	Display(a, iSize);

	return 0;
}

void GetNumbers(int arr[], int iSize)
{
	int i = 0;

	while (i < iSize)
	{
		scanf("%d", &arr[i]);
		i = i + 1;
	}
}

void Display(int arr[], int iSize)
{
	int i = 0;

	while (i < iSize)
	{
		printf("arr[%d] : %d\n", i, arr[i]);
		i = i + 1;
	}
}

//Pre-Conditions : 1) iSize >= 2 and Elements from index 0 to index N-2 must be sorted. 
void Insert_At_Sorting_Position(int arr[], int iSize)
{
	int itemp = arr[iSize - 1];
	int i = 0;

	i = iSize - 2;

	while (i >= 0 && arr[i] >= itemp)
	{
		arr[i + 1] = arr[i];
		i = i - 1;
	}

	arr[i + 1] = itemp;
}

void Call_Insertion_Sort(int arr[], int iSize)
{
	int subArraySize = 0;
	subArraySize = 2;

	while (subArraySize <= iSize)
	{
		Insert_At_Sorting_Position(arr, subArraySize);
		subArraySize++;
	}
}