#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Bag{
    bool check=false;
    int value=0;
};

typedef struct Things{
    int value;
    int weight;
}T;

void CompletePack(T arrayThings[], Bag bag[], int volume, int num, int &maxNum);

int main() {
    int num, volume;
    cin>>num>>volume;
    T *arrayThings;
    arrayThings = new T[num+1]{};
    for(int i=0;i<num;i++){
        int weight, value;
        cin>>weight>>value;
        arrayThings[i].weight=weight;
        arrayThings[i].value=value;
    }
    Bag *bag;
    int maxNum=0;
    bag = new Bag[volume+1]{};
    CompletePack(arrayThings, bag, volume, num, maxNum);
    cout<<bag[volume].value;
}

void CompletePack(T arrayThings[], Bag bag[], int volume, int num, int &maxNum){
    for(int i=0;i<num;i++){
        for(int j=arrayThings[i].weight;j<=volume;j++){
            bag[j].value = max(bag[j].value, bag[j-arrayThings[i].weight].value + arrayThings[i].value);
        }
    }
}