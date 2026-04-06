#include <iostream>

int InterSearch(int arr[], int left, int right, int key)
{
    bool flag = false;
    int mid;

    while ((!flag) && (left <= right))
    {
        mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[mid] > key) right = mid + 1;
        else if (arr[mid] < key) left = mid + 1;
        else flag = true;
    }

    if (arr[mid] == key) return mid;

    return -1;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << InterSearch(arr, 0, 4, 3);
}