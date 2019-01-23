#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 2

int main() {
     int tamanho,tamanho2, i;
     char c, continuar, string[500];
     char saida[500];
     char* saida2;
     bool valido;
     valido = true;
    
  
    do{
        continuar='n';
        printf("$- Verificar equação\n @-Calculadora\n #-Sair\n");
         scanf(" %s", &c);

        switch(c){

            case'$':
                
                
            printf("Modo equação\n");      
            printf("Para sair do modo equação digite &\n");
            
            printf("Digite uma equação:\n");
                for(i=0;i<500;i++)
                    {
                         string[i]='\0';
                         saida[i]='\0';
                    }      

                scanf(" %[^\n]s", string);

                if(string[0]=='&'){
                    continuar='n';
                }
                
                else{
                    continuar='s';
                }
                
                while(continuar=='s'){

                tamanho = strlen(string);      
                valido = verifica_eq(tamanho, string);
                   if(valido==false){
                       printf("expressão inválida");

                        }

                    else{
                        printf("expressão verdadeira\n");
                        saida2 = pos_fixa(tamanho, string, saida);
                         tamanho2= strlen(saida2);
                         printf(" saida %s \n", saida2);
                         calcula_eq(tamanho2, saida2);

                            }
                        
                        continuar='n';
                    }
            break;

            case '@':
            printf("Modo calculadora\n");

            calculadora('n');
           
            break;

            case '#':
            printf("xau\n");
            return 0;            
            break;
        }
       
        
    }while(c!='3');



}

