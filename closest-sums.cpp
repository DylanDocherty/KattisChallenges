//ACCEPTED

#include <iostream>
#include <vector> 
#include <cmath>
void applyClosestSum(int);
void findClosestInt(int,std::vector<int>);


int main() {
    
    int inputSizes= 0;
    int count = 0;
    while(std::cin >> inputSizes){
        count+=1;
        std::cout << "Case " << count << ":\n";
        applyClosestSum(inputSizes);
    }

    return 0;
}

void applyClosestSum(int inputSizes){
    int hold;
    int startingNumbers[inputSizes];
    int totalCombos = inputSizes*inputSizes;
    std::vector<int> allCombinations;
    
    for(int i=0;i<inputSizes;i++){
        std::cin >> startingNumbers[i];
    }
    for(int i=0;i<inputSizes;i++){
        for(int j=0;j<inputSizes;j++){
            if(i!=j){
                allCombinations.push_back(startingNumbers[i] + startingNumbers[j]);
            }else{
                // allCombinations[(i*inputSizes)+j] = -1;
            }
        }   
    }
    int queries;
    std::cin >> queries;
    int queriesInput;

    for(int i=0;i<queries;i++){
        std::cin >> queriesInput;    
        findClosestInt(queriesInput,allCombinations);
    }

}

void findClosestInt(int given,std::vector<int> numbers){
    int closestSum = -1;
    int testValue = 0;
    int testLowest = 9999999;
    for(int i: numbers){
        
        testValue = abs(i-given);
        if(testValue <= testLowest){
            closestSum = i;
            testLowest = testValue;
        }
    }

    std::cout << "Closest sum to " << given << " is " << closestSum << ".\n";
    // std::cout << closestSum;
}