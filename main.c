#include <stdio.h>
#include <stdlib.h>
#include "StudentStruct.h"
#include "ListStruct.h"
#include "CreateLoadStudents.h"

int main()
{
    system("chcp 65001");
    printf("Загрузить существующих студентов или создать новых?(y/N): ");
    char create_file = 'n';
    scanf("%c", &create_file);
    fflush(stdin);

    List* list = list(NULL);

    if (create_file == 'y')
        list = LoadStudents(NULL);
    else
        list = CreateStudents(NULL);

    MathTop(list);
    return 0;
}



