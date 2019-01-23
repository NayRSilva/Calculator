#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


t_elemento* aloca_elemento(char s){
    t_elemento* elemento = (t_elemento*)malloc(sizeof(t_elemento));
    if(elemento!=NULL){
    elemento->simbolo = s;
    }
    return elemento;
    
}

t_pilha* aloca_pilha(){
    t_pilha* pilha = (t_pilha*)malloc(sizeof(t_pilha));
    if(pilha!=NULL) /*caso consiga alocar memoria*/{
        pilha->topo = NULL;
        pilha->quantidade = 0;

        return pilha;
    }
    return pilha;
}

int insere(char s, t_pilha* pilha){

    if (pilha==NULL){
        return 2;
    } else{
        t_elemento* new;
        new = aloca_elemento(s);
        new->abaixo = pilha->topo;
        pilha->topo = new;
        pilha->quantidade ++;
        return 1;
    }

}

char pop(t_pilha* pilha){
    t_elemento* aux;
    char c;
    if(pilha->topo!=NULL){
        aux = pilha->topo;
        pilha->topo = aux->abaixo;
        c = aux->simbolo;
        free(aux);
    }
    else{
        c = 'N';
    }
return c;

}
char look_at_first(t_pilha* pilha){
    
    char c;
    if(pilha->topo!=NULL){
       c = pilha->topo->simbolo;
        }
        return c;


}
void free_p(t_pilha* pilha){
    t_elemento* aux;

    aux = pilha->topo;
    while(aux!=NULL){
        pilha->topo = aux->abaixo;
        free(aux);
        aux = pilha->topo;
    }
    free(pilha);
}

int inicializador(char init){
    if((init == '(')|| (init=='[')||(init=='{')){
        return 1;
    }
    else
    return -1;
}

int finalizador(char fin){
    if((fin == ')')|| (fin=='}')||(fin==']')){
        return 1;
    }
    else{
    return -1;
    }
}

t_pilha* enche_pilha(int tamanho, char *string){
    int i, result;
    t_pilha* pilha;

     pilha = aloca_pilha();
    for(i=0; i<tamanho; i++){
                result = inicializador(string[i]);
                
                if(result==1){
                    insere(string[i], pilha);

                }
            }
return pilha;

}

char tem_finalizador(char* string, int tamanho){
    char tem;
    int fin, i;
    tem = 'n';
        for(i=0; i<tamanho; i++){
        fin = finalizador(string[i]);
             if(fin == 1){
                 tem = 's';
}
        }
        return tem;

}

bool compara_sinal(t_pilha* pilha, char* string, int tamanho){
int i=0;
int result;
char caux;
bool valido;
    for(i=0; i<tamanho; i++){
                
                result= finalizador(string[i]);
               
               
               
                if(result == 1){
                  

                    caux = pop(pilha);

                    if((caux == '{')&&(string[i]=='}')){
                        valido = true;
                        

                    }
                    else if((caux == '[')&&(string[i]==']')){
                        valido = true;
                        
                        
                    }
                    else if((caux == '(')&&(string[i]==')')){
                        valido = true;

                        
                    }
                     else{
                        valido = false;
                        printf("false\n");
                        
                    }
                }
}

return valido;

}

bool pilha_vazia(t_pilha* pilha){
    if (pilha->topo==NULL){
        return true;
    }
    else{
        return false;
    }

}
bool isAbertura(char oi2)
{
    return (((oi2=='(')||(oi2=='['))||(oi2=='{'));
}
bool isFechamento(char oi2)
{
    return (((oi2==')')||(oi2==']'))||(oi2=='}'));
}
bool temMaiorPrioridade(char opAtual,char opEmpilhado)
{
    if (isAbertura(opEmpilhado)) return false;  
    else if(opEmpilhado=='*'||opEmpilhado=='/') return true;
    else if (opAtual=='+'||opAtual=='-') return true;
    return false;   
}

bool operador(char s){
    if((s=='*')||(s=='/')||(s=='+')||(s=='-')){
        return true;
    }
    else{
    return false;
    }   
}

