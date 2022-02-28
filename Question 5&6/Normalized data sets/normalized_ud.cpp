#include<bits/stdc++.h>
using namespace std;
int NO_OF_LINE = 100;
const int MAX = 100;

int main(){
    
    //FILE *fin = fopen("uniform_dist.csv","r");
    ifstream infile;
    infile.open("uniform_dist.csv");
    ofstream outfile("normalised uniform dist.txt");
    //FILE *fout = fopen("normalised uniform dist.txt","w");
    int data ;
    long long i = 0;
    infile >> data;
    NO_OF_LINE = data;
    outfile << NO_OF_LINE << endl;
    while(!infile.eof()){
        i++;
        infile >> data;
        outfile << fixed << setprecision(2) << ((float)data / MAX) << endl;
        cout << "\r" << fixed << setprecision(2) << ((float)i)/NO_OF_LINE * 100 << "% done" ;
    }
    cout << endl;

    infile.close();
    outfile.close();
    return 0;

}