#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudentStruct.h"
#include "ListStruct.h"
#include "CreateLoadStudents.h"

int main()
{
    errno_t my_error = errno;
    system("chcp 65001");
    printf("Загрузить существующих студентов или создать новых?(y/N): ");
    char create_file = 'n';
    scanf("%c", &create_file);
    fflush(stdin);

    List* list = list(NULL);

    list = (create_file == 'y')
            ? LoadStudents(NULL)
            : CreateStudents(NULL);

    MathTop(list);
    if (my_error != 0){
        printf("%s\n", strerror(my_error));
        exit(my_error);
    }
    return 0;
}



