#include<iostream>

template <class T>
class ArrayX
{
public:
	T* Arr;
	int iSize;
	int subArraySize;

public:
	ArrayX();
	ArrayX(int iSizeX, int subArraySizeX);
	~ArrayX();

	void Generic_Sorting();

	void Insert_At_Sorting_Postion(T* Arr, int subArraySize);

	void Accept();
	void Display();
};

template <class T>
ArrayX<T>::ArrayX()
{
	this->Arr = NULL;
	this->iSize = 0;
	this->subArraySize = 0;
}

template <class T>
ArrayX<T>::ArrayX(int iSizeX, int subArraySizeX)
{
	this->iSize = iSizeX;
	this->subArraySize = subArraySizeX;
	this->Arr = new T[iSize];
}

template <class T>
ArrayX<T>::~ArrayX()
{
	if (Arr != NULL)
	{
		delete[]Arr;
	}
}

template <class T>
void ArrayX<T>::Accept()
{
	std::cout << "Enter the elements : " << std::endl;

	int i = 0;

	while (i < iSize)
	{
		std::cin >> Arr[i];
		i++;
	}
}

template <class T>
void ArrayX<T>::Display()
{
	std::cout << "Entered elements are : " << std::endl;

	int i = 0;

	while (i < iSize)
	{
		std::cout << "arr[" << i << "] : " << Arr[i] << std::endl;
		i++;
	}
}

template <class T>
void ArrayX<T>::Generic_Sorting()
{
	int subArraySize = 2;

	while (subArraySize <= iSize)
	{
		Insert_At_Sorting_Postion(Arr, subArraySize);
		subArraySize++;
	}
}

template <class T>
void ArrayX<T>::Insert_At_Sorting_Postion(T* Arr, int iSize)
{
	int iTemp = Arr[iSize - 1];
	int i = iSize - 2;

	while (i >= 0 && Arr[i] >= iTemp)
	{
		Arr[i + 1] = Arr[i];
		i = i - 1;
	}

	Arr[i + 1] = iTemp;
}

int main(void)
{
	int iSize = 0;

	std::cout << "Enter the size of array : " << std::endl;
	std::cin >> iSize;

	int subArraySize = 0;

	ArrayX<int> aobj(iSize, subArraySize);

	aobj.Accept();
	aobj.Display();

	std::cout << "After Generic Sorting : " << std::endl;
	aobj.Generic_Sorting();
	aobj.Display();
	return 0;
}
