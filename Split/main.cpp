#include <iostream>
using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);


void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int e=0, o=0;
	int arr[n];
	FillRand(arr, n);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			e++;
		}
	}
	o = n - e;
	int* even = new int[e];
	int* odd = new int[o];
	Print(arr, n);
	o = 0, e = 0;
    for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[e] = arr[i];
			e++;
		}
		else
		{
			odd[o] = arr[i];
			o++;	
		}
	}
	Print(even, e);
	Print(odd, o);
	delete[] even;
	delete[] odd;
}

void FillRand(int* arr,const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}

}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