bool verifica_eq(int tamanho, char* strin){
    t_pilha* pilha = enche_pilha(tamanho, strin);
    char temfim;
    bool valido;
            temfim = tem_finalizador(strin,tamanho);       
            /*verifica se tem finalizador*/
            if(temfim=='n'){
               valido = pilha_vazia(pilha);
                free_p(pilha);  
            }
            else{
                valido = compara_sinal(pilha, strin, tamanho);
                free_p(pilha);  
            }

            return valido;

}
bool isNumber(char oi)
{
    return (((oi>='0')&&(oi<='9'))||oi=='.');
}


bool mesmoFechamento(char fec,char aber)
{
    if(aber=='{'&&fec=='}') return true;
    if(aber=='['&&fec==']') return true;
    if(aber=='('&&fec==')') return true;
    return false;
}
char* pos_fixa(int tamanho, char* string, char* saida){
    int i, j;
    t_pilha* pilha;
    char primeiro, aux;
    
    pilha = aloca_pilha();
                
                j=0;
                for(i=0; i<=tamanho; i++){
                
                    if(isNumber(string[i]))
                    {
                        strncpy(&saida[j], &string[i], 1);
                        j++;
                        
                        if(i+1>tamanho) {}
                        else if(!isNumber(string[i+1]))
                        {
                            saida[j]= ' ';
                            j++;
                        }
                    }
                    else if(operador(string[i])){
                        if(pilha_vazia(pilha)){
                            
                            insere(string[i], pilha);
                            
                        }
                        else if(temMaiorPrioridade(string[i],look_at_first(pilha))){
                                                    
                            primeiro = pop(pilha);
                            strncpy(&saida[j], &primeiro, 1);
                            j++;
                            saida[j]= ' ';
                            j++;
                                    while((pilha->topo!=NULL) && (temMaiorPrioridade(string[i],look_at_first(pilha)))){

                                    primeiro = pop(pilha);
                                    strncpy(&saida[j], &primeiro, 1);
                                    j++;
                                    saida[j]= ' ';
                                    j++;
                                        }

                            insere(string[i], pilha);
                        }

                        else
                        {
                            insere(string[i], pilha);
                        }
                    }

                    else if(string[i]=='\0'){
                        while(!(pilha_vazia(pilha))){
                            primeiro = pop(pilha);
                            strncpy(&saida[j], &primeiro, 1);
                            j++;
                            saida[j]=' ';
                            j++;
                        }

                        if(saida[j-1]==' ') saida[j-1]='\0';
                        else saida[j]='\0';
                    }

                    else if(string[i]==' '){}

                    else if(isAbertura(string[i]))
                    {
                        insere(string[i], pilha);
                    }  
                    else if(isFechamento(string[i])){
                        
                        aux = pop(pilha);
                             while(!mesmoFechamento(string[i],aux))
                             {
                                 strncpy(&saida[j], &aux, 1);
                                 j++;
                                 saida[j]=' ';
                                 j++;
                                 aux = pop(pilha);

                                }
                    }                          
                
                 

                }
                saida[j]= '\0';
                // printf("%s\n", saida);
                free_p(pilha);
                return saida;

}

double tofloat(char* c){
   
    int i, quant, frac;
    double dez, num,result, pot;
    dez=1;
    result = 0;
    quant=0;
    frac=0;
    pot= 1;
    
    for(i=(strlen(c)-1); i>=0; i--){
        if(c[i]=='-'){
            pot= (-1);
        }
        if(c[i]=='.'){
            frac= quant;
           
            }
        if(c[i]!='.'&&c[i]!='+'&&c[i]!='-'&&c[i]!='/'&&c[i]!='*'){
         num = c[i];
         num= num - '0';
         num = num * dez;
         dez= dez*10;
         result= result + num;
         quant++;
            }
        }

        result= result * pot;
    if(frac!=0){
       
        
        for(i=1; i<=frac;i++){
            result= result/10;
            }
    }
        
    return result;
}


t_elemento2* aloca_elemento2(double n){
    t_elemento2* elemento2 = (t_elemento2*)malloc(sizeof(t_elemento2));
        if(elemento2!=NULL){
        elemento2->simbolo = n;
            }
    return elemento2;
    
}


