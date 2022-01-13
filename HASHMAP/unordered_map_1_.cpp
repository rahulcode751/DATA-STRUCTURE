#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string, int>  mymap;

    /// insert
    pair<string,int> p("abc",1);
    mymap.insert(p);

    mymap["def"] = 2;  /// like array

    /// find or access
     cout<<mymap["abc"]<<endl;
     cout<<mymap.at("abc")<<endl;

     cout<<"Size "<<mymap.size()<<endl;

     /// cout<<mymap.at("ghi")<<endl;   /// throw exception
     cout<<mymap["ghi"]<<endl;

    cout<<"Size "<<mymap.size()<<endl;


     /// check presence of a key
     if(mymap.count("ghi") > 0){
        cout<<"ghi is present"<<endl;    /// yha ghi prsent h kyuki upar hmne   cout<<mymap["ghi"]<<endl;  ye kr diya to zero value chli gyi
     }else{
        cout<<"not present"<<endl;
     }


     /// update
     mymap["abc"] = 20;

     /// erase
     mymap.erase("ghi");

     cout<<"Size "<<mymap.size()<<endl;


     /// check presence of a key
     if(mymap.count("ghi") > 0){
        cout<<"ghi is present"<<endl;
     }else{
        cout<<"not present"<<endl;
     }

    return 0;
}
