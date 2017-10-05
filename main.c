#include "estatico.c"

int main(){
// declaracao de variaveis
    int opcao, erro;//, opMsg;
    aluno Aluno;
    livro Livro;
    banco usuarios, acervo;

    cria(&usuarios);
    cria(&acervo);

    printf("digite a opcao desejada: \n 1 - cadastro de usuario\n 2 - cadastro de livro\n");
    scanf("%d",&opcao);

    while(opcao != -1){
        switch(opcao){
            case 1: // cadastrar usuario;
                printf("nome: ");
                scanf(" %[^\n]s", Aluno.nome);
                printf("email: ");
                scanf(" %[^\n]s", Aluno.email);
                printf("telefone: ");
                scanf(" %[^\n]s", Aluno.telefone);
                printf("nusp: ");
                scanf(" %[^\n]s", Aluno.nusp);
                cadastraAluno(&usuarios, &Aluno, &erro);
                imprimeAlunos(&usuarios);

                break;

            case 2: //cadastrar livro;
                printf("Titulo: ");
                scanf(" %[^\n]s", Livro.titulo);
                printf("Autor: ");
                scanf(" %[^\n]s", Livro.autor);
                printf("Editora: ");
                scanf(" %[^\n]s", Livro.editora);
                printf("isbn: ");
                scanf("%d", &Livro.isbn);
                printf("Edicao: ");
                scanf("%d", &Livro.edicao);
                printf("qtd: ");
                scanf("%d", &Livro.qtd);
                cadastraLivro(&acervo, &Livro, &erro);
                imprimeLivros(&acervo);

            case 3: // retirar livro

                break;


            default:
                printf("\n\n caiu no default\n\n");


        }

    printf("digite a opcao desejada (-1 para sair)\n");
    scanf("%d",&opcao);
    }
    return 0;
}
