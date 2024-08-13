#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printPath(vector<vector<int>>&maze, int i, int j, string ans){
	if (i == maze.size()/2 && j==maze.size()/2){
		ans += "(";
		ans += to_string(i);
		ans += ", ";
		ans += to_string(j);
		ans += ") -> MID";
		cout<<ans<<endl;
		return;
	}
	if (maze[i][j]==0){
		return;
	}
	int k = maze[i][j];
	maze[i][j]=0;
	ans += "(";
	ans += to_string(i);
	ans += ", ";
	ans += to_string(j);
	ans += ") -> ";
	if (j+k<maze.size()){
		printPath(maze, i, j+k, ans);
	}
	if (i+k<maze.size()){
		printPath(maze, i+k, j,ans);
	}
	if (j-k>0){
		printPath(maze, i, j-k, ans);
	}
	if (i-k>0){
		printPath(maze, i-k, j, ans);
	}
	maze[i][j] = k;
}
int main () {
	vector<vector<int>>maze = {
		{ 3, 5, 4, 4, 7, 3, 4, 6, 3 },
		{ 6, 7, 5, 6, 6, 2, 6, 6, 2 },
		{ 3, 3, 4, 3, 2, 5, 4, 7, 2 },
		{ 6, 5, 5, 1, 2, 3, 6, 5, 6 },
		{ 3, 3, 4, 3, 0, 1, 4, 3, 4 },
		{ 3, 5, 4, 3, 2, 2, 3, 3, 5 },
		{ 3, 5, 4, 3, 2, 6, 4, 4, 3 },
		{ 3, 5, 1, 3, 7, 5, 3, 6, 4 },
		{ 6, 2, 4, 3, 4, 5, 4, 5, 1 }
	};
	printPath(maze,0,0,"");
}
