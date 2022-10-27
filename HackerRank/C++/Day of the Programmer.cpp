#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */
  
// Having a prefix vector is handier than calculating the dates each time
static const vector<string> datePrefix {
    "13.09.",   // [0] Non-leap year
    "12.09.",   // [1] Leap year
    "26.09."   	// [2] Date for the year 1918 when the calendars changed
};

bool isLeapYear(const int year, const bool isGregorian) {
    if (isGregorian) {
        return ((year % 400 == 0) or 		// Should be divisible by 400
        (year % 4 == 0 and year % 100 != 0)) ? 	// or by 4, but not by 100
        true : false;
    }
    else {
        return (year % 4 == 0) ? true : false;
    }
}

string dayOfProgrammer(int year) { 
    // 1918 was a weird year
    if (year == 1918) { 
        return datePrefix[2] + to_string(year);
    }
    
    const bool isGregorian = year > 1918;
    const bool lYear = isLeapYear(year, isGregorian);
    
    // lYear is either 0 when false or 1 when true, 
    // see the initialization of datePrefix if you are confused by the index
    return datePrefix[lYear] + to_string(year);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}