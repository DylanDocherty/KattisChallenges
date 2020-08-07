//ACCEPTED

#include <iostream>
#include <cmath>

int main() {

    // std::cout << "input 3 numbers \n";
    int inputSizes[3]= {0,0,0};
    std::cin >> inputSizes[0] >> inputSizes[1] >> inputSizes[2];
    float maxLength = sqrt(inputSizes[1]*inputSizes[1] + inputSizes[2]*inputSizes[2]);
    int hold;
    int output[inputSizes[0]];

    for(int i=0;i<inputSizes[0];i++){
        std::cin >> hold;
        if(hold<=maxLength){
            output[i] = 1;
        }
    }
    for(int j=0;j<inputSizes[0];j++){
        if(output[j] == 1){
            std::cout << "DA\n";
        }else{
            std::cout << "NE\n";
        }
    }
    return 0;
}