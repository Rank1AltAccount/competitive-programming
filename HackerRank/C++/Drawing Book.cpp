#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(const int n, const int p) {
    // I'm converting all page indexes to the rightmost (odd) ones for convenience
    // since the book always starts at 1, which is on the right side
    
    // If the pages are not odd, add 1
    const int targetPage = p + bool(not (p % 2)); 
    const int lastPage = n + bool(not (n % 2));
    
    // Dividing by 2 because you see 2 pages when you flip to the next page
    const int flipsFromLeft = (targetPage - 1) / 2; // 1 is the first page
    const int flipsFromRight = (lastPage - targetPage) / 2; 
    
    return flipsFromLeft < flipsFromRight ? flipsFromLeft : flipsFromRight;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

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