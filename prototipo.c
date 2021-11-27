#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h> 

//struct de LOGIN
typedef struct {
    char usuario[8];
    char senha[8];
} pessoa; pessoa p[100];

//struct PACIENTE
typedef struct {
        char nome[50];
        char cpf[14]; 
        char telefone[13]; 
        char endereco[50];
        char rua[50];
        char numero[10];
        char bairro[50];
        char cidade[50];
        char estado[2];
        char cep[11];   
        int dia;
        int mes;
        int ano;
        char email[50];
        char dt_diagnostico[10];
        char diabetes[1];
        char obesidade[1];
        char hipertensao[1];
        char tuberculose[1];
        char outros[1];
    }paciente; paciente pac[100];

//ponteiro para arquivos
FILE *pont_pac, *pont_pac_risc;
    
// variaveis
int opcao = 0;
int i = 0;

// PRINCIPAL
int main() {    
    login(); 
    return 0;
}

// login
void login() {
    system("clear"); 
    printf("\t\t\t*************************************\n\n");
    printf("\t\t\t*****SEJA BEM VINDO AO VACININHA*****\n\n");
    printf("\t\t\t*************************************\n\n");
    char usuario[10];
    char senha[8];

    strcpy(p[0].usuario, "admin");
    strcpy(p[0].senha, "admin");

    printf("\tusuario: ");
    scanf("%s", usuario);

    printf("\tSenha: ");
    scanf("%s", senha);
    
    if (strcmp(usuario,p[0].usuario) == 0 && strcmp(senha,p[0].senha) == 0){
        printf("\t\t\tLogin efetuado com exito. \n\n\n");

        // abrindo o arquivo com tipo de abertura A  Escrita. 
        // Os dados serão adicionados no fim do arquivo ("append")
        pont_pac = fopen("pacientes.txt", "a");      
        pont_pac_risc = fopen("pacientes_risco.txt", "a");   

        //testando se o arquivo foi realmente criado
        if(pont_pac == NULL){
            printf("Erro na abertura do arquivo pacientes.txt");
            return 1;
        } 

        //testando se o arquivo foi realmente criado
        if(pont_pac_risc == NULL){
            printf("Erro na abertura do arquivo pacientes_risco.txt");
            return 1;
        } 
        
        menu();  
    }

    else{
        printf("\n\nDADOS INVALIDOS!\n\n");
        login();    
    }
}

//menu
void menu(){   
    system("clear"); 
    printf("\t\t\tMENU \n\n");    
    printf("1 - Listar pacientes \n");
    printf("2 - Cadastrar paciente \n");   
    printf("3 - Sair \n\n");
    printf("Selecione a opção desejada: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            //ler_arquivo(pac);            
        break;

        case 2:
            cadastrar_paciente();            
        break;

        case 3:
            logout();           
        break;
    }    
}

