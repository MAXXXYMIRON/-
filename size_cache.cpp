#include <iostream>
#include <ctime>
#include <random>
#include <vector>

using namespace std;

const int n = 1000000;
const int b = 10;

int main()
{
	int* a = new int[n]; 
	vector<int> c; // массив индексов элементов, на котором происходит увеличение времени выполнения
	unsigned long var = 0, // для извлечения элемента массива
		start_time = 0, end_time = 0; // для расчета времени выполнения
	double time_operation = 0, // время выполнения операции над элементом массива
		time_buf = 0,
		cache_length = 0, sumCache = 0, countJump = 0;

	for (int i = 0; i < n; i++)
	{
		a[i] = 2;
	}

	for (int i = 0; i < n; i++)
	{
		start_time = clock();
		var = a[i];
		var += b;
		a[i] = var;
		end_time = clock();

		time_operation = (double)(end_time - start_time) / CLOCKS_PER_SEC;

		if (time_buf < time_operation) {
			//c.push_back(i);
			countJump++;
		}
		time_buf = time_operation;
	}

	//for (int i = 0; i < c.size(); i++)
	//{
	//	sumCache += c[i];
	//}

	cache_length = (n / countJump) * 32;

	cout << cache_length / (1024 * 8) << " kB" << endl;

	delete[] a;

	system("pause");
	return 0;
}
