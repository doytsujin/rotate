run:
	cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/bin/gcc-9 -DCMAKE_CXX_COMPILER:FILEPATH=/bin/g++-9 -H/home/airbus5717/code/rotate/rotate_1 -B/home/airbus5717/code/rotate/rotate_1/build -G Ninja
	
	./build/rotate

build:
	cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/bin/gcc-9 -DCMAKE_CXX_COMPILER:FILEPATH=/bin/g++-9 -H/home/airbus5717/code/rotate/rotate_1 -B/home/airbus5717/code/rotate/rotate_1/build -G Ninja


clean: 
	-rm build/rotate

