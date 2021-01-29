/*
https://leetcode.com/problems/search-a-2d-matrix/
*/

// When matrix is sorted row wise and the first element of the next row is greater than the 
// last element of the prev row
// Method 1 binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0)
            return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0;
        int high = (n * m) - 1;
        
        while(low <= high)
        {
            int mid = (low + (high - low) / 2);
            
            if(matrix[mid / m][mid % m] == target)
                return true;
            
            else if(matrix[mid / m][mid % m] < target)
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        
        return false;
        
    }
};

// https://leetcode.com/problems/search-a-2d-matrix-ii/
// Method 2
// When matrix is sorted both row wise and coloumn wise
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0)
            return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i = 0;
        int j = m - 1;
        
        while(i < n && j >=0)
        {
            if(target == matrix[i][j])
            {
                return true;
                break;
            }
            else if(target < matrix[i][j])
                j--;
            
            else
                i++;
        }
        
        return false;
        
    }
};