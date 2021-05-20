// Algoritmo para calcular a casca convexa por dividir para conquistar
#include<bits/stdc++.h>
using namespace std;
#define iPair pair<int, int>
set<iPair> hull;

int determinant(iPair p1, iPair p2, iPair p){
	int val = (p.second - p1.second) * (p2.first - p1.first) -	(p2.second - p1.second) * (p.first - p1.first);

	if (val == 0){return 0;}
	else if (val > 0){return 1;}
	else{return 2;}
}
// p1 e p2 são os pontos finais da linha 
void quickHull(iPair a[], int n, iPair p1, iPair p2, int side){
	int ind = -1;
	int max_dist = 0;

	// encontrar o ponto com distância máxima da linha.
	for (int i=0; i<n; i++)	{
      iPair p = a[i]; 
	  int dis = (p.second - p1.second) * (p2.first - p1.first) -	(p2.second - p1.second) * (p.first - p1.first);//distancia entre os dois pontos p1 e p2
      int temp = abs(dis);
      int aux;
      
	  dis>0?aux=1:aux=-1; //Retorna o lado do ponto p em relação à linha que une os pontos p1 e p2.
            
      if (aux == side && temp > max_dist){
			ind = i;
			max_dist = temp;
		}
	}
	if (ind == -1){ // Se nenhum ponto for encontrado adicione os pontos finais na casca convexa.
		hull.insert(p1);
		hull.insert(p2);
		return;
	}
	// Recorre para as duas partes divididas por um [ind] 
	quickHull(a, n, a[ind], p1, -determinant(a[ind], p1, p2));
	quickHull(a, n, a[ind], p2, -determinant(a[ind], p2, p1));
}
void printHull(iPair a[], int n){
	//Encontra o ponto com a coordenada x mínima e máxima 
	int min_x = 0, max_x = 0;
	for (int i=1; i<n; i++){
		if (a[i].first < a[min_x].first)
			min_x = i;
		if (a[i].first > a[max_x].first)
			max_x = i;
	}
	// Chamada recursiva
	quickHull(a, n, a[min_x], a[max_x], 1);
	quickHull(a, n, a[min_x], a[max_x], -1);

	cout << "Pontos que pertence a esta casca convexa: ";
	while (!hull.empty()){
		cout << "(" <<( *hull.begin()).first << ", "<< (*hull.begin()).second << ") ";
		hull.erase(hull.begin());
	}
}
int main(){
	iPair a[] = {{1, 2}, {3, 2}, {7, 4}, {8, 5}, {2, 7}, {9, 5},{6, 3},{3, 8},{6, 7},{1,4},{5, -3}};
	int n = sizeof(a)/sizeof(a[0]);
	printHull(a, n);
	return 0;
}