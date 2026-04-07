#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
int n;
int dist[20][20];
int dp[1 << 20][20];

// Function to solve TSP
int tsp(int mask, int pos) {
    // If all cities are visited, return distance to starting city
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // If already computed
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    // Try visiting all unvisited cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + 
                         tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    memset(dp, -1, sizeof(dp));

    cout << "Minimum travelling cost: " 
         << tsp(1, 0) << endl;

    return 0;
}
