//Arquivos - conceitos b·sicos
// Arquivo texto x Bin·rio

// Projeto do estacionamento -> Arquivo bin√°rio

// fopen("arquivo.bin", "rb" ou "wb" ou "ab")
// 		Abre o arquivo no modo bin·rio (leitura, escrita ou acrescentar)
// fread(void *ptr, size_t size, size_t count, FILE *fp)
// 		L√™ blocos bin√°rios do arquivo para a mem√≥ria
// fwrite(const void *ptr, size_t size, size_t count, FILE *fp)
// 		Escreve blocos bin√°rios da mem√≥ria para o arquivo
// fseek(FILE *fp, long offset, int origin)
// 		Move o ponteiro de posis„o no arquivo  --> PROJETO ESTACIONAMENTO
// ftell(FILE *fp)
// 		Retorna a posi√ß√£o atual do ponteiro no arquivo
// rewind(FILE *fp)
// 		Volta o ponteiro para o in√≠cio do arquivo
// fclose(FILE *fp)
// 		Fecha o arquivo

#include <iostream>
#include <string.h>

//Estrutura de dados do veiculo
typedef struct {
    char placa[10];
    int hr_entrada;
    int hr_saida;

}carro;


//FunÁ„o MENU
void menu(){

}

void reset_system(){
	int count_position = 1;
	FILE *arquivo;
	
	carro c;

	arquivo = fopen("Dados.dat","wb");
	
	strcpy(c.placa, "VAZIO");
	c.hr_entrada = 0;
	
	//Verifica se o arquivo pode ser criado
	if(arquivo == NULL){
		printf("Arquivo n„o pode ser criado");
		exit(1);
	}	
	
	printf("Cadastro dos carros:\n");
	while(1) {
		// lendo do arquvivo os dados de um funcion√°rio
		fread (&c, sizeof(carro), 1, arquivo);
		
		if (feof(arquivo)) break; //se for final do arquivo, sair do while atrav√©s do comando break
		printf("\nplaca: %s", c.placa);
		printf("\nhr_entrada: %d \n", c.hr_entrada);
		
		fflush(stdin); // limpando o buffer do teclado
		// gravando os dados do carro no arquivo
		fwrite (&c, sizeof (carro), 1, arquivo);
		count_position++;
		if ()
	}	
	
}

void out_vehicle(){
	fflush(stdin); // limpando o buffer do teclado
	char placa_out[10];
	int count_position = 0;
	
	FILE *arquivo;
	
	carro c;

	arquivo = fopen("Dados.dat","rb+");
	
	//Pergunta qual carro deseja retirar
	printf("\nQual veiculo deseja retirar: ");
	gets(placa_out);
	
	//Verifica se o arquivo pode ser criado
	if(arquivo == NULL){
		printf("Arquivo n„o pode ser criado");
		exit(1);
	}	
	
	printf("Cadastro dos carros:\n");
	while(1) {
		// lendo do arquvivo os dados de um funcion√°rio
		fread (&c, sizeof(carro), 1, arquivo);
		
		if (feof(arquivo)) break; //se for final do arquivo, sair do while atrav√©s do comando break
		printf("\nplaca: %s", c.placa);
		printf("\nhr_entrada: %d \n", c.hr_entrada);
		
		if ( !strcmp (c.placa, placa_out) ) break ;
		count_position++;
	}	
	
	fseek(arquivo, count_position * sizeof(carro), SEEK_SET);  // Vai direto para o x∫ carro (Ìndice 2)
	
	strcpy(c.placa, "VAZIO");
	c.hr_entrada = 0;
	
	fflush(stdin); // limpando o buffer do teclado
	// gravando os dados do carro no arquivo
	fwrite (&c, sizeof (carro), 1, arquivo);
	
	fclose(arquivo);
}

//FunÁ„o escrita no arquivo
void write_file(){
	printf("\n============================================\n");
	fflush(stdin); // limpando o buffer do teclado
	FILE *arquivo;
	int count_position = 0;
	carro c;

	arquivo = fopen("Dados.dat","rb+");
	
	//Verifica se o arquivo pode ser criado
	if(arquivo == NULL){
		printf("Arquivo n„o pode ser criado");
		exit(1);
	}
	
	while(1) {
		// lendo do arquvivo os dados de um funcion√°rio
		fread (&c, sizeof(carro), 1, arquivo);
		
		if (feof(arquivo)) break; //se for final do arquivo, sair do while atrav√©s do comando break
		printf("\nplaca: %s", c.placa);
		printf("\nhr_entrada: %d \n", c.hr_entrada);
		
		if ( !strcmp (c.placa, "VAZIO") ) break ;
		count_position++;
	}
	fseek(arquivo, count_position * sizeof(carro), SEEK_SET);  // Vai direto para o x∫ carro (Ìndice 2)
	
	printf("\n\n## posicao atual %d: ",ftell(arquivo));
	
	printf("\n placa? ");
	gets (c.placa);
		
	printf ("\n hora de entrada: ");
	scanf ("%d", &c.hr_entrada);
		
	fflush(stdin); // limpando o buffer do teclado
	// gravando os dados do carro no arquivo
	fwrite (&c, sizeof (carro), 1, arquivo);
	
	fclose(arquivo);

}//fim write_file

//FunÁ„o leitura no arquivo
void read_file(){
	printf("\n============================================\n");
	fflush(stdin); // limpando o buffer do teclado

	FILE *arquivo;
	
	carro c;

	// abrindo o arquivo bin√°rio para leitura com a op√ß√£o: rb
	if( (arquivo = fopen("Dados.dat", "rb")) == NULL ) {
		printf("Arquivo n√o pode ser criado\n");
	exit(1);
	}
		
	printf("Cadastro dos carros:\n");
	while(1) {
		// lendo do arquvivo os dados de um funcion√°rio
		fread (&c, sizeof(carro), 1, arquivo);
		if (feof(arquivo)) break; //se for final do arquivo, sair do while atrav√©s do comando break
		printf("\nplaca: %s", c.placa);
		printf("\nhr_entrada: %d \n", c.hr_entrada);
	}
	
	fclose(arquivo);
}//fim read_file


main(){
	int opcao;
	
	setlocale(LC_ALL,"portuguese");
	
	while(1){
		//por enquanto o menu provisorio esta aqui
		printf("\nPara incluir veiculo[1]\nPara ler a lista de veiculos[2]\nPara retirar um veiculo[3]\n -> ");
		scanf("%d",&opcao);
		
		if(opcao == 1)
			write_file();
		if(opcao == 2)
			read_file();	
		if(opcao == 3)
			out_vehicle();	
	}
	
}

	// quando for digitado "fim" o comando break encerra o comando while
	//if ( !strcmp (c.placa, "fim") ) break; //strcmp compara as duas strings

	//printf("\n%p", &c.placa);
	//printf("\n%p", &c.hr_entrada);
