#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>   

typedef struct {
    char login[8];
    char senha[8];
} pessoa; pessoa p[100];

// variaveis globais
int numero;

char nome[50];
char cpf[50];
char idade[50];
char sexo[50];
char endereco[50];


/******************* função principal (main) *********************/
int main() {

    login();
    menu();
    cadastro();    

    return 0;
}

// Função login
void login() {

    char login[10];
    char senha[8];

    printf("\t\t\t*************************************\n\n");
    printf("\t\t\t*******BEM VINDO AO VACININHA********\n\n");
    printf("\t\t\t*************************************\n\n");
   

    strcpy(p[0].login, "admin");
    strcpy(p[0].senha, "admin");


    printf("\tLogin: ");
    scanf("%s", login);

    printf("\tSenha: ");
    scanf("%s", senha);


    if (strcmp(login,p[0] .login) == 0 && strcmp(senha,p[0] .senha) == 0)

        printf("\n\nLOGADO!\n\n");

    else

        printf("\n\nDADOS INVALIDOS!\n\n");

    system("clear");
}

//Função menu
void menu(){
    
    printf("\t\t\tLogin efetuado com exito. \n\n\n");
    printf("\t\t\tMENU \n\n");
    printf("1 - Verificar agendamento. \n");
    printf("2 - Cadastrar paciente. \n\n");
    printf("Selecione a opção desejada: \n");
    scanf("%d", &numero);
    switch (numero) {
        case 1:

        break;

        case 2:

        break;
    }

    system("clear");    
}

// função cadastro
void cadastro() {


    printf("\t\t\t*****CADASTRO DE PACIENTE*****\n\n");
    
    printf("\nNome: ");
    scanf("%d", &nome);
    gets(nome);

    printf("\nCPF: ");
    scanf("%d", &cpf);
    gets(cpf);

    printf("\nIdade: ");
    scanf("%d", &idade);
    gets(idade);

    printf("\nSexo: ");
    scanf("%d", &sexo);
    gets(sexo);

    printf("\nEndereço: ");
    scanf("%d", &endereco);
    gets(endereco);
}

// Função consulta


// Função agendamento