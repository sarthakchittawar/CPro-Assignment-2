#include <stdio.h>
#include <math.h>
#include <string.h>

void main()
{
    int i, N, flag=0;
    printf("Enter the number of students: ");
    scanf("%d", &N);

    float ar[N], k;
    for (i=1; i<=N; i++)
    {
        printf("Enter final marks of student %d: ", i);
        scanf("%f", &k);
        if (0<=k && k<=100)
        {
            ar[i-1]=k;
        }
        else
        {
            printf("\nERROR, EXITING PROGRAM. Marks should be in the range 0-100 only\n");
            flag=1;     
            break; 
        }
    }
    if (flag==0)
    {
        printf("\nPass %%:\n");
        // Pass Percentage
        int c=0;
        for (i=0; i<N; i++)
        {
            if (ar[i]>=35)
            {
                c+=1;
            }
        }
        printf("Pass percentage of the students is %f %%\n", (float) c/N*100);

        //Mean, Variance, Standard Deviation
        printf("\nMean, Variance, Standard Deviation:\n");
        c=0;
        int d=0;
        for (i=0; i<N; i++)
        {
            c+=ar[i];
            d+=ar[i]*ar[i];
        }
        float mean = (float) c/N;
        float variance = (float) d/N - mean*mean;
        if (variance < 0)
        {
            variance = -variance;
        }
        
        printf("Mean = %f\n", mean);
        printf("Variance = %f\n", variance);
        printf("Standard Deviation = %f\n", sqrtf(variance));        
        
        //STDEV Range
        printf("\nStandard Deviation Range: \n");
        int c1=0,c2=0,c3=0;
        for (int i=0; i<N; i++)
        {
            if (mean-sqrtf(variance)<ar[i] && ar[i]<mean+sqrtf(variance))
            {
                c1+=1;
            }
            if (mean-2*sqrtf(variance)<ar[i] && ar[i]<mean+2*sqrtf(variance))
            {
                c2+=1;
            }
            else
            {
                c3+=1;
            }
        }
        printf("No. of marks within 1 Standard Deviation = %d\n", c1);
        printf("No. of marks within 2 Standard Deviation = %d\n", c2);
        printf("No. of marks not enclosed in 2 standard deviations = %d\n", c3);
        

        // Max/Min marks
        printf("\nMax/Min marks:\n");
        float max=0, min;
        for (i=0; i<N; i++)
        {
            if (ar[i]>max)
            {
                max = ar[i];
                if (i==0)
                {
                    min = max;
                }
            }
            if (ar[i]<min)
            {
                min = ar[i];
            }
        }
        printf("In the class: Maximum Marks = %f and Minimum Marks = %f\n", max, min);
        
        //Histogram
        printf("\nHistogram:\n");
        int p=1;
        for (int i=0; i<=9; i++)
        {
            c=0;
            for (int j=0; j<N; j++)
            {
                int x = i*10;
                //printf("%f %f %f\n",(float)x, ar[j], (float)x+9);
                if (i==9)
                {
                    if ((float)x <= ar[j] && ar[j]<= (float)x + 8)
                    {
                        c+=1;
                    }
                }
                else
                {
                    if ((float)x <= ar[j] && ar[j]<= (float)x + 9)
                    {
                        c+=1;
                    }
                }
            }
            //printf("%d\n",c);
            char s[100]="";
            for (int j=1; j<=c; j++)
            {
                strcat(s, "=");
            }
            if (i==0)
            {
                printf("  ");
            }
            if (i==9)
            {
                printf("[%d, %d] - %s\n", i*10, (i*10)+8, s);
   
            }
            else
            {
                printf("[%d, %d] - %s\n", i*10, (i*10)+9, s);
            }
            p+=1;
        } 
        c=0;
        for (int i=0; i<N; i++)
        {
            if (99<=ar[i] && ar[i]<=100)
            {
                c+=1;
            }
        }
        char s[100]="";
        for (int i=1; i<=c; i++)
        {
            strcat(s, "=");
        }
        printf("[99, 100]- %s\n", s);
               

    }
}
