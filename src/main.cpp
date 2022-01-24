#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define fs first
#define sc second

const int numColor=6;
int m=1;
int n=0;
int k=0;
long long cnt=0;
string colors[7]={NORMAL,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN};
vector<vector<pair<char,int>>>puzzle;
vector<string>word;

void printColor(string color,char text){
    cout<<color<<text;
    cout<<NORMAL;
}

void inputFile(string path)
{
    ifstream in(path);

    string s;
    getline(in,s);

    int strsize=s.size();

    for(int i=0;i<strsize;i++){
        if(s[i]==' ')m++;
    }

    while(s!=""){
        n++;
        getline(in,s);
    }

    while(getline(in,s)){
        k++;
    }

    in.close();

    freopen(path.c_str(), "r", stdin);

    puzzle.resize(n);
    word.resize(k);

    for(int i=0;i<n;i++){
        puzzle[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>puzzle[i][j].fs;
        }
    }
    
    for(int i=0;i<k;i++){
        cin>>word[i];
    }
}

void getResult(){
    int curColor=1;
    for(string s:word){
        int len=s.size();
        bool found=false;
        for(int i=0;i<n;i++){
            if(found)break;
            for(int j=0;j<m;j++){
                if(i+1>=len){
                    int it=0;
                    while(it<len-1 && s[it]==puzzle[i-it][j].fs){
                        it++;
                    }
                    if(s[it]==puzzle[i-it][j].fs){
                        found=true;
                        for(it=0;it<len;it++){
                            if(puzzle[i-it][j].sc)continue;
                            puzzle[i-it][j].sc=curColor;
                        }
                        curColor=(curColor%numColor)+1;
                        cnt+=it+2;
                        break;
                    }
                    cnt+=it+2;
                }
                if(n-i>=len){
                    int it=0;
                    while(it<len-1 && s[it]==puzzle[i+it][j].fs){
                        it++;
                    }
                    if(s[it]==puzzle[i+it][j].fs){
                        found=true;
                        for(it=0;it<len;it++){
                            if(puzzle[i+it][j].sc)continue;
                            puzzle[i+it][j].sc=curColor;
                        }
                        curColor=(curColor%numColor)+1;
                        cnt+=it+2;
                        break;
                    }
                    cnt+=it+2;
                }
                if(j+1>=len){
                    int it=0;
                    while(it<len-1 && s[it]==puzzle[i][j-it].fs){
                        it++;
                    }
                    if(s[it]==puzzle[i][j-it].fs){
                        found=true;
                        for(it=0;it<len;it++){
                            if(puzzle[i][j-it].sc)continue;
                            puzzle[i][j-it].sc=curColor;
                        }
                        curColor=(curColor%numColor)+1;
                        cnt+=it+2;
                        break;
                    }
                    cnt+=it+2;
                }
                if(m-j>=len){
                    int it=0;
                    while(it<len-1 && s[it]==puzzle[i][j+it].fs){
                        it++;
                    }
                    if(s[it]==puzzle[i][j+it].fs){
                        found=true;
                        for(it=0;it<len;it++){
                            if(puzzle[i][j+it].sc)continue;
                            puzzle[i][j+it].sc=curColor;
                        }
                        curColor=(curColor%numColor)+1;
                        cnt+=it+2;
                        break;
                    }
                    cnt+=it+2;
                }
                if(i+1>=len && j+1>=len){
                    int it=0;
                    while(it<len-1 && s[it]==puzzle[i-it][j-it].fs){
                        it++;
                    }
                    if(s[it]==puzzle[i-it][j-it].fs){
                        found=true;
                        for(it=0;it<len;it++){
                            if(puzzle[i-it][j-it].sc)continue;
                            puzzle[i-it][j-it].sc=curColor;
                        }
                        curColor=(curColor%numColor)+1;
                        cnt+=it+2;
                        break;
                    }
                    cnt+=it+2;
                }
                if(n-i>=len && m-j>=len){
                    int it=0;
                    while(it<len-1 && s[it]==puzzle[i+it][j+it].fs){
                        it++;
                    }
                    if(s[it]==puzzle[i+it][j+it].fs){
                        found=true;
                        for(it=0;it<len;it++){
                            if(puzzle[i+it][j+it].sc)continue;
                            puzzle[i+it][j+it].sc=curColor;
                        }
                        curColor=(curColor%numColor)+1;
                        cnt+=it+2;
                        break;
                    }
                    cnt+=it+2;
                }
                if(i+1>=len && m-j>=len){
                    int it=0;
                    while(it<len-1 && s[it]==puzzle[i-it][j+it].fs){
                        it++;
                    }
                    if(s[it]==puzzle[i-it][j+it].fs){
                        found=true;
                        for(it=0;it<len;it++){
                            if(puzzle[i-it][j+it].sc)continue;
                            puzzle[i-it][j+it].sc=curColor;
                        }
                        curColor=(curColor%numColor)+1;
                        cnt+=it+2;
                        break;
                    }
                    cnt+=it+2;
                }
                if(j+1>=len && n-i>=len){
                    int it=0;
                    while(it<len-1 && s[it]==puzzle[i+it][j-it].fs){
                        it++;
                    }
                    if(s[it]==puzzle[i+it][j-it].fs){
                        found=true;
                        for(it=0;it<len;it++){
                            if(puzzle[i+it][j-it].sc)continue;
                            puzzle[i+it][j-it].sc=curColor;
                        }
                        curColor=(curColor%numColor)+1;
                        cnt+=it+2;
                        break;
                    }
                    cnt+=it+2;
                }
            }
        }
    }
}

void printResult(){
    cout<<"Hasil pencarian :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printColor(colors[puzzle[i][j].sc],puzzle[i][j].fs);
            cout<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cout<<"=================="<<endl;
    cout<<"WORD SEARCH PUZZLE"<<endl;
    cout<<"=================="<<endl;
    cout<<"Masukkan nama file : ";
    string file;
    cin>>file;
    inputFile("test/"+file);
    auto start=high_resolution_clock::now();
    getResult();
    printResult();
    auto stop=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double durationMicro=duration.count();
    cout<<fixed;
    cout<<setprecision(3);
    if(durationMicro>=1e6){
        cout<<"Waktu eksekusi : "<<durationMicro/1e6<<" second";
    }else if(durationMicro>=1e3){
        cout<<"Waktu eksekusi : "<<durationMicro/1e3<<" milisecond";
    }else{
        cout<<"Waktu eksekusi : "<<durationMicro<<" microsecond";
    }
    cout<<endl;
    cout<<"Total perbandingan : "<<cnt<<" kali"<<endl;
    return 0;
}
