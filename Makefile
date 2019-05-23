all: build run

build:
	mkdir build && cd build && cmake ../ && make
	
run:
	cd build && ./intershipVK

clean:
	rm -rf build
