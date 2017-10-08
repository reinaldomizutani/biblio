#include "estatico.h"

void cria(banco *B){
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
void emprestaLivro(banco *B, int *nusp, int *isbn, int *erro){
    int pos=0;
    int erro2 = *erro;
    buscaLivro(B, *isbn, &pos);

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
void buscaLivro(banco *B, int isbn, int *posicao){

    for(*posicao = 0 ; *posicao <= TAM ; *posicao = *posicao+1){
        if(B->itens[*posicao].infoLivro.isbn == isbn)
            return;
    }
    *posicao = -1;
}
void buscaAluno(banco *B, int nusp, int *posicao){

    for(*posicao = 0 ; *posicao <= TAM ; *posicao = *posicao+1){
        if(B->itens[*posicao].infoAluno.nusp == nusp)
            return;
    }
    *posicao = -1;
}
void retornaLivro(banco *B, int *isbn, int *erro){
    int pos = 0;
    int erro2 = *erro;
    buscaLivro(B, *isbn, &pos);

    if(B->itens[pos].infoLivro.qtd > 0){
        B->itens[pos].infoLivro.qtd++;
        printf("\nlivro devolvido com sucesso (qtd = %d)  \n\n", B->itens[pos].infoLivro.qtd);
    }
    else{
        Sai(&B->itens[pos].infoLivro.alunos, &erro2);
        printf("\nUsuario informado (qtd = %d)  \n\n", B->itens[pos].infoLivro.qtd);
    }
    *erro = erro2;
}
void removeLivro(banco *B, int *isbn, int *erro){
    int pos, aux;
    if(EstaVazio(B)){
        *erro = 1;
    }
    else{
        *erro = 0;
        buscaLivro(B, *isbn, &pos);
        aux = B->itens[pos].prox;
        B->itens[pos].infoLivro = B->itens[B->ini].infoLivro;
        B->itens[pos].prox = aux;
        aux = B->ini;
        B->ini = B->itens[B->ini].prox;
        B->pv = aux;
    }
}
void removeFilaEspera(banco *B, int *nusp){
    int i;
    for(i=0 ; i<TAM ; i++){

    }
}
void removeAluno(banco *B, int *nusp, int*erro){
    int pos, aux;
    if(EstaVazio(B)){
        *erro = 1;
    }
    else{
        *erro = 0;
        buscaLivro(B, *isbn, &pos);
        aux = B->itens[pos].prox;
        B->itens[pos].infoLivro = B->itens[B->ini].infoLivro;
        B->itens[pos].prox = aux;
        aux = B->ini;
        B->ini = B->itens[B->ini].prox;
        B->pv = aux;
    }
}
}
    /*
    int pos;

    if (EstaVazio(B))
        *erro=1;
    else{
    buscaLivro(B, *isbn, &pos);
    // jogando o no no fim da fila;
    int pos2 = B->itens[pos].prox;
    B->itens[pos].infoLivro = B->itens[B->fim].infoLivro;
    B->itens[pos].prox = pos2;
    printf("\n%s\n", B->itens[pos].infoLivro.titulo);
    while(B->itens[pos2].prox != -1){
        pos = pos2;
        pos2 = B->itens[pos2].prox;
    }
    freenode(B, &B->itens[pos2].prox);

    }

    printf("\nPOS2 = %d\n", pos2);
    B->itens[pos].infoLivro = B->itens[B->fim].infoLivro;
    printf("\n\nLIVRO : %s\n\n", B->itens[pos].infoLivro.titulo);
    B->itens[pos].prox = pos2;
    freenode(B, &B->ini);
    }
    while(pos < TAM-1){
        B->itens[pos].infoLivro = B->itens[pos+1].infoLivro;
        pos++;
    }
    printf("\n\nLivro removido do acervo\n\n");
*/


// FUNÇÕES DE FILA

void criaFila(fila *F) {
    F->inicio=0;
    F->fim=0;
    F->total=0;
    for(int i=0 ; i<tamfila ; i++){
        F->alu[i].prox = i+1;
    }
    F->alu[tamfila-1].prox = -1;
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
    else
        return 0;
}
void Entra(fila *F, int nusp, int *erro){
    if (!EstaCheia(F)) {
         *erro=0;
         F->total++;
         F->alu[F->fim].nusp = nusp;

         if
            (F->fim==tamfila-1) F->fim=0;
         else
            F->fim++;
    }
    else *erro=1;
    return;
}
void Sai(fila *F, int *erro){

    if(EstaVazia(F))
        *erro = 1;
    else{
        *erro=0;
        F->total--;
        F->inicio++;

        if((F->inicio) > (tamfila-1))
            F->inicio = 0;
    }
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
    printf("\n%s\n%s\n%s\n", liv.titulo, liv.autor, liv.editora);
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
