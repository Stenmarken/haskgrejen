#include <stdio.h>
#include "hask.h"
#include <stdlib.h>

void printHask(Hask * hask) {
    Hask *temp = hask;

    while (temp != NULL) {
        int a = temp->val;
        printf("%d - ", a);
        temp = temp->next;
    }
    printf("\n\n");
}

int main() {
    Hask *hask = hask_new(2);
    printHask(hask);
    hask_push(hask, 3);
    hask_push(hask, 4);
    hask_push(hask, 5);

    printHask(hask);
    printf("%d\n\n", hask_len(hask));
    hask_insert(hask, 1, 0);
    printHask(hask);

    hask_remove(hask, 3);
    hask_clear(hask);
    printHask(hask);

    return 0;
}
Hask * hask_new(int val){
    Hask * hask = malloc(sizeof(Hask));
    hask->val = val;
    hask->next = NULL;
    return hask;
}

int hask_push(Hask * h, int val){
    Hask * hask = malloc(sizeof(Hask));
    hask->val = val;
    hask->next = NULL;

    Hask * temp = h;
    int index = 0;

    while(temp->next != NULL){
        index++;
        temp = temp->next;
    }
    temp->next = hask;
    return index;
}

void hask_insert(Hask * h, int val, int index){
    Hask * newHask = malloc(sizeof(Hask));
    newHask->val = val;
    newHask->next = NULL;

    Hask * temp = h;

    if(index == 0){
        int firstValue = temp->val;
        Hask *next = temp->next;
        temp->next = newHask;
        temp->val = val;
        newHask->next = next;
        newHask->val = firstValue;
    }
    else {
        int i = 0;
        while (i != index - 1) {
            temp = temp->next;
            i++;
        }
        Hask *next = temp->next;
        temp->next = newHask;
        newHask->next = next;
    }
}

/*
 * Vad är det som går fel?
 */
void hask_clear(Hask * h){
   Hask * prev = h;

   while(h){
       h = h->next;
       printf("Raderar %d\n", prev->val);
       free(prev);
       prev = h;
   }
}

/*
 * Vad är det som går fel?
 */
int hask_remove(Hask * h, int index){
    if(index == 0){
        int firstValue = h->val;
        int secondValue = h->next->val;

        h->val = secondValue;
        h->next->val = firstValue;
        index = 1;
    }
    int i = 0;
    Hask *temp = h;
    while (i != index - 1) {
        temp = temp->next;
        i++;
    }
    Hask *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    return 0;
}

int hask_len(Hask * h){
    int i = 0;
    while(h != NULL){
        i++;
        h = h->next;
    }
    return i;
}




