#include <bits/stdc++.h>
using namespace std;

int main(int argc,char * argv[])
{
	if(argc<5)
	{
		exit(0);
	}
	else
	{
		string t="../";
		string filename=argv[1];
		filename=t+filename;
		int number_of_attr=atoi(argv[2]);
		int number_of_blocks=atoi(argv[3]);
		int index_type=atoi(argv[4]);
		string outputfile="output.txt";
		string arguments;
		if(index_type==1)
		{
			// Btree
			arguments+="./btree ";
			arguments+=(filename+" ");
			arguments+=(std::to_string(number_of_attr));
			arguments+=" ";
			arguments+=(std::to_string(number_of_blocks));
			arguments+=" ";
			arguments+="> "+outputfile;
		}
		else
		{
			// Hash
			arguments+="./hash ";
			arguments+=(filename+" ");
			arguments+=(std::to_string(number_of_attr));
			arguments+=" ";
			arguments+=(std::to_string(number_of_blocks));
			arguments+=" ";
			arguments+="> "+outputfile;
		}
		system("g++ -std=c++0x -o hash hash.cpp");
		system("g++ -std=c++0x -o btree btree.cpp");
		system(arguments.c_str());
	}
	return 0;
}

