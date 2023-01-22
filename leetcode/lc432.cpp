#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;


typedef pair<int, string> pi;
class AllOne {
public:
    AllOne()
    {
    }
    
    void inc(string key)
    {
        if (cnts.find(key)!=cnts.end())
            cnts[key]++;
        else
            cnts[key]=1;
    }

    void dec(string key)
    {
        cnts[key]--;
        if (cnts[key]==0)
            cnts.erase(key);
    }

    string getMaxKey()
    {
        pi top = maxH.top();
        return top.second;
    }

    string getMinKey()
    {
        pi top = minH.top();
        return top.second;
    }
private:
    unordered_map<string, int> cnts;
    priority_queue<pi, vector<pi>, greater<pi>> minH;
    priority_queue<pi> maxH;
};

int main(){
    AllOne* a1 = new AllOne();
    a1->inc("hello");
    a1->inc("hello");
    cout << a1->getMaxKey() << endl;
    cout << a1->getMinKey() << endl;
    a1->inc("leet");
    cout << a1->getMaxKey() << endl;
    cout << a1->getMinKey() << endl;
    
    return 0;
}
