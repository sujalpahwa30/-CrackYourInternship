class Solution {
public:
// The below function will do dfs from currRow , currCol to it's neighbours containing initialColor
    void dfs(vector<vector<int>>& image , int currRow , int currCol , int initialColor , int newColor){
        int n = image.size();  // total rows 
        int m = image[0].size();  // total columns
        if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m){
            return;  // you are outside the grid
        }
// If the cell you landed is not of initial color
        if(image[currRow][currCol] != initialColor) return;
        image[currRow][currCol] = newColor;
        dfs(image , currRow+1 , currCol , initialColor , newColor);  // Down
        dfs(image , currRow , currCol-1 , initialColor , newColor);  // Left
        dfs(image , currRow-1 , currCol , initialColor , newColor);  // Up
        dfs(image , currRow , currCol+1 , initialColor , newColor);  // Right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        dfs(image , sr , sc , image[sr][sc] , color);
        return image;
    }
};