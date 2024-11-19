#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define Tam_cache 32
#define Tam_TLB 4
#define Tam_MV 16
#define Tam_MP 256
#define Tam_MS 4096

string MS[Tam_MS-Tam_MP-Tam_cache], MP[Tam_MP-Tam_cache], Cache[Tam_cache], MV[Tam_MV], TLB[Tam_TLB];

void start_Cache(){
    for(int i = 0; i < Tam_cache; i++){
        stringstream ss;
        ss << setw(3) << setfill('0') << uppercase << hex << i;
        Cache[i] = "0ex" + ss.str();
    }
}

void start_MP(){
    for(int i = Tam_cache; i < Tam_MP; i++){
        stringstream ss;
        ss << setw(3) << setfill('0') << uppercase << hex << i;
        MP[i-Tam_cache] = "0ex" + ss.str();
    }
}

void start_MS(){
    for(int i = Tam_MP; i < Tam_MS; i++){
        stringstream ss;
        ss << setw(3) << setfill('0') << uppercase << hex << i;
        MS[i-Tam_MP] = "0ex" + ss.str();
    }
}

int main(){
    start_Cache();
    cout << "Cache: " << endl;
    for(int i = 0; i < Tam_cache; i++){
        cout << Cache[i] << endl;
    }

    
    start_MP();
    cout << "MP: " << endl;
    for(int i = 0; i < Tam_MP-Tam_cache; i++){
        cout << MP[i] << endl;
    }

    start_MS();
    cout << "MS: " << endl;
    for(int i = 0; i < Tam_MS-Tam_MP-Tam_cache; i++){
        cout << MS[i] << endl;
    }
    
}