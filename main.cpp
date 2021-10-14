#include <iostream>

#include "Header.h"

bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid data!\n";
        return false;
    }
    else
    {
        if (std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid data!\n";
            return false;
        }
    }

    return true;
}

int castFishingRod()
{
	int numberOfSector;

	while (true)
	{
		std::cout << "\n\nThe number of the sector where the fishing rod is thrown: ";
		
		std::cin >> numberOfSector;

		if (!cinNoFail()) continue;

		return numberOfSector;
	}
}


int main()
{
	Pond pond;
	pond.output();

	std::cout << "\nThe pond is divided into 9 sectors.\n";
	std::cout << "There is 1 fish in the pond and there are 3 boots.";

	int numberOfFishingRodCasts{};

	while (true)
	{
		int numberOfSector = castFishingRod();

		try
		{
			++numberOfFishingRodCasts;
			pond.pullFishingRod(numberOfSector);

			std::cout << "You didn't pull anything out";
		}
		catch (const ExceptionInvalidSectorNumber& e)
		{
			std::cout << e.what();
			std::cout << ". Your fishing rod got tangled in the reeds!";
			continue;
		}
		catch (const ExceptionCaughtBoot& e)
		{
			std::cout << e.what();
			std::cout << ". You've lost!";
			break;
		}
		catch (const ExceptionCaughtFish& e)
		{
			std::cout << e.what();
			std::cout << ". You have won!";
			break;
		}
	}

	std::cout << "\nNumber of fishing rod casts: " << numberOfFishingRodCasts;
	pond.output();
}