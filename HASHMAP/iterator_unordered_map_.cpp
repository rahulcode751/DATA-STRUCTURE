#include<bits/stdc++.h>
using namespace std;

int main(){
     unordered_map<string, int> mymap; /// unorderd map
     mymap["abc"] = 1;
     mymap["abc1"] = 2;
     mymap["abc2"] = 3;
     mymap["abc3"] = 4;
     mymap["abc4"] = 5;
     mymap["abc5"] = 6;

     cout<<"unordered map "<<endl;
     for(auto it = mymap.begin(); it != mymap.end(); it++){
        cout<<"Key :"<<it->first<<" Value : "<<it->second<<endl;
     }
     cout<<endl;


     map<string, int> mymap2;   /// ordered map
     mymap2["abc1"] = 2;
     mymap2["abc"] = 10;
     mymap2["abc2"] = 3;
     mymap2["abc4"] = 5;
     mymap2["abc3"] = 4;
     mymap2["abc5"] = 6;

     cout<<"simple or ordered map "<<endl;
     for(map<string, int>::iterator it = mymap2.begin(); it != mymap2.end(); it++){
        cout<<"Key :"<<it->first<<" Value : "<<it->second<<endl;
     }
     cout<<endl;


     vector<int> v;
     v.push_back(10);
     v.push_back(2);
     v.push_back(3);
     v.push_back(4);
     v.push_back(5);

     for(auto it = v.begin() ; it != v.end() ;it++){
        cout<<*it<<endl;
     }

     ///unordered_map<string, int>::iterator it = mymap.find("abc");
     /// mymap.erase(it);
      mymap.erase(mymap.begin() , mymap.end());  /// for erase we can erase a key by mymap.erase("abc") like this

     /// find
     if(mymap.find("abc") == mymap.end()){   /// this is returning tha end pointer so our output is not present
        cout<<"Not present"<<endl;
     }else{
        cout<<"present"<<endl;
     }

      for(unordered_map<string, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
        cout<<"Key :"<<it->first<<" Value : "<<it->second<<endl;
     }
     cout<<"size : "<<mymap.size()<<endl;


     auto a = 5;
     cout<<a<<endl;

     auto c = "abc";
     cout<<c<<endl;

     return 0;
}
