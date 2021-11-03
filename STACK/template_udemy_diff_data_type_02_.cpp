#include<iostream>
using namespace std;

template<typename T, typename V>
class Pair{
   T x;
   V y;

   public:
       void setX(T x){
          this->x = x;
       }
       T getX(){
         return x;
       }
       void setY(V y){
          this->y = y;
       }
       V getY(){
         return y;
       }
};
int main(){
    Pair<int,Pair<double,int>> p;   /// ye online compiler pr chal ra h 
    p.setX(30);
    Pair<double,int> temp;
    temp.setX(10.96);
    temp.setY(20);

    p.setY(temp);

    cout<<p.getX()<<" "<<p.getY().getX()<<" "<<p.getY().getY()<<endl;
   return 0;
}
