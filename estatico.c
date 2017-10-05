#include "estatico.h"

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
void cadastraLivro(banco *B, livro *x, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].infoLivro=*x;
          B->itens[pos].prox=-1;
          if (B->fim!=-1)
              B->itens[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
              B->ini=pos;
     }
}
void cadastraAluno(banco *B, aluno *x, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].infoAluno=*x;
          B->itens[pos].prox=-1;
          if (B->fim!=-1)
             B->itens[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
             B->ini=pos;
     }
}










void retirarAluno(banco *B, aluno *x, int *erro) {
     int pos;
     if (EstaVazio(B))
        *erro=1;
     else {
          *erro=0;
          *x=B->itens[B->ini].infoAluno;
          pos=B->ini;
          B->ini=B->itens[B->ini].prox;
          if (B->ini==-1)
             B->fim=-1;
          freenode(B,&pos);
     }
}


void retirarLivro(banco *B, livro *x, int *erro) {
     int pos;
     if (EstaVazio(B))
        *erro=1;
     else {
          *erro=0;
          *x=B->itens[B->ini].infoLivro;
          pos=B->ini;
          B->ini=B->itens[B->ini].prox;
          if (B->ini==-1)
             B->fim=-1;
          freenode(B,&pos);
     }
}


void imprimeLivros (banco *B){
int i = B->ini;
livro liv;
system("cls");
while(i != -1){
    liv = B->itens[i].infoLivro;
    printf("\n\n%s\n%s\n%s\n\n", liv.titulo, liv.autor, liv.editora);
    i = B->itens[i].prox;
}
}

void imprimeAlunos (banco *B){
int i = B->ini;
aluno al;
system("cls");
while(i != -1){
    al = B->itens[i].infoAluno;
    printf("\n\n%s\n%s\n%s\n%szn\n", al.nome, al.nusp, al.email, al.telefone);
    i = B->itens[i].prox;
}
}
