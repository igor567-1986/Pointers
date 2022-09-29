#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define part_1
 
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

void push_col_back(int** arr,const int rows, int& cols);
void push_col_front(int** arr,const int rows, int& cols);
void insert_col(int** arr,const int rows, int& cols,int number_cols);

void pop_col_back(int** arr,const int rows, int& cols);
void pop_col_front(int** arr,const int rows, int& cols);
void erase_col(int** arr,const int rows, int& cols, int number_cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define rows_2d

void main()
{
	setlocale(LC_ALL, "");
	int n ;
#ifdef DYNAMIC_MEMORY_1
    int valye,index;
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
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
	delete arr[];
#endif //
#endif // DYNAMIC_MEMORY_1
	int rows, cols,index, number_cols;
	cout << "Введите колличество строк:"; cin >> rows;
	cout << "Введите колличество столбиков:"; cin >> cols;
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
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

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	cout << "Введите номер столба который хотите добавить: "; cin >> number_cols;
	insert_col(arr, rows, cols, number_cols);
	Print(arr, rows, cols);
	cout << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите номер столба который хотите удалить: "; cin >> number_cols;
	erase_col(arr, rows, cols, number_cols);
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
	      for (int j = 0; j < cols; j++)arr[i][j] = rand() % 100;
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)cout << arr[i] << "\t";
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cout << arr[i][j] << "\t";
		cout << endl;
	}
}


int* push_back(int* arr,  int& n, int value)
{

	// 1) Создаем буферный массив нужного размера:
	int* buffer = new int[++n];
	//2) Копируем исходный массив в буферный:
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	// 3) после того как все данные скопированны из исходного массива 
	// он больше не нужен и его надо удалить
	delete[]arr;
	// И только после этого можно написать вот так:
	arr[n] = value;
	// 6)После того как мы добавили в массив элемент,колличество элементов массива увеличивается.
	return buffer;
} 
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)buffer[i+1] = arr[i];
	delete[]arr;
	arr[0] = value;
	return buffer;
}
int* insert(int* arr, int& n, int value,int index)
{
    int* buffer = new int[++n];
   	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else if (i == index)buffer[i] = value;
		else buffer[i] = arr[i-1];
	}
	delete[]arr;
	return buffer;
} 
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n-1; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n - 1; i++)buffer[i] = arr[i+1];
	delete[]arr;
	return buffer;
} 
int* erase(int* arr, int& n, int index) 
{
	int* buffer = new int(--n);
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index)buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];
	}
	delete[]arr;
	return buffer;
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
	for (int i = 0; i < rows; i++) delete[]arr[i];                   
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
	int** buffer = new int* [++rows];
	for (int i = 0; i < rows; i++)
	{
		if (i < index)	buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = new int[cols] {};
	return buffer;
}
int** pop_row_back(int** arr, int& rows,const int cols)
{
	//1)удаляем строку из памяти
	delete[] arr[rows-1];
	//2)переопределяем массив указателей
	int** buffer = new int* [--rows ]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	delete[]arr[0];
	int** buffer = new int* [--rows ]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
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


void push_col_back(int** arr,const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//создаем новую строку нужного размера
		int* buffer = new int[cols + 1]{};
		// копируем все элементы i-й строки в новую строку (byffer)
		for (int j = 0; j < cols ; j++)buffer[j] = arr[i][j];
	    //удаляем исходную строку
		delete arr[i];
		// подменяем исходную строку новой
		arr[i] = buffer;
	}
	//после того как в каждую строку добывлен элемент,
	// в массиве появляется еще один столбец
	cols++;
}
void push_col_front(int** arr,const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		delete arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr,const int rows, int& cols, int number_cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			if (j < number_cols)buffer[j] = arr[i][j];
			else buffer[j+1 ] = arr[i][j];
		}
		delete arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr,const  int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for(int j=0;j<cols-1;j++)buffer[j] = arr[i][j];
		delete arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_front(int** arr,const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols; j++)	buffer[j] = arr[i][j+1];
		delete arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr,const int rows, int& cols, int number_cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols; j++)
		{
			if (j < number_cols)buffer[j] = arr[i][j];
			else buffer[j] = arr[i][j + 1];
		}
		delete arr[i];
		arr[i] = buffer;
	}
	cols--;
}