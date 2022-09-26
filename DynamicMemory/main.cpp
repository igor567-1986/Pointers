﻿#include <iostream>
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

 //2D
int** Allocate( const int rows, const int cols);
void Clear(int** arr, const int rows);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows,const int cols);
int** insert_row(int** arr, int& rows,const int cols,int index);
int** pop_row_back(int** arr, int& rows,const int cols);
int** pop_row_front(int** arr, int& rows,const int cols);
int** erase_row(int** arr, int& rows, int& cols,int index);

int** push_col_back(int** arr,const int rows, int& cols);
int** push_col_front(int** arr, const int rows, int& cols);


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define rows_2d

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int valye, index;
#ifdef part_1
	cout << "Введите добавляемое число в конец массива:"; cin >> valye;
	arr = push_back(arr, n, valye);
	Print(arr, n);
	cout << "Введите добавляемое число в начало массива:"; cin >> valye;
	arr = push_front(arr, n, valye);
	Print(arr, n);
	cout << "Введите добавляемое число и индекс  по которому он будет расположен в массиве он не должен быть выше" << n - 1 << ":"; cin >> valye; cout << "\t"; cin >> index;
	do
		if (index > n - 1)
		{
			cout << "Ошибка индекс введен не верно ,введите его заново"; cin >> index;
		}
	while (index > n - 1);
	arr = insert(arr, n, valye, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс по каторому надо удалить число в массиве он не должен быть выше" << n - 1 << ":"; cin >> index;
	do
		if (index > n - 1)
		{
			cout << "Ошибка индекс введен не верно ,введите его заново"; cin >> index;
		}
	while (index > n - 1);
	arr = erase(arr, n, index);
	Print(arr, n);
	delete[]arr;
#endif //
#endif // DYNAMIC_MEMORY_1
	int rows, cols,index;
	cout << "Введите колличество строк:"; cin >> rows;
	cout << "Введите колличество столбиков:"; cin >> cols;
	int** arr = Allocate( rows, cols);
	FillRand( arr, rows, cols);
	Print( arr, rows, cols);
	cout << endl;
#ifdef rows_2d
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	cout << "Введите индекс строки каторую нужно добавить:"; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	cout << "Введите индекс строки каторую нужно удалить:"; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << endl;
#endif // 

	arr = push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	Clear(arr, rows);
	arr = push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	Clear(arr, rows);
}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования
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

	// 1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем исходный массив в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) после того как все данные скопированны из исходного массива 
	// он больше не нужен и его надо удалить
	delete[]arr;

	//4) Подменяем адрес исходного массива в указателе "arr"
	arr = buffer;

	// И только после этого можно написать вот так:
	arr[n] = value;
	// поскольку только сейчас в массиве аrr ,появился еще один элемент,
	// в который можно сохранить значение
	n++;
	// 6)После того как мы добавили в массив элемент,колличество элементов массива увеличивается.
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

// 2D dynamic arays
int** Allocate( const int rows, const int cols)
{
	// Создаем массив указателей
	int** arr = new int* [rows];
	//Выделяем память под строки
	for (int i = 0; i < rows; i++) arr[i] = new int[cols]{};
	return arr;
}
void Clear(int** arr, const int rows)
{ 
	for (int i = 0; i < rows; i++)                    
	{
		delete[]arr[i];
	}
	delete[]arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//создаем буферный массив указателей
	int** buffer = new int* [rows+1];
	// копируем адреса строк из исходного в буферный
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	// Создаем новую (добовляемую строку)
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows,const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++) buffer[i+1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows,const int cols, int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		if (i < index)	buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
	

}
int** pop_row_back(int** arr, int& rows,const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows; i++)
	{
		if (i != rows - 1) buffer[i] = arr[i];
		else break;
	}
	delete[] arr;
	rows--;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows; i++)
	{
		if (i != rows - 1) buffer[i] = arr[i+1];
		else break;
	}
	delete[] arr;
	rows--;
	return buffer;
	
}
int** erase_row(int** arr, int& rows, int& cols, int index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows; i++)
	{
		if (i < index)	buffer[i] = arr[i];
		else if (i == rows - 1)break;
		else  buffer[i] = arr[i + 1];
	}
	delete[] arr;
	rows--;
	return buffer;
}


int** push_col_back(int** arr,const int rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)buffer[i] = new int[cols + 1]{};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols ; j++)buffer[i][j] = arr[i][j];
	    cout << endl;
	}
	Clear(arr, rows);
	cols++;
	return buffer;
}
int** push_col_front(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)buffer[i] = new int[cols + 1]{};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <= cols; j++)	buffer[i][j] = arr[i][j-1];
		cout << endl;
	}
	Clear(arr, rows);
	cols++;
	return arr;
}