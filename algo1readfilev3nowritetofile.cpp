//running the program without file parameter requires inputting the array and A value in the code
//	the program keeps track of running time when run in this manner
//
//run the program with a file parameter to get a result file with change.txt appended at the end




#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filehelper.cpp"
#include <climits>


using namespace std;


 int divconquer(int coins[], int m, int A, int answerCoins[])
 {
 

 
	if (A == 0)
	{
	
        return 0;
	
	}
	
	int res = INT_MAX;
	
	for (int i = 0; i < m; i++)
	{
        
        if (coins[i] <= A)
        {
        
       
            int result1 = divconquer(coins, m, A - coins[i], answerCoins);
 
            if (result1 != INT_MAX && result1 + 1 < res)
            {
            
            
            
                res = result1 + 1;
                
                
                //cout << "res was: " << res << endl;
                
                //cout << "result1 was: " << result1 << endl;
 
                answerCoins[i] = coins[i];
                //answerCoins[i] = answerCoins[i] + 1;
                
                /*
                for (int i = 0; i < m ; i++)
                {
                
                	if (coins[i]
                
                }
                */
                

 
            }
            
            //answerCoins[i] = answerCoins[i] + 1;
            
           
        }
        
        //answerCoins[i] = answerCoins[i] + 1;
         
    }
	
	return res;
 }
 



//vector version
int divconquerFile(std::vector<int> coins, int m, int A, int answerCoins[])
{
    
    if (A == 0)
    {
        
        return 0;
        
    }
    
    int res = INT_MAX;
    
    for (int i = 0; i < m; i++)
    {
        if (coins[i] <= A)
        {
            int result1 = divconquerFile(coins, m, A - coins[i], answerCoins);
            
            if (result1 != INT_MAX && result1 + 1 < res)
            {
                res = result1 + 1;
                
                //answerCoins[i] = answerCoins[i] + 1;
                answerCoins[i] = coins[i];
                
            }
        }
    }
    
    return res;
}



