#include <stdio.h>
#include <stdlib.h>

struct Course
{
    int course__Number;
    char course__Name;
    struct Course *next;
};

struct Student
{
    int student__Id;
    int semester__Number;
    struct Student *next;
};

