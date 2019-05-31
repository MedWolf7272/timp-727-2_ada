#include <stdio.h>
#include <stdlib.h>

//опорный - последний элемент массива
int	sorting_function(int	*arr, int	arr_left, int arr_right)
{
	int n = 0;
	
	if (arr_left == arr_right|| arr_left>arr_right) //условие остановки рекусрии
	{
		return 0;
	}
	else 
	{		
		int buf;
		int pillar = arr_right;
		for (int i = 0; i < pillar; i++)
		{
			if (arr[i] > arr[pillar]) //свдиг опорного
			{
				n++;
				buf = arr[i];
				arr[i] = arr[pillar - 1];
				n++;
				arr[pillar - 1] = arr[pillar];
				n++;
				arr[pillar] = buf;
				n++;
				pillar--;
				i--;
			}
			else
			{
				n++;
			}
		}
		return(n+sorting_function(arr, arr_left, pillar - 1) + sorting_function(arr, pillar + 1, arr_right));
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
	sorting_function(arr, 0, n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);
	//printf("%d\n", count);
	return 0;
}
