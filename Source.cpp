#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	ifstream file("GeoLiteCity-Location.csv");
	string value;

	string array[3][8]; //small array for testing purposes
	int a=0; //a and b will be used to traverse array
	int b=0;

	string dummyLine; //used to ignore first two lines
	getline(file, dummyLine); //first line ignored
	getline(file, dummyLine); //second line ignored

	for(int i=0; i<20;i++){ //only 20 records read and stored for testing purposes

		getline(file, value, ',');
		if(value[0]=='"') //if a quotation mark is encoutered at the beginning of a record, remove it and the one at the end
			value=string(value, 1, value.length()-2);
		array[a][b] = value;
		if(b==7){ //reset column to 0 and move to next row every 8 records
			a++;
			b=0;
		}
		b++;
	}

	for(int i=0; i<3; i++){
		for(int j=0;j<8;j++){
			cout<<array[i][j]<<" | ";
		}
		cout<<"breakline"<<endl;
	}

	system("pause");
}