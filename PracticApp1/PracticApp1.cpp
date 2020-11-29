
/// Sangilov Miraziz (@mirazizsan)

// Вариант 24

//////////////////////////   Задание //////////////////////////////////////

//Ввести массив А(7, 7).
//Найти максимальный и минимальный элементы в побочной диагонали
//и поменять местами столбцы массива, в которых они находятся.
//Вывести максимальный и минимальный элементы, номера столбцов, в которых они находятся, исходный и результирующий массивы.

///////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	const int ROW = 7;
	const int COL = 7;

	// Создание и заполнение массива
	int arr[ROW][COL];

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = rand() % (8 + 1) + 1;
		}
	}

	// Поиск максимального элемента в побочной диагонали
	int max;
	max = arr[0][6];
	int coloum_number_of_max;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] > max && i + j == 7 - 1)
			{
				max = arr[i][j];
				coloum_number_of_max = j;
			}

		}
	}

	// Поиск минимального элемента в побочной диагонали
	int j = 6;
	int min;
	min = arr[0][j];
	int coloum_number_of_min;

	for (int i = 0; i < ROW; i++)
	{
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
				coloum_number_of_min = j;
			}
		}
		j--;
	}

	// Вывод исходного массива
	cout << "\n\tИсходный массив:\n" << endl;

	for (int i = 0; i < ROW; i++)
	{
		cout << "\t\t|";

		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << "|";

		cout << endl;
	}

	// Замена столбцов
	int temp;

	for (int i = 0; i < ROW; i++)
	{
		temp = arr[i][coloum_number_of_max];
		arr[i][coloum_number_of_max] = arr[i][coloum_number_of_min];
		arr[i][coloum_number_of_min] = temp;
	}

	// Вывод максимального элемента на побочной диагонали
	cout << "\n\tМаксимальный элемент на побочной диагонали: " << max << endl;
	cout << "\tЭлемент <" << max << "> находится на " << coloum_number_of_max + 1 << " стобце." << endl;

	// Вывод минимального элемента на побочной диагонали
	cout << "\n\tМинимальный элемент на побочной диагонали: " << min << endl;
	cout << "\tЭлемент <" << min << "> находится на " << coloum_number_of_min + 1 << " стобце." << endl;

	// Вывод результирующего массива
	cout << "\n\tРезультирующий массив:\n" << endl;

	for (int i = 0; i < ROW; i++)
	{
		cout << "\t\t|";

		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << "|";

		cout << endl;
	}

	system("pause");
	return 0;
}