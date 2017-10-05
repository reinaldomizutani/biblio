#define TamP 100

typedef int elem;

typedef struct {
		int topo, total;
		elem itens[TamP];
} Pilha;

// Cria uma pilha P
void Create(Pilha *);
// Esvazia uma pilha P
void Empty(Pilha *);
//Insere o elemento X na pilha P. Retorna 0 se não houver erro, Retorna 1 se algum erro acontecer
int Push(Pilha *, elem *);
//Remove o elemento X da pilha P. Retorna 0 se não houver erro, Retorna 1 se algum erro acontecer
int Pop(Pilha *, elem *);
//Retorn a 1 se a pilha estiver vazia, 0 se a pilha tiver conteudo
int IsEmpty(Pilha *P);
//Retorn a 1 se a pilha estiver cheia, 0 se a pilha tiver conteudo ou vazia
int IsFull(Pilha *P);


