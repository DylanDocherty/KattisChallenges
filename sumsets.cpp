#include <iostream>
#include <vector> 
#include <cmath>
#include <algorithm>
#include <functional>
#include <map>
#include <sstream>


void print(std::vector<int> const &input);
bool vecContains(std::vector<int>,int);
std::vector<int> textToIntVec(std::string);
std::vector<int> allCombinations(std::vector<int>);


int main() {
    
    int inputSizes,holdVal;
    std::cin >> inputSizes;
    std::vector<int> set;
    for(int i=0;i<inputSizes;i++){
        std::cin >> holdVal;     
        set.push_back(holdVal);
    }
    std::sort(set.begin(), set.end());
    allCombinations(set);
    // std::cout << "starting processing...";

    return 0;
}

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

bool vecContains(std::vector<int> vec,int value){
    return std::find(vec.begin(), vec.end(), value) != vec.end();
}

std::vector<int> allCombinations(std::vector<int> set){
    std::cout << "set.size()";
    // if(set.empty()){
    //     std::cout << "no solution";
    //     return set;
    // }
    int maxElement = *std::max_element(set.begin(), set.end());
    int newTestVal = 0;
    int hold,atLeastOne=0;
    std::string tempString;
    std::map<std::string, int> comboMap;
    
    for (auto & first : set) {
        for (auto & second : set) {
            if(first!=second){
                tempString = std::to_string(first) + "   " + std::to_string(second);
                comboMap[tempString] = first + second;
            }
        }
    }
    for(auto & pair: comboMap){
        for(auto & third: set){
            if(!vecContains(textToIntVec(pair.first),third)){
                newTestVal = pair.second + third;
                if(newTestVal == maxElement){
                    if(atLeastOne==0){
                        hold = newTestVal;
                        atLeastOne = 1;
                    }else if(hold<newTestVal){
                        hold = newTestVal;
                    }
                }           
            }
        }
    }
    if(!atLeastOne){
        set.pop_back();
        return allCombinations(set);
    }else{
        std::cout << hold;
    }
}

std::vector<int> textToIntVec(std::string Text){
    std::vector<int> set;
    std::stringstream wordStream;
    wordStream.str(Text);
    std::string word = "";
    
    while(wordStream >> word){
        set.push_back(std::stoi(word));
        
    }
    return set;
}