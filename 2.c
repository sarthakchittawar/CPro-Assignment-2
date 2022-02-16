#include <stdio.h>

#define FLOORS 3
#define ROOMS 3

void main()
{
    
    int ar[FLOORS][ROOMS], flag=0;
    int a;

    printf("Enter Gender of occupant ('0' for male & '1' for female)\n");
    for (int i=0; i<FLOORS; i++)
    {
        for (int j=0; j<ROOMS; j++)
        {
            if (flag==0)
            {
                printf("FLOOR %d ROOM %d: ", i+1, j+1);
                scanf("%d", &a); 
                if (a==0 || a==1)
                {
                    ar[i][j]=a;
                }
                else {flag=1;}
                           
            }
            
        }

    }
    if (flag==1)
    {
        printf("\nProgram Ended. Please input ONLY 0 or 1\n");
    }

    //% of males/females
    float m=0,f=0;
    for (int i=0; i<FLOORS; i++)
    {
        for (int j=0; j<ROOMS; j++)
        {
            if (ar[i][j]==0)
            {
                m+=1;
            }
            else if (ar[i][j]==1)
            {
                f+=1;
            }
        }
    }
    printf("%f %f\n", m ,f);
    printf("Percentage of males in the hotel = %f%%\n",  m*100/(m+f));
    printf("Percentage of females in the hotel = %f%%\n",  f*100/(m+f));

    //% on each floor
    for (int i=0; i<FLOORS; i++)
    {
        m=0, f=0;
        for (int j=0; j<ROOMS; j++)
        {
            if (ar[i][j]==0)
            {
                m+=1;
            }
            else if (ar[i][j]==1)
            {
                f+=1;
            }
        }
        printf("\nFLOOR %d:\n", i+1);
        printf("Percentage of Males = %f%% & Percentage of Females = %f%%\n", m*100/(m+f), f*100/(m+f));
    }

    //Floor with max no. of males
    int male[FLOORS];
    for (int i=0; i<FLOORS; i++)
    {
        m=0;
        for (int j=0; j<ROOMS; j++)
        {
            if (ar[i][j]==0)
            {
                m+=1;
            }
        }
        male[i]=m;
    }
    int max=0;
    for (int i=0; i<FLOORS; i++)
    {
        if (male[i] > max)
        {
            max = male[i];
            m=i+1;
        }
    }
    printf("\nFloor %d has the maximum number of males. (i.e. %d males)\n", (int)m, max);

    //Redistribution
    m=0, f=0;
    for (int i=0; i<FLOORS; i++)
    {
        for (int j=0; j<ROOMS; j++)
        {
            if (ar[i][j]==0)
            {
                m+=1;
            }
            else if (ar[i][j]==1)
            {
                f+=1;
            }
        }
    }
    if ((int)m%ROOMS==0 && (int)f%ROOMS==0)
    {
        printf("\nRedistribution Possible:\n");
        printf("All male occupuants are distributed in %d room(s), whiile female occupants are distributed in %d room(s).\n", (int)m/ROOMS, (int)f/ROOMS);
    }
    else
    {
        printf("\nRedistribution not possible.\n");
    }
}
