/*Bryan Yam
20828243
November 5, 2019
SYDE 121
A. Chung
CPH 1346
Lab 05, 01*/	
/*The purpose of this program is to create a graph using an input file. and also export a logo.*/
/*I used different input values to test that my graph worked and was scaled properly*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool make_graph();
bool make_logo();
void get_file_input(vector<string>& names, vector<int>& val);

int main()
{
    make_graph();
    make_logo();
    return 0;
}
void get_file_input(vector<string>& names, vector<int>& val)
{
    // [setup] initialize corresponding variables
	string cur_pair; 
    int count = 0; 

	// [INPUT] handle file inputs
	ifstream my_ifstream; // create ifstream instance	

    my_ifstream.open("input.txt");
    while(my_ifstream)
    {
        getline(my_ifstream, cur_pair);
        count++; // counts the number of inputs 
    }

    count-=1;
    my_ifstream.close();

	my_ifstream.open("input.txt"); // open the input file

	if(!my_ifstream.fail()) { // check for failure
		// [PROCESSING] extract and print individual values

		for (int index = 0; index < count; ++index) { // read (key,val) pairs
			
			// separate into tokens; skip comma and space
            if(my_ifstream)
            {
                getline(my_ifstream, cur_pair); // read one line at time
                names.push_back(cur_pair.substr(0, cur_pair.find(',', 0))); 
			    val.push_back(atoi(cur_pair.substr(cur_pair.find(',', 0) + 2).c_str())); 
            }
		}

		// [OUTPUT] close the file
		my_ifstream.close(); // close the file
	}
}

bool make_graph()
{
    vector<string> names (0);
    vector<int> val (0);  
    get_file_input(names, val);

    ofstream graph; //creates ofsteam instance
    graph.open("output.svg"); //opens output file

    if (!graph.fail())
    {
        
        string colours[5] = {"fill:yellow;", "fill:purple;", "fill:blue;", "fill:red;", "fill:orange;"}; //assign bar graph colours 
        
		graph << "<?xml version=\"1.0\"?>" << endl;
		graph << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ";
		graph << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
		graph << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">" << endl;

        int a = 0;
        for (vector<int>::iterator b = val.begin(); b!= val.end(); ++b) //cycles through vector to find greatest value
        {
            if (*b>a)
                a = *b;
        }

        for (int bars = 0; bars<names.size(); bars++) //outputs the bar content into the file
        {
            int x(50*bars+100), y(300), width(20), height((int)(val[bars]/1.0/a*250)); //scales graph to greatest value
            y -= height;
            graph << "<rect x=\"" << x <<"\" y=\"" << y << "\" width=\"" << width;
            graph << "\" height=\"" << height << "\" style=\"" << colours[bars] << "\"/>" << endl;
        }

        int end_x = 150+50*names.size(); 
        graph << "<line x1=\"75\" y1=\"300\" x2=\"" << end_x << "\" y2=\"300\" style=\"stroke:black;stroke-width:2\"/>" << endl; //sets up the axis lines
        graph << "<line x1=\"75\" y1=\"75\" x2=\"75\" y2=\"300\" style=\"stroke:black;stroke-width:2\"/>" << endl;
        graph << "<line x1=\"75\" y1=\"50\" x2=\"75\" y2=\"100\" style=\"stroke:black;stroke-width:2\"/>" << endl;
        graph << "</svg>" << endl;

        graph.close(); //closes file
    }

    return true;
}

bool make_logo()
{   ofstream logo; //create ofstream instance 
    logo.open("syde_logo_b2yam.svg"); //opens output file

    if (!logo.fail())
    {    	
        logo << "<?xml version=\"1.0\"?>" << endl; //outputs svg content into file
		logo << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ";
		logo << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
		logo << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">" << endl;
        logo << "<text x=\"50\" y=\"50\" fill=\"purple\">SYDE is love, SYDE is life!</text>" << endl;
        logo << "</svg>" << endl;

        logo.close(); //closes file
    }
    return true;
}
