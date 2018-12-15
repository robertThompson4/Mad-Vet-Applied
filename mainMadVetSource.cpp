#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<deque>
#include<set>

using namespace std;

struct node
{
	public:
		int value;
		int level;
};

string doProblem(int, int, vector<vector<node>>, vector<vector<node>>);
void buildDeque(vector<vector<node>> machineGrid, vector<vector<node>> questionsGrid, vector<node> initial, deque<vector<node>>& dQone,set<string>&);
vector<node> mathFormulaOne(int level, int r1, int specValue, vector<vector<node>> machineGrid, vector<vector<node>> questionsGrid, vector<node>initial);
vector<node> mathFormulaTwo(int level, int r1, int specValue, vector<vector<node>> machineGrid, vector<vector<node>> questionsGrid, vector<node>initial);


void main()
{
	ifstream fin("madvet.in");
	ofstream fout("madvet.out");
	string output;
	node sample;
	sample.value = 0;
	sample.level = 0;
	vector<vector<node>> machineGridOne(3, vector<node>(3, sample));
	int amountOfDataSet = 0;
	int currentSet = 0;
	int amountOfQuestions = 0;
	
	while (!fin.eof())
	{
		int incrementOne = 0;
		fin >> amountOfDataSet;
		while (incrementOne != amountOfDataSet)
		{
			fin >> currentSet;
			fin >> amountOfQuestions;
			for (int r = 0; r < 3; r++)
				for (int c = 0; c < 3; c++)
					fin >> machineGridOne[r][c].value;
			vector<vector<node>> questionsGrid(amountOfQuestions, vector<node>(7, sample));
			for (int r = 0; r < amountOfQuestions; r++)
				for (int c = 0; c < 7; c++)
					fin >> questionsGrid[r][c].value;
			fout << currentSet << " " << amountOfQuestions << endl;
			int currentSetTwo = 1;
			while (currentSetTwo != amountOfQuestions + 1)
			{
				output = doProblem(currentSetTwo, amountOfQuestions, machineGridOne, questionsGrid);
				fout <<currentSetTwo<< " "<< output << endl;
				currentSetTwo++;
			}
			incrementOne++;
		}
	}
}

string doProblem(int currentSet, int amountOfQuestions, vector<vector<node>> machineGridOne, vector<vector<node>> questionsGrid)
{
	deque<vector<node>> dQone;
	set<string> dogS;
	string holderString = "";
	string holderString2 = "";
	string output = "k";
	int answerHolder = 0;
	int level = 0;
	node sample;
	long numOfque = 2;
	sample.value = 0;
	sample.level = 0;
	vector<node> changer;
	vector<node> startingNode;
	vector<node> holderStart(3, sample);
	vector<node> holderAns(3, sample);
	holderStart[0].value = questionsGrid[currentSet - 1][1].value;
	holderStart[1].value = questionsGrid[currentSet - 1][2].value;
	holderStart[2].value = questionsGrid[currentSet - 1][3].value;
	holderAns[0].value = questionsGrid[currentSet - 1][4].value;
	holderAns[1].value = questionsGrid[currentSet - 1][5].value;
	holderAns[2].value = questionsGrid[currentSet - 1][6].value;
	dQone.push_front(holderStart);
	holderString = to_string(holderStart[0].value) + to_string(holderStart[1].value) + to_string(holderStart[2].value);
	holderString2 = to_string(holderAns[0].value) + to_string(holderAns[1].value) + to_string(holderAns[2].value);
	dogS.insert(holderString);
	while (answerHolder == 0 && level == 0)
	{
		if (dQone.empty())
		{
			output = "NO SOLUTION";
			level = 30;
		}
		else if (dQone[0][0].value == holderAns[0].value&&dQone[0][1].value == holderAns[1].value&&dQone[0][2].value == holderAns[2].value)
			answerHolder = dQone[0][0].level;
		else if (dQone[0][0].level == 30) {
			level = 30;
			output = "NO SOLUTION";
		}
		
		else
		{
			changer = dQone[0];
			buildDeque(machineGridOne, questionsGrid, changer, dQone,dogS);
			dQone.pop_front();
		}

	}
	if(output!= "NO SOLUTION")
		output = to_string(answerHolder);
	return output;

}


