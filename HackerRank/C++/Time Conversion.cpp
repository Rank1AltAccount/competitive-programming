#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    bool postMeridiem = s[8] == 'P'; // Indexing directly because input is guaranteed to be the same
    
    if (s[0] == '1' and s[1] == '2') { // If noon
        if (not postMeridiem) {
            s = s.replace(0, 2, "00");
        }
    }
    else { 
        if (postMeridiem) {
            s = s.replace(0, 2, to_string(stoi(s.substr(0, 2)) + 12));
        } 
    }
    
    return s.substr(0, s.size() - 2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
