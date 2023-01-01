#include <bits/stdc++.h>

using namespace std;

// the loop work like this, if every letter is the same after
// reversal, we continue and return true, if not
// exit the function and return false
bool isPalindrome(string a)
{
    // we store the string we just received into our new
    // variable inside this bool function
    string b = a;

    // we reverse the order of string a
    reverse(a.begin(), a.end());

    // run through the loop to compare our original string
    // and our newly reverse string
    for (int i = 0; i < a.size(); i++) { if (a[i] == b[i]) { continue; } return false; }

    return true;
}


int main()
{
    // variable declaration
    string a = "";

    // input phase ----
    cout << "Enter the word you want to confirm it is a Palindrome or not: "
         << endl;
    cin  >> a;

    // processing phase
    bool valid = isPalindrome(a);

    // output phase.
    if (valid) { cout << "This word is a Palindrome"     << endl; }
        else   { cout << "This word is not a Palindrome" << endl; }

    return 1;
}
