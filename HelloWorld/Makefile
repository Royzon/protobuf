all: writer reader

writer: protobuf writer.o gwq5210.helloworld.pb.o
	g++ -o $@ writer.o gwq5210.helloworld.pb.o -pthread -lprotobuf -lpthread
reader: protobuf reader.o gwq5210.helloworld.pb.o
	g++ -o $@ reader.o gwq5210.helloworld.pb.o -pthread -lprotobuf -lpthread
gwq5210.helloworld.pb.o:
	g++ -c gwq5210.helloworld.pb.cc
protobuf: gwq5210.helloworld.proto
	protoc -I=. --cpp_out=. ./gwq5210.helloworld.proto
clean:
	rm -rf writer.o writer gwq5210.helloworld.pb.o reader reader.o gwq5210.helloworld.pb.cc gwq5210.helloworld.pb.h
