#include <stdio.h>
#include <stdlib.h>
int main(int arg, char* argv[]){

if(argv[1]==NULL){
printf("error\n");
return 0;
}

int num;
num = atoi(argv[1]);

if (num <= 1){
printf("no\n");
return 0;
}

if (num == 2){
printf("yes\n");
return 0;
}

int i;
for (i=2; i<=num/2; i++){

if(num%i==0){
printf("no\n");
return 0;
}
}

printf("yes\n");
return 0;

}
