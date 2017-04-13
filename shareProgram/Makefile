calendar.out: main.o day.o calendar.o
	g++ -Wall -ansi -g -o calendar.out main.o day.o calendar.o

main.o: main.cpp calendar.h day.h appt.h time.h
	g++ -Wall -ansi -g -c main.cpp

day.o: day.cpp day.h appt.h time.h
	g++ -Wall -ansi -g -c day.cpp

calendar.o: calendar.cpp calendar.h day.h appt.h time.h
	g++ -Wall -ansi -g -c calendar.cpp

appt.o: appt.cpp appt.h
	g++ -Wall -ansi -g -c appt.cpp

clean:
	rm -f main.o day.o calendar.o calendar.out
