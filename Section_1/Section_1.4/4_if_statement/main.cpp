#include <iostream>

int main()
{
    int currVal = 0, remVal = 0;
    
    if(std::cin >> currVal){
        int cnt = 1;
        while(std::cin >> remVal){
            if(remVal == currVal){
                cnt++;
            }else{
                std::cout << "You entered " << currVal << " " << cnt << " times." <<std::endl;
                currVal = remVal;
                cnt = 1;
            }
        }
    }
    return 0;
}
