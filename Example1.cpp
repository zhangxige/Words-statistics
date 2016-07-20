#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
	string word;
	int num;
	Item():word(),num(0){
	}
};

vector<Item> count(string &a){
	vector<Item> result;
	vector<string> tresult;
	string temp;
	for(int i=0;i<a.size();i++){
		if(a[i]!=' ')
			temp+=a[i];
		else{
			tresult.push_back(temp);
			temp.clear();
		} 
	}
	if(temp.size())
		tresult.push_back(temp);
	sort(tresult.begin(),tresult.end());
	Item x;
	if(tresult.size()){
		x.word=tresult[0];
		x.num=1;
		result.push_back(x);
	}
	int j=0;
	for(int i=1;i<tresult.size();i++){
		if(tresult[i]==result[j].word)
			result[j].num++;
		else{
			x.word=tresult[i];
			x.num=1;
			result.push_back(x);
			j++;
		}
	}

	return result;
}

int main(){
    string a="i am a good man welcom am good man";
	count(a);
    return 0;
}
