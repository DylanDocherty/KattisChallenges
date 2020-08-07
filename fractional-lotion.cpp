#include <iostream>
#include <vector>
#include <cmath>

float stringToDenominator(std::string);

int main() {
    std::string fraction;
    float denominator;
    float value;
    while(getline(std::cin,fraction)){
        // std::cout << stringToDenominator(fraction);
        denominator = stringToDenominator(fraction);
        value = 1/denominator;
    }
    
}

float stringToDenominator(std::string fraction){
    std::string numeratorString, denominatorString;

    int slashAt = fraction.find("/");
    denominatorString = fraction;
    denominatorString = fraction.substr(slashAt+1);

    float denominator;
    denominator = stoi(denominatorString);

    return denominator;
}

int findAllPairs(float denominator, float value){
    std::vector<float> primeFactorization;
    

    return 0;
}

// float stringToDenominator(std::string fraction){
//     std::string numeratorString, denominatorString;

//     int slashAt = fraction.find("/");
//     numeratorString = fraction;
//     denominatorString = fraction;
//     numeratorString.resize(slashAt);
//     denominatorString = fraction.substr(slashAt+1);

//     float numerator, denominator;
//     numerator = stoi(numeratorString);
//     denominator = stoi(denominatorString);

//     return denominator;
// }