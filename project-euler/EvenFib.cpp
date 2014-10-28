#include <iostream>
using namespace std;



int main(){
  long long t, n, previous;
  long long dp[10000000000000009];
  long long sum[10000000000000009];
  dp[0] = 0;
  sum[0] = 0;

  dp[1] = 1;
  sum[1] = 0;

  previous = 1;

  cin >> t;
  while(t--){

    cin >> n;
    for(int i = previous+1; i <= n; ++i){
      dp[i] = dp[i-1] + dp[i-2];
      if(dp[i] % 2 == 0){
	int j = i-1;
	while(sum[j] == 0 || j > 0){
	  --j;
	}
	sum[i] = dp[i] + sum[j];
      }

      if(previous < n){
	previous = n;
      }

      while(sum[n] == 0 || n > 0){
	--n;
      }
      if(n > 0){
	cout << sum[n] << endl;
      }else{
	cout << 0 << endl;
      }
    }//end for
  }//end while
}//end main


  /*
  while(t--){
    cin >> n;
    for(int i = previous+1; i < n; ++i){
      dp[i].key = dp[i-2].key + dp[i-1].key;
      if(dp[i].key % 2 == 0){
	int j = i-1;
	while(dp[j].sum != 0){
	  --j;
	}
	dp[i].sum = dp[i].key + dp[j].sum;
      }
    }
    if(previous < n){
      previous = n;
    }
    while(dp[n].sum != 0){
      --n;
    }
    if(n > 0){
      cout << dp[n].sum << endl;
    }else{
      cout << 0 << endl;
    }
  }//end while
  */
