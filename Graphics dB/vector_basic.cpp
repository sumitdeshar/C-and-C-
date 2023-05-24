#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> &v)
{
	for(int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<"\t";
	}
	cout<<endl;
}


int main(){
	vector<int> vec1;
	int element,size;
	cout<<"give size of vectors"<<endl;
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cout<<"ENter an element to add to vector: "<<endl;
		cin>>element;
		vec1.push_back(element);
	}
	display(vec1);
	vec1.pop_back();
	display(vec1);
//	vector<int>:: iterator iter = vec1.begin();
//	vec1.insert(iter+2,50,469);// vector_name(iterator_variavle+2,no of item to be added, item to be added)
	display(vec11);
    return 0;
   }
