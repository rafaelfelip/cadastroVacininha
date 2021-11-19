#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char login[8];
    char senha[8];
} pessoa; pessoa p[100];

typedef struct {
        char nome[50];
        char cpf[14];
        char telefone[13];
        char endereco[50];
        char rua[50];
        char numero[8];
        char bairro[50];
        char cidade[50];
        char estado[2];
        char cep[11];
        char dt_nascimento[10];
        char email[50];
        char dt_diagnostico[10];
        char diabetes[1];
        char obesidade[1];
        char hipertensao[1];
        char tuberculose[1];
        char outros[1];
    }

    paciente; paciente pac[100];
    int i = 0;

// variaveis globais
int numero;
//int numero1:


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

/******************* função MENU *********************/
void menu(){

    printf("\t\t\tLogin efetuado com exito. \n\n\n");
    printf("\t\t\tMENU \n\n");
    printf("1 - Consultar agendamento. \n");
    printf("2 - Cadastrar paciente. \n\n");
    printf("Selecione a opção desejada: \n");
    scanf("%d", &numero);
    switch (numero) {
        case 1:
            consulta();
        break;

        case 2:
            cadastro();
        break;
    }

    system("clear");
}

/******************* função CADASTRO *********************/
void cadastro(){



    printf("\t\t\tCADASTRO DE PACIENTE\n\n\n");

    printf("Nome: ");
    getchar();
    gets(pac[i].nome);

    printf("CPF 000.000.000-00): ");
    gets(pac[i].cpf);

    printf("Telefone  00-0000-0000): ");
    gets(pac[i].telefone);

    printf("Endereco Rua: ");
    gets(pac[i].rua);

    printf("Nº Residencial: ");
    gets(pac[i].numero);

    printf("Bairro: ");
    gets(pac[i].bairro);

    printf("Cidade: ");
    gets(pac[i].cidade);

    printf("UF do Estado: ");
    gets(pac[i].estado);

    printf("Digite o CEP 00.000-000: ");
    gets(pac[i].cep);

    printf("Data de Nascimento dd/mm/aaaa: ");
    gets(pac[i].dt_nascimento);

    printf("E-mail: ");
    gets(pac[i].email);

    printf("Data Diagnostico (dd/mm/aaaa): ");
    gets(pac[i].dt_diagnostico);

    printf("Possui diabetes? (S ou N): ");
    gets(pac[i].diabetes);

    printf("Possui obesidade? (S ou N): ");
    gets(pac[i].obesidade);

    printf("Possui hipertensao? (S ou N): ");
    gets(pac[i].hipertensao);

    printf("Possui tuberculose? (S ou N): ");
    gets(pac[i].tuberculose);

    printf("Possui outras comorbidades? (S ou N): ");
    gets(pac[i].outros);

    i++;


    /******************* EXPORTAR ARQUIVO BIN COM OS DADOS *********************/

    int v;
	int len_vet = sizeof(paciente); // tamanho do vetor
	FILE * arq;
    arq = fopen("dados.bin", "ab");

    if(arq != NULL){
	 	int indice = 0;
	 	//while(1){
	 	//	paciente p;
	 	//	size_t r = fread(&p, sizeof(paciente), 1, arq);

	 		// se retorno for menor que o count, então sai do loop
	 	//	if(r < 1)
	 	//		break;
	 	//	else
	 	//		aux_pacientes[indice++] = p;
	// 	}
	 	fclose(arq); // fecha o arquivo
	 	return indice;
	 }else{
	 	printf("\nErro ao abrir o arquivo para leitura!\n");
	 	exit(1); // aborta o programa
	}

    system("clear");
    printf("\t\t\t CADASTRO DE PACIENTE \n\n");
    printf("1 - Voltar Menu Principal. \n");
    printf("2 - Cadastrar Novo paciente. \n");
    printf("3 - Sair. \n\n");
    printf("Selecione a opção desejada: \n");

    scanf("%d", &numero);
    switch (numero) {
        case 1:
            menu();
        break;

        case 2:
            cadastro();
        break;

        case 3:
            system("clear");
            printf("\n\nBYE :).\n\n");
            break;
    }
}

/******************* função AGENDAMENTO *********************/
void agendamento () {
    printf("\t\t\tAGENDAMENTO\n\n\n");
    printf("\nAqui ficará o agendamento!");
}

/******************* função CONSULTA *********************/

void consulta () {
    printf("\t\t\tCONSULTA DE PACIENTES AGENDADOS\n\n\n");
    printf("\nAqui ficará a consulta!");
}
