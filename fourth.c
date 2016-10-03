#include <stdio.h>
#include <stdlib.h>
#include "fourth.h"

int main(int arg, char* argv[1]){

if(argv[1]==NULL){
printf("error\n");
return 0;
}

char const* const fileName = argv[1];
FILE* txt;
txt = fopen(fileName,"r");

char instruc;
int num;
int key;

if(!txt){
printf("error\n");
return 0;
}

struct hashtable* hashtab;
hashtab = (struct hashtable*)malloc(sizeof(struct hashtable));

while(fscanf(txt,"%c\t%d\n", &instruc, &num)>=0){

if(instruc != 'i' && instruc != 's'){
printf("error\n");
continue;
}

key = num%1000;

if(instruc == 'i'){

if(hashtab->track[key]==0){
hashtab->track[key]=1;
hashtab->values[key]=num;
printf("inserted\n");
continue;
}

else{
while(hashtab->track[key]==1){
if(hashtab->values[key]==num){
printf("duplicate\n");
break;
}
key=(key+1)%1000;
}
if(hashtab->track==0){
hashtab->track[key]=1;
hashtab->values[key]=num;
printf("inserted\n");
}
}
}

if(instruc == 's'){

if(hashtab->track[key]==0){
printf("absent\n");
continue;
}
else{
while(hashtab->track[key]==1){
if(hashtab->values[key]==num){
printf("present\n");
break;
}
key=(key+1)%1000;
}
if(hashtab->track[key]==0){
printf("absent\n");
continue;
}
}
}



}
fclose(txt);
free(hashtab);

return 0;
}

