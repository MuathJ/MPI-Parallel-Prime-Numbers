# MPI Parallel Prime Numbers

Find the prime numbers between 1 up to some integer N (N is given as input).

-------------------------------

primenum.cpp
-
make prime

Serial program that takes integer n as an argument (ex: 100) and prints all prime numbers up to n by checking all divisors and prints the estimated execution  time, and because all prime numbers are odd except 2, there is no need to check even numbers at all which will increase the performence.

	 For numbers 2 to n=100, Prime Numbers are: 
	 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
	 
	 Elapsed Time = 1.1e-05

-------------------------------

mpiprim.cpp	
-
make mpiprime

From the previous code "primenum.cpp", I converted it from a serial program to
MPI program where the prime numbers up to n are distributed across a custom
number of process in an even blocks fashion, 
(ex: n=100 p=4  ,  1-25 // 26-50 // 51-75 // 76-100).

	Process 0: 3 5 7 11 13 17 19 23  ,Elapsed Time = 2.2e-05
	Process 1: 29 31 37 41 43 47 		 ,Elapsed Time = 6e-06
	Process 2: 53 59 61 67 71 73 		 ,Elapsed Time = 2.3e-05
	Process 3: 79 83 89 97 		 		   ,Elapsed Time = 6e-06

-------------------------------

mpiprimecyclic.cpp
-
make mpicyc

From the previous code "mpiprim.cpp", I edited the for-loop section, 
now the prime numbers up to n are distributed in a cyclic fashion 
instead of even blocks, this method allows the processes to get approx
the same amount of small and large numbers which fixes the load imbalance
that was present in the previous code.

	Process 0: 3 11 19 43 59 67 83  ,Elapsed Time = 6e-06
	Process 1: 5 13 29 37 53 61 	  ,Elapsed Time = 4e-06
	Process 2: 7 23 31 47 71 79 	  ,Elapsed Time = 4e-06
	Process 3: 17 41 73 89 97 	 	  ,Elapsed Time = 4e-06


-------------------------------
