Folder contains 3 files
1) code.cpp that is main program and according to index we need to use two executables will be 
   executed:
   if index is through btree then btree code will be executed
   else hash code will be executed

2) btree.cpp - contains code of btree it opens input file puts distinct tuple in btree and then outputs tuples in GetNext() function.

3) hash.cpp - contains code of hash it opens input file puts distinct tuple in C++ map and then outputs tuples in GetNext() function.


-------------------------------------------------------------------------------------------

To Execute : -

./201225189 <input_file> <number_of_attributes> <number_of_blocks> <index_type>

index_type :
1 -> btree
0 -> hash


Output : -

Distinct tuple will be outputted in output.txt file


