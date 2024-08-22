// nearest K cars from origin
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Car{
    public:
    int ind;
    int distance;
    Car(int ind,int distance){
        this->ind=ind;
        this->distance=distance;
    }

    bool operator < (const Car &obj)const{
        return this->distance > obj.distance;
    }
};

void nearCar(vector<pair<int,int>> v,int K){
    vector<Car> c;
    for(int i=0; i<v.size(); i++){
        int dist=(v[i].first * v[i].first +v[i].second * v[i].second);
        c.push_back(Car(i,dist));
    }

    priority_queue<Car> pq(c.begin(),c.end());

    for(int i=0; i<K; i++){
        cout<<"nearest car is in index : "<<pq.top().ind<<endl;
        pq.pop();
    }
}
int main(){
    vector<pair<int,int>> v;
    v.push_back(make_pair(3,3));
    v.push_back(make_pair(5,-1));
    v.push_back(make_pair(1,1));
    v.push_back(make_pair(3,2));
    v.push_back(make_pair(2,2));

    int K=2;
    nearCar(v,K);
    

    return 0;
}