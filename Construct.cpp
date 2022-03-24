//动态规划训练

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

/** 嵌套结构体arrayMap **/
typedef struct Str{
    string str[100];
    int length=0;
}Str;
typedef struct arrayStr{
    struct Str array[100];
    int length=0;
}arrayStr;
typedef struct arrayMap{
    struct arrayStr aS;
}arrayMap;

bool canConstruct(string target,string array[],int length,map<string,bool> &memo);
int countConstruct(string target,string array[],int length,map<string,int> &memo);
void allConstruct(string target,string elem[],map<string,arrayMap> &m,int length);


int main() {
/** canConstruct **/
//    string target="abcdef";
//    string array[]={"ab","abc","cd","def","abcd"};
//    string target="skateboard";
//    string array[]={"bo","rd","ate","t","ska","sk","boar"};
//    string target="enterapotentpot";
//    string array[]={"a","p","ent","enter","ot","o","t"};
//    string target="eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
//    string array[]={"e","ee","eee","eeee","eeeee","eeeeee"};
//    map<string,bool> memo;
//    int length=sizeof(array)/sizeof(array[0]);
//    cout<<canConstruct(target,array,length,memo);

/** countConstruct **/
////    string target="purple";
////    string array[]={"purp","p","ur","le","purpl"};
////    string target="abcdef";
////    string array[]={"ab","abc","cd","def","abcd"};
////    string target="enterapotentpot";
////    string array[]={"a","p","ent","enter","ot","o","t"};
//    string target="eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
//    string array[]={"e","ee","eee","eeee","eeeee","eeeeee"};
//    map<string,int> memo;
//    int length=sizeof(array)/sizeof(array[0]);
//    cout<<countConstruct(target,array,length,memo);

/** allConstruct_byTable **/
    string target="abcdef";
    string elem[]={"ab","abc","cd","def","abcd","ef","c"};
//    string target="purple";
//    string elem[]={"purp","p","ur","le","purpl"};
//    string target="skateboard";
//    string elem[]={"bo","rd","ate","t","ska","boar"};
    int length=sizeof(elem)/sizeof(elem[0]);
    string str="";
    arrayMap a;
    map<string,arrayMap> m;
    for(int i=0;i<target.length()+1;i++){
        if(i==0) m.insert(pair<string,arrayMap>("[]",a));
        else{
            str=str+target[i-1];
            m.insert(pair<string,arrayMap>(str,a));
        }
    }
    allConstruct(target,elem,m,length);

}

bool canConstruct(string target,string array[],int length,map<string,bool> &memo){
    map<string,bool> ::iterator find;
    if(target=="") return true;
    if((find=memo.find(target))!=memo.end()) return find->second;
    for(int i=0;i<length;i++){
        if(target.find(array[i])==0){
            string str=target.substr(array[i].length());
            if(canConstruct(str,array,length,memo)==true) {
                memo.insert(pair<string,bool>(target, true));
                return true;
            }
        }
    }
    memo.insert(pair<string,bool>(target,false));
    return false;
}

int countConstruct(string target,string array[],int length,map<string,int> &memo){
    map<string,int> ::iterator find;
    if(target=="") return 1;
    if((find=memo.find(target))!=memo.end()) return find->second;
    int totalNum = 0;
    for(int i=0;i<length;i++){
        if(target.find(array[i])==0){
            string str=target.substr(array[i].length());
            totalNum+=countConstruct(str,array,length,memo);
            memo.insert(pair<string,int>(target, totalNum));
        }
    }
    memo.insert(pair<string,int>(target, totalNum));
    return totalNum;
}

void allConstruct(string target,string elem[],map<string,arrayMap> &m,int length){
//    length; //7
//    target.length()+1; //7
    map<string,arrayMap> ::iterator it;
    map<string,arrayMap> ::iterator itEnd;
    map<string,arrayMap> ::iterator find;
    it=m.begin();
    itEnd=m.end();
    int i=0;
    while(it!=itEnd){
        if(i==0){
            for(int j=0;j<length;j++){
                map<string,arrayMap> ::iterator find;
                if(target.find(elem[j])==0){ //elem[j]=ab,abc,abcd
                    if((find=m.find(elem[j]))!=m.end()){
                        find->second.aS.array[find->second.aS.length].str[find->second.aS.array[find->second.aS.length].length]=elem[j];
                        find->second.aS.array[find->second.aS.length].length++; //内部数组长度+1
                        find->second.aS.length++; //外部数组长度+1 注意：必须先内部再外部
                    }
                }
            }
        }
        else{
            if(it->second.aS.length!=0){
                string str=target.substr(it->first.length());
                for(int j=0;j<length;j++){
                    map<string,arrayMap> ::iterator find;
                    if(str.find(elem[j])==0){
                        string new_str=it->first+elem[j];
                        if((find=m.find(new_str))!=m.end()){
                            int len0=it->second.aS.length;
                            for(int p=0;p<len0;p++){
                                int l=it->second.aS.array[p].length;
                                for(int q=0;q<l;q++){
                                    find->second.aS.array[find->second.aS.length].str[q]=it->second.aS.array[p].str[q];
                                }
                                find->second.aS.array[find->second.aS.length].str[l]=elem[j];
                                find->second.aS.array[find->second.aS.length++].length=l+1;
                            }
                        }
                    }
                }
            }
        }
        it++;
        i++;
    }
    if((find=m.find(target))!=m.end()){
        int len1=find->second.aS.length; //len1=4
        if(len1!=0){
            for(int i=0;i<len1;i++){
                cout<<"[";
                int len2=find->second.aS.array[i].length;
                for(int j=0;j<len2;j++){
                    cout<<find->second.aS.array[i].str[j];
                    if(j+1<len2) cout<<" ";
                }
                cout<<"]"<<endl;
            }
        }
        else cout<<"[]";
    }
}


