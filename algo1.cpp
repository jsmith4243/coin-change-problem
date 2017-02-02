//running the program without file parameter requires inputting the array and A value in the code
//	the program keeps track of running time when run in this manner
//
//running the file with file parameter requires the array to be in the format [ 1 , 2 , 3, 4 ] to work with //streams



#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
 
                //answerCoins[i] = coins[i];
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
                
                answerCoins[i] = answerCoins[i] + 1;
                
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
    
    if (argc == 2)
    {
   
   
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
                
                cout << "A is : \n" << A;
                
            }
            
            
        }
        
        int answerCoins[m]; //array for the denominations that were used
        
        for(int i = 0; i < m; i++)
        {
        
        	answerCoins[i] = 0;
        
        }
        
        
        cout << "m is: " << m << endl;
        
        cout << "A is: " << A << endl;
        
        file.close();
        
        int mincoins = divconquerFile(coins, m, A, answerCoins);
        

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
        

        
        filetosave << "Array of denominations used is: " << endl;
        
        for (int i = 0; i < m; i++)
        {
        
        	filetosave << answerCoins[i] << " ";
        	
        }
        
        filetosave << endl;

        
        filetosave << "Min number of coins: " << mincoins << endl;
        
        
        
        
        cout << "array of denominations used is: " << endl;
        for (int i = 0; i < m; i++)
        {
        	cout << answerCoins[i] << " ";
        }
        
        cout << endl;
        
        cout << "Min number of coins: " << mincoins << endl;
        
        
        filetosave.close();
        
        
        return 0;
        
    }
    
    
    
    

    
    int answerCoins[m]; //array for the denominations that were used
      
	for (int i = 0; i < m; i++)
	{
		answerCoins[i] = 0;
	}
    
    
    
    
    
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








