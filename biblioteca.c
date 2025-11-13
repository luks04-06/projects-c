#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

void Limpar_Tela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

typedef struct
{
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidade;
} Livro;

void Cadastrar_Livros(int N, Livro *l)
{

    for (int i = 0; i < N; i++)
    {
        printf("\n");
        printf("Código: ");
        scanf("%d", &l[i].codigo);
        getchar();

        printf("Título: ");
        fgets(l[i].titulo, 100, stdin);
        l[i].titulo[strcspn(l[i].titulo, "\n")] = '\0';

        printf("Autor: ");
        fgets(l[i].autor, 100, stdin);
        l[i].autor[strcspn(l[i].autor, "\n")] = '\0';

        printf("Ano de publicação: ");
        scanf("%d", &l[i].ano);

        printf("Quantidade: ");
        scanf("%d", &l[i].quantidade);
        printf("\n");
    }
}

void Listar_Livros(int N, Livro *l)
{
    for (int i = 0; i < N; i++)
    {
        printf("\nCódigo: %d", l[i].codigo);
        printf("\nTítulo: %s", l[i].titulo);
        printf("\nAutor: %s", l[i].autor);
        printf("\nAno de publicação: %d", l[i].ano);
        printf("\nQuantidade dispónivel: %d", l[i].quantidade);
        printf("\n");
    }
}

void Buscar_Livro(int N, Livro *l)
{
    char encontrado[100];
    int achado = 0;

    getchar();
    printf("\nBuscar livro (título ou autor): ");
    fgets(encontrado, 100, stdin);
    encontrado[strcspn(encontrado, "\n")] = '\0';

    for (int i = 0; i < N; i++)
    {
        if (strcmp(l[i].titulo, encontrado) == 0 || (strcmp(l[i].autor, encontrado)) == 0)
        {

            printf("Titulos encontrados: \n");
            printf("Código: %d\n", l[i].codigo);
            printf("Título: %s\n", l[i].titulo);
            printf("Autor: %s\n", l[i].autor);
            printf("Ano de publicação: %d\n", l[i].ano);
            printf("Quantidade disponível: %d\n", l[i].quantidade);
            achado = 1;
            break;
        }
    }
    if (!achado)
        printf("\nNenhum livro encontrado!\n");
}

typedef struct
{
    int codigoLivro;
    char nomeLeitor[100];
    char data[20]; // dd/mm/aaaa
} Emprestimo;

void Registrar_Emprestimo(Emprestimo *le, Livro *l, int N)
{

    time_t agora;
    struct tm *info;

    printf("\nCódigo do Livro para emprestimo: ");
    scanf("%d", &le->codigoLivro);
    getchar();

    printf("Digite seu nome: ");
    fgets(le->nomeLeitor, 100, stdin);
    le->nomeLeitor[strcspn(le->nomeLeitor, "\n")] = '\0';

    time(&agora);
    info = localtime(&agora);

    strftime(le->data, 20, "%d/%m/%Y %H:%M:%S", info);

    int achou = 0;

    for (int i = 0; i < N; i++)
    {
        if (l[i].codigo == le->codigoLivro)
        {
            achou = 1;
            if (l[i].quantidade > 0)
            {
                l[i].quantidade--;
                printf("\nEmpréstimo registrado!\n");
            }
            else
            {
                printf("\nLivro indisponível para emprestimo.\n");
            }

            printf("Leitor: %s\n", le->nomeLeitor);
            printf("Data/Hora do Emprestimo: %s\n", le->data);
            return;
        }
    }

    if (!achou)
    {
        printf("\nLivro não encontrado!\n");
    }
}

void Devolver_Emprestimo(Emprestimo *le, Livro *l, int N)
{
    int achou = 0;

    printf("\nCódigo do Livro para devolução: ");
    scanf("%d", &le->codigoLivro);
    getchar();

    for (int i = 0; i < N; i++)
    {
        if (l[i].codigo == le->codigoLivro)
        {
            achou = 1;
            l[i].quantidade++;
            printf("\nDevolução realizada\n");
            printf("Livro %d devolvido.\n", le->codigoLivro);
            return;
        }
    }

    if (!achou)
    {
        printf("Livro não encontrado. Não é possível realizar a devolução\n");
    }
}

int main()
{
    int N, opcao;

    printf("Digite quantos livros deseja cadastrar: ");
    scanf("%d", &N);

    Livro *l = malloc(N * sizeof(Livro));
    Emprestimo le;

    Cadastrar_Livros(N, l);

    while (1)
    {
        Limpar_Tela(); 

        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Listar Livros\n");
        printf("2 - Buscar Livro\n");
        printf("3 - Registrar Empréstimo\n");
        printf("4 - Registrar Devolução\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            Listar_Livros(N, l);
            printf("\nPressione ENTER para voltar...");
            getchar();
            getchar();
            break;

        case 2:
            Buscar_Livro(N, l);
            printf("\nPressione ENTER para voltar...");
            getchar();
            getchar();
            break;

        case 3:
            Registrar_Emprestimo(&le, l, N);
            printf("\nPressione ENTER para voltar...");
            getchar();
            getchar();
            break;

        case 4:
            Devolver_Emprestimo(&le, l, N);
            printf("\nPressione ENTER para voltar...");
            getchar();
            getchar();
            break;

        case 5:
            free(l);
            exit(0);
        }
    }
}
