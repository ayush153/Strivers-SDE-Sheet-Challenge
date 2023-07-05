int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int start = 0;
	int end = arr.size()-1;
	while(start < end)
	{
		int mid = start + (end - start)/2;
		if (mid & 1) mid--;
		if (arr[mid] == arr[mid + 1]) start = mid + 2;
		else end = mid;
	}
    return arr[start];
}
