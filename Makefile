INC=-I../raspicam/src -I/opt/vc/src/hello_pi/libs/ilclient -I/opt/vc/include -I/usr/include
LIB=/opt/vc/src/hello_pi/libs/ilclient/libilclient.a -L/opt/vc/lib -lbcm_host -lopenmaxil -lbcm_host -lvcos -lvchiq_arm -lpthread -lraspicam -ldl -lrt 
CPPFLAGS = -std=c++11
BUILDLIST=Config.cpp File.cpp FileWriter.cpp LiveStream.cpp main.cpp RaspberryCamera.cpp RaspberryEncoder.cpp RecordStream.cpp TimeUtils.cpp 
THIRDPARTYBUILDLIST=ini/cpp/INIReader.cpp ini/ini.c

all:
	g++ $(CPPFLAGS) $(INC) $(BUILDLIST) $(THIRDPARTYBUILDLIST) /opt/vc/src/hello_pi/libs/ilclient/libilclient.a -L/opt/vc/lib -lbcm_host -lopenmaxil -lbcm_host -lvcos -lvchiq_arm -lpthread -lraspicam -o VideoService -ldl -lrt
	
clean:
	rm -rf VideoService *.o