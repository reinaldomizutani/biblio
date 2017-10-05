#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
#define TAM 1000
#define tamfila 10


typedef struct {
    int inicio, fim, total;
    int nusp[tamfila];
} fila;

typedef struct{
    char nome[MAX];
    char email[MAX];
    char telefone[MAX];
    int nusp;
}aluno;

typedef struct{
    char titulo[MAX];
    char autor[MAX];
    char editora[MAX];
    int isbn;
    int edicao;
    int qtd;
    fila alunos;
}livro;

typedef struct{
    union{
        aluno infoAluno;
        livro infoLivro;
    };
    int prox;
} no;

typedef struct {
        int ini, fim, pv;
        no itens[TAM];
} banco;


//operações da fila
void criaFila(fila*);
void EsvaziaFila(fila*);
int EstaVaziaFila(fila*);
int EstaCheiaFila(fila*);
void EntraFila(fila*, int*, int*);
/*


void SaiFila(Fila*, elem*, int*);
void busca_aluno_fila(Fila *F, int nusp, int *pos3);*/


// operações TAD
void cria(banco*);
void getnode(banco*,int*);
void freenode(banco*,int*);
void cadastraLivro(banco*,livro*,int*);
void cadastraAluno(banco*,aluno*,int*);
int EstaVazio(banco*);
int EstaCheio(banco*);
void Entra(fila*, int, int*);


// funções da fila
//void insereFilaEspera(banco*);


//void inserirAluno_Comeco(banco*, aluno*, int*);
void retirarAluno(banco*,aluno*,int*);
void retirarLivro(banco*,livro*,int*);
void imprimeLivros (banco*);
void imprimeAlunos (banco*);



// operações auxiliares
void buscaLivro(banco*, int, int*);
