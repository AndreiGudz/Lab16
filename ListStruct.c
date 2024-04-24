//
// Created by Андрей и Витя on 18.03.2024.
//

#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <string.h>
#include "ListStruct.h"

void* appendStudent(void*);
void* studentPrintInList(void*);
void* (printAllList)(void*);

void* (listInit)(void*){
    errno_t my_error = errno;
    List* list = malloc(sizeof(List));
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->print = studentPrintInList;
    list->append = appendStudent;
    list->printAll = printAllList;
    return (void*) list;
}

void* appendStudent(void* _list){
    errno_t my_error = errno;
    List* list = _list;
    Node* student = malloc(sizeof(Node));
    student->node_student = malloc(sizeof(Student));
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    studentFill(student->node_student);
    student->next = NULL;

    if(list->size == 0){
        list->head = student;
        list->tail = list->head;
    } else{
        list->tail->next = student;
        list->tail = student;
    }
    list->size++;
    return NULL;
}

void* (printAllList)(void* _list){
    errno_t my_error = errno;
    List* list = _list;
    Args* args = malloc(sizeof(Args) );
    args->list = list;
    for (args->count = 0 ; args->count < args->list->size; args->count++) {
        printf("%d ", args->count + 1);
        args->list->print(args);
    }
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    return NULL;
}

void* studentPrintInList(void* _args){
    errno_t my_error = errno;
    Args* args = _args;
    if (args->count < 0 || args->count >= args->list->size)
        return NULL;

    int i = 0;
    for(
            Node* cur_elem = args->list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next
            ){
        if(i == args->count){
            cur_elem->node_student->print(cur_elem->node_student);
        }
        i++;
    }
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    return NULL;
}


void* topTenInMath(void* _list){
    errno_t my_error = errno;
    List* list = _list;
    int top_in_math;
    if (list->size > 10)
        top_in_math = 10;
    else
        top_in_math = (int) list->size;

    int position_in_top = 1;
    for (
            int max_grade = 5;
            (position_in_top <= top_in_math) && (max_grade > 1);
            max_grade--)
        for (Node* cur_elem = list->head;
             cur_elem != NULL;
             cur_elem = cur_elem->next){
            if (
                    (cur_elem->node_student->mathematics_grade == max_grade)
                    && (position_in_top <= top_in_math)
                    ){
                printf("Top position %d\n", position_in_top);
                cur_elem->node_student->print(cur_elem->node_student);
                position_in_top += 1;
            }
        }
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    return NULL;
}