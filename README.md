# Cache-Simulator

This project is meant to simulate the CPU cache by creating hash tables of linked lists. 

After compiling, the program accepts 3 parameters: num_entries which is total size/slots available for the simulated cache, associativity of the cache / number of structs per linked list, and then the name of an input file which should contain a list of sudo-memory locations in decimal.

Program is set up to ensure the num_entries and associativity are both numbers greater than 0, and to check if the input file can be found. If all the parameters pass those checks it returns the passed information and calculates the number of indexes for the hashtable by divinding num_entries by the associativity.

From there it creates an hashtable with the size to match the calculated index size, and assigns a linkedlist at each index. Each linkedlist has a length of the associativity size, and each node is initialized with a tag of 0 and validBit set to INVALID (aka 0).

After initialization the program opens a new output file and starts a loop to go through the memory locations from the input file to see if the passed locations exist in the cache. If it does exist it notates a HIT in the output file, and if not it adds the tag and records a miss. If the cache is at capacity or meets a conflict it deletes the least recently used tag and replaces it with the new tag.

The loop continues for as long as there is consecutive memory locations givin in the input file, but will stop early if a non-numerical value is found. If this is the case it returns a note in the terminal saying that it did not reach the end of the file.

There is one bug with this, if the input file ends with a new line it will trigger the eof() return even if there isn't any more memory locations left in the input file.

Because the input file is expected to have sudo-memory locations in decimal, it simply pulls the decimal number as the tag.
