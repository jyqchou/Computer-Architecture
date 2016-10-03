#include <stdio.h>
#include <stdlib.h>
#include "third.h"

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
return 0;
}

struct Node* front = NULL;
struct Node* ptr = NULL;
ptr = (struct Node*)malloc(sizeof(struct Node));
struct Node* prev = NULL;
prev = (struct Node*)malloc(sizeof(struct Node));
struct Node* temp = NULL;
char instruc;
int num;

while (fscanf(txt, "%c\t%d\n", &instruc, &num)>=0){
if (instruc != 'i' && instruc != 'd'){
printf("error\n");
return 0;
}

if (temp != NULL){
temp=NULL;
}
temp = (struct Node*)malloc(sizeof(struct Node));


if (instruc == 'i'){

if (front == NULL){
front = (struct Node*)malloc(sizeof(struct Node));
front->value = num;
ptr = front;
continue;
}
else { //regular add

if (num <= front->value){
temp->value = num;
temp->next = front;
front = temp;
ptr = front;
prev = NULL;

continue;
}

while (ptr != NULL && ptr->value <= num){
if (prev == NULL){
prev = ptr;
ptr = (ptr->next);
}
else{
prev = ptr;
ptr=ptr->next;
}
}

if(ptr == NULL){
temp->value = num;
prev->next = temp;
ptr=front;
prev = NULL;
continue;
}
else{
temp->value = num;
temp->next = ptr;
prev->next = temp;
ptr = front; //reset
prev = NULL;
continue;
}
}


}

if (instruc == 'd'){

if (front == NULL){
continue;
}
else if (front->value == num){
if (front->next == NULL){
free(front);
front = NULL;
ptr = NULL;
}
ptr = front->next;
free(front);
front = ptr;
prev=NULL;
continue;
}
else{
prev=front;
ptr=front->next;
while(ptr->value<=num && ptr != NULL){
if(ptr->value == num){
prev->next = ptr->next;
free(ptr);
ptr = front;
prev=NULL;
break;
}
prev = ptr;
ptr=ptr->next;
}
}

}

}

fclose(txt);

if(front == NULL){
}
else{
ptr=front;
while(ptr != NULL){
printf("%d\t",ptr->value);
ptr=ptr->next;
free(front);
front = ptr;
}
}



return 0;

}
