struct twitter
{
    char id_pessoa[5];
    char nome_pessoa[40];
    char idade_pessoa[5];
    char twitter_pessoa[15];
};

int read_csv();
void printa_lista(struct twitter lista[], int tamanho);