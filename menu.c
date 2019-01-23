#include<stdio.h>
void menu(){
     char c, u, continuar;

    do{
        printf("!- Verificar equação\n @-Calculadora\n #-Sair\n");
         scanf(" %s", &c);
        switch(c){
         case '!':
         while(continuar!='s'){
            printf("Modo equação\n");
            printf("u ou v?");
            scanf(" %c", &u);

            if(u=='u'){
                printf("invalido\n\n");
                continuar='s';
            }
            else if(u== 'v'){
                printf("valido");
                printf("Para continuar aperte y");
                scanf(" %c", &continuar);
            
            }
         }
         break;
            
            case '@':
            printf("modo calculadora\n");
           
            break;
            case '#':
            printf("xau\n");
            return 0;            
            break;
        }
       
        
    }while(c!='3');



}



int main(){
menu();
}