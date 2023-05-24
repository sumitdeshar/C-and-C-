#include<iostream>
#include<vector>

using namespace std;

template <class T>
void display(vector<T> &v)
{
	cout<<"displaying this vector"<<endl;
	for(int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<"";
		//cout << v.at(i)<<""; displays same this as above	
	}
	cout<<endl;
}


int main()
{
    // Ways to create a vector
//    vector<int> vec1;// zero length integer vector
//    vector<char> vec2(4);//4-element character vector
//    vec2.push_back('A');
//    vector<char> vec3( vec2 );//4-element character vector
    vector<int> vec4(6,3);//6-element vector of 3s
    display(vec4);
    cout<<vec4.size()<<endl;
    
    return 0;
}


 // new code 
// #include <vector>
//#include <numeric>

//bool betterThanAverage(const std::vector<int>& classPoints, const int yourPoints) {
//  return std::accumulate(classPoints.cbegin(), classPoints.cend(), 0) < classPoints.size() * yourPoints;
//}
