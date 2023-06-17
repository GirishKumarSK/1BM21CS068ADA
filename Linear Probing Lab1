#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct {
    int key;
    int value;
} HashEntry;

HashEntry* hashTable[SIZE];

int hashCode(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    HashEntry* item = (HashEntry*) malloc(sizeof(HashEntry));
    item->key = key;
    item->value = value;

    int hashIndex = hashCode(key);

    while (hashTable[hashIndex] != NULL) {
        hashIndex++;
        hashIndex %= SIZE;
    }

    hashTable[hashIndex] = item;
}

void display() {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL)
            printf("(%d, %d)", hashTable[i]->key, hashTable[i]->value);
        else
            printf("~~");
        printf("\n");
    }
}

int search(int key) {
    int hashIndex = hashCode(key);

    while (hashTable[hashIndex] != NULL) {
        if (hashTable[hashIndex]->key == key)
            return hashTable[hashIndex]->value;

        hashIndex++;
        hashIndex %= SIZE;
    }

    return -1;
}

int main() {
   int keys[20],values[20];
   int size,c;
   printf("enter no of elements");
   scanf("%d",&size);
   for(int i=0;i<size;i++){
    printf("enter the key of %d element",i+1);
    scanf("%d",&keys[i]);
    printf("enter the value of %d element",i+1);
    scanf("%d",&values[i]);
   }


    for (int i = 0; i < size; i++)
        insert(keys[i], values[i]);
while(1){
    printf("enter 1 to display and 2 to search");
    scanf("%d",&c);
    if(c==1){
    printf("Hash table:\n");
    display();
    }
    else if(c==2){
    int searchkey;
    printf("enter the key of the element you want to search");
    scanf("%d",&searchkey);
    int result = search(searchkey);
    if (result != -1)
        printf("\nValue found for key %d: %d\n", searchkey, result);
    else
        printf("\nValue not found for key %d\n", searchkey);
    }
    else printf("invalid choice");}
    return 0;
}
