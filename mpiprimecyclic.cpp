#include <mpi.h>
#include <time.h>
#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <math.h>
using namespace std;

int isprime (int x)
{
	for (int i=2; i<=sqrt(x); i++)
		if (x%i == 0)
			return false;
	return true ;
}

int main(int argc, char **argv) 
{
	if (argc != 2) 
	{	cout<<" You Need to Pass 1 Parameteres number: n "<<endl;
        return 0;
    }
	cout<<endl;
	int my_rank,comm_sz;
 
	MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	
	unsigned long int n;
	n = atof(argv[1]);
	
	cout <<"Process " << my_rank << ": ";
	clock_t Start = clock();
	for (unsigned long int i=(2*my_rank+3); i<=n ; i+=2*comm_sz)
		if ( isprime (i) )
			cout<<i<<" ";
	clock_t Finish = clock();
	cout << "\t ,Elapsed Time = " << float(Finish-Start)/CLOCKS_PER_SEC << endl;
	

	MPI_Finalize();
	cout<<endl;
	return 0;
}
