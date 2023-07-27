#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> m;

    m["My"] = 1;

    pair<string,int> p = make_pair("name",2);
    m.insert(p);

    pair<string,int> p2("is",3);
    m.insert(p2);

    m["Anakin"] = 4;

    cout << m["My"] << endl;
    cout << m.at("name") << endl;
    cout << m["unkwn"] << endl; // creates a key for "unkwn" if not present @ 0
    cout << m.at("unkwn") << endl; // returns out of bound
    cout << m.size() << endl;

    //cout << "Anakin : " << m.count("Anakin") << endl;
    //cout << "Vader : " << m.count ("Vader") << endl;

    m.erase("Anakin");
    m["Vader"] = 4;
    //cout << "Anakin : " << m.count("Anakin") << endl;
    //cout << "Vader : " << m.count ("Vader") << endl;

    // iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }



    return 0;
}