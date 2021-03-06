#include <bits/stdc++.h>
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include "db.h"   
#include "leveldb/filter_policy.h"

#define MAXN 112345
#define Million 1000000
//#define CHECK_INPUT

using namespace std;

char st[MAXN];

void dbDelete(string key) {
    struct timespec ts;
    //clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    double last_time_ = static_cast<int64_t>(ts.tv_sec) * 1000000000Lu + static_cast<int64_t>(ts.tv_nsec);
    

    double current_time_ = static_cast<int64_t>(ts.tv_sec) * 1000000000Lu + static_cast<int64_t>(ts.tv_nsec);
    double latency = current_time_ - last_time_;

    // handle latency for delete
    
}

void dbRead(string key) {
    
}

void dbPut(string key, string value) {
}

void dbInsert(string key, string value) {
    
  
}

//#define CHECK_INPUT
ifstream infile;




int main( ) {
   
    
    leveldb::Options options;
    options.block_cache = NULL;
    options.filter_policy = leveldb::NewBloomFilterPolicy(4);
    options.create_if_missing = true;
    options.max_open_files = 50000;
    leveldb::DB* db;
    std::string dbpath = "tdb";   
    leveldb::Status status = leveldb::DB::Open(options, dbpath, &db);   
    leveldb::Status s ;  
    assert(status.ok());   
    printf("Open db OK\n");  
    
    struct timeval tvmain;
    double t_start, t_end, t_duration;
    time_t t;
    
    infile.open("../../dataset/load.txt");
    //FILE *fp = fopen("load", "r");
    
    string str,val;
    

    
    int count = 0;
    
    while (getline(infile, str)  ) {
       
        
        int pos = str.find(' ');
        string operation = str.substr(0, pos);
        str.erase(0, pos + 1);
        if (operation == "delete") {
           
	    s = db->Delete(leveldb::WriteOptions(),str);
	    
#ifdef CHECK_INPUT
            cout << str << endl;
#endif
        } else if (operation == "read") {
           
	   s = db->Get(leveldb::ReadOptions (), str, &val);  
	  
#ifdef CHECK_INPUT
            cout << str << " " << val << endl;
#endif
        } else {
            pos = str.find(' ');
            string key = str.substr(0, pos);
            str.erase(0, pos + 1);
            if (operation == "put") {
                s = db->Put(leveldb::WriteOptions(), key,str); 
            } else {
                s = db->Put(leveldb::WriteOptions(), key,str); 
            }
            
#ifdef CHECK_INPUT
            cout << key << " " << str << endl;
#endif
        }
        
        count ++;
	
    }
    
    infile.close();
    
    
    
    
    //db->Summary();
    
    
    //system("cp tdb/LOG ../../log"); 
    
    
    delete db;
    
    return 0;
}
