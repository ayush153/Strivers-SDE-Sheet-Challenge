#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	 int rows = matrix.size(), cols = matrix[0].size();
     vector < int > dummy1(rows,-1), dummy2(cols,-1);
     for (int i = 0; i < rows; i++)
     {
        for (int j=0; j<cols; j++)
        {
            if (matrix[i][j]== 0)
            {
                dummy1[i]=0;
                dummy2[j]=  0;
            }
        }

    }
  	for (int i=0; i<rows; i++) 
  	{
    	for (int j=0; j<cols; j++)
		{
      		if (dummy1[i]==0 || dummy2[j]==0) matrix[i][j]=0;
    	}
  	}

}
