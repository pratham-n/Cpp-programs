#include<iostream>
#include<iomanip>
using namespace std;

//class to hold the hours, minutes, seconds and functions
class time{
	private:
		int seconds;
		int hh, mm, ss;
	public:					//functions are made public to access in main
		get_time();
		convert_to_seconds();
		display_time();
};

//function to input the time
time :: get_time(){
	cout<<"Enter time: \n";
	cout<<"Hours? ";
	cin>>hh;
	cout<<"Minutes? ";
	cin>>mm;
	cout<<"Seconds? ";
	cin>>ss;
}

//function to convert time into seconds
time :: convert_to_seconds(){
	seconds= hh*3600 + mm*60 + ss;
}

//function to display the time
time :: display_time(){
	cout<<"The time is = "<< setw(2) << setfill('0') << hh <<":"
							<< setw(2) << setfill('0') << mm <<":"
							<< setw(2) << setfill('0') << ss <<endl;
	cout<<"Time in total seconds: "<< seconds << endl;
}

int main(){
	time t;		//declaring object
	//calling the functions to do the task
	t.get_time();			
	t.convert_to_seconds();
	t.display_time();
	return 0;
}





