#include <bits/stdc++.h>
using namespace std;

map<int,set<vector<int> > > map_for_hashing;

void Getnext(string filename,int number_of_attr,int number_of_blocks)
{
	ifstream inputstream(filename.c_str());
	string lines;
	while(getline(inputstream,lines))
	{
		stringstream tuple;
		tuple<<lines;
		string many_integers;
		vector < int > temp_vec;
		int sum=0;
		while(tuple>>many_integers)
		{
			int single_int=stoi(many_integers);
			sum+=single_int;
			sum%=number_of_blocks;
			temp_vec.push_back(single_int);
		}
		if(map_for_hashing[sum].find(temp_vec)==map_for_hashing[sum].end())
		{
			map_for_hashing[sum].insert(temp_vec);
			cout<<lines<<endl;
		}
	}
	inputstream.close();
	return;
}


void open(string filename,int number_of_attr,int number_of_blocks)
{
	map_for_hashing.clear();
	Getnext(filename,number_of_attr,number_of_blocks);
	return;
}


void distinct(string filename,int number_of_attr,int number_of_blocks)
{
	open(filename,number_of_attr,number_of_blocks);
	return;
}


int main(int argc,char * argv[])
{
	if(argc<4)
	{
		exit(0);
	}
	else
	{
		string filename=argv[1];
		int number_of_attr=atoi(argv[2]);
		int number_of_blocks=atoi(argv[3]);
		distinct(filename,number_of_attr,number_of_blocks);
	}
	return 0;
}