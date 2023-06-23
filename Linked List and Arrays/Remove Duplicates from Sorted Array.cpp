int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int idx = 1;
	for(int i = 0; i < n-1; i++) 
	{
		if(arr[i] != arr[i+1])
			arr[idx++] = arr[i+1];
	}
	return idx;
}