//Cadastro Paciente
void cadastrar_paciente(){   
    system("clear"); 
    printf("\t\t\tCADASTRO_DE_PACIENTE\n\n\n");    
   
    printf("Nome:");                   
    scanf("%s[^\n]",pac[i].nome);        
    fprintf(pont_pac, "%s\t", pac[i].nome);
            
    printf("\nCPF 000.000.000-00):");    
    scanf("%s[^\n]",pac[i].cpf);        
    fprintf(pont_pac, "%s\t", pac[i].cpf);
                 
    printf("\nTelefone  00-0-0000-0000):");     
    scanf("%s[^\n]",pac[i].telefone);    
    fprintf(pont_pac, "%s\t", pac[i].telefone);
         
    printf("\nEndereco Rua:");     
    scanf("%s[^\n]",pac[i].rua);
    fprintf(pont_pac, "%s\t", pac[i].rua);
         
    printf("\nNº Residencial:");     
    scanf("%s[^\n]",pac[i].numero);    
    fprintf(pont_pac, "%s\t", pac[i].numero);
     
    printf("\nBairro:");     
    scanf("%s[^\n]",pac[i].bairro);    
    fprintf(pont_pac, "%s\t", pac[i].bairro);
        
    printf("\nCidade:");     
    scanf("%s[^\n]",pac[i].cidade);
    fprintf(pont_pac, "%s\t", pac[i].cidade);
    
    printf("\nUF do Estado:");                    
    scanf("%s[^\n]",pac[i].estado);
    fprintf(pont_pac, "%s\t", pac[i].estado);
        
    printf("\nDigite o CEP 00.000-000:");         
    scanf("%s[^\n]",pac[i].cep);    
    fprintf(pont_pac, "%s\t", pac[i].cep);

    printf("%s","Por favor informe a data de ""nascimento [dd mm aaaa]:");        
    scanf("%d%d%d", &pac[i].dia, &pac[i].mes, &pac[i].ano);      
    fprintf(pont_pac, "%d%d%d\t", &pac[i].dia, &pac[i].mes, &pac[i].ano);  
         
    printf("\nE-mail: ");    
    scanf("%s[^\n]",pac[i].email);
    fprintf(pont_pac, "%s\t", pac[i].email);
    
    printf("%s","Por favor informe a data de ""Diagnostico [dd mm aaaa]:");        
    scanf("%s[^\n]",pac[i].dt_diagnostico);    
    fprintf(pont_pac, "%s\t", pac[i].dt_diagnostico);
    
    printf("\nPossui diabetes? (S ou N): ");       
    scanf("%s[^\n]",pac[i].diabetes);
    fprintf(pont_pac, "%s\t", pac[i].diabetes);
        
    printf("\nPossui obesidade? (S ou N): ");     
    scanf("%s[^\n]",pac[i].obesidade);
    fprintf(pont_pac, "%s\t", pac[i].obesidade);
    
    printf("\nPossui hipertensao? (S ou N): ");                    
    scanf("%s[^\n]",pac[i].hipertensao);
    fprintf(pont_pac, "%s\t", pac[i].hipertensao);
    
    printf("\nPossui tuberculose? (S ou N): ");     
    scanf("%s[^\n]",pac[i].tuberculose);
    fprintf(pont_pac, "%s\t", pac[i].tuberculose);
    
    printf("\nPossui outras comorbidade? (S ou N): ");      
    scanf("%s[^\n]",pac[i].outros);
    fprintf(pont_pac, "%s\t", pac[i].outros);

    verifica_risco();    
    i++;    

    printf("--->>>> PACIENTE CADASTRADO COM SUCESSO !!!\n\n");  

    printf("1 - Voltar - Menu Principal \n");
    printf("2 - Cadastrar - Novo paciente \n");    
    printf("3 - Sair \n\n");    
    printf("Selecione a opção desejada: ");   

    scanf("%d", &opcao);              
    switch (opcao) {
        case 1:
            menu();           
            break;

        case 2:
            cadastrar_paciente();
            break;

        case 3:
            system("clear");  
            logout();             
            break;
    }
}
 
//CALCULAR IDADE retorna em anos
int calcula_idade(){       
    int idade = 0;     
    time_t data_atual;
    data_atual = time(NULL);
    struct tm tm = *localtime(&data_atual); 
   
    idade =  (365*(tm.tm_year + 1900) + 30* (tm.tm_mon + 1) + tm.tm_mday 
            - 365* pac[i].ano - 30* pac[i].mes -  pac[i].dia) / 365;   
    return idade;
}

//VERIFACA COMORBIDADE retona número de comorbidades 
int verifica_comorbidades(){
    int comorbidades = 0;
    if  (strcmp (pac[i].diabetes,    "S") || strcmp (pac[i].diabetes,    "s") ||  
         strcmp (pac[i].obesidade,   "S") || strcmp (pac[i].obesidade,   "s") || 
         strcmp (pac[i].hipertensao, "S") || strcmp (pac[i].hipertensao, "s") ||
         strcmp (pac[i].tuberculose, "S") || strcmp (pac[i].tuberculose, "s") || 
         strcmp (pac[i].outros,      "S") || strcmp (pac[i].outros,      "s"))
    {
        comorbidades++;         
    }            

    return comorbidades;    
}

//SALVA EM ARQUIVO, VERIFACA GRUPO RISCO E SALVA CEP E IDADE EM ARQUIVO
verifica_risco(){

    if(calcula_idade() > 65 || verifica_comorbidades() > 0){        
        printf("\n\nPertence ao grupo de risco, dados serão gravados em arquivo: pacientes_risco.txt\n\n");
        
        //usando fprintf para armazenar a string no arquivo   
        //salvar em arquivo
        fprintf(pont_pac_risc, "%s\t", pac[i].cep);
        fprintf(pont_pac_risc, "%d", calcula_idade());           
        //fim salva arquivo/////////////////////////////////////////////////
    }else{
        printf("Não Pertence\n");
    }
}

 //FECHA OS ARQUIOVS E FINALIZA O PROGRAMA
void logout(){ 
    fclose(pont_pac_risc);
    fclose(pont_pac);
    printf("\n\nBYE :)\n\n"); 
    exit(0);    
}