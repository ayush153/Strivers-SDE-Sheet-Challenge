 void fill (vector<vector<int>> &image, int r, int c, int m, int n, int target, int newColor){
        
    if(r < 0  || c < 0 || r == m || c == n || image[r][c] == newColor || image [r][c] != target)
        return;
    image[r][c] = newColor;
    fill(image, r+1, c, m, n, target, newColor);
    fill(image, r-1, c, m, n, target, newColor);
    fill(image, r, c+1, m, n, target, newColor);
    fill(image, r, c-1, m, n, target, newColor);
 }

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int m = image.size();
    int n = image[0].size();
    fill(image, x, y, m, n, image[x][y], newColor);
    return image;
}
