#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char login[8];
    char senha[8];
} pessoa; pessoa p[100];
// variaveis
int numero;



// PRINCIPAL
int main() {

    login();
    menu();    

    return 0;
}

// Função login
void login() {

    printf("\t\t\t*************************************\n\n");
    printf("\t\t\t*****SEJA BEM VINDO AO VACININHA*****\n\n");
    printf("\t\t\t*************************************\n\n");
    char login[10];
    char senha[8];

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
    
}

// Consulta


// Cadastro