# andclekevled
Relação dos Bugs não concertados:

1) Vazamento de memória causado pela linha 403 da função leSchema do arquivo dictonary.c.
Linha 403:   tp_table *esquema = (tp_table *)malloc(sizeof(tp_table)*(objeto.qtdCampos+1));
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:insert, arquivo:sqlcommands.c:579  
:finalizaInsert,arquivo:sqlcommands.c:341
:abretabela,arquivo:sqlcommands.c:32
:leSchema,arquivo:dictionary.c:403 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 3,480 bytes.

2) Vazamento de memória causado pela linha 67 da função getPage do arquivo buffer.c.
Linha 67: column *colunas = (column *)malloc(sizeof(column)*objeto.qtdCampos*(buffer[page].nrec));
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:imprime,arquivo:sqlcommands.c:626
:getPage,arquivo:buffer.c:67 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 2,614(2,304 diretos, 310 indiretos)

3) Vazamento da memória causado pela linha 338 da função finalizaInsert do arquivo sqlcommands.c.
Linha 338:  tp_table *tab2 = (tp_table *)malloc(sizeof(struct tp_table));   -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:insert,arquivo:sqlcommands.c:579
:finalizaInsert:sqlcommands.c:338 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 960 bytes

4)Vazamento de memória causado pela linha 212 da função procuraAtributoFK do arquivo dictionary.c.
Linha 212: tp_table *vetEsqm = (tp_table *)malloc(sizeof(tp_table)*objeto.qtdCampos); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:excluirTabela,arquivo:sqlcommands.c:809
:procuraAtributoFK,arquivo:dictionary.c:212 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 720 bytes

5)Vazamento de memória causado pela linha 682 da função insereValor do arquivo dictionary.c.
Linha 682: e = (column *)malloc(sizeof(column)); -*
Funções envolvidas em ordem de chamda pelo programa, com as linhas correspondentes:
:insert,arquivo:sqlcommands.c:542
:insereValor,arquivo:dictionary.c:682 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 602(256 diretos, 346 indiretos)

6)Vazamento de memória causado pela linha 691 da função procuraSchemaArquivo do arquivo sqlcommands.c.
Linha 691: tp_table *esquema = (tp_table *)malloc(sizeof(tp_table)*objeto.qtdCampos); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:excluirTabela,arquivo:sqlcommands.c:872
:procuraSchemaArquivo,arquivo:sqlcommands.c:691 ->onde ocorre o vazamento de memória.
Dados sobre o vazamento: 600 bytes

7)Vazamento de memória causado pela linha 808 da função excluirTabela do arquivo sqlcommands.c.
Linha 808:   tp_table *tab2 = (tp_table *)malloc(sizeof(struct tp_table)); -*
Funções ennvolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:excluirTabela,arquivo:sqlcommands.c:808 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 480 bytes

8)Vazamento de memória causado pela linha 84 da função getPage do arquivo buffer.c.
Linha 84: colunas[h].valorCampo = (char *)malloc(sizeof(char)*campos[j].tam+1); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:insert,arquivo:sqlcommands.c:579
:finalizaInsert,arquivo:sqlcommands.c:367
:verificaChaveFK,arquivo:sqlcommands.c:186
:getPage,arquivo:buffer.c:84 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 420 bytes.

9)Vazamento de memória causado pela linha 842 da função excluirTabela do arquivo sqlcommands.c.
Linha 842:   tp_table *tab3 = (tp_table *)malloc(sizeof(struct tp_table)); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:excluirTabela,arquivo:sqlcommands.c:842 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 360 bytes.

10)Vazamento de memória causado pela linha 533 da função adicionaCampo do arquivo dictonary.c.
Linha 533: e = (tp_table *)malloc(sizeof(tp_table)); -*
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
:createTable,arquivo:sqlcommands.c:953
:adicionaCampo,arquivo:dictonary.c:533 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento: 360(240 diretos,120 indiretos) bytes
