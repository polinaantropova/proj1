INCLUDES=C:\Users\Dell\source\repos\probaDB
SOURCES=probaDB.cpp DB.cpp RoomForSale.cpp
OBJSCPP=$(SOURCES:.cpp=.obj)
all: $(OBJSCPP)	
	cl probaDB.obj DB.obj RoomForSale.obj DateForm.obj /Fe: a.exe

.cpp.o:
	cl /c $? $@ /I $(INCLUDES)

clean:
	del $(OBJSCPP) *.exe
test:
	a.exe
