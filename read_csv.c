#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_csv.h"

int read_csv()
{
    FILE* csv = fopen("arquivo.csv", "r");
    struct twitter lista[150];
    char line[150];

    if(csv == NULL)
    {
        printf("Esse arquivo nao existe");
        return 0;
    }


    // pula a primeira linha
    fgets(line, 150, csv);
    // indice da lista de structs
    int i = 0;
    // enquanto o arquivo nao terminar
    while(fgets(line, 150, csv))
    {
        // qual token vai ser passado
        int valor_campo = 0;
        printf("linha %s", line);
        // separa a string em tokens usando a virgula como delimitadora
        char *campo = strtok(line, ",");
        // enquanto houver tokens
        while(campo)
        {
            if(valor_campo == 0)
            {
                strcpy(lista[i].id_pessoa, campo);
            }
            if(valor_campo == 1)
            {
                strcpy(lista[i].nome_pessoa, campo);
            }
            if(valor_campo == 2)
            {
                strcpy(lista[i].idade_pessoa, campo);
            }
            if(valor_campo == 3)
            {
                strcpy(lista[i].twitter_pessoa, campo);
            }
            // vai para o proximo token
            campo = strtok(NULL, ",");
            valor_campo++;
        }
        // vai para o proximo item da lista
        i++;

    }
    //fecha o arquivo
    fclose(csv);
    printa_lista(lista, i);
    
}

void printa_lista(struct twitter lista[], int tamanho)
{
        //printf("aqui\n");
    for(int i=0; i<tamanho; i++)
    {
        printf("Id pessoa %s, Nome %s , Idade %s, Twitter %s\n", lista[i].id_pessoa, lista[i].nome_pessoa,
                                                                lista[i].idade_pessoa, lista[i].twitter_pessoa);
    }
}