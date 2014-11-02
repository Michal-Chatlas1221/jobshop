#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct step {
    int machineNumber;
    int requiredTime;
};

struct instance {
    int machines, jobs;
    step** data;
};

instance getInstance(int InstanceNumber) {

    ifstream input("test.txt", ios::in);
    instance data;
    string line;
    int i = 0;
    int nr = 0;

    while(true) {
        getline(input, line);

        if(line.length() < 10) {
            i++; //żeby pętla smigała jak trzeba
            if(i == 2) break;

            //pobranie rozmiarów instancji
            line.erase(0,1);
            string jobs = line.substr(0, line.find(';'));
            data.jobs = atoi(jobs.c_str());
            data.machines = atoi(line.substr(line.find(';')+1).c_str());

            //deklaracja tablicy data
            data.data = (step**) malloc (data.jobs*sizeof(*data.data));
            for (int i=0; i<data.jobs;i++){
                data.data[i]= (step*) malloc(data.machines*sizeof(data.data));
            }
        }
        else {
            line.erase(0, 1);
            int pos = 0;
            for(int n = 0; n < data.machines; n++) {
                pos = line.find(';');
                data.data[nr][n].machineNumber = atoi(line.substr(0, pos).c_str());
                cout<<data.data[nr][n].machineNumber<<" ";
                line.erase(0, pos+1);
                pos = line.find(';');
                data.data[nr][n].requiredTime = atoi(line.substr(0, pos).c_str());
                cout<<data.data[nr][n].requiredTime<<" ";
                line.erase(0, pos+1);
            }
        } cout<<endl;
    }

    return data;
}

int main()
{
    instance currentInstance;
    currentInstance = getInstance(1);
    currentInstance.data[9][10].machineNumber = 99129123;
    cout<<currentInstance.data[9][10].machineNumber;
}
