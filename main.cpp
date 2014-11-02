#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct instance {
    int machines, jobs;
    step* data;
};

instance getInstance(int InstanceNumber) {

    ifstream input("test.txt", ios::in);
    instance data;
    string line;
    int i = 0;

    while(true) {
        getline(input, line);

        if(line.length() < 10) {
            i++; //żeby pętla smigała jak trzeba
            if(i == 2) break;
            line.erase(0,1);
            string jobs = line.substr(0, line.find(';'));
            data.jobs = atoi(jobs.c_str());
            data.machines = atoi(line.substr(line.find(';')+1).c_str());
        }
    }

    return data;
}

int main()
{
    instance currentInstance;
    currentInstance = getInstance(1);
    cout<<currentInstance.jobs<<endl<<currentInstance.machines;
}