void buildDeque(vector<vector<node>> machineGrid, vector<vector<node>> questionsGrid, vector<node> initial, deque<vector<node>>& dQone,set<string>& dogS)
{
	
		string holderString = "";
		vector<node> holder;
		if (initial[0].value > 0)
		{
			holder = mathFormulaOne(0, 0, 0, machineGrid, questionsGrid, initial);
			holderString = to_string(holder[0].value) + to_string(holder[1].value) + to_string(holder[2].value);
			if (dogS.find(holderString) == dogS.end()) {
				dQone.push_back(holder);
				dogS.insert(holderString);
			}
		}
		if (initial[1].value > 0)
		{
			holder = mathFormulaOne(0, 1, 1, machineGrid, questionsGrid, initial);
			holderString = to_string(holder[0].value) + to_string(holder[1].value) + to_string(holder[2].value);
			if (dogS.find(holderString) == dogS.end()) {
				dQone.push_back(holder);
				dogS.insert(holderString);
			}
		}
		if (initial[2].value > 0)
		{
			holder = mathFormulaOne(0, 2, 2, machineGrid, questionsGrid, initial);
			holderString = to_string(holder[0].value) + to_string(holder[1].value) + to_string(holder[2].value);
			if (dogS.find(holderString) == dogS.end()) {
				dQone.push_back(holder);
				dogS.insert(holderString);
			}
		}
		if (initial[0].value >= machineGrid[0][0].value && initial[1].value >= machineGrid[0][1].value && initial[2].value >= machineGrid[0][2].value)
		{
			holder = mathFormulaTwo(0, 0, 0, machineGrid, questionsGrid, initial);
			holderString = to_string(holder[0].value) + to_string(holder[1].value) + to_string(holder[2].value);
			if (dogS.find(holderString) == dogS.end()) {
				dQone.push_back(holder);
				dogS.insert(holderString);
			}
		}
		if (initial[0].value >= machineGrid[1][0].value && initial[1].value >= machineGrid[1][1].value && initial[2].value >= machineGrid[1][2].value)
		{
			holder = mathFormulaTwo(0, 1, 1, machineGrid, questionsGrid, initial);
			holderString = to_string(holder[0].value) + to_string(holder[1].value) + to_string(holder[2].value);
			if (dogS.find(holderString) == dogS.end()) {
				dQone.push_back(holder);
				dogS.insert(holderString);
			}
		}
		if (initial[0].value >= machineGrid[2][0].value && initial[1].value >= machineGrid[2][1].value && initial[2].value >= machineGrid[2][2].value)
		{
			holder = mathFormulaTwo(0, 2, 2, machineGrid, questionsGrid, initial);
			holderString = to_string(holder[0].value) + to_string(holder[1].value) + to_string(holder[2].value);
			if (dogS.find(holderString) == dogS.end()) {
				dQone.push_back(holder);
				dogS.insert(holderString);
			}
		}

	}



vector<node> mathFormulaOne(int level, int r1, int specValue, vector<vector<node>> machineGrid, vector<vector<node>> questionsGrid, vector<node>initial)
{
	initial[specValue].value = initial[specValue].value - 1;
	initial[0].value = initial[0].value + machineGrid[r1][0].value;
	initial[1].value = initial[1].value + machineGrid[r1][1].value;
	initial[2].value = initial[2].value + machineGrid[r1][2].value;
	initial[0].level++;
	initial[1].level++;
	initial[2].level++;
	return initial;
}

vector<node> mathFormulaTwo(int level, int r1, int specValue, vector<vector<node>> machineGrid, vector<vector<node>> questionsGrid, vector<node>initial)
{
	initial[0].value = initial[0].value - machineGrid[r1][0].value;
	initial[1].value = initial[1].value - machineGrid[r1][1].value;
	initial[2].value = initial[2].value - machineGrid[r1][2].value;
	initial[specValue].value = initial[specValue].value + 1;
	initial[0].level++;
	initial[1].level++;
	initial[2].level++;
	return initial;
}