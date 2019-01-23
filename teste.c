#include<stdio.h>

int main(){

    char *c;

    scanf("%s", c);
}

bool operador(char string){
    if((string=='*')||(string=='/')||(string=='+')||(string=='-')){
        return true;
    }
    else return false;

}