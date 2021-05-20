// Algoritmo divisao e conquista para encontrar o maior e o menor elemento.
#include <iostream>
using namespace std;
 
void Menor_maior(int arr[], int l, int r, int &min, int &max){
      //Verificar se o array contem apenas 1 elemento.
      if (l == r){             
         if (max < arr[l]){           
             max = arr[l];
      }if (min > arr[r]){          
           min = arr[r];
        }
         return;
    } 
   int m = (l + r)/2; // Encontrar o elemento do meio
   Menor_maior(arr, l, m, min, max); // recursao para o array da esquerda
   Menor_maior(arr, m+1, r, min, max); // recursao para o array da direita
    
   if (min > arr[r]){     
      min = arr[r];
   }
   if (max < arr[l]) {     
      max = arr[l];
      }
   return;
}
int main(){
    int arr[] =  {19, 55, 2,85,77, 29,6,30,80, 755,3,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = -10000, min = 10000;
    Menor_maior(arr, 0, n-1, min, max);
 
    cout << "Menor elemento:  " << min << endl;
    cout << "Maior elemento:  " << max;
   return 0;
}