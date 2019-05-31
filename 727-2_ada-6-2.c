#include <stdio.h>
#include <stdlib.h>

int	sorting_function(int	*arr, int	arr_len)
{
	int d = arr_len / 2; //шаг сортировки
	int buf; //буффер для обмена местами
	int r; //указатель на конец отсортированной части подмножества
	int n=0; //счетчик колличества операций
	while (d >= 1) 
	{
		for (int i = 0; i < d; i++) //проход по массиву
		{
			r = i;
			for (int j = i+d; j < arr_len; j += d) //разбиение на подмножества
			{				
				for (int k = r; k >= 0; k-=d) //сортировка вставкой в подмножестве
				{
					if (arr[k] > arr[j])
					{
						n++;
						buf = arr[j];
						arr[j] = arr[k];
						arr[k] = buf;
						n++;
					}
					else
					{
						n++;
						break;
					}
				}
				r+=d;
			}

		}
		d = d / 2+0.5;
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
//	int co=
	sorting_function(arr, n);
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);
//	printf("%d\n", co);
	return 0;
}
