// Algoritmo para encontrar o tamanho da arvore binaria
#include <iostream>
using namespace std;
//Função auxiliar que aloca um novo no com os dados fornecidos e ponteiros NULL à esquerda e à direita. 
struct node{
    int info;
    node *esquerda;
    node *direita;
};
typedef node *nodeptr;
int Tamanho_arvore(node* node){
	if (node == NULL)
		return 0;
	else{
		int tam_l = Tamanho_arvore(node->esquerda);
		int tam_r = Tamanho_arvore(node->direita);
		if (tam_l > tam_r)
			return(tam_l + 1);
		else return (tam_r + 1);
	}
}
void Inserir(nodeptr &p, int x){
  
    if (p == NULL){
        p = new node;
        p->info = x;
        p->esquerda = NULL;
        p->direita = NULL;
    }
    else{
        if(x < p->info)// Insere na subarvore esquerda caso contrario insere na sbarvore a direita
            Inserir(p->esquerda, x);
        else
            Inserir(p->direita, x);
    }
}
//Arvore -->>              8
    //                   /   \
    //                 3      10 
    //               /  \      \
    //              1    6      14 
    //                  / \    /
    //                 4   7  13  
int main(){
    nodeptr arvore = NULL;
    Inserir(arvore,8);
    Inserir(arvore,3);
	Inserir(arvore,10);
	Inserir(arvore,14);
	Inserir(arvore,13);
	Inserir(arvore,1);
	Inserir(arvore,6);
	Inserir(arvore,4);
	Inserir(arvore,7);
	cout << "O tamanho da arvore e " << Tamanho_arvore(arvore);
	return 0;
}
