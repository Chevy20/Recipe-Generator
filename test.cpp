#include <iostream>

using namespace std;

int main(){
    if(const char* env_p = std::getenv("SPOONACULAR_API_KEY"))
        std::cout << "Your KEY is: " << env_p << '\n';
}