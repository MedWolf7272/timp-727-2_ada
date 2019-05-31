#include <stdio.h>
#include <stdlib.h>

int	sorting_function(int	*arr, int	arr_len)
{
	int n = 0; //счетчик колличества операций
	double p = 1.2473309; //фактор уменьшения
	int d = arr_len / p; //шаг сортировки
	int buf;  //буффер для перестановки
	for (int i = 0; i < arr_len; i ++) //обход массива
	{
		if (i + d <arr_len)  //проверка существования элемента
		{
			if (arr[i] > arr[i + d]) //проверка на необходимость перестановки
			{
				n++;
				buf = arr[i + d];
				arr[i + d] = arr[i];
				arr[i] = buf;
				n++;
			}
			else
			{
				n++;
			}
		}
		else
		{
			if (d != 1) 
			{
				i = -1;
				d = d / p; //уменьшение шага
			}
			else
			{
				break;
			}
		}
	}
	return n;
	
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
	//int co=
	sorting_function(arr, n);
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);
	//printf("%d\n", co);
	return 0;
}
