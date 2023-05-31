#include <bits/stdc++.h>

using namespace std;

void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
    int n = image.size();
    int m = image[0].size();
    
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != oldColor || image[sr][sc] == newColor) {
        return;
    }
    
    image[sr][sc] = newColor;
    
    // Recursively fill neighboring pixels
    floodFill(image, sr + 1, sc, newColor, oldColor);  // down
    floodFill(image, sr - 1, sc, newColor, oldColor);  // up
    floodFill(image, sr, sc + 1, newColor, oldColor);  // right
    floodFill(image, sr, sc - 1, newColor, oldColor);  // left
}

vector<vector<int>> solve(vector<vector<int>>& image, int sr, int sc, int color) {
    int oldColor = image[sr][sc];
    floodFill(image, sr, sc, color, oldColor);
    return image;
}

// Do not modify the code below
int main() {
    int n;
    cin >> n;
    vector<vector<int>> image(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }
    int sr, sc, color;
    cin >> sr >> sc >> color;

    vector<vector<int>> ans = solve(image, sr, sc, color);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {   
            cout << ans[i][j];
            if(j != n - 1)
                cout << ' ';
        }
        if(i != n - 1)
            cout << '\n';
    }
}
