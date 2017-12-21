#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include <stdio.h>

using namespace std;

vector<vector<string>> meisi;
vector<vector<string>> keiyousi;
vector<vector<string>> hukusi;

void file_input(string name,vector<vector<string>>& part);

int main(){
	file_input("名詞.csv",meisi);
	/*
	for(int i=0;i<meisi.size();i++){
    for(auto x: meisi[i]) cout<<x<<"	";
	 cout<<endl;
   }
	*/
}

void file_input(string name,vector<vector<string>>& part){
	string s;
	vector<string> s_str;
	char c='0';
	ifstream inputfile;
	inputfile.open(name);
	if(!inputfile){
		cout<<"ファイルが開けません"<<endl;
		//exit(1);
		inputfile.close();
	}
	else{
		while(inputfile.get(c)){
			if(c==','||c=='\n') {
				s_str.push_back(s);
				s.clear();
				if(c=='\n') {
					part.push_back(s_str);
					s_str.clear();
				}
			}
			else s=s+c;
		}		
	}
}
