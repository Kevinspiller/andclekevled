#include <stdio.h>
#include <stdlib.h>
#include <string.h>
////
#ifndef FMACROS // garante que macros.h não seja reincluída
   #include "macros.h"
#endif
///
#ifndef FTYPES // garante que types.h não seja reincluída
  #include "types.h"
#endif
////
#ifndef FMISC // garante que misc.h não seja reincluída
  #include "misc.h"
#endif

#ifndef FBUFFER // garante que buffer.h não seja reincluída
  #include "buffer.h"
#endif

#ifndef FDICTIONARY // the same
  #include "dictionary.h"
#endif

/* ----------------------------------------------------------------------------------------------
    Objetivo:   Recebe o nome de uma tabela e engloba as funções leObjeto() e leSchema().
    Parametros: Nome da Tabela, Objeto da Tabela e tabela.
    Retorno:    tp_table
   ---------------------------------------------------------------------------------------------*/
tp_table *abreTabela(char *nomeTabela, struct fs_objects *objeto, tp_table **tabela) {
    *objeto     = leObjeto(nomeTabela);
    *tabela     = leSchema(*objeto);

    return *tabela;
}
// Se foram especificadas colunas no *s_insert, verifica se elas existem no esquema.
int allColumnsExists(rc_insert *s_insert, table *tabela) {
	int i;
	if (!s_insert->columnName) return 0;

	for (i = 0; i < s_insert->N; i++)
		if (retornaTamanhoTipoDoCampo(s_insert->columnName[i], tabela) == 0) {
			printf("ERROR: column \"%s\" of relation \"%s\" does not exist.\n", s_insert->columnName[i], tabela->nome);
			return 0;
		}

	return 1;
}
////
int typesCompatible(char table_type, char insert_type) {
	return (table_type == 'D' && insert_type == 'I')
		|| (table_type == 'D' && insert_type == 'D')
		|| (table_type == 'I' && insert_type == 'I')
		|| (table_type == 'S' && insert_type == 'S')
		|| (table_type == 'S' && insert_type == 'C')
		|| (table_type == 'C' && insert_type == 'C')
		|| (table_type == 'C' && insert_type == 'S');
}
////
// Busca o tipo do valor na inserção *s_insert do valor que irá para *columnName
// Se não existe em *s_insert, assume o tipo do esquema já que não receberá nada.
char getInsertedType(rc_insert *s_insert, char *columnName, table *tabela) {
	int i;
	char noValue;
	for (i = 0; i < s_insert->N; i++) {
		if (objcmp(s_insert->columnName[i], columnName) == 0) {
			return s_insert->type[i];
		}
	}

	noValue = retornaTamanhoTipoDoCampo(columnName, tabela);

	return noValue;
}
// Busca o valor na inserção *s_insert designado à *columnName.
// Se não existe, retorna 0, 0.0 ou \0
char *getInsertedValue(rc_insert *s_insert, char *columnName, table *tabela) {
	int i;
	char tipo, *noValue;

	for (i = 0; i < s_insert->N; i++) {
		if (objcmp(s_insert->columnName[i], columnName) == 0) {
			return s_insert->values[i];
		}
	}

	tipo = retornaTamanhoTipoDoCampo(columnName, tabela);
	noValue = (char *)malloc(sizeof(char)*3);

	if (tipo == 'I') {
		noValue = "0";
	} else if (tipo == 'D') {
		noValue = "0.0";
	} else
		noValue[0] = '\0';

	return noValue;
}
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Inicializa os atributos necessários para a verificação de FK e PK.
    Parametros: Objeto da tabela, Tabela, Buffer e nome da tabela.
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
   ---------------------------------------------------------------------------------------------*/

int iniciaAtributos(struct fs_objects *objeto, tp_table **tabela, tp_buffer **bufferpool, char *nomeT){


    *objeto     = leObjeto(nomeT);
    *tabela     = leSchema(*objeto);
    *bufferpool = initbuffer();

    if(*tabela == ERRO_ABRIR_ESQUEMA) {
        return ERRO_DE_PARAMETRO;
    }

    if(*bufferpool == ERRO_DE_ALOCACAO)
        return ERRO_DE_PARAMETRO;

    return SUCCESS;
}
////
int verifyFK(char *tableName, char *column){
    if(verificaNomeTabela(tableName) == 1){
        struct fs_objects objeto = leObjeto(tableName);
        tp_table *esquema = leSchema(objeto);
		if(esquema == ERRO_ABRIR_ESQUEMA){
            printf("ERROR: cannot create schema.\n");
            return 0;
        }

        for(; esquema != NULL; esquema = esquema->next){
            if(objcmp(esquema->nome, column) == 0){
                if(esquema->chave == PK){
                    return 1;
                }
            }
        }
    }
	return 0;
}

////////
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Gera as verificações em relação a chave FK.
    Parametros: Nome da Tabela, Coluna C, Nome do Campo, Valor do Campo, Tabela Apontada e Atributo Apontado.
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
                ERRO_CHAVE_ESTRANGEIRA
   ---------------------------------------------------------------------------------------------*/

