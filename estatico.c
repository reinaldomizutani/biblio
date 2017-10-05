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
void getnode(banco *B, int *pos) { //retorna para *pos o primeiro vazio e troca o �ndice da lista de vazios para a pr�xima posi��o
    if (B->pv != -1) {
       *pos = B->pv;
       B->pv = B->itens[B->pv].prox;
       B->itens[*pos].prox = -1;
    }
    else *pos=-1;
}
void freenode(banco *B, int *pos) { //insere  a posi��o *pos no primeiro vazio e aponta o pr�ximo para o primeiro vazio
    B->itens[*pos].prox = B->pv;
    B->pv = *pos;
}
int EstaVazio(banco *B) { //retorna 1 se o banco estiver vazio
    if (B->ini==-1)
       return(1);
    else return(0);
}
int EstaCheio(banco *B) { // retorna 1 se o banco estiver cheio.
    if (B->pv==-1)
       return(1);
    else return(0);
}
void cadastraLivro(banco *B, livro *x, int *erro){
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].infoLivro=*x;
          B->itens[pos].prox=-1;
          printf("\n\n\nCADASTRA LIVRO\n\nQTD = %d", B->itens[pos].infoLivro.qtd);
          criaFila(&B->itens[pos].infoLivro.alunos);
          if (B->fim!=-1)
              B->itens[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
              B->ini=pos;
     }
}
void cadastraAluno(banco *B, aluno *x, int *erro){
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

//emprestaLivro(   &acervo,   &nusp,      &isbn,     &erro);
void emprestaLivro(banco *B, int *nusp, int *isbn, int *erro){
    int pos=0;
    int erro2 = *erro;
    buscaLivro(B, *isbn, &pos);

    printf("\n\nCHEGOU AQUI\n\n");
    if(B->itens[pos].infoLivro.qtd > 0){
        B->itens[pos].infoLivro.qtd--;
        printf("\nlivro retirado com sucesso (qtd = %d)  \n\n", B->itens[pos].infoLivro.qtd);
    }
    else{
        Entra(&B->itens[pos].infoLivro.alunos, *nusp, &erro2);
        printf("\nlivro adicionado a lista de espera (qtd = %d)  \n\n", B->itens[pos].infoLivro.qtd);
    }
    *erro = erro2;
}

/* BACKUP
void emprestaLivro(banco *B, aluno *x, livro *l, int *erro){
    int pos;
    int erro2 = *erro;
    buscaLivro(B, l->isbn, &pos);
    if(B->itens[pos].infoLivro.qtd > 0){
        B->itens[pos].infoLivro.qtd--;
        printf("\nlivro retirado com sucesso (qtd = %d)  \n\n", B->itens[pos].infoLivro.qtd);
    }
    else{
        Entra(&B->itens[pos].infoLivro.alunos, &x->nusp, &erro2);
        printf("\nlivro adicionado a lista de espera (qtd = %d)  \n\n", B->itens[pos].infoLivro.qtd);
    }
    *erro = erro2;
}*/
void buscaLivro(banco *B, int isbn, int *posicao){

    for(*posicao = 0 ; *posicao <= TAM ; *posicao = *posicao+1){
        if(B->itens[*posicao].infoLivro.isbn == isbn)
            return;
    }
    *posicao = -1;
}

// FUNÇÕES DE FILA

void criaFila(fila *F) {
    F->inicio=0;
    F->fim=0;
    F->total=0;
    return;
}
void esvaziaFila(fila *F) {
    F->inicio=0;
    F->fim=0;
    F->total=0;
    return;
}
int EstaVazia(fila *F) {
    if (F->total==0)
       return 1;
    else
    return 0;
}
int EstaCheia(fila *F) {
    if (F->total==tamfila)
       return 1;
    else return 0;
}
void Entra(fila *F, int nusp, int *erro){
    if (!EstaCheia(F)) {
         *erro=0;
         F->total++;
         F->nusp[F->fim]=nusp;
         if (F->fim==tamfila-1) F->fim=0;
         else F->fim++;
    }
    else *erro=1;
    return;
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
    printf("\n\nnome: %s\nnusp: %d\nemail: %s\ntelefone: %s\n", al.nome, al.nusp, al.email, al.telefone);
    i = B->itens[i].prox;
}
}
