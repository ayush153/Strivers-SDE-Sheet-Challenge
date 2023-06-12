bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();
    int low = 0;
    int high = m*n  - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int currentRow = mid / n;
        int currentCol = mid % n;
        
        if(mat[currentRow][currentCol] == target) return true;
        if(mat[currentRow][currentCol] < target)  low = mid + 1;
        else  high = mid - 1;
    }
    return false;
        
}
