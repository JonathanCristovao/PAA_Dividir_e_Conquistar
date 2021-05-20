//Algoritmo para encontrar o maior elemento do array por divisao e conquista
#include <iostream>
using namespace std;

int Maior_elemento(int a[], int l, int r){
if (l == r)  
    return a[l];

int m = (l+r)/2;
int u = Maior_elemento(a,l,m);//encontre o valor máximo para a parte inferior
int v = Maior_elemento(a,m+1,r); //encontre o valor máximo para a parte superior

//retorna o maior valor encontrado
if (u>v)
   return u;
else 
   return v; 
}
int main(){
   int v[] = {19, 55, 2,85,77, 29,6,755,30,80, 3,10}; // Array exemplo para a ordenacao dos dados
   int n = sizeof(v)/sizeof(int);
   cout <<"O maior elemento do array e "<<Maior_elemento(v,0,n-1)<<endl;
    return (0);
}