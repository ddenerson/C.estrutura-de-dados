#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


struct cadastro
{
    int num;
    struct cadastro*prox;
    struct cadastro*prim;
};

struct cadastro*inserirFim(struct cadastro bloco, struct cadastro*inicio);
struct cadastro*inserirIni(struct cadastro *bloco,struct cadastro prim);
void maior(struct cadastro *inicio);
void menor(struct cadastro *inicio);
void imprimir(struct cadastro *inicio);


#endif // HEADER_H_INCLUDED
