#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

void Cadastrar_Livros(int *N, Livro *l)
{

    for (int i = 0; i < *N; i++)
    {
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

void Listar_Livros(int *N, Livro *l)
{
    for (int i = 0; i < *N; i++)
    {
        printf("Código: %d", l[i].codigo);
        printf("Título: %s", l[i].titulo);
        printf("Autor: %s", l[i].autor);
        printf("Ano de publicação: %d", l[i].ano);
        printf("Quantidade dispónivel: %d", l[i].ano);
    }
}
