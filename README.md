UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - UFFS
Campus: Chapecó - SC
Curso: Ciência da Computação
Componente Curricular: Banco de dados II
Professor: Dr. Denio Duarte
Acadêmicos: André Luiz Hofer (1411100009), Cleiton A. Ambrosini (1411100039), Kevin M. Spiller (1211100049) e Marcelo Acordi (1411100007)
Projeto: UFFSDB
Link GitHub: https://github.com/Kevinspiller/andclekevledmar

******** Final Project ********
Considerações importantes:

- Para fazer a condição de diferença entre dois operandos na clausula where usa-se apenas '!='

- As funções e structs criadas e/ou modificadas contem comentários antes do inicio das mesmas explicando como
elas funcionam e o que elas fazem.

******** Finding and fixing bugs ********

  O arquivo log-erros.txt, é o report gerado pelo Valgrind, quanto aos vazamentos de memória.

1) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 403 da função leSchema do arquivo dictonary.c.
Linha 403:   tp_table *esquema = (tp_table *)malloc(sizeof(tp_table)*(objeto.qtdCampos+1));
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:insert, arquivo:sqlcommands.c:579
:finalizaInsert,arquivo:sqlcommands.c:341
:abretabela,arquivo:sqlcommands.c:32
:leSchema,arquivo:dictionary.c:403 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 3,480 bytes.

2) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 67 da função getPage do arquivo buffer.c.
Linha 67: column *colunas = (column *)malloc(sizeof(column)*objeto.qtdCampos*(buffer[page].nrec));
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
<<<<<<< Updated upstream
:imprime,arquivo:sqlcommands.c:626
:getPage,arquivo:buffer.c:67 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 2,614(2,304 diretos, 310 indiretos)

3) (NÃO CORRIGIDO) Vazamento da memória causado pela linha 338 da função finalizaInsert do arquivo sqlcommands.c.
Linha 338:  tp_table *tab2 = (tp_table *)malloc(sizeof(struct tp_table));   -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:insert,arquivo:sqlcommands.c:579
:finalizaInsert:sqlcommands.c:338 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 960 bytes

4) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 212 da função procuraAtributoFK do arquivo dictionary.c.
Linha 212: tp_table *vetEsqm = (tp_table *)malloc(sizeof(tp_table)*objeto.qtdCampos); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:excluirTabela,arquivo:sqlcommands.c:809
:procuraAtributoFK,arquivo:dictionary.c:212 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 720 bytes

5) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 682 da função insereValor do arquivo dictionary.c.
Linha 682: e = (column *)malloc(sizeof(column)); -*
Funções envolvidas em ordem de chamda pelo programa, com as linhas correspondentes:
:insert,arquivo:sqlcommands.c:542
:insereValor,arquivo:dictionary.c:682 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 602(256 diretos, 346 indiretos)

6) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 691 da função procuraSchemaArquivo do arquivo sqlcommands.c.
Linha 691: tp_table *esquema = (tp_table *)malloc(sizeof(tp_table)*objeto.qtdCampos); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:excluirTabela,arquivo:sqlcommands.c:872
:procuraSchemaArquivo,arquivo:sqlcommands.c:691 ->onde ocorre o vazamento de memória.
Dados sobre o vazamento: 600 bytes

7) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 808 da função excluirTabela do arquivo sqlcommands.c.
Linha 808:   tp_table *tab2 = (tp_table *)malloc(sizeof(struct tp_table)); -*
Funções ennvolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:excluirTabela,arquivo:sqlcommands.c:808 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 480 bytes

8) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 84 da função getPage do arquivo buffer.c.
Linha 84: colunas[h].valorCampo = (char *)malloc(sizeof(char)*campos[j].tam+1); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:insert,arquivo:sqlcommands.c:579
:finalizaInsert,arquivo:sqlcommands.c:367
:verificaChaveFK,arquivo:sqlcommands.c:186
:getPage,arquivo:buffer.c:84 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 420 bytes.

9) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 842 da função excluirTabela do arquivo sqlcommands.c.
Linha 842:   tp_table *tab3 = (tp_table *)malloc(sizeof(struct tp_table)); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:excluirTabela,arquivo:sqlcommands.c:842 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 360 bytes.

10) (NÃO CORRIGIDO) Vazamento de memória causado pela linha 533 da função adicionaCampo do arquivo dictonary.c.
Linha 533: e = (tp_table *)malloc(sizeof(tp_table)); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:createTable,arquivo:sqlcommands.c:953
:adicionaCampo,arquivo:dictonary.c:533 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 360(240 diretos,120 indiretos) bytes

=======

-----------------------------------------------------------------------------------------------
11) (NÃO CORRIGIDO) Apos feito a conexão com o banco, se digitar ;;;; (ou seja varias vezes) retorna: uffsdb=# uffsdb=# uffsdb=# uffsdb=#. No prompt imprime o nome do banco de acordo com a quantidade de ; for digitado.

--------------------------------------------------------------------------------------------------------------------------------------------

12) (NÃO CORRIGIDO) Nomes gigantes para criação de banco, tabela e atributo dão erro de corrupção de memoria. Segue abaixo exemplos de criação deles:

create database efgefgefgefgefgefgefgefgefgefgefgefgefgefgefgefgefg;

create table abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc(
name varchar(20));

create table teste(
nomelongodemaisextensogiganteeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee integer));

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

13) (NÃO CORRIGIDO) Nome do banco aparece varias vezes no prompt, provavelmente este erro acontece varios \n foram identificado apos cada linha, no caso a seguir, foi identificado 2.
Linhas de comando testadas:

create table pessoa(
cpf varchar(15) primary key,
nome varchar(40));

Resultado:
uffsdb=# create table pessoa(
cpf varchar(15) primary key,
nome varchar(40));uffsdb(# uffsdb(#

------------------------------------------------------------------------

14) (NÃO CORRIGIDO) Tipo integer aceita numero negativo ao inserir na tupla porém transforma o numero em positivo. Exemplo:
insert into funcionario values('Joao',-23);
-INSERT 0 1

 select * from funcionario;
 nome                 | idade      
----------------------+------------
 Joao                 | 23  

------------------------------------------------------------------
15) (NÃO CORRIGIDO) Problema na utilização das setas para voltar código digitado usando a seta up e até mesmo para andar sobre os caracteres da linha usando as setas left e right.

--------------------------------------------------------------------
16) (CORRIGIDO) Não mostra mensagem ao inserir string em char, por exemplo:

create table testachar( idade integer primary key, sexo char );
insert into testachar values (20,'chapeco');

o resultado após dar um select seria:

idade       | sexo      
------------+------------
 20         | C   

 para a correção foi incluido as seguintes linhas no arquivo sqlcommands.c:

556:	printf( "\nWARNING: Attempted to write value of type \'string\' to attribute of type \'char\'.\n" );
557:	printf( "String \'%s\' will be truncated to \'%c\'\n", s_insert->values[i], s_insert->values[i][0] );
