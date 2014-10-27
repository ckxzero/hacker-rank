#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int candyRating[100000];
  long long minCandy[100000];
  long long sum = 0;

  cin >> n;
  for (int i = 0; i < n; ++i) {
      cin >> candyRating[i];
  }

  minCandy[0] = 1;
  // look left then look right
  for (int i = 1; i < n; ++i) {
    if (candyRating[i] > candyRating[i-1]) {
      minCandy[i] = minCandy[i-1] + 1;
    } else {
      minCandy[i] = 1;
    }
  }
  for (int i = n-2; i >= 0; --i) {
    if (candyRating[i] > candyRating[i+1]) {
      if (minCandy[i] <= minCandy[i+1]) {
	minCandy[i] = minCandy[i+1] + 1;
      }
    }
  }

  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += minCandy[i];
  }

  cout << sum << endl;

  return 0;
}
