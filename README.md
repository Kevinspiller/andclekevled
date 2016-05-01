# andclekevled
Relação dos Bugs não concertados:

1) Vazamento de memória causado pela linha 403 da função leSchema do arquivo dictonary.c.
Linha 403:   tp_table *esquema = (tp_table *)malloc(sizeof(tp_table)*(objeto.qtdCampos+1));
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
->insert, arquivo:sqlcommands.c:579  
->finalizaInsert,arquivo:sqlcommands.c:341
->abretabela,arquivo:sqlcommands.c:32
->leSchema,arquivo:dictionary.c:403 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento:
3,480 bytes in 8 blocks are definitely lost in loss record 50 of 51
----------------------------------------------------------------------------------------------

2) Vazamento de memória causado pela linha 67 da função getPage do arquivo buffer.c.
Linha 67: column *colunas = (column *)malloc(sizeof(column)*objeto.qtdCampos*(buffer[page].nrec));
Funções envolvidas em ordem de chamada pelo programa, com as linhas correspondentes:
->imprime,arquivo:sqlcommands.c:626
->getPage,arquivo:buffer.c:67 -> onde ocorre o vazamento de memória.
Dados sobre o vazamento:
2,614 (2,304 direct, 310 indirect) bytes in 3 blocks are definitely lost in loss record 49 of 51
