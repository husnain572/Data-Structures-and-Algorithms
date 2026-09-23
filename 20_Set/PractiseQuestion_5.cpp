/*Coding Question
Given the number of questions as n, and marks for the correct answer as pand g marks for the incorrect answer. One can either attempt to solve the question in an examination and get either marks if the answer is right, or g marks if the answer is wrong, or leave the question unattended and get 9 marks. The task is to find the count of all the different possible marks that one can score in the examination.

Input I: n = 2 p = 1, q = -1
Output I: 5
Explanation: The different possible marks are: -2, -1, 0, 1,2
*/
// Solution
#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n,p,q;
    cin>>n>>p>>q;
    unordered_set<int>s;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            int correct=i;
            int incorrect=j;
            int unsolved=n-(i+j);
            if(unsolved>=0){
                int score=incorrect*q+correct*p;
                s.insert(score);
            }
            else{
                break;
            }
        }
    }
    cout<<"Answer is:"<<s.size()<<endl;
    return 0;
}
