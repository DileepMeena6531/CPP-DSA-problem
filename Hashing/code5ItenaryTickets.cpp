// itinary from tickets
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void plainTick(unordered_map<string, string> ticket)
{
    unordered_set<string> to;
    for(auto it: ticket){
        to.insert(it.second);
    }
    string start="";

    for(auto it:ticket){
        if(to.find(it.first)==to.end()){
            start=it.first;
        }
    }
    
    cout<<start<<"->";
    while(ticket.count(start)){
        cout<<ticket[start]<<"->";
        start=ticket[start];
    }
    cout<<"is destignation"<<endl;
}
int main()
{
    unordered_map<string, string> ticket;
    ticket["chennai"] = "bengaluru";
    ticket["mumbai"] = "delhi";
    ticket["goa"] = "chennai";
    ticket["delhi"] = "goa";

    plainTick(ticket);

    return 0;
}