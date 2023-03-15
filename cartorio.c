#include <stdio.h>	//biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

/////////////////////////////////INICIO DA FUNÇÃO REGISTRAR////////////////////////////////////////////////////

int registro() //função reponsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	//inicio da inclusao de dados da string cpf e criação de arquivos com a informação dessa string
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, o "w" é parar acessar o arquivo e escrever a informação
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // o "a" é para acessar o arquivo e alterar a informação
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

/////////////////////////////////FINAL DA FUNÇÃO REGISTRAR////////////////////////////////////////////////////


/////////////////////////////////INICIO DA FUNÇÃO CONSULTAR////////////////////////////////////////////////////

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //função utilizada para variaveis onde será preciso linguagens que utilizem acentos, como o português
	
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //o "r" quer dizer para abrir o arquivo e ler a informação
	
	if(file == NULL){
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo,200, file) != NULL){ //a lógica é que fgets vai abrir o file e enquanto tiver conteudo(for diferente de nulo) ele vai pegar e salvar na variavel conteudo
		printf("\nEssas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

/////////////////////////////////FINAL DA FUNÇÃO CONSULTAR////////////////////////////////////////////////////

/////////////////////////////////INICIO DA FUNÇÃO DELETAR////////////////////////////////////////////////////
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
}

/////////////////////////////////FINAL DA FUNÇÃO DELETAR////////////////////////////////////////////////////

/////////////////////////////////INICIO DA MAIN/MENU////////////////////////////////////////////////////
int main ()
{
	
	int opcao=0; //sempre deve ser definido o valor da variavel para informar o computador que estamos separando um espaço na memoria para ela
	int laco=1;
		
	for(laco=1;laco=1;) //função for para criar um laço de repetição, a variavel laco recebeu o valor de 1, e informamos no laço que enquanto o valor for 1, sempre repetir o que esta dentro do codigo
	{

		system("cls"); //comando para limpar a tela quando resetar a repetição
	
		setlocale(LC_ALL, "Portuguese"); //definição de linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //printf é a função para mostrar o texto ao usuário, o # é apenas visual
		printf("escolha a opção desejada do menu:\n\n"); // o \n é para quebra de linha
		printf("\t1 - Registrar nomes\n"); // o \t é para espaçamento
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); //scanf para scanear o valor que o usuario digita, e o %d serve para armazenar um valor do tipo inteiro, o que o usuario digitar
	
		system("cls"); //comando para informar ao sistema para deletar o que estava no programa, para a tela não ficar cheia de coisa depois que o usuario escolheu a opçao
	
		switch(opcao) //função switch é uma forma mais correta de utilizar o if quando queremos mais de um "se"
		{
			case 1: //o case seria como o if e o : seria o {
			registro(); //chamada de funções
			break; //break seria como }
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("\n Até a proxima! \n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		}
	
	}
}

/////////////////////////////////FINAL DA MAIN/MENU////////////////////////////////////////////////////
