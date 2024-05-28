#include <stdio.h> // biblioeca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h>  // biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{   
    // Inicio da cria��o de vari�veis/string
    char arquivo[100];
    char cpf[100];
    char nome[100];
    char sobrenome[100];
    char cargo[100];
    // Fim da cria��o de vari�veis e string
    
    printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
    scanf("%s", cpf); // %s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores de sting
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // Salva o valor da vari�vel
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");

}

int consultar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

	char cpf[100];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf ("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	    printf("\nEssa sao as informa��es do usu�rio: ");
	    printf("%s", conteudo);
	    printf ("\n\n");
    }
    
    system("pause");
    
    
}

int deletar()
{
    char cpf[100];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sitema!.\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; // Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
{		
	 
	system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	    printf("###Cartorio do Kau�###\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); 
	    printf("\t4 - Sair do sistema\n");
	    printf("Op��o:");// Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha dos coment�rios
	
	    system("cls"); // Respons�vel por limpar a tela
	    
	    switch(opcao) // Inicio da sele�o do menu
	    {
	    	case 1:
	        registro(); // Chamando fun��es
    	    break;
    	
        	case 2:
            consultar();
            break;
        
            case 3:
            deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por usar o sistema!\n");
		    return 0;
		    break;
		
		    default:    
		    printf("Essa op��o n�o est� disponivel!\n");
	        system("pause");
	        break;
	    }
		}
	
    }

