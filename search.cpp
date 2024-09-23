#include <iostream>
using namespace std;

int sequentialSearch(int *array, int size, int key)
{
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == key)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int size;
	cout << "\nMasukan Banyaknya Array : ";
	cin >> size;

	int array[size];
	int key;

	for (int i = 0; i < size; i++)
	{
		cout<<"\n Masukan value array ke "<< i <<" :";
		cin >> array[i];
	}

	cout << "\nMasukan angka yang ingin dicari : ";
	cin >> key;

	int index = sequentialSearch(array, size, key);
	if (index != -1)
	{
		cout << "\nAngka ditemukan di index ke: " << index;
	}
	else
	{
		cout << "\nAngka tidak ditemukan";
	}

	return 0;
}
