#include "estatico.h"
#include "pilha.h"
#include "fila.h"

void imprime(){
    int i = 0;
    scanf("%d", &i);

        system("clear");
    printf("=====================================================================\n");
    printf("=                     Sistema de Biblioteca                         =\n");
    printf("=                                                                   =\n");
    printf("=      Escolha a opcao desejada:                                    =\n");
    printf("=      1 - Cadastrar novo usuário                                   =\n");
    printf("=      2 - cadastrar novo livro no acervo                           =\n");
    printf("=      3 - Retirar livro                                            =\n");
    printf("=      4 - Devolver livro                                           =\n");
    printf("=      5 - Remover livro do acervo                                  =\n");
    printf("=      6 - Remover usuário                                          =\n");
    printf("=                                                                   =\n");
    printf("=                                                                   =\n");
    printf("=      digite sua opcao:                                            =\n");
    printf("=                                                                   =\n");
    printf("=                                                                   =\n");
    printf("=                                                                   =\n");
    printf("=====================================================================\n");


    while(i!=-1){
    system("clear");
    printf("=====================================================================\n");
    printf("=                     Sistema de Biblioteca                         =\n");
    printf("=                                                                   =\n");
    printf("=      Escolha a opcao desejada:                                    =\n");
    printf("=      1 - Cadastrar novo usuário                                   =\n");
    printf("=      2 - cadastrar novo livro no acervo                           =\n");
    printf("=      3 - Retirar livro                                            =\n");
    printf("=      4 - Devolver livro                                           =\n");
    printf("=      5 - Remover livro do acervo                                  =\n");
    printf("=      6 - Remover usuário                                          =\n");
    printf("=                                                                   =\n");
    printf("=                                                                   =\n");
    printf("=      digite sua opcao:                                            =\n");
    printf("=                                                                   =\n");
    printf("=                                                                   =\n");
    printf("=                                                                   =\n");
    printf("=====================================================================\n");
    scanf("%d", &i);
    }
}

void cria(banco *B) {
     int i;
     for (i=0;i<TAM-1;i++)
         B->itens[i].prox=i+1;
     B->itens[TAM-1].prox=-1;
     B->pv=0;
     B->ini=-1;
     B->fim=-1;
}

void getnode(banco *B, int *pos) {
    if (B->pv!=-1) {
       *pos=B->pv;
       B->pv=B->itens[B->pv].prox;
       B->itens[*pos].prox=-1;
    }
    else *pos=-1;
}
void freenode(banco *B, int *pos) {
    B->itens[*pos].prox=B->pv;
    B->pv=*pos;
}
int EstaVazio(banco *B) {
    if (B->ini==-1)
       return(1);
    else return(0);
}
int EstaCheio(banco *B) {
    if (B->pv==-1)
       return(1);
    else return(0);
}
/*void inserirAluno_Comeco(banco *B, aluno *X, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].usuarios=*X;
          B->itens[pos].prox=B->ini;
          B->ini=pos;
          if (B->fim==-1)
             B->fim=pos;
     }
}*/
void retirarAluno(banco *B, aluno *x, int *erro) {
     int pos;
     if (EstaVazio(B))
        *erro=1;
     else {
          *erro=0;
          *x=B->itens[B->ini].usuarios;
          pos=B->ini;
          B->ini=B->itens[B->ini].prox;
          if (B->ini==-1)
             B->fim=-1;
          freenode(B,&pos);
     }
}
void inserirAluno_fim(banco *B, aluno *x, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].usuarios=*x;
          B->itens[pos].prox=-1;
          if (B->fim!=-1)
             B->itens[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
             B->ini=pos;
     }
}

void retirarLivro_comeco(banco *B, livro *x, int *erro) {
     int pos;
     if (EstaVazio(B))
        *erro=1;
     else {
          *erro=0;
          *x=B->itens[B->ini].acervo;
          pos=B->ini;
          B->ini=B->itens[B->ini].prox;
          if (B->ini==-1)
             B->fim=-1;
          freenode(B,&pos);
     }
}
void inserirLivro_fim(banco *B, livro *x, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].acervo=*x;
          B->itens[pos].prox=-1;
          if (B->fim!=-1)
             B->itens[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
             B->ini=pos;
     }
}

void retirarLivro (banco *B, livro *x, int *erro){
    if (!EstaVazio(B)){
        *erro=0;
            if (B->itens->acervo->qtd==-1){
                EntraFila(F, X, erro);
            }
            else{
                retirarLivro_comeco(B, x, erro);
            }
    }
    else{
        *erro=1;
    }
}

void imprimeAlunos (banco *B){
    int i = B->ini;
    aluno al;

    while(i != -1){
        al = B->itens[i].usuarios;
        printf("\n\n%s\n%s\n%s\n%s\n\n", al.nome, al.nusp, al.email, al.telefone);
        i = B->itens[i].prox;
    }
}


//FUNCOES DA PILHA
void Create(Pilha *p){
	p->topo = -1;
	p->total = 0;
	return;
}

void Empty(Pilha *p){
	p->topo = -1;
	return;
}

int IsEmpty(Pilha *P){
	if(P->topo == -1)
		return 1;
	else return 0;
}

int IsFull(Pilha *P){
	if(P->topo == TamP-1)
		return 1;
	else return 0;
}

int Push(Pilha *P, elem *X){

	if(!IsFull(P)){
		P->topo++;
		P->total++;
		P->itens[P->topo] = *X;
		return 0;
	} else return 1;

//FUNÇÕES DA FILA
void CriaFila(Fila *F) {
     F->inicio=0;
     F->fim=0;
     F->total=0;
     return;
}

void EsvaziaFila(Fila *F) {
     F->inicio=0;
     F->fim=0;
     F->total=0;
     return;
}

int EstaVaziaFila(Fila *F) {
    if (F->total==0)
       return 1;
    else return 0;
}

int EstaCheiaFila(Fila *F) {
    if (F->total==TamF)
       return 1;
    else return 0;
}

void EntraFila(Fila *F, elem *X, int *erro) {
     if (!EstaCheiaFila(F)) {
          *erro=0;
          (F->total)++;
          F->itens[F->fim]=*X;
          if (F->fim==TamF-1) F->fim=0;
          else F->fim++;
     }
     else *erro=1;
     return;
}

void SaiFila(Fila *F, elem *X, int *erro) {
     if (!EstaVaziaFila(F)) {
          *erro=0;
          F->total--;
          *X=F->itens[F->inicio];
          if (F->inicio==TamF-1) F->inicio=0;
          else F->inicio++;
     }
     else *erro=1;
     return;
}
