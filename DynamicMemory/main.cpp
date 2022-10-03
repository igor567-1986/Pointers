#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define part_1
 
void FillRand(int arr[], const int n); 
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template<typename T>void Print(T* arr, const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T* arr, int& n,  T value);
template<typename T>T* push_front(T* arr, int& n, T value);
template<typename T>T* insert(T* arr, int& n, T value,int index);
template<typename T>T* pop_back(T* arr, int& n);
template<typename T>T* pop_front(T* arr, int& n);
template<typename T>T* erase(T* arr, int& n,int index);

 //2D
template<typename T>T** Allocate( const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows,const int cols);
template<typename T>T** insert_row(T** arr, int& rows,const int cols,int index);
template<typename T>T** pop_row_back(T** arr, int& rows,const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows,const int cols);
template<typename T>T** erase_row(T** arr, int& rows, int& cols,int index);

template<typename T>void push_col_back(T** arr,const int rows, int& cols);
template<typename T>void push_col_front(T** arr,const int rows, int& cols);
template<typename T>void insert_col(T** arr,const int rows, int& cols,int number_cols);

template<typename T>void pop_col_back(T** arr,const int rows, int& cols);
template<typename T>void pop_col_front(T** arr,const int rows, int& cols);
template<typename T>void erase_col(T** arr,const int rows, int& cols, int number_cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define rows_2d

void main()
{
	setlocale(LC_ALL, "");
	int n=0 ;
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
	int** arr = Allocate<int>(rows, cols);
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
	for (int i = 0; i < n; i++)*(arr + i) = rand() % 100;	
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)*(arr + i) = rand() ;	
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	      for (int j = 0; j < cols; j++)arr[i][j] = rand() % 100;
}
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)arr[i][j] = rand() ;
}

template<typename T>void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)cout << arr[i] << "\t";
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cout << arr[i][j] << "\t";
		cout << endl;
	}
}


template<typename T>T* push_back(T* arr,  int& n,T value)
{

	// 1) Создаем буферный массив нужного размера:
	T* buffer = new T[n+1];
	//2) Копируем исходный массив в буферный:
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	// 3) после того как все данные скопированны из исходного массива 
	// он больше не нужен и его надо удалить
	delete[]arr;
	// И только после этого можно написать вот так:
	buffer[n] = value;
	n++;
	// 6)После того как мы добавили в массив элемент,колличество элементов массива увеличивается.
	return buffer;
} 
template<typename T>T* push_front(T* arr, int& n, T value)
{
	T* buffer = new T[++n];
	for (int i = 0; i < n; i++)buffer[i+1] = arr[i];
	delete[]arr;
	buffer[0] = value;
	return buffer;
}
template<typename T>T* insert(T* arr, int& n, T value,int index)
{
    T* buffer = new T[++n];
   	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else if (i == index)buffer[i] = value;
		else buffer[i] = arr[i-1];
	}
	delete[]arr;
	return buffer;
} 

template<typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new T[n-1];
	for (int i = 0; i < n-1; i++)buffer[i] = arr[i];
	delete[]arr;
	n--;
	return buffer;
}
template<typename T>T* pop_front(T* arr, int& n)
{
	T* buffer = new T[n-1];
	for (int i = 0; i < n - 1; i++)buffer[i] = arr[i+1];
	delete[]arr;
	n--;
	return buffer;
} 
template<typename T>T* erase(T* arr, int& n, int index)
{
	T* buffer = new T(--n);
	for (int i = 0; i < n; i++)
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
} 

// 2D dynamic arays
template<typename T>T** Allocate( const int rows, const int cols)
{
	// Создаем массив указателей
	T** arr = new T* [rows];
	//Выделяем память под строки
	for (int i = 0; i < rows; i++) arr[i] = new int[cols]{};
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
{ 
	for (int i = 0; i < rows; i++) delete[]arr[i];                   
	delete[]arr;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	return push_back(arr, rows, new T[cols]{});
}
template<typename T>T** push_row_front(T** arr, int& rows,const int cols)
{
	return push_front(arr, rows, new T[cols]{});
}
template<typename T>T** insert_row(T** arr, int& rows,const int cols, int index)
{
	return insert(arr, rows, new T[cols]{}, index);
}
template<typename T>T** pop_row_back(T** arr, int& rows,const int cols)
{
	//1)удаляем строку из памяти
	delete[] arr[rows-1];
	//2)переопределяем массив указателей
	return pop_back(arr, rows);
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	delete[]arr[0];
	return pop_front(arr, rows);
}
template<typename T>T** erase_row(T** arr, int& rows, int& cols, int index)
{
    delete[] arr[index];
	T** buffer = new T * [rows - 1];
	for (int i = 0; i < rows; i++)
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
	return buffer;
	/*return erase(arr, rows, index); */
}


template<typename T>void push_col_back(T** arr,const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i],cols,T());
		cols--;
	}
	cols++;
}
template<typename T>void push_col_front(T** arr,const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_front(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>void insert_col(T** arr,const int rows, int& cols, int number_cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], cols, T(),number_cols);
		cols--;
	}
	cols++;
}
template<typename T>void pop_col_back(T** arr,const  int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}
template<typename T>void pop_col_front(T** arr,const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] =pop_front (arr[i], cols);
		cols++;
	}
	cols--;
}
template<typename T>void erase_col(T** arr,const int rows, int& cols, int number_cols)
{
	for (int i = 0; i < rows; i++)
	{
		/*T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols; j++)
			j < number_cols ? buffer[j] = arr[i][j] : buffer[j] = arr[i][j + 1];
		delete arr[i];
		arr[i] = buffer;*/
		arr[i] = erase(arr[i], cols,number_cols);
		cols++;
	}
	cols--;
}