int main(int argc, char *argv[])
{


    
    time_t starttimer;
    
    time_t endtimer;
    
    time(&starttimer);
    
    //parameters for when use the version without file name parameter
    int coins[] = {1, 6, 13, 37, 150};
    
    int m = sizeof (coins) / sizeof(coins[0]); //number of items in coins[] array
    
    int A = 72; //the amount to make change for
    
    if (argc == 2) //if a file argument was input, run in file mode, use divconquerFile() instead of divconquer()
    {
    
    	
    
        int answerCoins[m]; //array for the denominations that were used
        
        for(int i = 0; i < m; i++)
        {
        
        	answerCoins[i] = 0;
        
        }
        
        
   
   
   		int coinmatrix[100][100] = {0};
   		int totals[100] = {0};
   		int sizes[100] = {0};
   		int trials;
   		
   		parseFile(argv[1],totals,sizes,trials,coinmatrix);
   		
   		
   		
   		
   		
   		
   		
        for (int j=0; j<trials ; j++){
            
            //p2.algorithm2(coinmatrix[j], sizes[j], totals[j]);
            
            
            std::vector<int> coinmatrixvector;
        	vector<int>::iterator coinmatrixvectoriterator;
            //put coinmatrix into a vector
             
            for (int i = 0; i < sizes[j]; i++)
            {
            
            	coinmatrixvector.push_back(coinmatrix[j][i]); //coinmatrix[j]
            	
            
            }
            
           
            // cout << "matrixvector is: " << coinmatrixvector[0] << " " << coinmatrixvector[1] << " " << coinmatrixvector[2] << " " << coinmatrixvector[3] << " "  << endl;
            //cout << "size is: " << sizes[j] << endl;
            //cout << "total is : " << totals[j] << endl;
            
            
            
            
            //int mincoins = divconquerFile(coins, m, A, answerCoins); //int divconquerFile(std::vector<int> coins, int m, int A, int answerCoins[])
            int mincoins = divconquerFile(coinmatrixvector, sizes[j], totals[j], answerCoins); //int divconquerFile(std::vector<int> coins, int m, int A, int answerCoins[])

            
            
            time(&endtimer);  // finish time
            cout << "Change slow algorithm: " << endl;
            std::cout<< "Minimum coins required is: " << mincoins << endl;;
    		time_t totaltime;
    
    		totaltime = (endtimer - starttimer);
    
    		int totaltimemillis = totaltime / 1000;
    
 
    
    		cout << "Time taken is: " << totaltime << endl;
            
            
            /*
            //print array
            std::cout << "[";
            for (int k=0; k<sizes[j]; k++){
                std::cout << coinmatrix[j][k];
                if (k != sizes[j]-1) std::cout << ", ";
            }
            std::cout << "]\n";
            */
            
            
            
            
            
            string newfilename;
            
            newfilename.append(argv[1]);
            
            newfilename.append("change.txt");
            
            //cout << "newfilename is: " << newfilename << endl;
            
            fstream filetosave;
            
            filetosave.open(newfilename.c_str(), fstream::out | fstream::app);
            //filetosave.open("savefile", fstream::in | fstream::out | fstream::app);
            
            if (filetosave.fail())
            {
                
                cout << "Output file opening failed.\n";
                
                exit(1);
                
                
                
            }
            
            filetosave << "\nChange Slow Algorithm: " << endl;
            
            
            filetosave << "Array of denominations used is: " << endl;
            
            for (int i = 0; i < sizes[j]; i++)
            {
                
                filetosave << answerCoins[i] << " ";
                
            }
            
            filetosave << endl;
            
            
            filetosave << "Min number of coins: " << mincoins << endl;
            
            
            
            
            cout << "array of denominationss used is: " << endl;
            for (int i = 0; i < sizes[j]; i++)
            {
                cout << answerCoins[i] << " ";
            }
            
            cout << endl;

            
            filetosave.close();
            
            
        }
   
        std::vector<int> coins;
   
        vector<int>::iterator p;
   
        A = 0;
        
        m = 0;
   
        fstream file;
        
        file.open(argv[1]);
        
        if (file.fail())
        {
            
            cout << "Input file opening failed.\n";
            
            exit(1);
            
        }
        
        
        string next;
        
        while (file >> next)
        {
            
            if ((next != "[") && (next != "]") && (next != ",") && (next != "\n"))
            {
      
                //coins.push_back(reinterpret_cast<int>(next));
                coins.push_back(atoi(next.c_str()));
                //coins.push_back(next);
                
                //cout << next << " ";
                
                m++;
                
                
            }
            
            if (next == "]")
            {
                
                file >> A;
                
            }
            
            
        }
        

        
        
        
        
        
        
        return 0;
        
    }
    
    
    
    

    
    int answerCoins[m]; //array for the denominations that were used
      
	for (int i = 0; i < m; i++)
	{
		answerCoins[i] = 0;
	}
    
    
    
    cout << "Change slow algorithm: " << endl;
   
    
    cout << "m is: " << m << endl;
    
    cout << "A is: " << A << endl;
    
    int mincoinsnonfile = divconquer(coins, m, A, answerCoins);
    
     

    
    
    
    /*
    for (p = coins.begin(); p != coins.end(); p++)
    {
        cout << *p << " ";
    }
     */
     

    /*
     for (int i = 0; i < m; i++)
     {
     
     cout << answerCoins[i] << endl;
     
     }
     */
     
    cout << "Denominations used are: " << endl;
    for (int i = 0 ; i < m; i++)
    {
    
    	cout << answerCoins[i] << " " ;
    
    }
    
    cout << endl;
     
    cout << "Min number of coins: " << mincoinsnonfile << endl;
    
    
    time(&endtimer);
    
    cout << "start time: " << starttimer << endl;
    
    cout << "end time: " << endtimer << endl;
    
    time_t totaltime;
    
    totaltime = (endtimer - starttimer);
    
    int totaltimemillis = totaltime / 1000;
    
 
    
    cout << "Time taken is: " << totaltime << endl;
    
    
    

    
    return 0;
    
    
}








