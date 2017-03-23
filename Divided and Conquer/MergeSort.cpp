//merge sort with inversion count
#include<bits/stdc++.h>
#define INF 1e9
#define sz 100
using namespace std;

int swp,num,a[sz];

void Merge(int a[],int p,int q,int r)
{
    int left[sz],right[sz],i,j;
    int n1 = q-p+1, n2 = r-q;
    for(int i=1; i<=n1; i++)
        left[i] = a[p+i-1];

    for(int i=1; i<=n2; i++)
        right[i] = a[q+i];

    left[n1+1] = INF;
    right[n2+1] = INF;

    i=j=1;

    for(int k=p; k<=r; k++)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
        }
        else
        {
            a[k]=right[j];
            swp+=(n1-i+1);//to count inversion number
            j++;
        }
    }
}

void merge_sort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r) /2;//middle point
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        Merge(a,p,q,r);//call the function to merge after divided
    }
}
int main()
{
    int n;
    cout << "Enter how many numbers: ";
    cin>>n;
    //scanf("%d", &n);
    int a[n];
    cout <<"Given array is: ";
    for(int i=0; i<n; i++)
    {
        //scanf("%d",&a[i]);
        cin>>a[i];
    }
    merge_sort(a, 0, n);//here 0 for index
    cout <<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        //printf("%d ",a[i]);
        cout<<a[i]<<" ";
    }
    //if you want to count inversion
    cout<<endl<<"Inversion: "<<swp<<endl;
    return 0;
}
