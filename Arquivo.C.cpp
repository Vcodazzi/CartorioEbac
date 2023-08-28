#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibliotaca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()
{
	//inicio de cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim de cria��o de variaveis/string 
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s", nome);//salvando variavel 
	
	file = fopen(arquivo, "a");//abrir arquivo existente e "a" significa atualizar arquivo existente.
	fprintf(file,nome);//salvando a variavel no arquivo
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");//defini�ao de linguagem 
	
	//inicio de qual variavel vai ser consultada
	char cpf[40];
	char conteudo[200];
	//fim de consulta da variavel 
	
	printf("Digite o CPF a ser consultado: ");//coletando dados do usu�rio
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//abrindo arquivo e "r" significa ler o arquivo
	
	if(file == NULL)//comando de resposta para arquivos n�o existentes 
	{
		printf("\nN�o localizado!.\n");
    }
    
    while(fgets(conteudo, 200, file) != NULL)//comando de resposta para arquivos existentes
    {
    	printf("\nEssas s�o as informa��es do usu�rio:\n ");
    	printf("%s", conteudo);
    	printf("\n\n");
    }
    
    system("pause");
	
	fclose(file);//fechamento de arquivo
}

int deletar()
{
	char cpf[40];
	//variavel a ser consultada
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��es do usu�rio
	scanf("%s",cpf);
    
	FILE *file;
	file = fopen(cpf,"r");//abrindo e "r" lendo arquivo 
		
	if(file == NULL)//Analise de usu�rio inexistente.
	{
		fclose(file);
		printf("Usu�rio n�o encontrado no sistema!.\n");
	}
	
	else if(file != NULL)//Analise de usu�rio existente.
	{
		fclose(file);
		printf("Usu�rio deletado com sucesso!\n");
		remove(cpf);
	}
	
	system("pause");
}

int main()
{
	int opcao=0;//defini�ao de variaveis 
	int repeticao=1;
	
	for(repeticao=1;repeticao=1;)
	{
		system("cls");
	
	    setlocale(LC_ALL,"portuguese");//defini�ao de linguagem 
	
	    printf("### Cart�rio de Alunos EBAC ###\n\n\n");//inicio do menu
	    printf("escolha a op��o desejada no menu:\n\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n\n\n");
	    printf("escolha de op��o : ");//fim do menu
	
	    scanf("%d", &opcao);//armazenamento a escolha do usuario
	
        system("cls");
	
	    switch(opcao)//inicio da sele�ao	
	    {
	    	case 1:
	    	registro();
		    break;
		    
		    case 2:
			consulta();
		    break;
		    
		    case 3:
			deletar();
		    break;
		    
		    default:
		    printf("essa op��o n�o est� disponivel!\n\n");
		    system("pause");
		    break;
		}//fim da sele�ao
    }
}


