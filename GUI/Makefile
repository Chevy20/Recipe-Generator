CC=g++
CFLAGS1= -Wall -g -c
CFLAGS2= -g

# Link the two object files together.

WebView: WebView.o
	${CC} ${CFLAGS2} -o WebView WebView.o

# Compile each source file to an object.

WebView.o: WebView.cpp
	${CC} ${CFLAGS1} -o WebView.cpp -lwt -lwthttp
