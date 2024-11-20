#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

#define Tam_cache 32
#define Tam_TLB 8
#define Tam_MV 32
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

void Preenchimento_MV(int a){
    srand(time(NULL));

    for(int i = a; i < Tam_MV; i++){
        stringstream ss;
        ss << setw(3) << setfill('0') << uppercase << hex << rand()%Tam_MS;
        MV[i] = "0vx" + ss.str();
    }
}



void Visu_mf(){
    
    
    cout << "Cache: " << endl;
    for(int i = 0; i < Tam_cache; i++){
        cout << i << ": " << Cache[i] << endl;
    }
    cout << "MP: " << endl;
    for(int i = Tam_cache; i < Tam_MP; i++){
        cout << i << ": "  << MP[i] << endl;
    }
    cout << "MS: " << endl;
    for(int i = Tam_MP; i < 3840; i++){
        cout << i << ": "<< MS[i] << endl;
    }
}

void Visu_MV(){
    char Paginas;
    cout << "Deseja ver todas as paginas da MV?" << endl;
    cin >> Paginas;
    if(Paginas == 'S' || Paginas == 's'){
        for(int i = 0; i < 4; i++){
            cout << "<<=== PAGINA " << i+1 << " ===>>" << endl << endl;
            for(int j = 8*i; j < 8*(i+1); j++){
                cout << j%8 << ": " << MV[j] << endl;
            }
            cout << endl;
        }
    }
    else{
        int Pg;
        cout << "Qual pagina deseja acessar? (1 a 4)" << endl;
        cin >> Pg;
        cout << endl << "<<=== PAGINA " << Pg << " ===>>" << endl << endl;
            for(int j = 8*Pg-1; j < 8*Pg; j++){
                cout << j%8 << ": " << MV[j] << endl;
            }
            cout << endl;
    }

}

void MV_to_mf(){
    int Pagina, indice;
    cout << "Selecione a pagina e o indice do endereco que voce deseja achar na memoria fisica" << endl;
    cout << "Pagina(1 a 4): ";
    cin >> Pagina;
    cout << endl << "Indice(0 a 7): ";
    cin >> indice;
    cout << endl;
    
    

}

void Verifica_MV(){

}


int main(){

    start_Cache();
    start_MP();
    start_MS();

   int a = 0;
   string End_MV;
   cout << "Insira os enderecos a serem gravados na MV (Quando estiver satisfeito digite N)" << endl;
   while (cin >> End_MV && End_MV != "N" && End_MV != "n" && a < Tam_MV){
        MV[a] = "v0x" + End_MV;
        a++;
   }
   Preenchimento_MV(a);

   int operacao;
   cout << "O que deseja que o programa faca agora?" << endl   
        << "1 - Visualizar da memoria fisica" << endl
        << "2 - Visializar da Memoria Virtual" << endl
        << "3 - Traduzir de MV para memoria fisica" << endl
        << "4 - Verificar se um endereco fisico esta na MV" << endl
        << "0 - Encerrar o programa" << endl;
    
    while (cin >> operacao && operacao != 0){
        
        if(operacao == 1){
            cout << "Essa opcao mostra todos os enderecos da memoria fisica (4096 enderecos), digite 'S' para confirmar" << endl;
            char Certificacao;
            cin >> Certificacao;
            if(Certificacao == 'S' || Certificacao == 's')
                Visu_mf();
        }
        if(operacao == 2)
            Visu_MV();
        if(operacao == 3)
            MV_to_mf();
        if(operacao == 4)
            Verifica_MV();
        if(operacao != 1 && operacao != 2 && operacao != 3 && operacao != 4) {
            cout << "Instrucao invalida, por favor insira um numero dos listados acima" << endl;
        }
    }

    return 0;
    
}
