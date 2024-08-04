// pair in c++

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool campare(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}

int main()
{

    vector<pair<int, int>> Act(3, make_pair(0, 0));
    Act[0] = make_pair(0, 9);
    Act[1] = make_pair(1, 2);
    Act[2] = make_pair(2, 4);

    for (int i = 0; i < 3; i++)
    {
        cout << Act[i].first << "," << Act[i].second << endl;
    }

    cout<<"--------------"<<endl;

    sort(Act.begin(),Act.end(),campare);

    for (int i = 0; i < 3; i++)
    {
        cout << Act[i].first << "," << Act[i].second << endl;
    }

    return 0;
}