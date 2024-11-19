#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    for(int i = 0; i < 4096; i++){
        cout << "0eX";
        cout << setw(3) << setfill('0')<< hex << uppercase << i << endl;
    }
}