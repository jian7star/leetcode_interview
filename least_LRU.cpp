#include<vector>
#include<iostream>
using namespace std;
struct node{
    int val, key, fre;
};
class LRUCache {
public:
    int capacity;
    int used=0;
    vector<node> v;
public:
    LRUCache(int capacity):capacity(capacity){
    }
    
    int get(int key) {
        for(auto &val:v){
            if(val.key==key){
                val.fre=++used;
                return val.val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        vector<node>::iterator least=v.begin();
        for(auto it=v.begin();it<v.end();it++){
                if(it->key==key){
                    it->val=value;
                    it->fre=++used;
                    return;
                }
            }
        if(v.size()==capacity){
            int min_used=0;
            for(auto it=v.begin();it<v.end();it++)
            {
                if(used-it->fre>min_used){
                    min_used=used-it->fre;
                    least=it;
                }
            }
            v.erase(least);
            node newval;
            newval.key=key;
            newval.val=value;
            newval.fre=++used;
            v.push_back(newval);
        }else{
            node newval;
            newval.key=key;
            newval.val=value;
            newval.fre=++used;
            v.push_back(newval);
        }
        print();
        
    }
    void print(){
        for(const auto& val: v){
            cout<<val.key<<' '<<val.val<<endl;
        }
    }
};
int main()
{
    LRUCache lru(2);
    cout<<lru.get(2)<<endl;
    lru.put(2,6);
    cout<<lru.get(1)<<endl;
    lru.put(1,5);
    lru.put(1,2);
    cout<<lru.get(1)<<endl;
    cout<<lru.get(2)<<endl;


}