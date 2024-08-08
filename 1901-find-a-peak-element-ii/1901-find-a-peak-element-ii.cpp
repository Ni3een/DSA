class Solution {
public:
    int maxi(vector<vector<int>> &mat, int n, int m, int col) {
        int index = -1;
        int maxofrow = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxofrow) {
                maxofrow = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(); // row size 
        int m = mat[0].size(); // column size
        int left = 0;
        int right = m - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int maxrow = maxi(mat, n, m, mid);
            int leftVal = mid - 1 >= 0 ? mat[maxrow][mid - 1] : -1;
            int rightVal = mid + 1 < m ? mat[maxrow][mid + 1] : -1;

            if (mat[maxrow][mid] > leftVal && mat[maxrow][mid] > rightVal) return {maxrow, mid};
            else if (mat[maxrow][mid] < leftVal) right = mid - 1;
            else left = mid + 1;
        }

        return {-1, -1};
    }
};