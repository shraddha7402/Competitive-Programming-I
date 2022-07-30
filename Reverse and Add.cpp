/*
3
195
265
750
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>
#include <iterator>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
using namespace std;
 
 
long long int reverInt(long long int x)
{
    long long int rn=0;
    while(x > 0)
    {
        rn*= 10;
        rn += x%10;
        x/= 10;
    }
 
    return rn;
}
int main()
{
    int N;
    cin >> N;
 
    for (int i=0; i<N; i++)
    {
 
        long long int n, rn=0, nreversals=0;
        cin >> n;
         
         
        while(reverInt(n) != n)
        {
            nreversals++;
            n += reverInt(n);
        }
 
        cout << nreversals << " " << n << endl;
     
 
 
    }
 
 
    return 0;
}
