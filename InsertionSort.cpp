#include<iostream>
using namespace std;

class ArrayX
{
public :
	int* a;
	int iSize;
	int subArraySize;

	ArrayX()
	{
		a = NULL;
		iSize = 0;
	}

	ArrayX(int iSizeX, int subArraySizeX)
	{
		iSize = iSizeX;
		subArraySize = subArraySizeX;
		cout << "iSize" << iSize << endl;
		a = new int[iSize];
	}

	~ArrayX()
	{
		if (a)
		{
			delete[] a;
			a = NULL;
		}
	}

	void GetNumbers()
	{
		int i = 0;
		cout << "iSize" << iSize << endl;

		while (i < iSize)
		{
			cout << "Hello" << endl;
			cin >> a[i];
			i = i + 1;
		}
	}

	void Display()
	{
		int i = 0;

		while (i < iSize)
		{
			cout << "arr[" << i <<"] : " <<  a[i] << endl;
			i = i + 1;
		}
	}

	void Insert_At_Sorting_Position()
	{
		int itemp = a[iSize - 1];
		int i = iSize - 2;

		while (i >= 0 && a[i] >= itemp)
		{
			a[i + 1] = a[i];
			i = i - 1;
		}

		a[i + 1] = itemp;
	}

	void Call_Insertion_Sort()
	{
		subArraySize = 2;
		while (subArraySize <= iSize)
		{
			Insert_At_Sorting_Position();
			subArraySize++;
		}
	}
};

int main()
{
	int iSize = 0;
	cout << "Enter the size of the array : " << endl;
	cin >> iSize;

	cout << "Size is : " << iSize << endl;

	ArrayX aobj(iSize, 0);

	cout << "Please Enter the elements you want : " << endl;
	aobj.GetNumbers();

	cout << "Elements before the sorting are : " << endl;
	aobj.Display();

	//cout << "Elements after the calling Insert_At_Sorting_Position() are : " << endl;
	//aobj.Insert_At_Sorting_Position();
	//aobj.Display();

	cout << "Elements after the calling Call_Insertion_Sort() are : " << endl;
	aobj.Call_Insertion_Sort();
	aobj.Display();

	return 0;
}

//
//void Call_Insertion_Sort(int arr[], int iSize)
//{
//	int subArraySize = 0;
//	subArraySize = 2;
//
//	while (subArraySize <= iSize)
//	{
//		Insert_At_Sorting_Position(arr, subArraySize);
//		subArraySize++;
//	}
//}