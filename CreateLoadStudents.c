//
// Created by Андрей и Витя on 14.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string.h>
#include "ListStruct.h"
#include "CreateLoadStudents.h"

#define SRandom srand(time(NULL))

void* (SaveStudents)(void*);

void* (CreateStudents)(void*){
    errno_t my_error = errno;
    SRandom;
    List* list = list(NULL);
    int count = 0;

    printf("How many students create (max 20): ");
    scanf("%d", &count);
    printf("\n");
    fflush(stdin);
    if (count > 20)
        count = 20;

    for (int i = 0; i < count; i++)
        list->append(list);

    list->printAll(list);

    printf("сохранить новых студентов?(y/N): ");
    char save_file = 'n';
    scanf("%c", &save_file);
    fflush(stdin);
    printf("\n");

    if (save_file == 'y'){
        SaveStudents(list);
    }
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    return list;
}

void* (LoadStudents)(void*){
    errno_t my_error = errno;
    FILE* my_file = fopen("students_file.bin", "rb");
    if(my_file == NULL){
        printf("Файл students_file.bin не существует!\n %s\n", strerror(my_error));
        perror("Файл students_file.bin не существует!");
        exit(my_error);
    }

    List* list = list(NULL);
    fread(&(list->size), sizeof(int), 1, my_file);
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    for (int i = 0 ; i < list->size; i++){
        Node* student = malloc(sizeof(Node) );
        student->node_student = malloc(sizeof(Student) );

        fread(student->node_student->name, sizeof(char[20]), 1, my_file);
        fread(student->node_student->last_name, sizeof(char[20]), 1, my_file);
        fread(&(student->node_student->gender), sizeof(char), 1, my_file);
        fread(&(student->node_student->gender), sizeof(int), 1, my_file);
        fread(&(student->node_student->group), sizeof(char[8]), 1, my_file);
        fread(&(student->node_student->mathematics_grade), sizeof(int), 1, my_file);
        fread(&(student->node_student->chemistry_grade), sizeof(int), 1, my_file);
        fread(&(student->node_student->physics_grade), sizeof(int), 1, my_file);
        studentFillFunction(student->node_student);
        student->next = NULL;

        if(i == 0){
            list->head = student;
            list->tail = list->head;
        } else{
            list->tail->next = student;
            list->tail = student;
        }
    }
    fclose(my_file);
    list->printAll(list);
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    return list;
}

void* (SaveStudents)(void* _list){
    errno_t my_error = errno;
    List* list = _list;
    FILE* my_file = fopen("students_file.bin", "wb");
    if(my_file == NULL){
        printf("%s\n", strerror(my_error));
        perror("Файл students_file.bin не был создан");
        exit(my_error);
    }

//    int i = 0;
    fwrite(&(list->size), sizeof(int), 1, my_file);
    for (
            Node* cur_elem = list->head;
            cur_elem != NULL;
            cur_elem = cur_elem->next
            ){
        Student* student = cur_elem->node_student;
        fwrite(student->name, sizeof(char[20]), 1, my_file);
        fwrite(student->last_name, sizeof(char[20]), 1, my_file);
        fwrite(&(student->gender), sizeof(char), 1, my_file);
        fwrite(&(student->gender), sizeof(int), 1, my_file);
        fwrite(&(student->group), sizeof(char[8]), 1, my_file);
        fwrite(&(student->mathematics_grade), sizeof(int), 1, my_file);
        fwrite(&(student->chemistry_grade), sizeof(int), 1, my_file);
        fwrite(&(student->physics_grade), sizeof(int), 1, my_file);
    }
    fclose(my_file);
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    return NULL;
}

