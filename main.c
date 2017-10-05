#include "estatico.c"

int main(){
// declaracao de variaveis
    int opcao, erro, opMsg;
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
                inserirAluno_fim(&usuarios, &Aluno, &erro);
                void imprimeAlunos (&usuarios);

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
                inserirLivro_fim(&acervo, &Livro, &erro);


                break;


            default:
                printf("\n\n caiu no default\n\n");


        }

    printf("digite a opcao desejada (-1 para sair)\n");
    scanf("%d",&opcao);
    }

    //MENSAGENS CONTIDAS NA PILHA
    //1-CADASTRO FEITO COM SUCESSO! Aproveite nosso acervo!!!
    //2-Voce foi inserido na fila de espera.
    //3-O livro que solicitou ja está disponível para retirada.
    //4-Livro devolvido na biblioteca! Obrigado!
    //5-Voce foi removido da lista da espera.

   /* switch (opMsg){

        case 1:
            printf("CADASTRO FEITO COM SUCESSO! Aproveite nosso acervo!!!");
            break;

        case 2:
            printf("Voce foi inserido na fila de espera.");
            break;

        case 3:
            printf("O livro que solicitou ja está disponível para retirada.");
            break;

        case 4:
            printf("Livro devolvido na biblioteca! Obrigado!");
            break;

        case 5:
            printf("Voce foi removido da lista da espera.");
            break;
    }

*/

    return 0;
}
