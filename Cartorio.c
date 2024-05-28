#include <stdio.h> // biblioeca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h>  // biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{   
    // Inicio da criação de variáveis/string
    char arquivo[100];
    char cpf[100];
    char nome[100];
    char sobrenome[100];
    char cargo[100];
    // Fim da criação de variáveis e string
    
    printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
    scanf("%s", cpf); // %s refere-se a string
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores de sting
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // Salva o valor da variável
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
		printf ("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	    printf("\nEssa sao as informações do usuário: ");
	    printf("%s", conteudo);
	    printf ("\n\n");
    }
    
    system("pause");
    
    
}

int deletar()
{
    char cpf[100];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
	{
		printf("O usuário não se encontra no sitema!.\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; // Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
{		
	 
	system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	    printf("###Cartorio do Kauã###\n\n"); //Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); 
	    printf("\t4 - Sair do sistema\n");
	    printf("Opção:");// Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha dos comentários
	
	    system("cls"); // Responsável por limpar a tela
	    
	    switch(opcao) // Inicio da seleão do menu
	    {
	    	case 1:
	        registro(); // Chamando funções
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
		    printf("Essa opção não está disponivel!\n");
	        system("pause");
	        break;
	    }
		}
	
    }

