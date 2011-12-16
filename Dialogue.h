#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
#include <vector>

class Dialogue
{
private:
    String option;
    vector<String> responses;
    String *current;
public:
    Dialogue();
    updateDialogue();
    getCurrentResponse();
    getOption();
    addResponse(String s);
    setOption(String s);
};

#endif // DIALOGUE_H
