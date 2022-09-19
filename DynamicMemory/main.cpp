#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define part_1
 
void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n,  int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value,int index);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n,int index);
int* Allocate(int** arr, int rows, int cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int valye, index;
#ifdef part_1
	cout << "������� ����������� ����� � ����� �������:"; cin >> valye;
	arr = push_back(arr, n, valye);
	Print(arr, n);
	cout << "������� ����������� ����� � ������ �������:"; cin >> valye;
	arr = push_front(arr, n, valye);
	Print(arr, n);
	cout << "������� ����������� ����� � ������  �� �������� �� ����� ���������� � ������� �� �� ������ ���� ����" << n - 1 << ":"; cin >> valye; cout << "\t"; cin >> index;
	do
		if (index > n - 1)
		{
			cout << "������ ������ ������ �� ����� ,������� ��� ������"; cin >> index;
		}
	while (index > n - 1);
	arr = insert(arr, n, valye, index);
	Print(arr, n);
#endif // 
	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "������� ������ �� �������� ���� ������� ����� � ������� �� �� ������ ���� ����" << n - 1 << ":"; cin >> index;
	do
		if (index > n - 1)
		{
			cout << "������ ������ ������ �� ����� ,������� ��� ������"; cin >> index;
		}
	while (index > n - 1);
	arr = erase(arr, n, index);
	Print(arr, n);
	delete[]arr;
#endif // DYNAMIC_MEMORY_1
	int rows, cols;
	cout << "������� ����������� �����:"; cin >> rows;
	cout << "������� ����������� ���������:"; cin >> cols;
	//������� ������ ����������
	int** arr = new int* [rows];
	//�������� ������ ��� ������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//������� ������� ������ ���������� �������
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	// � ����� ������ ����������
	delete[]arr;
}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


int* push_back(int* arr,  int& n, int value)
{

	// 1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1];
	//2) �������� �������� ������ � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) ����� ���� ��� ��� ������ ������������ �� ��������� ������� 
	// �� ������ �� ����� � ��� ���� �������
	delete[]arr;

	//4) ��������� ����� ��������� ������� � ��������� "arr"
	arr = buffer;

	// � ������ ����� ����� ����� �������� ��� ���:
	arr[n] = value;
	// ��������� ������ ������ � ������� �rr ,�������� ��� ���� �������,
	// � ������� ����� ��������� ��������
	n++;
	// 6)����� ���� ��� �� �������� � ������ �������,����������� ��������� ������� �������������.
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value,int index)
{
    int* buffer = new int[n + 1];
    n++;
	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else if (i == index)buffer[i] = value;
		else buffer[i] = arr[i-1];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];

	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[n - 1];

	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int* arr, int& n, int index) 
{
	int* buffer = new int(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index)buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* Allocate(int** arr, int rows, int cols)