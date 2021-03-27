#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define jg 3

void jogos() /// fun��o para listar todos jogos
{
    FILE *jgs;
    char jogo[30];

    jgs = fopen("jogos.txt", "rt"); /// abri um arquivo de texto onde est� os jogos

    if(jgs != NULL)
    {
        for(int i = 0; i < jg; i++)
        {

            fgets(jogo, 30, jgs);
            puts(jogo);
            setbuf(stdin, NULL);
        }
    }
    else
    {
        printf("\nERRO!\n\n");
    }
    fclose(jgs); ///fecha o arquivo
}
void cadastro (char nome[]) /// fun��o para cadastro
{
    ///setlocale(LC_ALL,"");
    FILE *cadastrar;
    int telefone[11], i;

    cadastrar = fopen("clientes.txt", "a+"); /// abre um novo aarquivo para guardar os nomes dos clientes

    if(cadastrar != NULL)
    {
       fprintf(cadastrar, "%s ", nome);
       for (i = 0; i < 11; i++)
       {
           fprintf(cadastrar, "%d",telefone[i]);
       }
       fprintf(cadastrar, "\n");

        printf("\nCadastrado com sucesso!\n\n");

        system("pause");
        system("cls");

        printf("Acesso concedido!\n\n");
        Menu();
    }
    else
    {
        printf("\n\nERRO!\n\n");
    }
    fclose(cadastrar); /// fecha o arquivo ap�s fazer o que tinha se ser feito

}
void Menu () /// fun��o para menu
{


    int opc;
    do
    {
        printf("MENU\n\n");
        printf("1- Alugar jogos\n");
        printf("\n2- Devolu��o\n");
        printf("\n3- Sair\n");
        scanf("%d",&opc);

        system("cls");

        switch(opc)
        {
        case 1:
            printf("Deseja alugar qual jogo?\n\n");

            jogos();

            system("pause");
            system("cls");
            break;
        case 2:

            break;
        case 3:
            system("pause");

            exit(0);

            break;
        default:
            break;
        }
    }
    while(opc != 3);
}

void usuario () /// fun��o para conferir cadastro
{
    ///setlocale(LC_ALL, "");
    int retorno, flg = 0;
    char cliente[30], listado[30];
    FILE *confere;

    printf("Digite seu nome de usu�rio: "); /// pedindo o nome de usu�rio
    setbuf(stdin, NULL);
    gets(cliente);

    confere = fopen("clientes.txt", "r"); /// Abre arquivo no modo leitura 'r', se fosse 'w' seria para gravar excluindo
                                         /// o  conte�do anterior e 'a' grava e mant�m o conte�do do arquivo

    if(confere == NULL) /// se o arquivo n�o abrir executa o que est� dentro, no caso aqui, se for igual a NULL
    {
       printf("\n\nERRO ao  abrir o arquivo!\n\n ");
       system("pause");
       return 1;
    }

/// procurar pelo usu�rio-----------------------------------------

    while(fscanf(confere, "%s", &listado)!=EOF)
    {
        fflush(stdin);
        if(strcmp(listado,cliente) == 0)
            {
                system("cls");
                printf("Bem vindo(a) de volta, %s! \n\n", listado);
                flg++;
                Menu();
            }
    }
///----------------------------------------------------------------
    fclose(confere); /// fecho o arquivo ap�s as opera��es feitas

     if (flg != 0)
            {
                printf("\n\nUsu�rio n�o encontrado, por favor tente novamente!\n\n");

                system("pause");
                system("cls");

                main();
            }
}

int main() /// fun��o principal
{
    setlocale(LC_ALL, "");

    int jogos_disponiveis , opcao, jogos_alugados = 0, total_jogos = jg;
    char nome[30], cliente[30];

    jogos_disponiveis = total_jogos - jogos_alugados;

    printf("Bem Vindo a locadora de jogos!\n\n");

    /// conferir cadastro -----------------------------------------

    printf("Possui cadastro ? sim (1) ou n�o (2): ");
    scanf("%d", &opcao);

    system("cls");

    if(opcao == 2)
    {
        printf("Vamos fazer um ? \n\nDigite seu nome:");
        setbuf(stdin, NULL);
        gets(nome);

        fflush(stdin);
        cadastro(nome);
    }
    else if(opcao == 1)
    {
        usuario();
    }
///--------------------------------------------------------------

    return 0;
}
