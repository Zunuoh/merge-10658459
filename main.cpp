#include <iostream>

using namespace std;
int Merge(int One[],int p, int q,int r)
{
    int n1,n2,i,j,k;

    n1=q-p+1;
    n2=r-q;
    int L[n1],R[n2];

    for(i=0;i<n1;i++)
    {
        L[i]=One[p+i];
    }

    for(j=0;j<n2;j++)
    {
        R[j]=One[q+j+1];
    }
    i=0,j=0;

    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            One[k]=L[i++];
        }
        else
        {
            One[k]=R[j++];
        }
    }

    while(i<n1)
    {
        One[k++]=L[i++];
    }

    while(j<n2)
    {
        One[k++]=R[j++];
    }
}
int MergeSort(int One[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(One,p,q);
        MergeSort(One,q+1,r);
        Merge(One,p,q,r);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the Array: ";
    cin>>n;
    int One[n],i;
    cout<<"Enter the values of the array:";
    for(i=0;i<n;i++)
    cin>>One[i];

    MergeSort(One,0,n-1);
    cout<<"The Sorted List is";
    for(i=0;i<n;i++)
    {
        cout<<One[i]<<" ";
    }
    return 0;
}
