#include <iostream>

using namespace std;

int main()
{
    int my_array[7] = {8,6,9,3,7,4,10};
    int minVal = my_array[0];

    for (int i : my_array) {
        if (i < minVal) {
            minVal = i;
        }
    }

    std::cout << "Lowest value: " << minVal << std::endl;
    return 0;
}
