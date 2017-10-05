#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
#define TAM 1000

typedef struct{
    int isbn;
    int num;
    int prox;
}retirados;

typedef struct{
    char nome[MAX];
    char email[MAX];
    char telefone[MAX];
    char nusp[MAX];
    retirados devolver;
}aluno;

typedef struct{
    char titulo[MAX];
    char autor[MAX];
    char editora[MAX];
    int isbn;
    int edicao;
    int qtd;
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


void cria(banco*);
void getnode(banco*,int*);
void freenode(banco*,int*);
void cadastraLivro(banco*,livro*,int*);
void cadastraAluno(banco*,aluno*,int*);
int EstaVazio(banco*);
int EstaCheio(banco*);



//void inserirAluno_Comeco(banco*, aluno*, int*);
void retirarAluno(banco*,aluno*,int*);
void retirarLivro(banco*,livro*,int*);
void imprimeLivros (banco*);
void imprimeAlunos (banco*);
