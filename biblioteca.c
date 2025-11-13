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
        printf("\nQuantidade dispónivel: %d", l[i].ano);
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
}

typedef struct
{
    int codigoLivro;
    char nomeLeitor[100];
    char data[20]; // dd/mm/aaaa
} Emprestimo;

void Registrar_Emprestimo(Emprestimo *le)
{

    time_t agora;
    struct tm *info;

    printf("\nCódigo do Livro: ");
    scanf("%d", &le->codigoLivro);
    getchar();

    printf("Digite seu nome: ");
    fgets(le->nomeLeitor, 100, stdin);
    le->nomeLeitor[strcspn(le->nomeLeitor, "\n")] = '\0';

    time(&agora);
    info = localtime(&agora);

    strftime(le->data, 20, "%d/%m/%Y %H:%M:%S", info);

    printf("\nEmpréstimo registrado:\n");
    printf("Livro: %d\n", le->codigoLivro);
    printf("Leitor: %s\n", le->nomeLeitor);
    printf("Data/Hora: %s\n", le->data);
}





int main()
{
    int N;
    Limpar_Tela();
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    Livro *l = malloc(N * sizeof(Livro));

    Emprestimo le;

    Cadastrar_Livros(N, l);
    Listar_Livros(N, l);
    Buscar_Livro(N, l);
    Registrar_Emprestimo(&le);
}