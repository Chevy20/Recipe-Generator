#include "HTTPRequest.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[]){

try
    {
        
        http::Request request{"https://api.spoonacular.com/recipes/complexSearch"};
        const std::string body = "foo=1&bar=baz";
        const auto response = request.send("GET", body, {
            {"Content-Type", "application/json"},
            {"x-api-key", "de32085d5f03454bbccdad302c309955"}
        });
        std::cout << std::string{response.body.begin(), response.body.end()} << '\n'; // print the result
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }
}