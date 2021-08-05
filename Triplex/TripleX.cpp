#include <iostream>
#include <ctime>

//functions declaration
bool PlayGame(int LevelDifficulty);
void PlayIntroduction(int LevelDifficulty);


/*
    How it works?
    You have a limited number of tries to get access to the next level    
    when you get access to a next level you reset the number of tries you have
    but you increase the difficulty
*/
int main()
{
    srand(time(NULL));
    bool bLevelComplete;
    int Tries = 0;
    int Leveldifficulty = 5;
    int MaxLevel = 10;
    while ( Tries <= 10)
    {
        bLevelComplete = PlayGame(Leveldifficulty); //Play the game the game 
        std::cin.clear(); //Clear any input erros
        std::cin.ignore(); //Discard the buffer
        std:: cout << "You have "<< 10 - Tries << " Tries left\n";
      
        //cheking if you win
        if(bLevelComplete)
        {
            Tries = 0;
            ++Leveldifficulty;
            if(Leveldifficulty == MaxLevel)
            {
                std::cout << "\n* You did it you crazy son of a bitch!\n you did it!!!";
                return 0;
            }
            
        }else{
            Tries++;
        }
    }
    std::cout << "\n* You failed, they got you\n";
    //ending the program with no errors
    return 0;
}

//functions initialization
void PlayIntroduction(int LevelDifficulty){
    //Story of the game 
    
    std::cout << std::endl;
    std::cout << "You're a thief! You're trying to steal the most secure bank in the world!\n";
    std::cout << "You're Hacking into the electronic safe with the level of security of:" <<LevelDifficulty << "\n";
    std::cout << "You need to enter the right code to continue...\n";
    std::cout << std::endl;
}

bool PlayGame(int LevelDifficulty)
{
    
    PlayIntroduction(LevelDifficulty);
    //Variable declaration and initialization
    
    int CodeA = rand() % LevelDifficulty + LevelDifficulty; 
    int CodeB = rand() % LevelDifficulty + LevelDifficulty;  
    int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    int CodeProduct = CodeA * CodeB * CodeC;
    int CodeSum = CodeA+CodeB+CodeC;

    //Outputing the variables
    std::cout << "* There are 3 numbers in the code \n";
    std::cout << "* The product of the numbers is: " << CodeProduct  << "\n";
    std::cout << "* The sum of the numbers is:  "<< CodeSum  << "\n";
    std::cout << std::endl;
    //inputing the PlayerGuess
    
    int PlayerGuessA;
    int PlayerGuessB;
    int PlayerGuessC;
    int PlayerGuessSum;
    int PlayerGuessProduct;

    std::cout << "* Type your guess: \n";
    std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;


    PlayerGuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    PlayerGuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    //outputing PlayerGuess

    std::cout << "* You entered: "<< PlayerGuessA << PlayerGuessB << PlayerGuessC  << "\n";
    std::cout << "* The product of your guess is: "<< PlayerGuessProduct   << "\n";
    std::cout << "* The sum of your guess is: "<< PlayerGuessSum  << "\n";
    
    //checking if the PlayerGuess is the right code
    if ( PlayerGuessProduct == CodeProduct && PlayerGuessSum == CodeSum)
    {
       std::cout << "* You passed the security test!\n";
       return true;
    }else
    {
        std::cout << "* You failed the security test\n";
        return false;
    }
    
}