int verificaChaveFK(char *nomeTabela,column *c, char *nomeCampo, char *valorCampo, char *tabelaApt, char *attApt){
    int x,j, erro, page;
    char str[20];
    char dat[5] = ".dat";
    struct fs_objects objeto;
    tp_table *tabela;
    tp_buffer *bufferpoll;
    column *pagina = NULL;

    strcpylower(str, tabelaApt);
    strcat(str, dat);              //Concatena e junta o nome com .dat

    erro = existeAtributo(nomeTabela, c);
    /*if(erro != SUCCESS )
        return ERRO_DE_PARAMETRO;*/

    //if(existeAtributo(tabelaApt, c))
        //return ERRO_CHAVE_ESTRANGEIRA;

    if(iniciaAtributos(&objeto, &tabela, &bufferpoll, tabelaApt) != SUCCESS) {
        free(bufferpoll);
        free(tabela);
        return ERRO_DE_PARAMETRO;
    }


    erro = SUCCESS;
    for(x = 0; erro == SUCCESS; x++)
        erro = colocaTuplaBuffer(bufferpoll, x, tabela, objeto);

    for (page = 0; page < PAGES; page++) {
        if (pagina) free(pagina);
        pagina = getPage(bufferpoll, tabela, objeto, page);
        if (!pagina) break;

        for(j = 0; j < objeto.qtdCampos * bufferpoll[page].nrec; j++){
            if (pagina[j].nomeCampo) {
                if(objcmp(pagina[j].nomeCampo, attApt) == 0){

                    if(pagina[j].tipoCampo == 'S'){
                        if(objcmp(pagina[j].valorCampo, valorCampo) == 0){
                            free(pagina);
                            free(bufferpoll);
                            free(tabela);
                            return SUCCESS;
                        }
                    } else if(pagina[j].tipoCampo == 'I'){
                        int *n = (int *)&pagina[j].valorCampo[0];
                        if(*n == atoi(valorCampo)){
                            free(pagina);
                            free(bufferpoll);
                            free(tabela);
                            return SUCCESS;
                        }
                    } else if(pagina[j].tipoCampo == 'D'){
                        double *nn = (double *)&pagina[j].valorCampo[0];

                        if(*nn == atof(valorCampo)){
                            free(pagina);
                            free(bufferpoll);
                            free(tabela);
                            return SUCCESS;
                        }
                    } else if(pagina[j].tipoCampo == 'C'){
                        if(pagina[j].valorCampo == valorCampo){
                            free(pagina);
                            free(bufferpoll);
                            free(tabela);
                            return SUCCESS;
                        }
                    } else {
                        free(pagina);
                        free(bufferpoll);
                        free(tabela);
                        return ERRO_CHAVE_ESTRANGEIRA;
                    }
                }
            }
        }
    }

    if (pagina) free(pagina);
    free(bufferpoll);
    free(tabela);
    return ERRO_CHAVE_ESTRANGEIRA;
}
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Gera as verificações em relação a chave PK.
    Parametros: Nome da Tabela, Coluna C, Nome do Campo, Valor do Campo
    Retorno:    INT
                SUCCESS,
                ERRO_DE_PARAMETRO,
                ERRO_CHAVE_PRIMARIA
   ---------------------------------------------------------------------------------------------*/

int verificaChavePK(char *nomeTabela, column *c, char *nomeCampo, char *valorCampo) {
    int j, x, erro, page;
    column *pagina = NULL;

    struct fs_objects objeto;
    tp_table *tabela;
    tp_buffer *bufferpoll;

    erro = existeAtributo(nomeTabela, c);
    if (erro != SUCCESS ) {
        free(bufferpoll);
        return ERRO_DE_PARAMETRO;
    }


    if (iniciaAtributos(&objeto, &tabela, &bufferpoll, nomeTabela) != SUCCESS) {
        free(bufferpoll);
        free(tabela);
        return ERRO_DE_PARAMETRO;
    }

    erro = SUCCESS;
    for(x = 0; erro == SUCCESS; x++)
        erro = colocaTuplaBuffer(bufferpoll, x, tabela, objeto);

    page = 0;
    for (page = 0; page < PAGES; page++) {
        if (pagina) free(pagina);
        pagina = getPage(bufferpoll, tabela, objeto, page);
        if (!pagina) break;

        for(j = 0; j < objeto.qtdCampos * bufferpoll[page].nrec; j++){
            if (pagina[j].nomeCampo) {
                if (objcmp(pagina[j].nomeCampo, nomeCampo) == 0) {
                    if (pagina[j].tipoCampo == 'S') {
                        if (objcmp(pagina[j].valorCampo, valorCampo) == 0){
                            free(pagina);
                            free(bufferpoll);
                            free(tabela);
                            return ERRO_CHAVE_PRIMARIA;
                        }
                    } else if (pagina[j].tipoCampo == 'I') {
                        int *n = (int *)&pagina[j].valorCampo[0];

                        if (*n == atoi(valorCampo)) {
                            free(pagina);
                            free(bufferpoll);
                            free(tabela);
                            return ERRO_CHAVE_PRIMARIA;
                        }
                    } else if (pagina[j].tipoCampo == 'D'){
                        double *nn = (double *)&pagina[j].valorCampo[0];

                        if (*nn == atof(valorCampo)){
                            free(pagina);
                            free(bufferpoll);
                            free(tabela);
                            return ERRO_CHAVE_PRIMARIA;
                        }
                    } else if (pagina[j].tipoCampo == 'C'){
                        if (pagina[j].valorCampo == valorCampo){
                            free(pagina);
                            free(bufferpoll);
                            free(tabela);
                            return ERRO_CHAVE_PRIMARIA;
                        }
                    }
                }
            }
        }
    }

    if (pagina) free(pagina);
    free(bufferpoll);
    free(tabela);
    return SUCCESS;
}

