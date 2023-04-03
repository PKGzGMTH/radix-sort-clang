#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* get max value from array
 * @param arr array of intenger
 * @param n range of array
*/
int	max_value(int *arr, int n)
{
	int	max;

	max = arr[0];
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/* sort with radix algorithm
 * @param arr array of intenger
 * @param n range of array
 * @param mode true if show full log
 * @return sorted array
*/
int	*radix_sort(int *arr, int n, bool fullmode)
{
	int	index;
	int	div;
	int	max;
	int	round;
	int	**mem;
	int	mem_count[10];

	div = 1;
	round = 0;
	max = max_value(arr, n);
	mem = (int **) calloc (10, sizeof(int *));
	for (int i = 0; i < 10; i++)
		mem[i] = (int *) calloc (n, sizeof(int));
	while (max)
	{
		max /= 10;
		round++;
	}
	printf ("Max: %d\nRound: %d\n", max_value(arr, n), round);
	for (int r = 0; r < round; r++)
	{
		index = 0;
		for (int i = 0; i < 10; i++)
			mem_count[i] = 0;
		for (int i = 0; i < n; i++)
		{
			mem[(arr[i]/div)%10][mem_count[(arr[i]/div)%10]] = arr[i];
			mem_count[(arr[i]/div)%10]++;
			if (fullmode)
			{
				printf("================================\n");
				for (int i = 0; i < 10; i++)
				{
					printf("[%d]: ", i);
					for (int j = 0; j < mem_count[i]; j++)
						printf("%d ", mem[i][j]);
					printf("\n");
				}
			}
		}
		printf("====== Radix Sort Round %d ======\n", r + 1);
		for (int i = 0; i < 10; i++)
		{
			printf("[%d]: ", i);
			for (int j = 0; j < mem_count[i]; j++)
				printf("%d ", mem[i][j]);
			printf("\n");
		}
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < mem_count[j]; i++)
				arr[index++] = mem[j][i];
		}
		printf("================================\nArray: ");
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n\n");
		div *= 10;
	}
	for (int i = 0; i < 10; i++)
		if (mem[i])
			free (mem[i]);
	if (mem)
		free (mem);
	return (arr);
}

int	main(int argc, char **argv)
{
	int	n;
	int	*arr;

	n = argc - 1;
	arr = (int *) calloc (n, sizeof(int));
	for (int i = 0; i < n; i++)
		arr[i] = atoi(argv[i + 1]);
	printf("================================\nInput: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	radix_sort(arr, n, true);

	printf("================================\nSorted Array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n================================\n");
	if (arr)
		free (arr);
	return (0);
}
