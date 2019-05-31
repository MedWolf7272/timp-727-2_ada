#include <stdio.h>
#include <stdlib.h>


int	sorting_function(int *arr, int	arr_len)
{
	if (arr_len==1)
	{
		return 0;
	}
	else 
	{
		int buf;
		int n = 0; //счетчик колличества операций
		//всплываем самый большой элемент
		for (int i = (arr_len / 2)-1; i >= 0; i--) //обход кучи без листьев
		{
			if ((2 * i + 1) < arr_len && (2 * i + 2) < arr_len) 
			{
				//есть оба листа
				if (arr[i] > arr[2 * i + 1]) //проверка левого потомка
				{
					n++;
					if (arr[i] > arr[2 * i + 2]) //проеврка правого потомка
					{
						n++;
						//heap - ok
					}
					else //меняем голову с правым потомком
					{
						n++;
						buf = arr[2 * i + 2];
						arr[2 * i + 2] = arr[i];
						arr[i] = buf;
						n++;
					}
				}
				else
				{
					n++;
					if (arr[2 * i + 2] < arr[2 * i + 1]) //ищем максимального потомка
					{
						//n++;
						buf = arr[2 * i + 1]; //меняем голову с левым потомком
						arr[2 * i + 1] = arr[i];
						arr[i] = buf;
						n++;
					}
					else //меняем голову с правым потомком
					{
						//n++;
						buf = arr[2 * i + 2];
						arr[2 * i + 2] = arr[i];
						arr[i] = buf;
						n++;
					}
				}
			}
			else 
			{
				//есть только левый лист
				if (arr[i] > arr[2 * i + 1]) //проверка левого потомка
				{
					n++;
					//heap - ok
				}
				else //меняем голову с левым потомком
				{
					n++;
					buf = arr[2 * i + 1];
					arr[2 * i + 1] = arr[i];
					arr[i] = buf;
					n++;
				}			

			}
		}
		//ставим самый большой элемент в конец
		buf = arr[0];
		arr[0] = arr[arr_len - 1];
		arr[arr_len-1] = buf;
		n++;
		//снова сортируем кучу
		return (n + sorting_function(arr, arr_len - 1));
	}
}
int main()
{
	
	int n;
	scanf("%d", &n);
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//int count=
	sorting_function(arr, n);
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);
	//printf("%d\n", count);
	return 0;
}
