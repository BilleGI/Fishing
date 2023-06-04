#include <iostream>
#include <vector>
#include <ctime>
#include <limits>
#include "fish.h"
#include "boot.h"
#include "bcaught.h"
#include "fcaught.h"

const int NUMBER_SECTIONS(9);

bool check_mean(std::vector<Field*>& pond, int& random)
{
    for(int i = 0; i < NUMBER_SECTIONS; ++i)
        if(pond[i] != nullptr && random == pond[i]->getNumber()) return false;
    return true;
}

void fill_pond(std::vector<Field*>& pond)
{
    for(int i = 0; i < NUMBER_SECTIONS;)
    {
        int random;
        random = rand()%NUMBER_SECTIONS;
        if(i == 0)
        {
            pond[random] = new Fish(random);
            i++;
        }
        else if((i > 0 && i <= 3) && check_mean(pond, random))
        {
            pond[random] = new Boot(random);
            i++;
        }
        else if(i > 3) i++;
    }
}

void myChoice(int& choice)
{
    for(int i = 0; i < 40; ++i) std::cout << "-";
    std::cout << "\nSelect a section: ";
    while(!(std::cin>>choice))
    {
        std::cout << "Enter the correct mean: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void fish(std::vector<Field*>& pond)
{
    while(true)
    {
        int choice;
        myChoice(choice);
        try
        {
            if(choice < 0 || choice >= NUMBER_SECTIONS) throw std::invalid_argument("choice");
            else if(dynamic_cast<Fish*>(pond[choice]) != nullptr) throw  FishCaught();
            else if(dynamic_cast<Boot*>(pond[choice]) != nullptr) throw BootCaught();
        }
        catch(const std::invalid_argument& x)
        {
            std::cerr << "Invalid argument: " << x.what() << std::endl;
        }
        catch(const FishCaught& x)
        {
            std::cerr << x.what() << std::endl;
            std::cerr << "Type fish: " << static_cast<Fish*> (pond[choice])->getType() << std::endl;
            break;
        }
        catch(const BootCaught& x)
        {
            std::cerr << x.what() << std::endl;
            break;
        }
        catch (...)
        {
            std::cerr << "Some king of exception has happend..." << std::endl;
        }
    }
}

int main()
{
    std::srand(std::time(nullptr));
    std::vector<Field*> pond(NUMBER_SECTIONS);
    std::cout << "Game - fishing." << std::endl;
    fill_pond(pond);
    fish(pond);
    return 0;
}