/////
int finalizaInsert(char *nome, column *c){
    column *auxC, *temp;
    int i = 0, x = 0, t, erro, j = 0;
    FILE *dados;

    struct fs_objects objeto,dicio; // Le dicionario
    tp_table *auxT ; // Le esquema
    auxT = abreTabela(nome, &dicio, &auxT);

    table *tab     = (table *)malloc(sizeof(table));
    tp_table *tab2 = (tp_table *)malloc(sizeof(struct tp_table));
    memset(tab2, 0, sizeof(tp_table));

    tab->esquema = abreTabela(nome, &objeto, &tab->esquema);
    tab2 = procuraAtributoFK(objeto);

    for(j = 0, temp = c; j < objeto.qtdCampos && temp != NULL; j++, temp = temp->next){
        switch(tab2[j].chave){
            case NPK:
                erro = SUCCESS;
                break;

            case PK:
                erro = verificaChavePK(nome, temp , temp->nomeCampo, temp->valorCampo);
                if (erro == ERRO_CHAVE_PRIMARIA){
                    printf("ERROR: duplicate key value violates unique constraint \"%s_pkey\"\nDETAIL:  Key (%s)=(%s) already exists.\n", nome, temp->nomeCampo, temp->valorCampo);

					free(auxT); // Libera a memoria da estrutura.
					//free(temp); // Libera a memoria da estrutura.
					free(tab); // Libera a memoria da estrutura.
					free(tab2); // Libera a memoria da estrutura.
                    return ERRO_CHAVE_PRIMARIA;
                }

                break;

            case FK:
                if (tab2[j].chave == 2 && strlen(tab2[j].attApt) != 0 && strlen(tab2[j].tabelaApt) != 0){

                    erro = verificaChaveFK(nome, temp, tab2[j].nome, temp->valorCampo, tab2[j].tabelaApt, tab2[j].attApt);

                    if (erro != SUCCESS){
                        printf("ERROR: invalid reference to \"%s.%s\". The value \"%s\" does not exist.\n", tab2[j].tabelaApt,tab2[j].attApt,temp->valorCampo);

						free(auxT); // Libera a memoria da estrutura.
						free(temp); // Libera a memoria da estrutura.
                        free(tab); // Libera a memoria da estrutura.
						free(tab2); // Libera a memoria da estrutura.
                        return ERRO_CHAVE_ESTRANGEIRA;
                    }
                }

                break;
        }
    }


    if (erro == ERRO_CHAVE_ESTRANGEIRA){
        printf("ERROR: unknown foreign key error.\n");

		free(auxT); // Libera a memoria da estrutura.
		free(temp); // Libera a memoria da estrutura.
        free(tab); // Libera a memoria da estrutura.
		free(tab2); // Libera a memoria da estrutura.
        return ERRO_CHAVE_ESTRANGEIRA;
    }

    if (erro == ERRO_CHAVE_PRIMARIA){
        printf("ERROR: unknown primary key error.\n");

		free(auxT); // Libera a memoria da estrutura.
		free(temp); // Libera a memoria da estrutura.
        free(tab); // Libera a memoria da estrutura.
		free(tab2); // Libera a memoria da estrutura.
        return ERRO_CHAVE_PRIMARIA;
    }
    if (erro == ERRO_DE_PARAMETRO) {
        printf("ERROR: invalid parameter.\n");
		free(auxT); // Libera a memoria da estrutura.
		free(temp); // Libera a memoria da estrutura.
        free(tab); // Libera a memoria da estrutura.
		free(tab2); // Libera a memoria da estrutura.
        return ERRO_DE_PARAMETRO;
    }

    char directory[LEN_DB_NAME*2];
    strcpy(directory, connected.db_directory);
    strcat(directory, dicio.nArquivo);

    if((dados = fopen(directory,"a+b")) == NULL){
        printf("ERROR: cannot open file.\n");
		free(auxT); // Libera a memoria da estrutura.
		free(temp); // Libera a memoria da estrutura.
        free(tab); // Libera a memoria da estrutura.
		free(tab2); // Libera a memoria da estrutura.
        return ERRO_ABRIR_ARQUIVO;

	}

    for(auxC = c, t = 0; auxC != NULL; auxC = auxC->next, t++){
        if (t >= dicio.qtdCampos)
            t = 0;

        if (auxT[t].tipo == 'S'){ // Grava um dado do tipo string.

            if (sizeof(auxC->valorCampo) > auxT[t].tam && sizeof(auxC->valorCampo) != 8){
                printf("ERROR: invalid string length.\n");
				free(tab); // Libera a memoria da estrutura.
				free(tab2); // Libera a memoria da estrutura.
				free(auxT); // Libera a memoria da estrutura.
				free(temp); // Libera a memoria da estrutura.
				fclose(dados);
                return ERRO_NO_TAMANHO_STRING;
            }

            if (objcmp(auxC->nomeCampo, auxT[t].nome) != 0){
                printf("ERROR: column name \"%s\" is not valid.\n", auxC->nomeCampo);
				free(tab); // Libera a memoria da estrutura.
				free(tab2); // Libera a memoria da estrutura.
				free(auxT); // Libera a memoria da estrutura.
				free(temp); // Libera a memoria da estrutura.
				fclose(dados);
                return ERRO_NOME_CAMPO;
            }

            char valorCampo[auxT[t].tam];
            strncpy(valorCampo, auxC->valorCampo, auxT[t].tam);
            strcat(valorCampo, "\0");
            fwrite(&valorCampo,sizeof(valorCampo),1,dados);

        } else if (auxT[t].tipo == 'I'){ // Grava um dado do tipo inteiro.
            i = 0;
            while (i < strlen(auxC->valorCampo)){
                if (auxC->valorCampo[i] < 48 || auxC->valorCampo[i] > 57){
                    printf("ERROR: column \"%s\" expectet integer.\n", auxC->nomeCampo);
					free(tab); // Libera a memoria da estrutura.
					free(tab2); // Libera a memoria da estrutura.
					free(auxT); // Libera a memoria da estrutura.
					//free(temp); // Libera a memoria da estrutura.
					fclose(dados);
                    return ERRO_NO_TIPO_INTEIRO;
                }
                i++;
            }

            int valorInteiro = 0;

            sscanf(auxC->valorCampo,"%d",&valorInteiro);
            fwrite(&valorInteiro,sizeof(valorInteiro),1,dados);

        } else if (auxT[t].tipo == 'D'){ // Grava um dado do tipo double.
            x = 0;
            while (x < strlen(auxC->valorCampo)){
                if((auxC->valorCampo[x] < 48 || auxC->valorCampo[x] > 57) && (auxC->valorCampo[x] != 46)){
                    printf("ERROR: column \"%s\" expect double.\n", auxC->nomeCampo);
					free(tab); // Libera a memoria da estrutura.
					free(tab2); // Libera a memoria da estrutura.
					free(auxT); // Libera a memoria da estrutura.
					free(temp); // Libera a memoria da estrutura.
					fclose(dados);
                    return ERRO_NO_TIPO_DOUBLE;
                }
                x++;
            }

            double valorDouble = convertD(auxC->valorCampo);
            fwrite(&valorDouble,sizeof(valorDouble),1,dados);
        }
        else if (auxT[t].tipo == 'C'){ // Grava um dado do tipo char.

            if (strlen(auxC->valorCampo) > (sizeof(char))) {
                printf("ERROR: column \"%s\" expect char.\n", auxC->nomeCampo);
				free(tab); // Libera a memoria da estrutura.
				free(tab2); // Libera a memoria da estrutura.
				free(auxT); // Libera a memoria da estrutura.
				free(temp); // Libera a memoria da estrutura.
				fclose(dados);
                return ERRO_NO_TIPO_CHAR;
            }
            char valorChar = auxC->valorCampo[0];
            fwrite(&valorChar,sizeof(valorChar),1,dados);
        }

    }

    fclose(dados);
    free(tab); // Libera a memoria da estrutura.
	free(tab2); // Libera a memoria da estrutura.
    free(auxT); // Libera a memoria da estrutura.
    free(temp); // Libera a memoria da estrutura.
    return SUCCESS;
}

