/*********************
Name: Darren Bowers
Homework 3: Cache Simulator
Purpose: Creating hash tables of linked lists to simulate a cpu cache
**********************/

#include "main.h"

int main(int argc, char*argv[]) {
    
    if(argc == 4){
        unsigned long entries = atoi(argv[1]);
        unsigned long assoc = atoi(argv[2]);

        if(entries > 0 && assoc > 0){
            string input_filename = argv[3];

            cout << "Number of entries: " << entries << endl;
            cout << "Associativity: " << assoc << endl;
            cout << "Input File Name: " << input_filename << endl;

            string output_filename = "cache_sim_output";

            ofstream output;
            ifstream input;

            input.open(input_filename);

            if(input.is_open()){
                unsigned index = entries / assoc;
                cout << "number of indexes is " << index << endl;
                unsigned long count = 0;
                bool eofCheck = false;
                HashTable cache_sim(&entries, &assoc); 
                output.open(output_filename);
                while (input >> count) {
                    if(cache_sim.seachFill(count)){
                        output << count << " : HIT" << endl;
                    }else{
                        output << count << " : MISS" << endl;
                    }
                    if(input.eof()){
                        eofCheck = true;
                    }

                }
                if(!eofCheck){
                    cout << "End of file was not reached, there may be a misplaced character in the input file" << endl;
                }
                input.close();
                output.close();
            }else{
                cout << "Could not open input file " << input_filename << ". Exiting ..." << endl;
            }
        }else{
            cout << "num_entries and associativity need to be a number greater than 0" << endl;
        }


    }else{
        cout << "Expected three arguements - Proper Usage: " << endl;
        cout << "   ./cache num_entries associativity filename" << endl;
    }
    
    return 0;
}
