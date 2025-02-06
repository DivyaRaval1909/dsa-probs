#include<iostream>
using namespace std;

bool isPrime(long long num) {
     if (num <= 1) 
     return false;
     if (num == 2 || num == 3)
      return true;
    if (num % 2 == 0 || num % 3 == 0) 
    return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

bool isTPrime(int n) {
    int root = sqrt(n);
    if (root * root != n)
     return false;  
    return isPrime(root);
}


int main()
{
    int n;
    cin>>n;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        
        if(isTPrime(a[i]))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    



    return 0;
}