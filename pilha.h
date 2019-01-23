#ifndef _PILHA_H_
#define _PILHA_H_
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>


typedef struct elemento{
    char simbolo;
    struct elemento* abaixo;
}t_elemento;

typedef struct elemento2{
    double simbolo;
    struct elemento2* abaixo;
}t_elemento2;

typedef struct{
    t_elemento *topo;
    int quantidade;
}t_pilha;

typedef struct{
    t_elemento2 *topo;
    int quantidade;
}t_pilha2;

void menu();
t_elemento* aloca_elemento(char s);
t_pilha * aloca_pilha();
int insere(char s, t_pilha* pilha);
int inicializador(char init);
char pop(t_pilha* pilha);
void free_p(t_pilha* pilha);
int finalizador(char fin);
t_pilha* enche_pilha(int tamanho, char *string);
char tem_finalizador(char* string, int tamanho);
bool compara_sinal(t_pilha* pilha, char* string, int tamanho);
bool pilha_vazia(t_pilha* pilha);
bool operador(char s);
int compara_operador(char primeiro, char s);
bool verifica_eq(int tamanho, char* strin);
char* pos_fixa(int tamanho, char* string, char* saida);
double tofloat(char c[]);
t_elemento2* aloca_elemento2(double n);
int insere2(double s, t_pilha2* pilha);
t_pilha2* aloca_pilha2();   
void free_p2(t_pilha2* pilha);
double pop2(t_pilha2* pilha);
void calcula_eq(int tamanho2, char* saida2);
double calculadora(char termina);
#endif
