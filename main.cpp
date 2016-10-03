#include <iostream>
#include <fstream>
#include <cstdlib>

void createData(){
    double D = 1;
    
    int nt = 100;
    int nx = 10;
    
    double xmin = 0;
    double xmax = 1;
    
    double tmin = 0;
    double tmax = 1;
 
    double dt = (tmax-tmin)/nt;
    double dx = (xmax-xmin)/nx;
    
	double sol[nt][nx];

    // init sol
    for (int t=0; t<nt; t++){
        for (int x=0; x<nx; x++){
            sol[t][x] = 0;
        }
    }
    
    // initial value
    for (int x=0; x<nx; x++){
        sol[0][x] = (x*x)/2;
    }
    
    // boundary value
    for (int t=0; t<nt; t++){
        sol[t][0] = D*t + (1/2);
        sol[t][nx-1] = D*t;
    }
    
    
    for (int t=0; t<nt-1; t++){
        for (int x=1; x<nx-1; x++){
            sol[t+1][x] = D * ( dt/(dx*dx) ) * (sol[t][x+1] - 2*sol[t][x] + sol[t][x-1]) + sol[t][x];
        }
    }
    
    // have to transpose the data for gnuplot
    std::ofstream myfile;
    myfile.open("../results.dat");
    
    if (myfile.is_open()){
        for (int x=0; x<nx; x++){
            myfile << sol[0][x];
            for (int t=1; t<nt; t++){
                myfile << ","<< sol[t][x];
            }
            myfile << "\n";
        }
        myfile.close();
        
    } else {
        std::cerr << "Unable to open file";
    }
    
    return;
}

void testGnu(){
    std::system("dir");
    return;
}


int main(int argc, char **argv){
    testGnu();
    
    
	return 0;
}
