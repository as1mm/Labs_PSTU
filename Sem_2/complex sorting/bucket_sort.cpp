#include <iostream>

void bucketSort(int arr[], int size)
{
    if (size <= 1) return;
    const int BUCKET_NUM = 10;
    const int BUCKET_SIZE = 100;
    int buckets[BUCKET_NUM][BUCKET_SIZE];
    int bucketSizes[BUCKET_NUM] = { 0 };

    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    { if (arr[i] > maxVal) maxVal = arr[i]; }

    // раскидываем элементы по ведрам
    for (int i = 0; i < size; i++)
    {
        // вычисляем индекс ведра
        int bucketIndex = (BUCKET_NUM * arr[i]) / (maxVal + 1);
        // защищаемся от переполнения ведра в статическом массиве
        if (bucketSizes[bucketIndex] < BUCKET_SIZE)
        {
            buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
            bucketSizes[bucketIndex]++;
        }
    }

    // сортируем каждое ведро (здесь — сортировкой вставками)
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        // пошла сортировка
        for (int j = 1; j < bucketSizes[i]; j++)
        {
            int tmp = buckets[i][j];
            int k = j-1;
            while (k >= 0 && buckets[i][k] > tmp)
            {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = tmp;
        }
    }
    // собираем элементы обратно в исходный массив
    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        { arr[idx++] = buckets[i][j]; }
    }
}

int main()
{
    int arr[10] = {2, 3, 3, 1, 1, 9, 5, 4, 2, 9};
    for (int i = 0; i < 10; i++) { std::cout << arr[i] << " "; }
    std::cout << "\n";

    bucketSort(arr, 10);

    for (int i = 0; i < 10; i++) { std::cout << arr[i] << " "; }
}