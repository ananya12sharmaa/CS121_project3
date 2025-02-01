#include <iostream>
#include <random>

const int raceLen= 15;
const int hn = 5;

void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

void advance(int horseNum, int *horses)
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, 1);

	int coin = dist(rd);
    
    	// If the coin lands on heads, move the horse forward
    	if (coin == 1)
	{
        	horses[horseNum]++;
    	}	

}


void printLane(int horseNum, int *horses)
{
        for(int position=0; position<=raceLen; ++position )
        {
                if(horses[horseNum]==position)
                {
                        std::cout << horseNum;
                }
                else
                {
                        std::cout << ".";
                }
        }
        std::cout << std::endl;
}

bool isWinner(int horseNum, int *horses)
{
        bool winner = false;
        if(horses[horseNum]>= raceLen)
        {
                std::cout << "Our Horse " << horseNum << " WINS!!" << std::endl;
                winner = true;
        }
        return winner;

}

int main()
{
        int horses[5]={0,0,0,0,0};

        for(int i=0; i <hn; ++i)
        {
                printLane(i,horses);
        }
        std::cout << "LET THE HORSE RACE BEGINNN!!" <<std::endl;
        bool check=true;
        while(check)
        {
                for(int i=0; i <hn; ++i)
                {
			advance(i,horses);
			printLane(i,horses);
		}
		for(int i=0; i<5; ++i)
		{
			if(isWinner(i, horses))
			{
				check=false;
			}
		}
		if(check)
		{
			std::cout << "Press enter for another turn" << std::endl;
			std::cin.get();
		}
	}
	return 0;
}
