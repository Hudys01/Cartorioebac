#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()
{
	//inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo "w" = a escrever
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Defininco a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int desligamento()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario n�o se encotra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Defininco a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar aluno\n"); // Registrar nome
		printf("\t2 - Consultar aluno \n"); // Consultar nome
		printf("\t3 - Desligamento de aluno \n"); // Deletar nome
		printf("\t4 - Sair do sistema \n\n");
		printf("*Esse Softare � de livre uso!* \n\n");
		printf("Op��o:"); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuario
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
				registro(); //chamada de fun��es
			break;
			case 2:
				consulta();
			break;
			case 3:
				desligamento();
			break;
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
			break;
			default:
				printf("Esta op��o n�o esta disponivel!\n");
				system("pause");
			break; //Fim da sele��o	
		}
	}
}
