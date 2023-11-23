// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector> 

using namespace std;

const int SZ = 200;
class TableNode{
public:    
    int val , key;
    TableNode* next;
    TableNode(int key , int val){
        this->val= val;
        this->key = key;
        this->next = NULL;
    }
};

class HashTable{
    vector<TableNode*>table;
    
    public:
    
    HashTable(){
        table.resize(SZ);
        for(int  i = 0 ; i < SZ ;i++){
            table[i] = NULL;
        }
    }
    
    void insert(int key , int val){
        if(table[key%SZ] == NULL){
            table[key%SZ] = new TableNode(key , val);
        }else {
            TableNode* cur = table[key%SZ];
            while(cur->next!=NULL){
                cur = cur->next;
            }
            cur->next = new TableNode(key , val);
        }
    }
    
    int find(int key){
        TableNode* cur = table[key%SZ];
        while(cur!=NULL){
            if(cur->key == key) return cur->val; 
            cur = cur->next;
        }
        cout << "key not found" << endl;
        return -1;
    }
    
    void remove(int key){
        
        TableNode* dummy = new TableNode(-1 , -1);
        dummy->next = table[key%SZ];
        
        TableNode* prev = dummy;
        TableNode* cur = prev->next;
        
        while(cur!=NULL){
            if(cur->key == key){
                prev->next = cur->next;
                cout << "removed" <<endl; 
                table[key%SZ] = dummy->next;
                return ;
            }else {
                prev = cur;
                cur = cur->next;
            } 
        }
        cout << "key not found to remove" << endl;
    }
    
    
};

int main() {
    
    HashTable hash = HashTable();
    
    hash.insert(1 , 5);
    cout<<hash.find(1)<<endl;
    cout<<hash.find(201)<<endl;
    hash.insert(201 , 10) ;
    cout<<hash.find(201)<<endl;
    hash.remove(201);
    cout<<hash.find(201)<<endl;
    hash.remove(202);
    cout<<hash.find(202)<<endl;
    
    
    return 0;
}