/* insert: Recebe uma estrutura rc_insert e valida os tokens encontrados pela interface().
 *         Se os valores forem válidos, insere um novo valor.
 */
void insert(rc_insert *s_insert) {
	int i;
	table *tabela = (table *)malloc(sizeof(table));
	tabela->esquema = NULL;
	memset(tabela, 0, sizeof(table));
	column *colunas = NULL;
	tp_table *esquema = NULL;
	struct fs_objects objeto;
	memset(&objeto, 0, sizeof(struct fs_objects));
	char  flag=0;

	abreTabela(s_insert->objName, &objeto, &tabela->esquema); //retorna o esquema para a insere valor
	strcpylower(tabela->nome, s_insert->objName);

	if(s_insert->columnName != NULL) {
		if (allColumnsExists(s_insert, tabela)) {
			for (esquema = tabela->esquema; esquema != NULL; esquema = esquema->next) {
				if(typesCompatible(esquema->tipo,getInsertedType(s_insert, esquema->nome, tabela))) {
					colunas = insereValor(tabela, colunas, esquema->nome, getInsertedValue(s_insert, esquema->nome, tabela));
				} else {
					printf("ERROR: data type invalid to column '%s' of relation '%s' (expected: %c, received: %c).\n", esquema->nome, tabela->nome, esquema->tipo, getInsertedType(s_insert, esquema->nome, tabela));
					flag=1;
				}
			}
		} else {
			flag = 1;
		}
	} else {
		if (s_insert->N == objeto.qtdCampos) {
			for(i=0; i < objeto.qtdCampos; i++) {

				if(s_insert->type[i] == 'S' && tabela->esquema[i].tipo == 'C') {
          printf( "\nWARNING: Attempted to write value of type \'string\' to attribute of type \'char\'.\n" );
          printf( "String \'%s\' will be truncated to \'%c\'\n", s_insert->values[i], s_insert->values[i][0] );
					s_insert->values[i][1] = '\0';
					s_insert->type[i] = 'C';
				}

				if(s_insert->type[i] == 'I' && tabela->esquema[i].tipo == 'D') {

					s_insert->type[i] = 'D';
				}

				if(s_insert->type[i] == tabela->esquema[i].tipo)
					colunas = insereValor(tabela, colunas, tabela->esquema[i].nome, s_insert->values[i]);
				else {
					printf("ERROR: data type invalid to column '%s' of relation '%s' (expected: %c, received: %c).\n", tabela->esquema[i].nome, tabela->nome, tabela->esquema[i].tipo, s_insert->type[i]);
					flag=1;
				}
			}
		} else {
			printf("ERROR: INSERT has more expressions than target columns.\n");
			flag = 1;
		}
	}

	if (!flag)
		if (finalizaInsert(s_insert->objName, colunas) == SUCCESS)
			printf("INSERT 0 1\n");

	free(esquema);
	freeColumn(colunas);
	freeTable(tabela);
}
/*---------------------------------------------------------------------------------------------------------------------------
	ver_equal: recebe o tipo das variaveis para o qual deve ser convertido, a variavel presente na coluna da tabela do banco
			   e a que o usuario digitou, faz a conversão e após a comparação de igualdade entre as duas, 
			   retornando TRUE se forem iguais ou FALSE se forem diferentes. 
----------------------------------------------------------------------------------------------------------------------------*/
bool ver_equal(char type, char *value_left, char *value_right){
    int int_Left, int_Right;
    double double_Left, double_Right;

    switch(type){
        case 'D':
            double_Left = atof(value_left);
            double_Right = atof(value_right); 
            return double_Left == double_Right;
        case 'I':
            int_Left = atoi(value_left);
            int_Right = atoi(value_right); 
            return int_Left == int_Right;
        case 'S':
            return strcmp(value_left,value_right) == 0;
    }
    return FALSE;
}
/*-------------------------------------------------------------------------------------------------------------------------
	ver_less: recebe o tipo das variaveis para o qual deve ser convertido, a variavel presente na coluna da tabela do banco
			   e a que o usuario digitou, faz a conversão e após a comparação se o valor da variavel presente
			   no na coluna do banco é menor do que o valor da variavel que o usuario digitou, 
			   retornando TRUE se for menor ou FALSE se não for. 
--------------------------------------------------------------------------------------------------------------------------*/
bool ver_less(char type, char *value_left, char *value_right){
    int int_Left, int_Right;
    double double_Left, double_Right;

    switch(type){
        case 'D':
            double_Left = atof(value_left);
            double_Right = atof(value_right); 
            return double_Left < double_Right;
        case 'I':
            int_Left = atoi(value_left);
            int_Right = atoi(value_right); 
            return int_Left < int_Right;
        case 'S': 
            return strcmp(value_left,value_right) < 0;
    }
    return FALSE;
}
/*----------------------------------------------------------------------------------------------------------------------------
	ver_greater: recebe o tipo das variaveis para o qual deve ser convertido, a variavel presente na coluna da tabela do banco
			   e a que o usuario digitou, faz a conversão e após a comparação se o valor da variavel presente
			   no na coluna do banco é maior do que o valor da variavel que o usuario digitou, 
			   retornando TRUE se for maior ou FALSE se não for. 
-----------------------------------------------------------------------------------------------------------------------------*/
bool ver_greater(char type, char *value_left, char *value_right){
    int int_Left, int_Right;
    double double_Left, double_Right;

    switch(type){
        case 'D':
            double_Left = atof(value_left);
            double_Right = atof(value_right); 
            return double_Left > double_Right;
        case 'I':
            int_Left = atoi(value_left);
            int_Right = atoi(value_right); 
            return int_Left > int_Right;
        case 'S': 
            return strcmp(value_left,value_right) > 0;
    }
    return FALSE;
}
/* -----------------------------------------------------------------------------------------------------------------
	comparerValues: recebe o tipo das variaveis para o qual deve ser convertido, o valor presente na coluna do banco,
					o valor que o usuario digitou e a operação que deve ser feita.
-------------------------------------------------------------------------------------------------------------------*/
bool comparerValues(char type, char *value_left, char *value_right, operation op){
    switch(op){
        case EQ:
            return ver_equal(type, value_left, value_right);
        case LT:
            return ver_less(type, value_left, value_right);
        case GT:
            return ver_greater(type, value_left, value_right);
        case NQ:
            return !ver_equal(type, value_left, value_right); // diferente
        case LTQ:
            return ver_equal(type, value_left, value_right) || ver_less(type, value_left, value_right); // menor ou igual
        case GTQ:
            return ver_equal(type, value_left, value_right) || ver_greater(type, value_left, value_right); // maior ou igual
    }
    return FALSE;
}
/* -----------------------------------------------------------------------------------------------------------------
	getStrValue: converte os bytes lidos do disco de acordo com o tipo passado para o tipo texto.
				 pq ele le do disco como ponteiro de char independente do tipo que foi gravado por
				 isso é necessario fazer a conversão do valor para depois fazer as operações.
				 O retorno é uma string.
-------------------------------------------------------------------------------------------------------------------*/
char ** getStrValue(char * source, char type){
    char **result;
    double *d;
    int *n;
    result = (char**) malloc(sizeof(char**));
    *result = (char*) malloc(100);
    switch(type){
        case 'D':
            d = (double *)&source[0];
            sprintf(*result,"%.8f", *d);
            break;
        case 'I':
            n = (int *)&source[0];
            sprintf(*result,"%d", *n);
            break;
        case 'S':
            strcpy(*result, source);
            break;
    }
    return result;
}
/* -----------------------------------------------------------------------------------------------------------------
	se tiver uma condição tipo a or c and b ele faz na ordem da esquerda para direita sem considerar
	a precedencia de operador e não primeiro o and e dps o or.
-------------------------------------------------------------------------------------------------------------------*/
bool where_check(rc_select *GLOBAL_SELECT, column *pagina, int start, int nr_campos){
    rc_where *aux;
    bool result = TRUE;
    int j;
    char *val_left = NULL, *val_right = NULL;
    char type;

    for(aux = GLOBAL_SELECT->where; aux != NULL; aux = aux->next){ // laço percorrendo todos as condições da lista do where
        if(!result && aux->left_logic == logic_AND) // se o resultado atual é FALSE e o comparador atual for AND não precisa fazer a comparação pois o resultado é falso										
            continue;								 

        if(result && aux->left_logic == logic_OR)// se o resultado atual é TRUE e o comparador atual for OR não precisa fazer a comparação pois o resultado é TRUE
            continue;							 

        if(aux->comp->left.type == 'C' || aux->comp->right.type == 'C'){ // se o o usuario digitou um valor tipo C (coluna) então busca o valor da coluna na pagina
            for(j = 0; j < nr_campos; j++){ // percore as tuplas da tabela 
	            if(aux->comp->left.type == 'C'){
	                if(strcmp(aux->comp->left.value, pagina[j+start].nomeCampo) == 0){ // compara o nome na tupla com o nome que o usuario digitou no where
                        if(pagina[j+start].tipoCampo == 'C') // se o valor da tupla for do tipo char
                            type = 'S'; 				// converte para tipo S para ficar compativel com a estrutura criada
	                    else
	                        type = pagina[j+start].tipoCampo; 

                        val_left = *getStrValue(pagina[j+start].valorCampo, type); // chama função para converte o valor lido na tupla para string
	                }
                }
	            if(aux->comp->right.type == 'C'){
	                if(strcmp(aux->comp->right.value, pagina[j+start].nomeCampo) == 0){
	                   if(pagina[j+start].tipoCampo == 'C')
	                        type = 'S';
	                    else
	                        type = pagina[j+start].tipoCampo;
	                    
	                    val_right = *getStrValue(pagina[j+start].valorCampo, type);
	                }
	            }
            }
        }

        //if(aux->comp->right.type == 'C')
        //	type_left = type_right;

        /* comparaçoes para pegar o valor que o usuario digitou sem que seja uma coluna */
        if(aux->comp->left.type != 'C'){    // se o valor que o usurario digitou não for uma coluna então apenas copia o valor          
            val_left = malloc(sizeof(char)*(strlen(aux->comp->left.value) + 1)); // + 1 por causa do \0 no final da string
            strcpy(val_left, aux->comp->left.value);
            val_left += '\0';
        }
        if(aux->comp->right.type != 'C'){ // se o valor que o usurario digitou não for uma coluna então apenas copia o que o valor      
            val_right = malloc(sizeof(char)*(strlen(aux->comp->right.value) + 1));
            strcpy(val_right, aux->comp->right.value);
            val_right += '\0';
        }
        if(val_left == NULL || val_right == NULL){ // para saber se a coluna existe na tabela 
            printf("Error object not found\n");
            return FALSE;
        }

        if(aux->left_logic == logic_OR) // se for OR ele entra nesse if
            result = result || comparerValues(type, val_left, val_right, aux->comp->op);
        else // se for AND ou NONE (NONE = primeira comparação) ele faz essa comparação. O result ja vem como TRUE inicialmente e AND so funciona se for dois TRUE
            result = result && comparerValues(type, val_left, val_right, aux->comp->op);
    }
    return result;
}

