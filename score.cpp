#include "score.h"


int Score::getBestScore()
{
    std::ifstream file("score.txt");
    if(file.is_open())
    {
        int score;
        file >> score;
        return score;
    }
    else std::cout << "Could not open file score.txt\n";
}
void Score::setBestScore(int score)
{
    std::ofstream file("score.txt", std::ofstream::trunc);
    if(file.is_open())
    {
        file << score;
    }
    else cout << "Could not open file score.txt\n";
}
