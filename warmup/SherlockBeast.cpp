#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t,n,fives,threes,r;


/*
    1. insert max numbers 5 (n%3) = r (number of 3)
        if n == 3x+5y, good
    2. find the stopping point
    3. print 5's up to the stopping point, and 3's the rest of the way
    4. keep adding multiples of 5s to 3s until no more.
        if n == 3x+5y, good
        else -1
*/
int main() {
  cin>>t;
  while(t--){
    cin>>n;
    if(n<3){
      cout<<"-1"<<endl;
    }else if(n%3==0){
      for(int i=0; i<n; ++i){
	cout<<5;
      }
      cout<<endl;
    }else{
      threes=n%3;
      fives=n-threes;
      r=5-threes;
      threes+=r;
      fives-=r;

      while((fives%3!=0 || threes%5!=0) && fives>=5){
	threes+=5;
	fives-=5;
	//if(fives%3==0 && threes%5==0)break;
      }

      if(fives%3==0 && threes%5==0){
	for(int i=0; i<fives; ++i){
	  cout<<5;
	}
	for(int i=0; i<threes; ++i){
	  cout<<3;
	}
	cout<<endl;
      }else{
	cout<<"-1"<<endl;
      }
    }//end else
  }//t
  return 0;
}