void imprime(rc_select *GLOBAL_SELECT) {
    int j,erro, x, p, cont=0;
    struct fs_objects objeto;

    if(!verificaNomeTabela(GLOBAL_SELECT->objName)){
        printf("\nERROR: relation \"%s\" was not found.\n\n\n", GLOBAL_SELECT->objName);
        return;
    }
	
    objeto = leObjeto(GLOBAL_SELECT->objName);

    tp_table *esquema = leSchema(objeto);

    if(esquema == ERRO_ABRIR_ESQUEMA){
        printf("ERROR: schema cannot be created.\n");
        free(esquema);
        return;
    }

    tp_buffer *bufferpoll = initbuffer();

    if(bufferpoll == ERRO_DE_ALOCACAO){
        free(bufferpoll);
        free(esquema);
        printf("ERROR: no memory available to allocate buffer.\n");
        return;
    }

    erro = SUCCESS;
    for(x = 0; erro == SUCCESS; x++)
        erro = colocaTuplaBuffer(bufferpoll, x, esquema, objeto);


    int ntuples = --x;
	p = 0;
	while (x) {

		column *pagina = getPage(bufferpoll, esquema, objeto, p);
		if (pagina == ERRO_PARAMETRO) {
			printf("ERROR: could not open the table.\n");
			free(bufferpoll);
			free(esquema);
			return;
		}

		if (!cont) {
            int checkRun;
			for (j = 0; j < objeto.qtdCampos; j++) {
                if(GLOBAL_SELECT->nColumn > 0) {
                    for(checkRun = 0; checkRun < GLOBAL_SELECT->nColumn;checkRun++) {
                        if(strcmp(GLOBAL_SELECT->columnName[checkRun],pagina[j].nomeCampo)==0) {
                          	if (pagina[j].tipoCampo == 'S')
                            printf(" %-20s ", pagina[j].nomeCampo);
                          	else
                            printf(" %-10s ", pagina[j].nomeCampo);
                            if (j < objeto.qtdCampos - 1)
                                printf("|");
                        }
                    }
                }else{
                    if (pagina[j].tipoCampo == 'S')
                        printf(" %-20s ", pagina[j].nomeCampo);
                    else
                        printf(" %-10s ", pagina[j].nomeCampo);
                    if (j < objeto.qtdCampos - 1)
                        printf("|");
                }
				
			}
			printf("\n");
            if(GLOBAL_SELECT->nColumn > 0) {
                for (j = 0; j < GLOBAL_SELECT->nColumn; j++) {
                printf("%s", (pagina[j].tipoCampo == 'S') ? "----------------------" : "------------");
                if (j < GLOBAL_SELECT->nColumn - 1)
                    printf("+");
                }
            }else{
                for (j = 0; j < objeto.qtdCampos; j++) {
                printf("%s", (pagina[j].tipoCampo == 'S') ? "----------------------" : "------------");
                if (j < objeto.qtdCampos - 1)
                    printf("+");
                }    
            }
			
			printf("\n");
		}
		cont++;
        
        int checkRunTwo,state;
        for (j = 0; j < objeto.qtdCampos * bufferpoll[p].nrec; j++) {
            state = 0;
            if((j % objeto.qtdCampos)==0)
                if (!where_check(GLOBAL_SELECT, pagina, j, objeto.qtdCampos)){ 
                    ntuples--; 
                    j += objeto.qtdCampos - 1;
                    continue;
                }  
            for(checkRunTwo = 0; checkRunTwo < GLOBAL_SELECT->nColumn;checkRunTwo++) {
                    if(strcmp(GLOBAL_SELECT->columnName[checkRunTwo],pagina[j].nomeCampo)==0) {
                        state = 1;
                    }
            }    
                if(GLOBAL_SELECT->nColumn > 0) {
                    if(state == 1) {
                                
                            if (pagina[j].tipoCampo == 'S')
                                printf(" %-20s |", pagina[j].valorCampo);
                            else if (pagina[j].tipoCampo == 'I') {
                                int *n = (int *)&pagina[j].valorCampo[0];
                                printf(" %-10d |", *n);
                            }
                            else if (pagina[j].tipoCampo == 'C') {
                                printf(" %-10c |", pagina[j].valorCampo[0]);
                            }
                            else if (pagina[j].tipoCampo == 'D') {
                                double *n = (double *)&pagina[j].valorCampo[0];
                                printf(" %-10f |", *n);
                            }            
                    }
                }else{
                            if (pagina[j].tipoCampo == 'S')
                                printf(" %-20s |", pagina[j].valorCampo);
                            else if (pagina[j].tipoCampo == 'I') {
                                int *n = (int *)&pagina[j].valorCampo[0];
                                printf(" %-10d |", *n);
                            }
                            else if (pagina[j].tipoCampo == 'C') {
                                printf(" %-10c |", pagina[j].valorCampo[0]);
                            }
                            else if (pagina[j].tipoCampo == 'D') {
                                double *n = (double *)&pagina[j].valorCampo[0];
                                printf(" %-10f |", *n);
                            }             
                }
                if (j >= 1 && ((j + 1) % objeto.qtdCampos) == 0)
                                printf("\n");
                              
        }
        x-=bufferpoll[p++].nrec;
    }
    printf("\n(%d %s)\n\n",ntuples,(1>=ntuples)?"row": "rows");

    free(bufferpoll);
    free(esquema);
}
/* ----------------------------------------------------------------------------------------------
    Objetivo:   Copia todas as informações menos a tabela do objeto, que será removida.
    Parametros: Objeto que será removido do schema.
    Retorno:    INT
                SUCCESS,
                ERRO_REMOVER_ARQUIVO_SCHEMA
   ---------------------------------------------------------------------------------------------*/

