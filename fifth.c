#include <stdio.h>
#include <stdlib.h>

int main(int arg, char* argv[1]){

if(argv[1]==NULL){
printf("error\n");
return 0;
}

char const* const fileName = argv[1];
FILE* txt;
txt = fopen(fileName,"r");

if(!txt){
printf("error\n");
fclose(txt);
return 0;
}

int m,n,p,i;

if(fscanf(txt,"%d\t%d\n", &m, &n) != 2){ 

printf("error\n");
fclose(txt);
return 0;
}

int** a;
a = (int**)malloc(m*sizeof(int*));
for (p=0; p<m; p++){
a[p] = (int*)malloc(n*sizeof(int));
}


int** b;
b = (int**)malloc(m*sizeof(int*));
for (p = 0; p<m; p++){
b[p] = (int*)malloc(n*sizeof(int));
}

int** c;
c = (int**)malloc(m*sizeof(int*));
for (p = 0; p<m; p++){
c[p] = (int*)malloc(n*sizeof(int));
}


int j;
int k;
for(j=0;j<m;j++){
for(k=0;k<n;k++){
fscanf(txt,"%d",&i);
a[j][k] = i;
}

}

for(j=0;j<m;j++){
for(k=0;k<n;k++){
fscanf(txt,"%d",&i);
b[j][k] = i;
}
}

for(j=0;j<m;j++){
for(k=0;k<n;k++){
c[j][k] = a[j][k] + b[j][k];
}
}

for(j=0;j<m;j++){
for(k=0;k<n;k++){
printf("%d\t", c[j][k]);
}
printf("\n");
}

fclose(txt);

for(j=0;i<m;i++){
free(a[j]);
free(b[j]);
free(c[j]);
}
free(a);
free(b);
free(c);

return 0;

}
