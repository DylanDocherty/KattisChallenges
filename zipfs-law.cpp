#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <sstream>


std::string stringToLower(std::string);
std::string getRidOfPunctuation(std::string);
std::string getRidOfDigits(std::string);
std::string removeEOT(std::string);
std::map<std::string,int> textToWordMapCount(std::string);
void analyzeTextForTolerance(std::string,int);

int main() {
    
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int tolerance;
    std::cin >> tolerance;

    std::string input, text=" ", copyOfText;
    while(getline(std::cin,input)){
        if(input.find("EndOfText")!=std::string::npos){
            text = text + " " + removeEOT(input);
            text = getRidOfPunctuation(text);
            // text = removeEOT(text);
            text = stringToLower(text);
            text = getRidOfDigits(text);
            copyOfText = text;
            analyzeTextForTolerance(text,tolerance);
            text = "";
            std::cout << "\n\n";
            std::cin >> tolerance;
        }else{
            text = text + " " + input;
        }
    }
    return 0;
}

void analyzeTextForTolerance(std::string Text,int tolerance){
    std::map<std::string,int> wordCount;
    wordCount = textToWordMapCount(Text);
    bool atLeastOne = false;
    for (const auto& pair : wordCount) {
        if(pair.second == tolerance){
            // std::cout << "'" <<pair.first << "':" << pair.second << "\n";
            std::cout << pair.first <<  "\n";
            atLeastOne = true;
        }
    }
    if(!atLeastOne){
        std::cout << "There is no such word. ";
    }
}

std::map<std::string,int> textToWordMapCount(std::string Text){
    std::map<std::string,int> counter;
    std::stringstream wordStream;
    wordStream.str(Text);
    std::string word = "";
    
    while(wordStream >> word){
        if(word.length()>45) continue;
        if(word.length()==1 && (word!= "i" || word!="a")) continue;
        if(counter[word]!=NAN){
            counter[word]+=1;
        }else{
            counter[word]=1;
        }
    }
    return counter;
}

std::string stringToLower(std::string toChange){
    for(int i=0;i<toChange.size();i++){
        toChange[i] = tolower(toChange[i]);
    }
    return toChange;
}

std::string removeEOT(std::string Text){
    int pos = Text.find("EndOfText");
    return Text.substr(0,pos);
}

std::string getRidOfPunctuation(std::string text){
    for(int i=0;i<text.size();i++){
        if(ispunct(text[i])){
            text[i] = ' ';
        }
    }
    return text;
}

std::string getRidOfDigits(std::string text){
    for(int i=0;i<text.size();i++){
        if(isdigit(text[i])){
            text[i] = ' ';
        }
    }
    return text;
}