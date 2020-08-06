#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <math.h>
using namespace std;

int isprime (int x)
{
	for (int i=2; i<=sqrt(x); i++)
		if ( x%i == 0 )
			return false;
	return true ;
}

int main(int argc, char **argv) 
{
	if (argc != 2) 
	{	cout<<" You Need to Pass 1 Parameteres number: n "<<endl;
        return 0;
    }
	
	unsigned long int n;
	n = atof(argv[1]);
	
    cout<<endl<<"-------------------------------------";
	cout<<endl<<" For numbers 2 to n="<<n<<", Prime Numbers are: "<<endl;
	clock_t Start = clock();
	if (n>=2)
		cout<<" 2 ";
	
	for (unsigned long int i=3 ; i<=n ; i+=2)
		if ( isprime (i) )
			cout<<i<<" ";
	clock_t Finish = clock();
	cout << "\n\n Elapsed Time = " << float(Finish-Start)/CLOCKS_PER_SEC << endl;
	
	cout<<endl<<endl;
	return 0;
}
