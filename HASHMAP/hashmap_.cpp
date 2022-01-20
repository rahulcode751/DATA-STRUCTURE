#include<bits/stdc++.h>
using namespace std;

template<typename V>
class MapNode{

public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode(){
        delete next;   /// whole linked list will be destroy bcoz it is recursive
    }
};

template<typename V>
class mymap{
   private:
       MapNode<V>** buckets;  // array
       int count;
       int numBuckets;

       int getBucketIndex(string key){
           int hashcode = 0;
           int base = 1;
           int p = 37;   /// prime number
           for(int i=key.size()-1;i>=0;i--){
                hashcode += key[i] * base;  /// hashcode and base in dono step me bht fast or bht bde number me change ho rhe the to ahmne unme bhi comprssion lagakar chota kiya
                base = base * p;
                hashcode = hashcode%numBuckets;
                base = base%numBuckets;
           }
           return hashcode%numBuckets;  /// compression and return
       }
   public:
    mymap(){
        count = 0;
        numBuckets = 5;  // initially let say size of array is 5
        buckets = new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i] = NULL;  /// apni bucket ke andar garbage value thi unhe hta ke null dal diya
        }
    }
    ~mymap(){
       for(int i=0;i<numBuckets;i++){
        delete buckets[i];  /// each entry in array is  head of linked list to we will delete the lin ked list first by doing iration
       }
       delete []buckets;   /// this delete the array
    }

    int size(){
       return count;
    }

    V getValue(string key){ /// it will return the value of V type
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    void insert(string key, V value){
      int bucketIndex = getBucketIndex(key);
      MapNode<V>* head = buckets[bucketIndex];
      while(head!=NULL){    /// is loop me hmne kiya kya agr let suppose abc ko key h linked list me already present h or hm same index of bucket
          ///  pr new abc keylna cha rhe h lekin hashmap me to key uniqe hoti h to ye loop kya kregi dekhegi ki linked list me ye key present h
          ///  agar h to uski value ko update kr degi yani nyi wali key ki value dal degi purani wali ko hta kr kyuku hash map me ek key ek bar
          ///  hi ati h to bs hm value change kr denge
        if(head->key == key){
            head->value = value;
            return;
        }
        head = head->next; /// agar linked list me key nhi mili yani hm linked list ke end yani null pr poch gye ye line ye show kr ri h
      }

      MapNode<V>* node = new MapNode<V>(key,value);  /// yha hmne new node banayi
      node->next = buckets[bucketIndex];             /// head update
      buckets[bucketIndex] = node;
      count++;
    }

    V remove(string key){  /// it will remove the entry and will return tha value correspond to that key
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;

        while(head!=NULL){

            if(head->key == key){
                if(prev == NULL){   /// means first node me hi mil gyi key yani head pr
                    buckets[bucketIndex] = head->next;  /// isiliye bucket index ko change kr diya
                }else{
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }
        return 0;  /// means key is not present in linked list
    }
};
int main(){

  return 0;
}
