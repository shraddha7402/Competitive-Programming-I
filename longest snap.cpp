/*
3
10:07 12:19 Football game
13:11 16:17 Why why why me?
16:59 17:30 Nanananna Music :D
1
12:00 16:00 Burdens up my ass
1
12:00 15:59           Miserable At Best
3
15:00 17:00 Hey, don't blow a fuse!
13:00 15:00 Codeforces contest!!
10:00 11:00 Dinner time....yeaa :D
3
13:00 14:00 Shower
14:00 15:00 Again Shower!
15:00 16:00 Not again :(
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
struct hour
{
 int h1,h2,m1,m2;
};
bool cmp(hour a, hour b)
{
    if(a.h1 < b.h1)
       return true;
    if(a.h1 > b.h1)
       return false;
    //Minute
    if(a.m1<b.m1)
      return true;
    if(a.m1>b.m1)
      return false;    //Hour 2
    if(a.h2 < b.h2)
       return true;
    if(a.h2 > b.h2)
       return false;
    //Minute
    if(a.m2<b.m2)
      return true;
    if(a.m2>b.m2)
       return false;
}
void print(vector<hour> vec)
{
    for(int x=0; x<vec.size(); x++)
    {
        cout<<vec[x].h1<<":"<<vec[x].m1<<"  "<<vec[x].h2<<":"<<vec[x].m2<<endl;
    }
}
int main()
{
int activities, h1, m1 ,h2, m2, answer, descanso, cont = 1;
int outh1, outh2, outm1, outm2;
vector<hour> vec;
string cad;
while(scanf("%d", &activities) != EOF)
{
    for(int x=1; x<=activities; x++)
    {
        scanf("%d:%d",&h1, &m1);
        scanf("%d:%d",&h2, &m2);
        getline(cin,cad);
        hour p;
        p.h1 = h1;p.m1=m1;
        p.h2 = h2;p.m2=m2;
        vec.push_back(p);
    }
    sort(vec.begin(), vec.end(),cmp);
    //print(vec);
    int tmpIni, tmpFin;
    answer = -15;
        tmpIni = 600;
        tmpFin =(vec[0].h1*60 + vec[0].m1);
        descanso = abs(tmpIni - tmpFin);
        //cout<<tmpIni<<" "<<tmpFin<<" "<<descanso<<endl;
        if(descanso > answer)
        {
            outh1  = 10;
            outm1  = 0;
            answer = descanso;
        }
    for(int y=0, z=1; z<vec.size(); y++, z++)
    {
        tmpIni =(vec[y].h2*60 + vec[y].m2);
        tmpFin =(vec[z].h1*60 + vec[z].m1);
        descanso = abs(tmpIni - tmpFin);
        //cout<<tmpIni<<" "<<tmpFin<<" "<<descanso<<endl;
        if(descanso > answer)
        {
            outh1  = vec[y].h2;
            outm1  = vec[y].m2;
            answer = descanso;
        }
    }
        tmpIni =(vec[vec.size()-1].h2*60 + vec[vec.size()-1].m2);
        tmpFin =1080;
        descanso = abs(tmpIni - tmpFin);
        //cout<<tmpIni<<" "<<tmpFin<<" "<<descanso<<endl;
        if(descanso > answer)
        {
            outh1  = vec[vec.size()-1].h2;
            outm1  = vec[vec.size()-1].m2;
            answer = descanso;
        }
    if(answer < 60)
    {
        if(outm1 == 0)
           printf("Day #%d: the longest nap starts at %d:00 and will last for %d minutes.\n", cont++, outh1, answer);
        else if(outm1 < 10)
            printf("Day #%d: the longest nap starts at %d:0%d and will last for %d minutes.\n", cont++, outh1, outm1, answer);
        else
            printf("Day #%d: the longest nap starts at %d:%d and will last for %d minutes.\n", cont++, outh1, outm1, answer);
    }
    else
    {
       int hourAnswer       = answer / 60;
       int minutesAnswer    = answer % 60;
       //cout<<"Ans: "<<answer<<"   hora:"<<hourAnswer<<"  min:"<<minutesAnswer<<endl;
       if(outm1 == 0)
          printf("Day #%d: the longest nap starts at %d:00 and will last for %d hours and %d minutes.\n", cont++, outh1, hourAnswer, minutesAnswer);
       else if(outm1 < 10)
        printf("Day #%d: the longest nap starts at %d:0%d and will last for %d hours and %d minutes.\n", cont++, outh1, outm1, hourAnswer, minutesAnswer);
       else
        printf("Day #%d: the longest nap starts at %d:%d and will last for %d hours and %d minutes.\n", cont++, outh1, outm1, hourAnswer, minutesAnswer);
    }
    vec.clear();
}
return 0;
}