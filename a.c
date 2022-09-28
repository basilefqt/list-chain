#include <stdio.h>
#include <stdlib.h>

typedef struct block{
    int value;
    struct block *next;
}block;

void add_block(int element, struct block *pointer){
    while((*pointer).next){
        pointer = (*pointer).next;
    }
    struct block *new_block_pointer = malloc(sizeof(block));
    (*new_block_pointer).value = element;
    (*pointer).next = &(*new_block_pointer);
}

void dump(struct block *pointer){
    while((*pointer).next){
        printf("%d\n",(*pointer).value);
        pointer = (*pointer).next;
    }
    printf("%d\n",(*pointer).value);
}

int dump_index(int index, struct block *pointer){
    for(int i = 0; i < index; i++){
        pointer = (*pointer).next;
    }
    printf("%d",(*pointer).value);
}

void delete_by_index(int index, struct block *pointer){
    struct block *flag_backup_pointer;
    for(int i = 0; i < index-1; i++){
        pointer = (*pointer).next;
    }
    flag_backup_pointer = &(*pointer);
    pointer = (*pointer).next;
    (*flag_backup_pointer).next = (*pointer).next;
    // free(pointer);
}

void delete_by_value(int search_value, struct block *pointer){
    struct block *flag_init_pointer;
    int turn;
    flag_init_pointer = pointer;
    turn = -1;
    while((*pointer).next){
        turn++;
        if((*pointer).value == search_value){delete_by_index(turn,flag_init_pointer);}
        pointer = (*pointer).next;
    }
    if((*pointer).value == search_value){delete_by_index(turn,flag_init_pointer);}
}

int main(){
    struct block init = {0};
    add_block(3,&init);
    add_block(2,&init);
    add_block(3,&init);
    dump(&init);
    printf("____________\n");
    delete_by_value(2,&init);
    dump_index(1,&init);
    // dump(&init);
}


    // dump_index(1,&init);
    // delete_by_index(3,&init);