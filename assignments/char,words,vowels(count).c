#include<stdio.h>
void main()
{
    char str[100];
    printf("enter the string:");
    scanf("%s",str);
    int vowels;
    vowels=0;
    int i;
    for(i=0;i<100;i++)
    {
          if(str[i]=='a' || str[i]=='e'|| str[i]=='i'|| str[i]=='o' || str[i]=='u')
        {
            vowels+=1;
        }
    }
    printf("The count of vowel is:");
    printf("%d",vowels);
    int characters;
    characters=0;
    int specialcharacter;
    specialcharacter=0;
    int j;
    for(j=0;j<100;j++)
    {
      if((str[j]>='a' && str[j]<='z') || (str[j]>='A' && str[j]<='Z') )
      {
          characters+=1;
      }

    }
    printf("The count of characters is:");
    printf("%d",characters);
    /*
    printf("the count of special characters is:");
    printf("%d",specialcharacter);
    */
    int words;
    words=1;
    int k;
    for(k=0;k<100;k++)
    {
        if(str[k]==' ')
        {
            words+=1;
        }
    }
    printf("the count of words is:");
    printf("%d",words);

}
