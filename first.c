#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{

if (argv[1]==NULL){
printf("error\n");
return 0;
}

int num;
num = atoi(argv[1]);

if (num%2 != 0){
printf("odd\n");
}
else if (num%2 == 0){
printf("even\n");
}

return 0;

}
