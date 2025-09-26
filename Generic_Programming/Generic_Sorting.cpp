#include<iostream>

class ArrayX
{
public:
	int* Arr;
	int iSize;
	int subArraySize;

public:
	ArrayX();
	ArrayX(int iSizeX, int subArraySizeX);
	~ArrayX();

	void Accept();
	void Display();
};

ArrayX::ArrayX()
{
	this->Arr = NULL;
	this->iSize = 0;
	this->subArraySize = 0;
}

ArrayX::ArrayX(int iSizeX, int subArraySizeX)
{
	this->iSize = iSizeX;
	this->subArraySize = subArraySizeX;
	this->Arr = new int[iSize];
}

ArrayX::~ArrayX()
{
	if (Arr != NULL)
	{
		delete[]Arr;
	}
}

ArrayX::Accept()
{
	std::cout << "Enter the elements : " << std::endl;

	int i = 0;

	while (i < iSize)
	{
		std::cin >> Arr[i];
		i++;
	}
}

ArrayX::Display()
{
	std::cout << "Entered elements are : " << std::endl;

	int i = 0;

	while (i < iSize)
	{
		std::cout << "arr[" << i <<"]"<< Arr[i] << std::endl;
		i++;
	}
}

int main(void)
{
	int iSize = 0;

	std::cout << "Enter the size of array : " << std::endl;
	std::cin >> iSize;

	int subArraySize = 0;

	ArrayX aobj(iSize, subArraySize);

	aobj.Accept();
	aobj.Display();
	return 0;
}