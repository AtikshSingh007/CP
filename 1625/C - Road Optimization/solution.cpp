#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int num_signs, total_dist, max_removed;
    cin >> num_signs >> total_dist >> max_removed;
 
    vector<int> positions(num_signs + 1);
    for (int i = 0; i < num_signs; ++i) {
        cin >> positions[i];
    }
    positions[num_signs] = total_dist;
 
    vector<int> limits(num_signs);
    for (int i = 0; i < num_signs; ++i) {
        cin >> limits[i];
    }
 
    vector<vector<int>> min_time_dp(num_signs + 1, vector<int>(max_removed + 1, INF));
 
    min_time_dp[0][0] = 0;
 
    for (int i = 0; i < num_signs; ++i) {
        for (int j = 0; j <= max_removed; ++j) {
            if (min_time_dp[i][j] == INF) continue;
 
            int removed_count = 0;
            for (int l = i + 1; l <= num_signs; ++l) {
                if (j + removed_count <= max_removed) {
                    int segment_dist = positions[l] - positions[i];
                    int segment_time = segment_dist * limits[i];
                    min_time_dp[l][j + removed_count] = min(
                        min_time_dp[l][j + removed_count],
                        min_time_dp[i][j] + segment_time
                    );
                }
                removed_count++;
            }
        }
    }
 
    int result = INF;
    for (int j = 0; j <= max_removed; ++j) {
        result = min(result, min_time_dp[num_signs][j]);
    }
 
    cout << result << "
";
 
    return 0;
}