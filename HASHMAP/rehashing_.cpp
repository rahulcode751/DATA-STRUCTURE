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
        delete next;
    }
};

template<typename V>
class mymap{
   private:
       MapNode<V>** buckets;
       int count;
       int numBuckets;

       int getBucketIndex(string key){
           int hashcode = 0;
           int base = 1;
           int p = 37;
           for(int i=key.size()-1;i>=0;i--){
                hashcode += key[i] * base;
                base = base * p;
                hashcode = hashcode%numBuckets;
                base = base%numBuckets;
           }
           return hashcode%numBuckets;
       }

       void rehash(){
          MapNode<V>** temp = buckets;
          buckets = new MapNode<V>*[2*numBuckets];
          for(int i=0;i<2*numBuckets;i++){
            buckets[i] = NULL;
          }
          int oldBucketSize = numBuckets;
          numBuckets *= 2;
          count = 0;

          for(int i=0;i<oldBucketSize;i++){
             MapNode<V>* head = temp[i];
             while(head!=NULL){
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head = head->next;
             }
          }

          for(int i=0;i<oldBucketSize;i++){
            delete temp[i];   /// linked list is deleted
          }
          delete []temp;    /// now temp array is deleted
       }
   public:
    mymap(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i] = NULL;
        }
    }
    ~mymap(){
       for(int i=0;i<numBuckets;i++){
        delete buckets[i];
       }
       delete []buckets;
    }

    int size(){
       return count;
    }

    V getValue(string key){
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
      while(head!=NULL){
        if(head->key == key){
            head->value = value;
            return;
        }
        head = head->next;
      }
      MapNode<V>* node = new MapNode<V>(key,value);
      node->next = buckets[bucketIndex];
      buckets[bucketIndex] = node;
      count++;
      double loadFactor = (1.0*count)/numBuckets;
      if(loadFactor > 0.7){
        rehash();
      }
    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head!=NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
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
        return 0;
    }

    double getLoadFactor(){
       return (1.0*count)/numBuckets;
    }
};
int main(){

    mymap<int> ourmap;
    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        ourmap.insert(key,value);
        cout<<ourmap.getLoadFactor()<<endl;
    }
    cout<<ourmap.size()<<endl;

    ourmap.remove("abc1");  /// iski value 0 ho jaygi
    ourmap.remove("abc6");  /// iski value 0 ho jaygi

    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout<<key<<" "<<ourmap.getValue(key)<<endl;
        cout<<ourmap.getLoadFactor()<<endl;
    }
     cout<<ourmap.size()<<endl;
  return 0;
}
