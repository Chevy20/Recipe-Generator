#include <iostream>
#include <Poco/URI.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPMessage.h>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

int main()
{
    // Create a URI
    URI uri("https://api.spoonacular.com");
      
    // Create a session
    HTTPClientSession session(uri.getHost(), uri.getPort());
    
    string path(uri.getPathAndQuery());

    if(path.empty()) path = "/recipes/findByIngredients?ingredients=apples";

    // Set connection to keepalive
    session.setKeepAlive(true);
    
    // Choose the http request method
    HTTPRequest request(HTTPRequest::HTTP_GET, "https://api.spoonacular.com/recipes/findByIngredients?ingredients=apples");
    
    // Add headers
    request.setContentType("application/json");
    request.add("x-api-key", "de32085d5f03454bbccdad302c309955");
    
    cout << request.getContentType() << endl;
    request.
    // Send the request
    session.sendRequest(request);
    
    // Receive response
    HTTPResponse response;
    istream &page = session.receiveResponse(response);
    
    // Print the status code
    cout << response.getStatus() << endl;
    cout << response.getReasonForStatus(response.getStatus()) << endl;
    
    // Lets compile and start wireshark 
    
    return 0;
}