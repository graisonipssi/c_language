#include <stdlib.h>

int *ip_range(int min, int max) {
    if (min >= max)
        return (NULL);

    int size = max - min;
    int *array = (int *)malloc(sizeof(int) * size);

    if (array == NULL)
        return (NULL);

    int i = 0;
    while (i < size) {
        array[i] = min + i;
        i++;
    }

    return (array);
}
