//Algoritmo MergeSort para a ordenaçao dos elementos em um array desordenado.
#include <iostream>
using namespace std;

void intercala_elementos(int a[], int n){
 int *temp = new int [n]; // arranjo temporario para intercalacao
 int meio = n/2;  
 int i=0, j=meio, k=0; 

 while ((i<meio) && (j<n)){  // enquanto i e j não chega ao fim dos arranjos
   
   if(a[i] < a[j]){ // o menor elemento vai para o arranjo temporario temp
      temp [k] = a[i];
      i++;
   }else{
      temp [k] = a[j];
      j++;
   }
   k++;
   }
 if (i == meio ){// copia o restante dos elementos do segundo arranjo para o arranjo temporario
   while (j < n){
      temp [k] = a[j];
      j++;
      k++;
   }
 }else{ //copia o restante dos elementos do primeiro arranjo para o arranjo temporario
   while (i < meio ){
     temp [k] = a[i];
     i++;
     k++;
   }
 }
//Elementos intercalados copiados para o array original a[]
 for (i = 0; i < n; i ++){
     a[i] = temp [i];
   } 
delete [] temp ; //Apagando o array temporario
}
void mergeSort(int a[], int n){
int meio;
 if (n>1){
   meio = n/2;
 mergeSort(a,meio);
 mergeSort(a+meio,n-meio);
 intercala_elementos(a,n);
 }
}
int main(){
   int arr[] = {19, 55, 2,85,77, 29,6,30,80, 755,3,10}; // Array exemplo para a ordenacao dos dados
   int n = sizeof(arr)/sizeof(arr[0]);
   int min;
   cout << "Array original :" <<" " ;
   for (int i = 0; i < n; i++){
       cout << arr[i] << " ";
   }
   cout<<" "<<endl; 
   mergeSort(arr,n);

   cout<< "Array ordenado :" <<" ";
   for (int i = 0; i < n; i++){
         cout << arr[i] << " ";
   }
   return (0);
}