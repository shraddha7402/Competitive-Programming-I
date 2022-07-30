/*

Problem D - Australian Voting

Australian ballots require that the voter rank the candidates in order of choice. Initially only the first choices are counted and if one candidate receives more than 50% of the vote, that candidate is elected. If no candidate receives more than 50%, all candidates tied for the lowest number of votes are eliminated. Ballots ranking these candidates first are recounted in favour of their highest ranked candidate who has not been eliminated. This process continues [that is, the lowest candidate is eliminated and each ballot is counted in favour of its ranked non-eliminated candidate] until one candidate receives more than 50% of the vote or until all candidates are tied.
Input

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
The first line of input is an integer n <= 20 indicating the number of candidates. The next n lines consist of the names of the candidates in order. Names may be up to 80 characters in length and may contain any printable characters. Up to 1000 lines follow; each contains the contents of a ballot. That is, each contains the numbers from 1 to n in some order. The first number indicates the candidate of first choice; the second number indicates candidate of second choice, and so on.

Output

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.
The Output consists of either a single line containing the name of the winner or several lines containing the names of the candidates who tied.

Sample Input

1

3
John Doe
Jane Smith
Sirhan Sirhan
1 2 3
2 1 3
2 3 1
1 2 3
3 1 2
Output for Sample Input

John Doe

*/
/*Australian Voting Accepted*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <cmath>
using namespace std;
 
struct Candidate
{
    string Name;
    int Votes;
    bool Eleminated;
};
 
Candidate Cands[21];
int Ballots[1000][1001];
void initVotes()
{
    for (int i=1; i<=20; i++) Cands[i].Votes = 0;
}
 
void initeleminated()
{
    for (int i=1; i<=20; i++) Cands[i].Eleminated = false;
}
 
int checkAbove50(int nVoters, int nCandidates)
{
    for (int i=1; i<= nCandidates; i++) if ((double)Cands[i].Votes > nVoters/2.0) return i;
    return -1;
}
 
void countVotes(int nVoters)
{
    for (int i=0; i<nVoters; i++)
        for (int j=0; j<3; j++)
            if (!Cands[Ballots[i][j]].Eleminated)
            {Cands[Ballots[i][j]].Votes++; break;}
}
 
bool eleminate(int nCandidates)
{
    int Highest=-1, Lowest=10000;
 
    for (int i=1; i<=nCandidates; i++) 
    {
        if (Cands[i].Votes > Highest && !Cands[i].Eleminated) Highest = Cands[i].Votes;
        if (Cands[i].Votes < Lowest  && !Cands[i].Eleminated) Lowest = Cands[i].Votes;
    }
 
    if (Lowest == Highest) return false;
 
    for (int i=1; i<=nCandidates; i++) if (Cands[i].Votes == Lowest) Cands[i].Eleminated = true;
 
    return true;
}
int main()
{
 
    int N;
     
 
    cin >> N;
    cin.get();
    cin.get();
    int nCandidates;
 
    for (int f=0; f<N; f++)
    {
        cin >> nCandidates;
        cin.get();
 
        for (int i=1; i<=nCandidates; i++) getline(cin,Cands[i].Name);
         
        initeleminated();
         int nVoters=0;
        for (nVoters=0;nVoters <1000; nVoters++)
        {
            char input;
            input = cin.get();
            if (input == '\n') break;
            cin.putback(input);
             
            for (int i=0; i<nCandidates; i++) 
                cin >> Ballots[nVoters][i];
 
            cin.get();
        }
        int winner = -1;
        do
        {
            initVotes();
            countVotes(nVoters);
            winner = checkAbove50(nVoters,nCandidates);
            if (winner != -1) break;
 
        }while(eleminate(nCandidates));
 
        if (winner == -1)
        {   for (int i=1; i<=nCandidates; i++) 
                if (!Cands[i].Eleminated) cout << Cands[i].Name << endl;
        }
        else cout << Cands[winner].Name << endl;
        if (f < N-1) cout << endl;
    }
 
    return 0;
}
