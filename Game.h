#ifndef GAME_H
#define GAME_H

class Game
{
  private:
    bool state[40];
    int getUserInput(int);
    
    
  public:
    Game();
    bool *getState();
    void run();
    
};

#endif // GAME_H
