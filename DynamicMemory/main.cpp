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
int** push_row_back(int** arr,int& rows, int& cols);

int* push_front(int* arr, int& n, int value); 
int** push_row_front(int** arr, int& rows, int& cols );

int* insert(int* arr, int& n, int value,int index);
int** insert_row(int** arr, int& rows, int& cols,int index);

int* pop_back(int* arr, int& n);
int** pop_row_back(int** arr, int& rows, int& cols);

int* pop_front(int* arr, int& n);
int** pop_row_front(int** arr, int& rows, int& cols);

int* erase(int* arr, int& n,int index);
int** erase_row(int** arr, int& rows, int& cols,int index);
 
void Allocate(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows, const int cols);


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
	int rows, cols,index;
	cout << "������� ����������� �����:"; cin >> rows;
	cout << "������� ����������� ���������:"; cin >> cols;
	int** arr = new int* [rows];
	
	Allocate( arr, rows, cols);
	FillRand( arr, rows, cols);
	Print( arr, rows, cols);
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������ ������ ������� ����� ��������:"; cin >> index;
	arr = insert_row(arr, rows, cols,index);
	Print(arr, rows, cols);
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������ ������ ������� ����� �������:"; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows, cols);
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
int** push_row_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int*[rows + 1];
	for (int i = 0; i < rows + 1; i++) buffer[i] = new int[cols] {};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		cout << endl;
	}
	delete[]arr;
	arr = buffer;
	rows++;
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
int** push_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++) buffer[i] = new int[cols] {};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i+1][j] = arr[i][j];
		}
		cout << endl;
	}
	delete[]arr;
	arr = buffer;
	rows++;
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
int** insert_row(int** arr, int& rows, int& cols,int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++) buffer[i] = new int[cols] {};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
            if(i<index)	buffer[i][j] = arr[i][j];
			else buffer[i+1][j] = arr[i][j];
		}
		cout << endl;
	}
	delete[]arr;
	arr = buffer;
	rows++;
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
int** pop_row_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows -1; i++) buffer[i] = new int[cols] {};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i != rows - 1) buffer[i][j] = arr[i][j];
			else break;
		}
		cout << endl;
	}
	delete[]arr;
	arr = buffer;
	rows--;
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
int** pop_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++) buffer[i] = new int[cols] {};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i != rows - 1) buffer[i][j] = arr[i+1][j];
			else break;
		}
		cout << endl;
	}
	delete[]arr;
	arr = buffer;
	rows--;
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
int** erase_row(int** arr, int& rows, int& cols, int index)
{
	int** buffer = new int* [rows -1];
	for (int i = 0; i < rows - 1; i++) buffer[i] = new int[cols] {};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i < index)	buffer[i][j] = arr[i][j];
			else if (i == rows - 1)break;
			else  buffer[i][j] = arr[i+1][j];

		}
		cout << endl;
	}
	delete[]arr;
	arr = buffer;
	rows--;
	return arr;
}

void Allocate(int** arr, const int rows, const int cols)
{
	//�������� ������ ��� ������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}

void Clear(int** arr, const int rows, const int cols)
{
	//������� ������� ������ ���������� �������
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
}

