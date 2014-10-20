#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int nums[50000];
long long profits[50000];

int main() {

   cin >> t;

   for (int i = 0; i < t; ++i) {

      cin >> n;
      for (int j = 0; j < n; ++j) {
         cin >> nums[j];
      }

      profits[0] = 0;
      for (int j = 1; j < n; ++j) {
         for (int k = j-1; k >= 0; --k) {
            if (nums[j] <= nums[k]) {
               profits[j] += profits[k];
               break;
            } else if (nums[j] > nums[k]) {
               profits[j] += nums[j] - nums[k];
            }
         } //k
      } //j

      cout << profits[n-1] << endl;

      for (int j = 0; j < n; ++j) {
	profits[j] = 0;
      }
   } //i
   return 0;
}

