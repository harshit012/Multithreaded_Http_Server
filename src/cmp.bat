g++ -std=c++11 -c *.cpp -lws2_32 -I ..\include -std=c++11
ar rcs ..\lib\hcwplib.lib *.o
