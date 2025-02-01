/*Making a Horse Race game in C++
due Friday midnight 
made with  a previously developed algorithm and built and revised the algorithm and re-built and so on so forth.
*/

//importing the libraries

#include <iostream>
#include <random>

//creating constants that will be used throughout the program
const int raceLen= 15;
const int hn = 5;

//function prototypes
void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);


//advance function to move(or not move)the individual horses
void advance(int horseNum, int *horses)
{
	//randomly tossing the coint to decide if the horse moves or not
	//We know horses dont toss coins but that's what computers are here for us ;-)
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, 1);

	int coin = dist(rd);
    
    	// If the coin lands on heads, move the horse forward
    	if (coin == 1)
	{
        	horses[horseNum]++;//since arrays are pointers
    	}	

}//advance function ends



//to print the horses on track
void printLane(int horseNum, int *horses)
{
	//loop to print . at the race track length but where the horse number is
        for(int position=0; position<=raceLen; ++position )
        {
                if(horses[horseNum]==position)
                {
                        std::cout << horseNum;
                }//if block ends
                else
                {
                        std::cout << ".";
                }//else block ends
        }//loop ends
        std::cout << std::endl;//taking the control of cursor to the next line
}//printing function ends


//function the check if any horse won
bool isWinner(int horseNum, int *horses)
{
        bool winner = false;
        if(horses[horseNum]>= raceLen)
        {
                std::cout << "Our Horse " << horseNum << " WINS!!" << std::endl;
                winner = true;
        }
        return winner;

}//function ends


//our main function
int main()
{
	//initialising our array
        int horses[hn]={0,0,0,0,0};
	
	//to print the starting checkpoint of our horses
	

	std::cout << "Hi there! You are her to witness a crazy fun horse race between our Horses numbered 0,1,2,3,4! "<<  std::endl;
        for(int i=0; i <hn; ++i)
        {
                printLane(i,horses);
        }
        std::cout << "LET THE HORSE RACE BEGINNN!!" <<std::endl;

	
        bool check=true;
        while(check)
        {	
		//inner loop to check to update the move and move each horse
                for(int i=0; i <hn; ++i)
                {
			advance(i,horses);
			printLane(i,horses);
		}//for loop ends

		//another loop to check if any horse won, given there also could be tie
		for(int i=0; i<hn; ++i)
		{
			if(isWinner(i, horses))
			{
				check=false;
			}//block ends
		}//loop ends

		if(check)
		{
			std::cout << "Press enter for another turn" << std::endl;
			std::cin.get();
		}//to keep going
	}//outer loop ends

	//to ensure the program is successfully ran
	return 0;
}//main ends