t_pilha2* aloca_pilha2(){
    t_pilha2* pilha = (t_pilha2*)malloc(sizeof(t_pilha2));
    if(pilha!=NULL) /*caso consiga alocar memoria*/{
        pilha->topo = NULL;
        pilha->quantidade = 0;

        return pilha;
    }
    return pilha;
}

int insere2(double s, t_pilha2* pilha2){

    if (pilha2==NULL){
        printf("vazio");
        return 2;
        }
    else{
        t_elemento2* new;
        new = aloca_elemento2(s);
        new->abaixo = pilha2->topo;
        pilha2->topo = new;
        pilha2->quantidade ++;
        return 1;
        }

}

char look_at_first_double(t_pilha2* pilha){
    
    double c;
    if(pilha->topo!=NULL){
       c = pilha->topo->simbolo;
        }
        return c;


}

double pop2(t_pilha2* pilha){
    t_elemento2* aux;
    double n;
    if(pilha->topo!=NULL){
        aux = pilha->topo;
        pilha->topo = aux->abaixo;
        n = aux->simbolo;
        pilha->quantidade --;
        free(aux);
    }
    
return n;

}

void free_p2(t_pilha2* pilha){
    t_elemento2* aux;

    aux = pilha->topo;
    while(aux!=NULL){
        pilha->topo = aux->abaixo;
        free(aux);
        aux = pilha->topo;
    }
    free(pilha);
}

void calcula_eq(int tamanho2, char* saida2){
    t_pilha2* pilha2 = aloca_pilha2();
    int i, j, auxInt;
    char num[20];
    double conversor, operador1, operador2, resultado;


    j=0;
    for(i=0; i<=tamanho2; i++){
        if(saida2[i]==' '){

        }
        else if(isNumber(saida2[i]))
        {
            num[j]=saida2[i];
            j++;
            
            auxInt=i+1;
            if(auxInt>tamanho2+1) auxInt=tamanho2+1;

            if(isNumber(saida2[auxInt])){

            }
            else{
                num[j]='\0';
                conversor = tofloat(num);
                insere2(conversor, pilha2);
 
                for(int o=0;o<j;o++)
                {
                    num[o]='\0';
                }
                j=0;
            }
        }
        else if(operador(saida2[i])){
            
            if(pilha2->quantidade>=2){
                operador1 = pop2(pilha2);
                operador2 = pop2(pilha2);
                   
            }

            if(saida2[i]=='+'){

                resultado = operador1 + operador2;
                insere2(resultado, pilha2);
                   
            }
            else if(saida2[i]=='-')
            {
                resultado = operador2 - operador1;
                insere2(resultado, pilha2);
          
            }
            else if(saida2[i]=='*')
            {
                 resultado = operador2 * operador1;
                insere2(resultado, pilha2);
            }
            else if(saida2[i]=='/')
            {
                resultado = operador2 / operador1;
                insere2(resultado, pilha2);
               
            }
            else{
                printf("Quantidade de argumentos insuficiente\n");
            }
        }
                   
    
    }
    
    resultado = pop2(pilha2);
    printf("resultado %lf\n\n", resultado);
    free(pilha2);
    ;
           
}

void show(t_pilha2* pilha){
    t_elemento2* aux;
    aux = pilha->topo;
    
    while(aux!=NULL){
        printf("%lf\n", aux->simbolo);
        aux = aux->abaixo;

    }
}


int so_num(char* string, int tamanho){
int result, i;
    result = 1;

    for(i=0; i<tamanho; i++){
        if(((string[i]>='0')&&(string[i]<='9'))||(string[i]=='.')){

            result = result;
        }
        else{
            result = -1;
        }
    }
return result;
}

