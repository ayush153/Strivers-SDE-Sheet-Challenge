int search(int* arr, int n, int key) {
    // Write your code here.
    if (n == 0)
        return -1;
    
    int low = 0;
    int high = n - 1;
    
    // finding smallest  element index;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    int start = low;
    low = 0;
    high = n - 1;

    if (key >= arr[start] && key <= arr[high])
        low = start;
    else
        high = start;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