int procuraSchemaArquivo(struct fs_objects objeto){

    FILE *schema, *newSchema;
    int cod = 0;
    char *tupla = (char *)malloc(sizeof(char) * 109);
    memset(tupla, '\0', 109);

    tp_table *esquema = (tp_table *)malloc(sizeof(tp_table)*objeto.qtdCampos);
    memset(esquema, 0, sizeof(tp_table)*objeto.qtdCampos);

    char directory[LEN_DB_NAME*2];
    memset(&directory, '\0', LEN_DB_NAME*2);

    strcpy(directory, connected.db_directory);
    strcat(directory, "fs_schema.dat");

    if((schema = fopen(directory, "a+b")) == NULL) {
        free(tupla);
        return ERRO_REMOVER_ARQUIVO_SCHEMA;
    }

    strcpy(directory, connected.db_directory);
    strcat(directory, "fs_nschema.dat");

    if((newSchema = fopen(directory, "a+b")) == NULL) {
        free(tupla);
        return ERRO_REMOVER_ARQUIVO_SCHEMA;
    }

    fseek(newSchema, 0, SEEK_SET);

    while((fgetc (schema) != EOF)){ // Varre o arquivo ate encontrar todos os campos com o codigo da tabela.
        fseek(schema, -1, 1);
        fseek(newSchema, 0, SEEK_END);

        if(fread(&cod, sizeof(int), 1, schema)){ // Le o codigo da tabela.
            if(cod != objeto.cod){
                fwrite(&cod, sizeof(int), 1, newSchema);

                fread(tupla, sizeof(char), TAMANHO_NOME_CAMPO, schema);
                strcpylower(esquema[0].nome,tupla);                  // Copia dados do campo para o esquema.
                fwrite(tupla, sizeof(char), TAMANHO_NOME_CAMPO, newSchema);

                fread(&esquema[0].tipo , sizeof(char), 1 , schema);
                fread(&esquema[0].tam  , sizeof(int) , 1 , schema);
                fread(&esquema[0].chave, sizeof(int) , 1 , schema);

                fwrite(&esquema[0].tipo , sizeof(char), 1, newSchema);
                fwrite(&esquema[0].tam  , sizeof(int) , 1, newSchema);
                fwrite(&esquema[0].chave, sizeof(int) , 1, newSchema);

                fread(tupla, sizeof(char), TAMANHO_NOME_TABELA, schema);
                strcpylower(esquema[0].tabelaApt,tupla);
                fwrite(&esquema[0].tabelaApt, sizeof(char), TAMANHO_NOME_TABELA, newSchema);

                fread(tupla, sizeof(char), TAMANHO_NOME_CAMPO, schema);
                strcpylower(esquema[0].attApt,tupla);
                fwrite(&esquema[0].attApt, sizeof(char), TAMANHO_NOME_CAMPO, newSchema);

            } else {
                fseek(schema, 109, 1);
            }
        }
    }

    fclose(newSchema);
    fclose(schema);

    char directoryex[LEN_DB_NAME*4];
    memset(&directoryex, '\0', LEN_DB_NAME*4);
    strcpy(directoryex, connected.db_directory);
    strcat(directoryex, "fs_schema.dat");

    remove(directoryex);

    strcpy(directoryex, "mv ");
    strcat(directoryex, connected.db_directory);
    strcat(directoryex, "fs_nschema.dat ");
    strcat(directoryex, connected.db_directory);
    strcat(directoryex, "fs_schema.dat");

    system(directoryex);

    free(tupla);
    return SUCCESS;
}

