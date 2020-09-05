/*
Numeros the Artist had two lists that were permutations of one another. He was very proud. Unfortunately, 
while transporting them from one exhibition to another, 
some numbers were lost out of the first list. Can you find the missing numbers?

Notes

If a number occurs multiple times in the lists, you must ensure that the frequency of that number in both lists is the same. 
If that is not the case, then it is also a missing number.
You have to print all the missing numbers in ascending order.
Print each missing number once, even if it is missing multiple times.
The difference between maximum and minimum number in the second list is less than or equal to 100.

Sample Input

10
203 204 205 206 207 208 203 204 205 206
13
203 204 204 205 206 207 205 208 203 206 205 206 204

Sample Output
204 205 206

*/


#include <iostream>     
#include <algorithm>    
#include <vector>

using namespace std;       

int main () {

  int size1, size2;
  cin>>size1;
  int first[1000000];
  for (int i = 0; i < size1; ++i)
    {    
        cin>>first[i];
    }

  cin>>size2;
  int second[1000000];
  for (int i = 0; i < size2; ++i)
    {    
        cin>>second[i];
    }

  vector <int> v(size1 + size2);                      
  vector<int>::iterator it;

  sort (first,first+size1);     
  sort (second,second+size2);

  if(second[size2 - 1] - second[0] < 101)
  {
  it=set_difference (second, second+size2, first, first+size1, v.begin());

  v.resize(it-v.begin());
  v.erase(unique(v.begin(), v.end()));

  for (it=v.begin(); it!=v.end(); ++it)
    cout << *it<< " ";
  cout << '\n';

  return 0;
}
}