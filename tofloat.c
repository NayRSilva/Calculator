#include<stdio.h>
#include<string.h>

double tofloat(char c[]){
   
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
int main(){
char c[40];
double a;

scanf("%s", c);


a= tofloat(c);
printf("%lf", a);
return 0;

}