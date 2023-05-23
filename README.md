# Week #11 - Graphs

## Problem 1

You are given `row x col` grid representing a map where `grid[i][j] = 1` represents land and `grid[i][j] = 0` represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

![image](https://github.com/CS-221-DS-ALGO/week11-graphs/assets/129171338/5f791154-7519-4037-9f55-09a2f896d330)

**Example**
```
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
```

## Problem 2

There are $n$ cities numbered from $0$ to $n-1$. Given the array edges where $edges[i] = [from_i, to_i, weight_i]$ represents a bidirectional and weighted edge between cities $from_i$ and $to_i$, and given the integer `distanceThreshold`.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most `distanceThreshold`, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities $i$ and $j$ is equal to the sum of the edges' weights along that path.

<img width="277" alt="image" src="https://github.com/CS-221-DS-ALGO/week11-graphs/assets/129171338/66fe1aa5-d437-4db1-bce6-bd229cfe2c32">


**Example**
```
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
```

