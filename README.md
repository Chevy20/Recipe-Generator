# Recipe-Generator
A C++ linux application that will generate recipes based on what the user has on their stock. Was developed in a group. <br>
Note: Was hosted on Western University's Bitbucket. Moved to git for public access. <br>
Files I wrote: <br>
FoodAPI.hpp and FoodAPI.cpp <br>
FoodItem.h and FoodItem.cpp <br>
Model.h and Model.cpp <br>
RecipeItem.h and RecipeItem.cpp <br>
SQLiteConnector.h and SQLiteConnector.cpp <br>
StockTable.h and StockTable.cpp <br>
t_dbConnector.h and t_dbStrategy.h <br>
terminalApplication.cpp <br>
TerminalView.h and TerminalView.cpp <br>

How to Run:<br>
Dependencies needed: <br>
CURL: https://www.cyberciti.biz/faq/how-to-install-curl-command-on-a-ubuntu-linux/#:~:text=Advertisement-,Installing%20cURL%20for%20Ubuntu%20Linux,by%20running%3A%20curl%20%2D%2Dversion <br>
SQLite3: https://linuxhint.com/install-sqlite-ubuntu-linux-mint/ <br>
wt: https://www.webtoolkit.eu/wt/doc/reference/html/InstallationUnix.html <br>
jsoncpp:https://linux.tips/programming/how-to-install-and-use-json-cpp-library-on-ubuntu-linux-os <br>

How to Build: 
Once dependencies have been installed you can build the terminalApplication with the following command:  <br>
g++ terminalApplication.cpp FoodAPI.cpp FoodItem.cpp Model.cpp Recipe.cpp RecipeItem.cpp SQLiteConnector.cpp StockTable.cpp View.cpp terminalView.cpp  -o terminalApplication  -lstdc++ -lcurl -lm -ljsoncpp -lsqlite3 <br>

Once dependencies have been installed you can build the webApplication with the following command: <br>
g++ webApplication.cpp FoodAPI.cpp FoodItem.cpp Model.cpp Recipe.cpp RecipeItem.cpp SQLiteConnector.cpp StockTable.cpp View.cpp  WebView.cpp  -o webApplication  -lstdc++ -lcurl -lm -ljsoncpp -lsqlite3 -lwt -lwthttp <br>

You can run terminalAppplication and webApplication at the same time but they MUST be run in seperate shell instances!!!! <br>

To run webApplication, type the following:  <br>
./webApplication --docroot . --http-address 0.0.0.0 --http-port 9080 <br>

You will see a line in the terminal that says:  <br>
[2022-Nov-30 06:08:00.805] 999 - [info] "wthttp: started server: http://0.0.0.0:9080" <br>

Open http://0.0.0.0:9080 to access the webApplication <br>

Note: please close web page from browser before shutting down webserver. <br>
To shutdown the webServer, Control + C on the terminal <br>

To run terminalApplication, type the following: <br>
./terminalApplication <br>
