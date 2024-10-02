#include "minishell.h"

static void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(char **arr, int left, int right)
{
	char	*pivot;
	int		i;
	int		j;

	pivot = arr[right];
	i = left - 1;
	j = left;
	while (j <= right - 1)
	{
		if (ft_strcmp(arr[j], pivot) <= 0)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
		++j;
	}
	swap(&arr[i + 1], &arr[right]);
	return (i + 1);
}

void	quick_sort(char **arr, int left, int right)
{
	int	p;

	if (left < right)
	{
		p = partition(arr, left, right);
		quick_sort(arr, left, p - 1);
		quick_sort(arr, p + 1, right);
	}
}