/* ----------------------------------------------------------------------------------------------
    Objetivo:   Função para exclusão de tabelas.
    Parametros: Nome da tabela (char).
    Retorno:    INT
                SUCCESS,
                ERRO_REMOVER_ARQUIVO_OBJECT,
                ERRO_REMOVER_ARQUIVO_SCHEMA,
                ERRO_LEITURA_DADOS.
   ---------------------------------------------------------------------------------------------*/

int excluirTabela(char *nomeTabela) {
    struct fs_objects objeto, objeto1;
    tp_table *esquema, *esquema1;
    int x,erro, i, j, k, l, qtTable;
    char str[20];
    char dat[5] = ".dat";
    memset(str, '\0', 20);

    if (!verificaNomeTabela(nomeTabela)) {
        printf("ERROR: table \"%s\" does not exist.\n", nomeTabela);
        return ERRO_NOME_TABELA;
    }

    strcpylower(str, nomeTabela);
    strcat(str, dat);              //Concatena e junta o nome com .dat

    abreTabela(nomeTabela, &objeto, &esquema);
    qtTable = quantidadeTabelas();

    char **tupla = (char **)malloc(sizeof(char **)*qtTable);
    memset(tupla, 0, qtTable);

    for (i=0; i < qtTable; i++) {
        tupla[i] = (char *)malloc(sizeof(char)*TAMANHO_NOME_TABELA);
        memset(tupla[i], '\0', TAMANHO_NOME_TABELA);
    }

    tp_table *tab2 = (tp_table *)malloc(sizeof(struct tp_table));
    tab2 = procuraAtributoFK(objeto);   //retorna o tipo de chave que e cada campo

    FILE *dicionario;

    char directory[LEN_DB_NAME*2];
    memset(directory, '\0', LEN_DB_NAME*2);

    strcpy(directory, connected.db_directory);
    strcat(directory, "fs_object.dat");

    if((dicionario = fopen(directory,"a+b")) == NULL)
        return ERRO_ABRIR_ARQUIVO;

    k=0;
    while(fgetc (dicionario) != EOF){
        fseek(dicionario, -1, 1);

        //coloca o nome de todas as tabelas em tupla
        fread(tupla[k], sizeof(char), TAMANHO_NOME_TABELA , dicionario);
        k++;

        fseek(dicionario, 28, 1);
    }

    fclose(dicionario);

    for(i = 0; i < objeto.qtdCampos; i++){
        if(tab2[i].chave == PK){
            for(j=0; j<qtTable; j++) {                      //se tiver chave primaria verifica se ela e chave
                if(objcmp(tupla[j], nomeTabela) != 0) {     //estrangeira em outra tabela

                    abreTabela(tupla[j], &objeto1, &esquema1);

                    tp_table *tab3 = (tp_table *)malloc(sizeof(struct tp_table));
                    tab3 = procuraAtributoFK(objeto1);

                    for(l=0; l<objeto1.qtdCampos; l++) {
                        if(tab3[l].chave == FK) { //verifica se a outra tabela possui chave estrangeira. se sim, verifica se e da tabela anterior.
                            if(objcmp(nomeTabela, tab3[l].tabelaApt) == 0) {
                                printf("ERROR: cannot drop table \"%s\" because other objects depend on it.\n", nomeTabela);
                                return ERRO_CHAVE_ESTRANGEIRA;
                            }
                        }
                    }
                    free(tab3);
                }
            }
        }
    }

    free(tab2);

    tp_buffer *bufferpoll = initbuffer();

    if(bufferpoll == ERRO_DE_ALOCACAO){
        printf("ERROR: no memory available to allocate buffer.\n");
        return ERRO_LEITURA_DADOS;
    }

    erro = SUCCESS;
    for(x = 0; erro == SUCCESS; x++)
        erro = colocaTuplaBuffer(bufferpoll, x, esquema, objeto);

    if(procuraSchemaArquivo(objeto) != 0) {
        free(bufferpoll);
        return ERRO_REMOVER_ARQUIVO_SCHEMA;
    }

    if(procuraObjectArquivo(nomeTabela) != 0) {
        free(bufferpoll);
        return ERRO_REMOVER_ARQUIVO_OBJECT;
    }

   	strcpy(directory, connected.db_directory);
    strcat(directory, str);

    remove(directory);

    free(bufferpoll);

    printf("DROP TABLE\n");

    return SUCCESS;
}