double calculadora(char termina){
    char input[500];
    char terminar;
    int j;
    double num, aux1, aux2,aux3, result, repeticao, i, copia;
     int tamanho;
   
    t_pilha2* pilhanum = aloca_pilha2();
terminar = termina;

while((terminar!='y')&&(terminar!='Y')){
    for(j=0;j<500;j++)
        {
            input[j]='\0';
             }   
        if(pilhanum->topo==NULL){
        
            printf("Pilha vazia\n");
            scanf("%s", input);
            tamanho = strlen(input);
            if(tamanho==1){
               if((input[0]=='+')||(input[0]=='-')||(input[0]=='*')||(input[0]=='/')){
                   printf("Sem argumentos suficientes\n");
                    }
                else if ((so_num(input, tamanho))==1){
                            num = tofloat(input);
                            printf("%lf\n", num);
                            insere2(num, pilhanum);
                            printf("pilha:\n");                            
                show(pilhanum);
                    }
                }   
            else if ((so_num(input, tamanho))==1){
                num = tofloat(input);
                 insere2(num, pilhanum);
                 printf("pilha:\n");
                 show(pilhanum);
                    }
            }
        else{
            scanf("%s", input);
            tamanho = strlen(input);
            if(tamanho==1){

                if((input[0]=='+')||(input[0]=='-')||(input[0]=='*')||(input[0]=='/')||(input[0]=='c')){
                    if((pilhanum->quantidade)<=1){
                        printf("Sem argumentos suficientes\n");
                        }
                    else{
                            if(input[0]=='+'){
                                aux1 = pop2(pilhanum);
                                aux2 = pop2(pilhanum);
                                result = aux2 + aux1;
                                insere2(result, pilhanum);
                                }

                            else if(input[0]=='-'){
                                aux1 = pop2(pilhanum);
                                aux2 = pop2(pilhanum);
                                result = aux1 - aux2;

                                insere2(result, pilhanum);
                                }

                            else if(input[0]=='*'){
                                aux1 = pop2(pilhanum);
                                aux2 = pop2(pilhanum);
                                result = aux2 * aux1;

                                insere2(result, pilhanum);
                                }
                            else if(input[0]=='/'){
                                aux1 = pop2(pilhanum);
                                aux2 = pop2(pilhanum);
                                result = aux1 / aux2;

                                insere2(result, pilhanum);
                                }
                            else if(input[0]=='c'){
                                repeticao = pop2(pilhanum);
                                copia = pop2(pilhanum);

                                for(i=0; i<repeticao; i++){
                                    insere2(copia, pilhanum);
                                    }

                                }
                        
                            }
                    
                            printf("Pilha:\n");
                            show(pilhanum);
                            printf("Finalizar operaçao?(y/n)");
                            scanf(" %c", &terminar);
                    
                    }
                else if ((so_num(input, tamanho))==1){
                      
                      num = tofloat(input);
                      
                      insere2(num, pilhanum);
                    }
                }

            else {
                if ((so_num(input, tamanho))==1){
           
                    num = tofloat(input);

                   insere2(num, pilhanum);
        
                }

                else if((input[1])=='!'){

                    if(input[0]=='+'){

                       aux1 = pop2(pilhanum);
                       aux2 = pop2(pilhanum);
                       result = aux1 + aux2;
                           while(pilhanum->topo!=NULL){
                               aux3 = pop2(pilhanum);
                               result= aux3 + result;
                                 }
                               insere2(result, pilhanum);
                        }

                    else if(input[0]=='-'){
                        aux1 = pop2(pilhanum);
                        aux2 = pop2(pilhanum);
                        result = aux1 - aux2;
                            while(pilhanum->topo!=NULL){
                                aux3 = pop2(pilhanum);
                                result= result - aux3;
                                }
                        insere2(result, pilhanum);
                        }

                     else if(input[0]=='*'){
                         aux1 = pop2(pilhanum);
                         aux2 = pop2(pilhanum);
                         result = aux2 * aux1;
                             while(pilhanum->topo!=NULL){
                                 aux3 = pop2(pilhanum);
                                 result= aux3 * result;
                                 }
                         insere2(result, pilhanum);
                      }
                    else if(input[0]=='/'){
                        aux1 = pop2(pilhanum);
                        aux2 = pop2(pilhanum);
                        result = aux1 / aux2;
                            while(pilhanum->topo!=NULL){
                                aux3 = pop2(pilhanum);
                                result= result / aux3;
                                }
                        insere2(result, pilhanum);
                        }
            printf("Pilha:\n");
            show(pilhanum);
            printf("Finalizar operaçao?(y/n)");
            scanf(" %c", &terminar);

                    }
            
                }
       printf("pilha fim:\n");
        show(pilhanum);
            }

    }
printf("fim\n");
free_p2(pilhanum);
return 0;
}

