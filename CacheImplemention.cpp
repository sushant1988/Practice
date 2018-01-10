#include<iostream>
#include<unordered_map>

using namespace std;

class DBL {
    string Key;
    string Value;
    DBL *next;
    DBL *prev;
    public:
    DBL(string key, string value) {
        Key = key;
        Value = value;
        next = NULL:
        prev = NULL;
    }
};

/*
typedef struct DBLNode {
    string Key;
    string Value;
    DBL *next;
    DBL *prev;
}DBL;*/

class CacheImp {
    unordered_map<string, DBL*> Map;
    unordered_map<string, DBL*>::iterator it;
    DBL *DBLHead;
    DBL *DBLtail;

    void AddToDBL();
    void RemoveFromDBL();

    public:
    CacheImp();
    void Insert();
    DBL *Remove();
    DBL *Fetch();
    vector<DBL*> Dump();
};

CacheImp::CacheImp() {
    DBLHead = NULL;
    DBLtail = NULL:
}

void CacheImp::AddToDBL(string key, string value)
{
    if(DBLHead) {
        DBL *nw = new DBL(key, value);
        DBLTail->next = nw;
        nw->prev = DBLTail;
        DBLTail = nw;
    } else {
        DBLHead = new DBL(key, value);
        DBLTail = DBLHead;
    }
}