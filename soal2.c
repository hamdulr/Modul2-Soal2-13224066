/*
Nama    : Hamzah Abdul Rahim
NIM     : 13224066
Modul   : 2 Dynamic Structures
Tanggal : 11 November 2026
Soal    : Soal 2
Deskripsi: mencari elemen yang elemen sebelum dan sesudahnya lebih besar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int height;
    struct Node *next;
} Node;

void putFront(Node **head, int h ){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->height = h;
    newNode->next = *head;
    *head = newNode;
}

int isEmpty(Node *head){
    return head == NULL;
}

int power(int base, int exp){
    int res = 1;
    for(int i = 1;i<=exp;i++){
        res*=base;
    }
    return res;
}

void printList(Node *head){
    Node *cur = head;
    while(cur!=NULL){
        printf("%d ", cur->height);
        cur = cur->next;
    }
    printf("\n");
}

int charToInt(char c){
    if(c == '1'){
        return 1;
    }
    if(c == '2'){
        return 2;
    }
    if(c == '3'){
        return 3;
    }
    if(c == '4'){
        return 4;
    }
    if(c == '5'){
        return 5;
    }
    if(c == '6'){
        return 6;
    }
    if(c == '7'){
        return 7;
    }
    if(c == '8'){
        return 8;
    }
    if(c == '9'){
        return 9;
    }
    if(c == '0'){
        return 0;
    }
    else{
        return 0;
    }
}

int strToNum(char *str){
    int len = strlen(str);
    int truelen = 0;
    for(int i = 0;i<len;i++){
        if(str[i] != 'X'){
            truelen++;
        }
        else{
            break;
        }
    }
    int res = 0;
    int base = 1;
    for(int i = 0; i<truelen;i++){
        res+= charToInt(str[truelen-i-1])*base;
        base*=10;
    }
    //res = res%(power(10,len-1));
    return res;
}

void turnToList(Node **head, char *string, int *els){
    char num[6];
    int elems = 0;
    strcpy(num, "XXXXX");
    int len = strlen(string);
    int curidx = 0;
    for(int i = 0;i<len+1;i++){
        if(string[i] == ' ' || i == len){
            curidx = 0;
            //printf("%s\n", num);
            int nums;
            nums = strToNum(num);
            //printf("%d\n", nums);
            putFront(head, nums);
            strcpy(num, "XXXXX");
            elems++;
        }
        else{
            num[curidx] = string[i];
            curidx++;
        }
    }
    *els = elems;
}

void checkSun(Node *head, int els){
    int iter = 0;
    int jum = 0;
    int prev1, prev2;
    Node * cur = head;
    Node * places = NULL;
    for(int i = 0;i<els;i++){
        int heig;
        heig = cur->height;
        if(i == 0){
            prev2 = heig;
        }
        else if(i == 1){
            prev1 = heig;
        }
        else{
            if(heig>prev1 && prev1<prev2){
                putFront(&places, els-i+1);
                jum++;
            }
            prev2 = prev1;
            prev1 = heig;
        }
        cur = cur->next;
    }
    if(jum>0){
        printList(places);
    }
    else{
        printf("NONE");
    }
}


int main(){
    Node * head = NULL;
    char str[100];
    int elements;
    scanf("%[^\n]%*c", str);
    //printf("%s, %d", str, strlen(str));

    turnToList(&head, str, &elements);
    //printList(head);
    //printf("%d\n", elements);

    checkSun(head, elements);




    

}
