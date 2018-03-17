#include "Header.h";
using namespace std;

int main23431()
{
	char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%A, %B %d, %Y %H:%M:%S";
	strftime(buffer, 80, format, timeinfo);
	cout << "Current Datetime: " << buffer << endl;
	cin.get();
	return 0;
}