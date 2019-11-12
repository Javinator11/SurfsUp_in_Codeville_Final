#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Display {
public:
	//Prints out the winners
	void top3Display(string arregloStr[]) {
		cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
		cout << "      In First place we have " << arregloStr[6] << endl;
		cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
		cout << "                                          In Second place we have " << arregloStr[5] << endl;
		cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
		cout << "                                                                                  In Third place we have " << arregloStr[4] << endl;
		cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	}
};


class sortAlgortihm:Display {
public:
	//Algorithm use to sort the diffrent places
	void insertion_sort(int arreglo[], int tamano, string arregloStr[])
	{
		int i = 1;
		while (i < tamano)
		{
			int j = i;
			while (j > 0)
			{
				if (arreglo[j] < arreglo[j - 1])
				{
					//Uses a function "swap" to sort by order
					swap(arreglo[j], arreglo[j - 1]);
					swapStr(arregloStr[j], arregloStr[j - 1]);

				}
				else
				{
					break;
				}
				--j;
			}
			++i;
		}
		//Call the display function "top3Display"
		Display displ;
		displ.top3Display(arregloStr);
	}

private:
	//To swap arrays that use int
	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	//To swap arrays that use strings
	void swapStr(string& a, string& b)
	{
		string temp = a;
		a = b;
		b = temp;
	}

};


class fileReader:sortAlgortihm {
public:
	vector<string> vecStr;
	vector<int> vecNum;
	void read_File() {
		//Creating variables
		ifstream readFile;
		string str;

		//Open File location
		readFile.open("D:\\Programas 3er Semestre\\results.txt");

		//If the file dosen't open
		if (!readFile)
		{
			cout << " Couldn't open file" << endl;
			return;
		}
		//If the file does open
		else
		{
			while (!readFile.eof())
			{
				//Gets a line from the file and stores it on the vector
				getline(readFile, str);
				vecStr.push_back(str);
				stringstream ss(str);
					
				string word;
				int num;

				//Uses the stringstream to make another vector with just the scores of the players
				while (ss >> word)
				{
					if (ss >> num)
					{
						vecNum.push_back(num);
					}
				}
			}
		}
		readFile.close();
	}

	//Creates new arrays to which convert the vectors
	int arreglo[7];
	string arregloStr[7];

	void vec_converter() {
		//Vector to arrays
		for (int i = 0; i < vecNum.size(); i++)
		{
			arreglo[i] = vecNum[i];
			arregloStr[i] = vecStr[i];
		}
		//Calls the "insertion.sort" function to sort the arrays
		sortAlgortihm sort;
		sort.insertion_sort(arreglo, 7, arregloStr);
	}
};

class UI {
public:
	void UI_begin(){
		cout << "--------------------------------Welcome to the Codeville's Surfs Up Competition-----------------------------------" << endl;
		cout << "///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "///////////                                                                                                 ///////////" << endl;
		cout << "///////////                                                                                                 ///////////" << endl;
		cout << "///////////                              Click 'Enter' to see results                                       ///////////" << endl;
		cout << "///////////                                                                                                 ///////////" << endl;
		cout << "///////////                                                                                                 ///////////" << endl;
		cout << "///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

		cin.get();
	}
};

int main()
{
	//Calls the "UI_begin" function
	UI newUi;
	newUi.UI_begin();


	fileReader reads;
	//Calls the "read_File " function
	reads.read_File();
	//Calls the "vec_converter" function 
	reads.vec_converter();

	return 0;
}