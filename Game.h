#ifndef GAME_H
#define GAME_H

class Game
{
  private:
    bool state[40];
    int getUserInput(int);
    void updateGame(Observation *o, Player *p)
    
  public:
    Game();
    bool *getState();
    void run();
    
};

#endif // GAME_H
