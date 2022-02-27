#include <stdio.h>
#include <conio.h>
int main(){  int number;
   float cgpa;
    printf("Number Of Students:");
    scanf("%d", &number);
    int student[number];
    for (int i = 0; i < number; i++)
    {
        printf("Enter Marks Of Student %d:", i + 1);
        scanf("%d", &student[i]);
    }

    for(int j=0 ; j < number; j++){

        if (student[j] >= 85){
        cgpa=4;
        printf("Student %d CGPA : \n",j+1,cgpa);

    }
    else if(student[j] < 85 && student[j] >= 80 ){
        cgpa=3.8;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }

    else if(student[j] < 80  && student[j] >= 75 ){
        cgpa=3.4;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }

    else if(student[j] < 75 && student[j] >= 71 ){
        cgpa=3;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }

    else if(student[j] < 71 && student[j] >= 68 ){
        cgpa=2.8;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }

    else if(student[j] < 68 && student[j] >= 64 ){
        cgpa=2.4;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }

    else if(student[j] < 64 && student[j] >= 61 ){
        cgpa=2;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }

    else if(student[j] < 61 && student[j] >= 57 ){
        cgpa=1.8;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }

    else if(student[j] < 57 && student[j] >= 53 ){
        cgpa=1.4;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }

    else if(student[j] < 53 && student[j] >= 50 ){
        cgpa=1;
        printf("Student %d CGPA : \n",j+1,cgpa);
    }
    else if (student[j] < 50){
            cgpa=0;
            printf("Student %d CGPA : \n",j+1,cgpa);

    }
    getch();
    }
    return 0;
}
