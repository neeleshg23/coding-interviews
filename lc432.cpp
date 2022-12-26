#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

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
        return "aa";
    }

    string getMinKey()
    {
        return "bb";
    }
private:
    unordered_map<string, int> cnts;
    priority_queue< pair<int, string> > minH;
    priority_queue< pair<int, string> > maxH;
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
