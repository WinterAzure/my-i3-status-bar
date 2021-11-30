#include <iostream>

#include "config.hxx"

using namespace std;

int main(int argc,char *argv[]){
    if (argc!=1){
        cerr<<"Please directly run.\n"<<endl;
        exit(EXIT_FAILURE);
    }
    stringstream output;
    while (1){
        for (auto i:modules){
            output<<i();
        }
        cout<<output.str()<<endl;
        sleep(5);
        output.str("");
    }
}