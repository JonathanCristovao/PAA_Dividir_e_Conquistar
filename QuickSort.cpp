#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int quickSort(vector <int> &v, int l, int r){
   int i = l, j = r; //i recebe o valor da esquerda e j o valor da direita
   int p = v[r];  // pivô escolhido  o ultimo elemento a direita.  
   while (i <= j){         // particao 
              
      while (v[i] < p)
            i++;
         while (v[j] > p)
               j--;
               if (i <= j){
                  swap(v[i],v[j]);
                  i++; 
                  j--;
               }
            }
         if (l<j)
            quickSort(v, l, j);
               
         if (i<r)
            quickSort(v, i,r);
}
int main(){
   vector <int> v = {19, 55, 2,85,77, 29,6,30,80, 755,3,10};
   quickSort(v, 0, v.size()-1);
   
   for (int i = 0; i <v.size(); i++){
       cout << v[i] << " ";
   }
}