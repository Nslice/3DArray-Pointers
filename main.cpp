#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T = int, int dmns3, int dmns2, int dmns1>
void test(T testArr[dmns3][dmns2][dmns1], T*** src)
{
	cout << "\n************************** TEST *******************************\n";
	for (int i = 0; i < dmns3; i++)
	{
		for (int j = 0; j < dmns2; j++)
		{
			for (int k = 0; k < dmns1; k++)
			{
				int num = testArr[i][j][k] = src[i][j][k];
				cout << num << '\t';
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "************************** TEST *******************************\n";

}



int main()
{
	srand(time(nullptr));

	const int masA = 3, masB = 4, masC = 5;
	int*** cr, **ir, *jr;


	////объ€вление 
	int*** arr = new int**[masA];

	for (cr = arr; cr < arr + masA; cr++)
	{
		*cr = new int*[masB];
		for (ir = *cr; ir < *cr + masB; ir++)
			*ir = new int[masC];
	}
	//////////////////////////////////////// заполнение и вывод

	for (cr = arr; cr < arr + masA; cr++)
	{
		for (ir = *cr; ir < *cr + masB; ir++)
		{
			for (jr = *ir; jr < *ir + masC; jr++)
			{
				*jr = rand() % 30;
				cout << *jr << '\t';
			}
			cout << endl;
		}
		cout << endl;
	}

	
	int testArr[masA][masB][masC];
	test<int, masA, masB, masC>(testArr, arr);


	//////////////////////////////////// очистка
	for (cr = arr; cr < arr + masA; cr++)
	{
		for (ir = *cr; ir < *cr + masB; ir++)
		{
			delete[] * ir;
		}
		delete[] * cr;
	}
	delete[] arr;

	cout << "OK\n";

	return 0;
}