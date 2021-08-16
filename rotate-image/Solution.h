/*
    48. Rotate Image
    Medium

    You are given an n x n 2D matrix representing an image, 
    rotate the image by 90 degrees (clockwise).

    You have to rotate the image in-place, which means you 
    \have to modify the input 2D matrix directly. DO NOT allocate 
    another 2D matrix and do the rotation.

    Example 1:


Input: matrix = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]

Output: [[7,4,1],
         [8,5,2],
         [9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],
                 [2,4,8,10],
                 [13,3,6,7],
                 [15,14,12,16]]

Output: [[15,13,2,5],
         [14,3,4,1],
         [12,6,8,9],
         [16,7,10,11]]
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        
        int n = matrix.size();
        
        int row1 = 0; 
        int row2 = n - 1; 
        
        // step 1: swap the top and bottom row
        while(row1 < row2) {
            
            for (int j = 0; j < n; ++j) {
                swap(matrix[row1][j], matrix[row2][j]);
            }            
            row1++;
            row2--;            
        }
        
        // step 2: transpose
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};