//Assignment (Greedy Approach)
/*Implement a problem of activity selection problem with K persons. 
Statement: Given two arrays S[] and E[] of size N denoting starting and 
closing time of the shops and an integer value K denoting the number 
of people, the task is to find out the maximum number of shops they 
can visit in total if they visit each shop optimally based on the following 
conditions:
 A shop can be visited by only one person.
 A person cannot visit another shop if its timing collides with it.
*/
#include<iostream>
using namespace std;
int main()
{
    int k,s[10],e[10],n=0,a=0;

    cout<<"\nEnter the no. of shops:\n";
    cin>>n;

    cout<<"\nEnter starting time:\n";
    for(int i=0;i<n;i++)
    {
        cin>>s[i];//starting time
    }
    cout<<endl;

    cout<<"\nEnter ending time:\n";
    for(int i=0;i<n;i++)
    {
        cin>>e[i];//ending time
    }
    cout<<endl;

    cout<<"\nEnter no. of People:\n";
    cin>>k;//people no.

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(e[i] > e[j])
            {
                int temp = e[i];
                e[i] = e[j];
                e[j] =temp;

                temp = s[i];
                s[i] = s[j];
                s[j]=temp;
            }
        }
    }
     int person[10];
     for(int i=0;i<k;i++)
     {
        person[i]=0;
     }

     for(int i=0;i<n;i++)
     {
        for(int j=0;j<k;j++)
        {
            if(s[i]>=person[j])
            {
                person[j] = e[i];
                a++;
                break;
            }
        }
     }

    cout<<"\nThe no. of shops visited: "<<a<<endl;
    return 0;
}

/*
Enter the no. of shops:
4

Enter starting time:
1
2
3
4

Enter ending time:
5
3
4
5

Enter no. of People:
2
The no. of shops visited: 4
*/