/////
int verifyFieldName(char **fieldName, int N){
    int i, j;
    if(N<=1) return 1;
    for(i=0; i < N; i++){
        for(j=i+1; j < N; j++){
            if(objcmp(fieldName[i], fieldName[j]) == 0){
                printf("ERROR: column \"%s\" specified more than once\n", fieldName[i]);
                return 0;
            }
        }
    }
    return 1;
}

//////
void createTable(rc_insert *t) {
	int size;
    strcpylower(t->objName, t->objName);        //muda pra minúsculo
    char *tableName = (char*) malloc (sizeof(char)*TAMANHO_NOME_TABELA),
        fkTable[TAMANHO_NOME_TABELA], fkColumn[TAMANHO_NOME_CAMPO];

    strncpylower(tableName, t->objName, TAMANHO_NOME_TABELA);

    strcat(tableName, ".dat\0");                  //tableName.dat

    if(existeArquivo(tableName)){
        printf("ERROR: table already exist\n");
        free(tableName);
        return;
    }

    table *tab = NULL;
    tab = iniciaTabela(t->objName);    //cria a tabela

    if(0 == verifyFieldName(t->columnName, t->N)){
        free(tableName);
        freeTable(tab);
        return;
    }
    int i;
    for(i=0; i < t->N; i++){
    	if (t->type[i] == 'S')
    		size = atoi(t->values[i]);
    	else if (t->type[i] == 'I')
    		size = sizeof(int);
    	else if (t->type[i] == 'D')
    		size = sizeof(double);
        else if (t->type[i] == 'C')
    		size = sizeof(char);

    	if (t->attribute[i] == FK) {
    		strncpylower(fkTable, t->fkTable[i], TAMANHO_NOME_TABELA);
    		strncpylower(fkColumn,t->fkColumn[i], TAMANHO_NOME_CAMPO);
    	} else {
    		strcpy(fkTable, "");
    		strcpy(fkColumn, "");
    	}

        tab = adicionaCampo(tab, t->columnName[i], t->type[i], size, t->attribute[i], fkTable, fkColumn);
        if((objcmp(fkTable, "") != 0) || (objcmp(fkColumn, "") != 0)){
            if(verifyFK(fkTable, fkColumn) == 0){
    			printf("ERROR: attribute FK cannot be referenced\n");
                free(tableName);
                freeTable(tab);
                return;
    		}
        }
    }

    printf("%s\n",(finalizaTabela(tab) == SUCCESS)? "CREATE TABLE" : "ERROR: table already exist\n");
    free(tableName);
    if (tab != NULL) freeTable(tab);
}
///////
