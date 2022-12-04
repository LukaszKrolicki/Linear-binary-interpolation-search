#include <iostream>
using namespace std;

void print(int* S, int n){
    for(int i=0; i<n;i++)
    {
        cout<<S[i]<<" ";
    }
}

//linear search
int linear_search(int* S, int n, int x){
    int l_krokow=0;
    for(int i=0; i<n;i++){
        l_krokow++;
        if(S[i]== x)
        {
            cout<<"Liczba krokow: "<<l_krokow<<endl;
            return i;
        }
    }

    cout<<"Liczba krokow: "<<l_krokow<<endl;
    return -1;
}


//binary search
void sort(int* S, int n){
    int temp;
    for(int i=0; i<n;i++)
    {
        for(int j=i+1; j<n;j++){
            if(S[j]<S[i])
            {
                temp=S[j];
                S[j]=S[i];
                S[i]=temp;
            }
        }
    }
}

int binarySearch1(int* S, int n, int x){
    int l_krokow=0;
    int left=0;
    int right=n-1;
    int mid=(left+right)/2;
    while(left<=right){
        l_krokow++;
        mid=(left+right)/2;
        if(S[mid]==x)
        {
            cout<<"Liczba krokow: "<<l_krokow<<endl;
            return mid;

        }
        else if(S[mid]>x){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<"Liczba krokow: "<<l_krokow<<endl;
    return -1;
}

//interpolationSearch
int interpolationSearch(int* S, int n, int x){
    int l_krokow=0;
    int left=0;
    int right=n-1;
    int mid = left + (x - S[left]) * (right-left) / (S[right] - S[left]);
    while(left<=right){
        l_krokow++;
        mid = left + (x - S[left]) * (right-left) / (S[right] - S[left]);
        if(S[mid]==x)
        {
            cout<<"Liczba krokow: "<<l_krokow<<endl;
            return mid;

        }
        else if(S[mid]>x){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<"Liczba krokow: "<<l_krokow<<endl;
    return -1;
}


int main(){
    //Example

    int n=13;
    int *S=new int[n]{111,88,39,23,88,112,199,113,185,77,78,13,230};
    sort(S,n);
    int x=185;

    print(S,n);
    cout<<endl<<endl;
    cout<<linear_search(S,n,x)<<endl;

    cout<<endl<<endl;
    print(S,n);
    cout<<endl<<endl;
    cout<<binarySearch1(S,n,x)<<endl;

    cout<<endl<<endl;
    cout<<interpolationSearch(S,n,x)<<endl;

}
