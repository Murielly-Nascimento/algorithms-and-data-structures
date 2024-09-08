#include <iostream>
using namespace std;

class NO{
    public:
        int valor;
        NO* proximo;
};

class PILHA{
    public:
        int qtd = 0;
        int topo = 0;
        NO* proximo = nullptr;

    PILHA() : proximo(nullptr), qtd(0), topo(0) {}
};

PILHA inserir(PILHA pilha, int valor){
    if(pilha.topo == 0){
        pilha.proximo = nullptr;
        pilha.topo = valor;
    }
    else{
        NO* novo = new NO();
        novo->proximo = pilha.proximo;
        novo->valor = pilha.topo;
        
        pilha.topo = valor;
        pilha.proximo = novo;    
    }
    pilha.qtd +=1;

    return pilha;
}

PILHA desempilhar(PILHA pilha){
    if (pilha.proximo == nullptr){
        cout << "Pilha vazia." << endl;
        return pilha;
    }
    NO *aux = pilha.proximo;

    if (aux->proximo == nullptr){
        pilha.proximo = nullptr;
        pilha.topo = aux->valor;
    }
    else{
        pilha.proximo = aux->proximo;
        pilha.topo = pilha.proximo->valor;
        
    }
    pilha.qtd -=1;
    delete aux;

    return pilha;
}

PILHA esvaziar(PILHA pilha){
    while(pilha.proximo != nullptr){
        pilha = desempilhar(pilha);
    }
    return pilha;
}

int main(void){

    PILHA pilha;
    pilha = inserir(pilha, 10);
    pilha = inserir(pilha, 3);
    
    cout << pilha.topo << endl;

    pilha = desempilhar(pilha);

    cout << pilha.topo << endl;

    pilha = esvaziar(pilha);

    return 0;
}