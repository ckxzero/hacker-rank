#include <iostream>
using namespace std;

/*
 3, 5, 6, 9,10,12,15
18,20,21,24,25,27,30
33,35,36,39,40,42,45

 3, 2, 1, 3, 1, 3, 2 = difference between numbers
 */

int t,n,counter;
long long sum, num;

int main() {
  int i;
  cin>>t;
  while(t--){
    cin>>n;
    sum=0;
    counter=0;
    i=n/15;
    if(i>0){
      while(i--){
	//cout << "i: "<<i<< "\tsum: " << sum << endl;
	if(counter==0){
	  num+=3;
	  sum+=num;
	  counter++;
	  //cout << "sum" <<num<<": " << sum << endl;
	}if(counter==1){
	  num+=2;
	  sum+=num;
	  counter++;
	  //cout << "sum" <<num<<": " << sum << endl;
	}if(counter==2){
	  num+=1;
	  sum+=num;
	  counter++;
	  //cout << "sum" <<num<<": " << sum << endl;
	}if(counter==3){
	  num+=3;
	  sum+=num;
	  counter++;
	  //cout << "sum" <<num<<": " << sum << endl;
	}if(counter==4){
	  num+=1;
	  sum+=num;
	  counter++;
	  //cout << "sum" <<num<<": " << sum << endl;
	}if(counter==5){
	  num+=2;
	  sum+=num;
	  counter++;
	  //cout << "sum" <<num<<": " << sum << endl;
	}if(counter==6){
	  num+=3;
	  sum+=num;
	  counter=0;
	  //cout << "sum" <<num<<": " << sum << endl;
	}
	//--i;
      }
      //cout << "***: " << (n-n%15) << endl;
      for(i=n-n%15+1; i<n; ++i){
	if(i%3==0 || i%5==0){
	  //	  cout << "sum: " << sum << "i: " << i << endl;
	  sum+=i;
	}
      }
    }else{
      for(i=3; i<n; ++i){
	if(i%3==0 || i%5==0){
	  //	  cout << "sum: " << sum << "i: " << i << endl;
	  sum+=i;
	}
      }
    }
    cout<<sum<<endl;
  }
}
