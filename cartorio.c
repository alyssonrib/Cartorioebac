#include <stdio.h>	//biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

/////////////////////////////////INICIO DA FUN��O REGISTRAR////////////////////////////////////////////////////

int registro() //fun��o repons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	//inicio da inclusao de dados da string cpf e cria��o de arquivos com a informa��o dessa string
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, o "w" � parar acessar o arquivo e escrever a informa��o
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // o "a" � para acessar o arquivo e alterar a informa��o
	fprintf(file, ", ");
	fclose(file);
	//fim da inclusao de dados da string cpf, depois da virgula
	
	//inicio da inclusao de dados da string nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	//fim da inclusao de dados da string nome, depois da virgula
	
	//inicio da inclusao de dados da string sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	//fim da inclusao de dados da string sobrenome, depois da virgula
	
	//inicio da inclusao de dados da string cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	//fim da inclusao de dados da string cargo
	
	system("pause");
}

/////////////////////////////////FINAL DA FUN��O REGISTRAR////////////////////////////////////////////////////


/////////////////////////////////INICIO DA FUN��O CONSULTAR////////////////////////////////////////////////////

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //fun��o utilizada para variaveis onde ser� preciso linguagens que utilizem acentos, como o portugu�s
	
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //o "r" quer dizer para abrir o arquivo e ler a informa��o
	
	if(file == NULL){
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo,200, file) != NULL){ //a l�gica � que fgets vai abrir o file e enquanto tiver conteudo(for diferente de nulo) ele vai pegar e salvar na variavel conteudo
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

/////////////////////////////////FINAL DA FUN��O CONSULTAR////////////////////////////////////////////////////

/////////////////////////////////INICIO DA FUN��O DELETAR////////////////////////////////////////////////////
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
}

/////////////////////////////////FINAL DA FUN��O DELETAR////////////////////////////////////////////////////

/////////////////////////////////INICIO DA MAIN/MENU////////////////////////////////////////////////////
int main ()
{
	
	int opcao=0; //sempre deve ser definido o valor da variavel para informar o computador que estamos separando um espa�o na memoria para ela
	int laco=1;
		
	for(laco=1;laco=1;) //fun��o for para criar um la�o de repeti��o, a variavel laco recebeu o valor de 1, e informamos no la�o que enquanto o valor for 1, sempre repetir o que esta dentro do codigo
	{

		system("cls"); //comando para limpar a tela quando resetar a repeti��o
	
		setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //printf � a fun��o para mostrar o texto ao usu�rio, o # � apenas visual
		printf("escolha a op��o desejada do menu:\n\n"); // o \n � para quebra de linha
		printf("\t1 - Registrar nomes\n"); // o \t � para espa�amento
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //scanf para scanear o valor que o usuario digita, e o %d serve para armazenar um valor do tipo inteiro, o que o usuario digitar
	
		system("cls"); //comando para informar ao sistema para deletar o que estava no programa, para a tela n�o ficar cheia de coisa depois que o usuario escolheu a op�ao
	
		switch(opcao) //fun��o switch � uma forma mais correta de utilizar o if quando queremos mais de um "se"
		{
			case 1: //o case seria como o if e o : seria o {
			registro(); //chamada de fun��es
			break; //break seria como }
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("\n At� a proxima! \n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
	
	}
}

/////////////////////////////////FINAL DA MAIN/MENU////////////////////////////////////////////////////
