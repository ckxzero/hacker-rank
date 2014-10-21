#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int t, n;
  long long a[100009];
  long long sum[100009];
  long long dp[100009];

  cin >> t;
  for (int i = 0; i < t; ++i) {
    
    cin >> n;
    for (int j = n-1; j >= 0; --j) {
      cin >> a[j];
    }

    sum[0] = a[0];
    for (int j = 1; j < n; ++j) {
      sum[j] = a[j] + sum[j-1];
    }
    
    dp[0] = a[0]; //a[0] represents bottom of stack
    dp[1] = a[0] + a[1];
    dp[2] = a[0] + a[1] + a[2];
    // work backwards
    for (int j = 3; j < n+1; ++j) {
      dp[j] = max(a[j] + sum[j-1] - dp[j-1], a[j] + a[j-1] + sum[j-2] - dp[j-2], a[j] + a[j-1] + a[j-2] + sum[j-3] - dp[j-3]);
    } //j

    cout << maxScore[n];
  } //i

}
