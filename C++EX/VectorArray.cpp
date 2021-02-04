#include <iostream>
#include <vector>
using namespace std;
double average(const vector<double>& arr)
{
	double sum = 0;
	for (unsigned i = 0; i < arr.size(); i++)
		sum += arr[i];
	return sum / arr.size();
}
void main()
{
	vector<double> arr(4);
	for (int i = 0; i < 4; i++)
		arr[i] = 4;
	cout<<average(arr)<<endl;
	
}

