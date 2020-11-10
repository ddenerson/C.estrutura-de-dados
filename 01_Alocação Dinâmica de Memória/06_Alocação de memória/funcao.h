#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

struct info
{
    char nome[40];
    int idade;
    char sexo;
    struct info *prox;
};

struct info*cadastrar(struct info bloco, struct info*inicio);

void mostrar(struct info*inicio);

void maior_idade(struct info*inicio);


#endif // FUNCAO_H_INCLUDED
