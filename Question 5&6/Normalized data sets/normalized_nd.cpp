#include<bits/stdc++.h>
using namespace std;
int NO_OF_LINE = 10e6;
double MAX = INT_MIN * 1.0;

void max_val(int n){
    ifstream infile;
    infile.open("normal_dist.csv");
    double data = 0;
    int data1;
    infile >> data1;
    for (int i = 0; i < n; i++)
    {

        infile >> data;
        if (data > MAX)
        MAX = data;
    }

    infile.close();
}

int main(){
    
    //FILE *fin = fopen("uniform_dist.csv","r");
    ifstream infile;
    infile.open("normal_dist.csv");
    ofstream outfile("normalised normal dist.txt");
    //FILE *fout = fopen("normalised uniform dist.txt","w");
    double data;
    int data2;
    long long i = 0;
    infile >> data2;
    NO_OF_LINE = data2;
    max_val(NO_OF_LINE);
    outfile << NO_OF_LINE << endl;
    while(!infile.eof()){
        i++;
        infile >> data;
        outfile << fixed << setprecision(4) << ((float)data / MAX)  << endl;
        cout << "\r" << ((float)i)/NO_OF_LINE * 100 <<" % done" ;
    }
    cout << endl;
    cout << "MAXIMUM IS " << fixed << setprecision(4) << MAX << endl;

    infile.close();
    outfile.close();
    return 0;

}