cd code/
g++ -std=c++0x code.cpp
./a.out "$@"
cp output.txt ../output.txt
rm -rf output.txt
cd ..