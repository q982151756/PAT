#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct Person{
    char *name;
    int age;
    int worth;

    bool operator < (const Person p) const{
        if(worth > p.worth) return true;
        else if(worth < p.worth) return false;
        else{ // ????,????,??????
            if(age < p.age) return true;
            else if(age > p.age) return false;
            else{ // ????,????,??????
                for(int i = 0; i < 9; i++){
                    if(name[i] < p.name[i]) return true;
                    else if(name[i] > p.name[i]) return false;
                }
                return true;
            }
        }

    }

};

int main()
{
    vector<Person> persons;
    int N,K;
    cin >> N >> K;
    persons.resize(N);
    for(int i = 0; i < N; i++){
        char *name = new char[9];
        scanf("%s%d%d",name,&(persons[i].age),&(persons[i].worth));
        persons[i].name = name;
    }
    sort(persons.begin(),persons.end());
    int maxCnt,age_begin,age_end;
    int outputCnt = 0;
    for(int i = 0; i < K; i++){
        scanf("%d%d%d",&maxCnt,&age_begin,&age_end);
        outputCnt = 0;
        printf("Case #%d:\n",i+1);
        for(int i = 0; i < N; i++){
            if(persons[i].age >= age_begin && persons[i].age <= age_end){
                printf("%s %d %d\n",persons[i].name, persons[i].age, persons[i].worth);
                outputCnt++;
                if(outputCnt >= maxCnt) break;
            }
        }
        if(outputCnt == 0) printf("None\n");
    }
    return 0;
}
