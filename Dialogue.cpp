#include "Dialogue.h"

Dialogue::Dialogue()
{
    current = 0;
    option="No Option";
}
private:
    String option;
    vector<String> responses;
    int current;

Dialogue::updateDialogue(){
    current++;
}

String Dialogue::getCurrentResponse(){
    return responses.at(current);
}

Dialogue::getOption(){
    return option;
}

Dialogue::addResponse(String s){
    responses.push_back(s);
}

Dialogue::setOption(String s){
    option=s;
}

