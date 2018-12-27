#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int **create_arr(int a) {
  int **arr = new int* [a];

  for (int i = 0 ; i < a ; i++) {
    arr[i] = new int[a];
 }

  for (int i = 0 ; i < a ; i++) {
    for (int j = 0 ; j < a ; j++) {
      arr[i][j] = rand()% 100 - 50;
      cout << arr [i][j] << "\t";
    }
    cout << endl;
  }
  return arr;
}

int diag_sum(int **arr, int a) {
  int sum = 0 ;
  for (int i = 0 ; i < a ; i++) {
    for (int j = 0 ; j < a ; j++) {
      if (arr[i][0] < 0) {
        cout << arr[i][j] << "\t";
        if (i==j || i+j+1==a) {
          sum += abs(arr[i][j]);
        }
      }
    }
    cout << endl;
   }
  cout << "sum =  " << sum;

  return sum;
}

int **sort_array(int **arr, int a) {
int temp ;
 for(int i = 0; i<a; i++) {
    for(int j=0; j<a; j++) {
        for(int k=j+1; k<a; k++) {
          if(arr[i][k] < arr[i][j]) {
              temp = arr[i][j];
              arr[i][j] = arr[i][k];
              arr[i][k] = temp;
            }
        }
    }
 }
cout << "Your sorted array : \n\n";
for (int i = 0 ; i < a ; i++) {
    for (int j = 0 ; j < a ; j++) {
      cout << arr[i][j] << "\t";
    }
    cout << endl;
  }
}

int main() {
  srand(time(NULL));
  int a ;
  cout << "Enter a:";
  cin >> a ;
  int **arr1 = create_arr(a);
  cout << endl;
  int **arr2 = create_arr(a);
  cout << endl;
  int **arr3 = create_arr(a);
  cout << endl;

  int sum1 = diag_sum(arr1 , a);
  cout << endl;
  int sum2 = diag_sum(arr2 , a);
  cout << endl;
  int sum3 = diag_sum(arr3 , a);
  cout << endl;

  int sum = sum1;
  if (sum1 > sum2) {
    sum = sum2;
    if (sum2 > sum3) {
      sum = sum3;
       sort_array(arr3,a);
    }
    else {
      sort_array(arr2,a);
    }
  }
  else if (sum1 > sum3) {
    sum = sum3;
    sort_array(arr3,a);
  }
  else {
    sort_array(arr1,a);
  }

cout << " min sum = " << sum;

}

