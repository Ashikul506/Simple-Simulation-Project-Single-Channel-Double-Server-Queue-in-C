#include<stdio.h>
int main(void)
{
    int i,j,p;
    int rd_arr[10],intr_arr[10],rd_ser[10],a_ser[10],b_ser[10],arr_t[10],a_ser_beg[10],b_ser_beg[10],a_ser_end[10],b_ser_end[10],a_wt[10],b_wt[10],wt[10],a_ts[10],b_ts[10],ts[10];
    printf("How many processes?\n");
    scanf("%d",&p);
    printf("Enter random digits for the arrival of the processes:\n");
    printf("RD for process 1:0\n");
    intr_arr[0]=0;
    for(i=1;i<p;i++)
    {
        printf("RD for process %d:",i+1);
        scanf("%d",&rd_arr[i]);
        if(rd_arr[i]>0 && rd_arr[i]<=25)
        {
            intr_arr[i]=1;
        }
        else if (rd_arr[i]>25 && rd_arr[i]<=65)
        {
            intr_arr[i]=2;
        }
        else if (rd_arr[i]>65 && rd_arr[i]<=85)
        {
            intr_arr[i]=3;
        }
        else if (rd_arr[i]>86 && rd_arr[i]<=100)
        {
            intr_arr[i]=4;
        }
        else
            printf("Wrong input.\n");
    }
    printf("Enter random digits for the time of services\n");
    for(i=0;i<p;i++)
    {
        printf("RD for service %d:",i+1);
        scanf("%d",&rd_ser[i]);
    }
    arr_t[0]=0;
    for(i=1;i<p;i++)
    {
        arr_t[i]=arr_t[i-1]+intr_arr[i];
    }
    a_ser_beg[0]=0;
    if(rd_ser[0]>0 && rd_ser[0]<=30)
    {
        a_ser[0]=2;
    }
    else if(rd_ser[0]>30 && rd_ser[0]<=58)
    {
        a_ser[0]=3;
    }
    else if(rd_ser[0]>58 && rd_ser[0]<=83)
    {
        a_ser[0]=4;
    }
    else if(rd_ser[0]>83 && rd_ser[0]<=100)
    {
        a_ser[0]=5;
    }
    else
    {
        printf("Wrong input.");
    }
    a_ser_end[0]=a_ser_beg[0]+a_ser[0];
    b_ser_beg[0]=0;
    b_ser[0]=0;
    b_ser_end[0]=0;
    for(i=1;i<p;i++)
    {
        if(arr_t[i]>=a_ser_end[i-1])
        {
            a_ser_beg[i]=arr_t[i];
            if(rd_ser[i]>0 && rd_ser[i]<=30)
            {
                a_ser[i]=2;
            }
            else if(rd_ser[i]>30 && rd_ser[i]<=58)
            {
                a_ser[i]=3;
            }
            else if(rd_ser[i]>58 && rd_ser[i]<=83)
            {
                a_ser[i]=4;
            }
            else if(rd_ser[i]>83 && rd_ser[i]<=100)
            {
                a_ser[i]=5;
            }
            else
            {
                printf("Wrong input.");
            }
            a_ser_end[i]=a_ser_beg[i]+a_ser[i];
            b_ser_beg[i]=b_ser_beg[i-1];
            b_ser[i]=b_ser[i-1];
            b_ser_end[i]=b_ser_end[i-1];
        }
        else if(arr_t[i]>=b_ser_end[i-1])
        {
            b_ser_beg[i]=arr_t[i];
            if(rd_ser[i]>0 && rd_ser[i]<=35)
            {
                b_ser[i]=3;
            }
            else if(rd_ser[i]>35 && rd_ser[i]<=60)
            {
                b_ser[i]=4;
            }
            else if(rd_ser[i]>60 && rd_ser[i]<=80)
            {
                b_ser[i]=5;
            }
            else if(rd_ser[i]>81 && rd_ser[i]<=100)
            {
                b_ser[i]=6;
            }
            else
            {
                printf("Wrong input.");
            }
            b_ser_end[i]=b_ser_beg[i]+b_ser[i];
            a_ser_beg[i]=a_ser_beg[i-1];
            a_ser[i]=a_ser[i-1];
            a_ser_end[i]=a_ser_end[i-1];
        }
        else if((a_ser_end[i-1]>arr_t[i]) && (a_ser_end[i-1]<=b_ser_end[i-1]))
        {
            a_ser_beg[i]=a_ser_end[i-1];
            if(rd_ser[i]>0 && rd_ser[i]<=30)
            {
                a_ser[i]=2;
            }
            else if(rd_ser[i]>30 && rd_ser[i]<=58)
            {
                a_ser[i]=3;
            }
            else if(rd_ser[i]>58 && rd_ser[i]<=83)
            {
                a_ser[i]=4;
            }
            else if(rd_ser[i]>83 && rd_ser[i]<=100)
            {
                a_ser[i]=5;
            }
            else
            {
                printf("Wrong input.");
            }
            a_ser_end[i]=a_ser_beg[i]+a_ser[i];
            b_ser_beg[i]=b_ser_beg[i-1];
            b_ser[i]=b_ser[i-1];
            b_ser_end[i]=b_ser_end[i-1];
        }
        else if((a_ser_end[i-1]>arr_t[i]) && (a_ser_end[i-1]>b_ser_end[i-1]))
        {
            b_ser_beg[i]=b_ser_end[i-1];
            if(rd_ser[i]>0 && rd_ser[i]<=35)
            {
                b_ser[i]=3;
            }
            else if(rd_ser[i]>35 && rd_ser[i]<=60)
            {
                b_ser[i]=4;
            }
            else if(rd_ser[i]>60 && rd_ser[i]<=80)
            {
                b_ser[i]=5;
            }
            else if(rd_ser[i]>81 && rd_ser[i]<=100)
            {
                b_ser[i]=6;
            }
            else
            {
                printf("Wrong input.");
            }
            b_ser_end[i]=b_ser_beg[i]+b_ser[i];
            a_ser_beg[i]=a_ser_beg[i-1];
            a_ser[i]=a_ser[i-1];
            a_ser_end[i]=a_ser_end[i-1];
        }
        else
            printf("Found some problem.");
    }
    for(i=0;i<p-1;i++)
    {
        for(j=i+1;j<p;j++)
        {
            if(a_ser_beg[i]==a_ser_beg[j])
            {
                a_ser_beg[j]=0;
                a_ser[j]=0;
                a_ser_end[j]=0;
            }
            if(b_ser_beg[i]==b_ser_beg[j])
            {
                b_ser_beg[j]=0;
                b_ser[j]=0;
                b_ser_end[j]=0;
            }
        }
    }
    for(i=0;i<p;i++)
    {
        a_wt[i]=a_ser_beg[i]-arr_t[i];
        b_wt[i]=b_ser_beg[i]-arr_t[i];
        if(a_wt[i]>=b_wt[i])
        {
            wt[i]=a_wt[i];
        }
        else if(a_wt[i]<b_wt[i])
        {
            wt[i]=b_wt[i];
        }
        else
        {
            printf("Found some problem.");
        }
        a_ts[i]=wt[i]+a_ser[i];
        b_ts[i]=wt[i]+b_ser[i];
        if(a_ts[i]>=b_ts[i])
        {
            ts[i]=a_ts[i];
        }
        else if(a_ts[i]<b_ts[i])
        {
            ts[i]=b_ts[i];
        }
        else
            printf("Found some problem.");
    }
    printf("                          |            Able          |            Baker         |                 \n");
    printf("Customer|Intra   |Arrival |Service |Service |Service |Service |Service |Service |Wait    |Time    \n");
    printf("Number  |Arrival |Time    |Begin   |Time    |End     |Begin   |Time    |End     |Time    |Spend   \n");
    for(i=0;i<p;i++)
    {
        printf("   %d        %d         %d        %d        %d        %d       %d        %d        %d        %d        %d   \n",i+1,intr_arr[i],arr_t[i],a_ser_beg[i],a_ser[i],a_ser_end[i],b_ser_beg[i],b_ser[i],b_ser_end[i],wt[i],ts[i]);
    }
    return 0;
}
