// Number to Words
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string get_word_for_units(char a) {
    string ans = "";
    switch(a) {
        case '1': ans = "One"; break;
        case '2': ans = "Two"; break;
        case '3': ans = "Three"; break;
        case '4': ans = "Four"; break;
        case '5': ans = "Five"; break;
        case '6': ans = "Six"; break;
        case '7': ans = "Seven"; break;
        case '8': ans = "Eight"; break;
        case '9': ans = "Nine"; break;
        case '0': ans = "Zero"; break;
    }
    return ans;
}
string get_word_for_tens(char a) {
    string ans = "";
    switch(a) {
        case '2': ans = "Twenty"; break;
        case '3': ans = "Thirty"; break;
        case '4': ans = "Forty"; break;
        case '5': ans = "Fifty"; break;
        case '6': ans = "Sixty"; break;
        case '7': ans = "Seventy"; break;
        case '8': ans = "Eighty"; break;
        case '9': ans = "Ninety"; break;
    }
    return ans;
}
string get_word_for_last_twos(string a) {
    string ans = "";
    if(a[0] == '1') {
        if(a == "10") ans = "Ten";
        else if(a == "11") ans = "Eleven";
        else if(a == "12") ans = "Twelve";
        else if(a == "13") ans = "Thirteen";
        else if(a == "14") ans = "Fourteen";
        else if(a == "15") ans = "Fifteen";
        else if(a == "16") ans = "Sixteen";
        else if(a == "17") ans = "Seventeen";
        else if(a == "18") ans = "Eighteen";
        else if(a == "19") ans = "Nineteen";
    }
    else if(a[0] == '0') { ans = get_word_for_units(a[1]); if(ans == "Zero") ans = ""; }
    else {
        ans = get_word_for_tens(a[0]);
        if(a[1] >= '1' && a[1] <= '9') ans += " " + get_word_for_units(a[1]);
    }
    return ans;
}
string get_words_for_hundreds(string str) {
    if(str[0] == '0') return get_word_for_last_twos(str.substr(1));
    else return get_word_for_units(str[0]) + " Hundred " + get_word_for_last_twos(str.substr(1));
}
string get_words_for_number(string number_str) {
    // u, xxx, yyy, zzz, www    =>  Number format for billions
    // [1-19], [20, .., 90][100, 200, .., 300]..  =>  number ranges for which words to be found
    int len = number_str.length();
    string ans = "";
    if(len == 1) {
        ans = get_word_for_units(number_str[0]);
    }
    else if(len == 2) {
        ans = get_word_for_last_twos(number_str);
    }
    else if(len == 3) {
        ans = get_words_for_hundreds(number_str);
    }
    else if(len > 3 && len <= 6) {
        string thousands = get_words_for_number(number_str.substr(0, len - 3));
        if(thousands == "") ans = get_words_for_number(number_str.substr(len - 3));
        else ans = thousands + " Thousand " + get_words_for_number(number_str.substr(len - 3));
    }
    else if(len > 6 && len <= 9) {
        string millions = get_words_for_number(number_str.substr(0, len - 6));
        if(millions == "") ans = get_words_for_number(number_str.substr(len - 6));
        else ans = millions + " Million " + get_words_for_number(number_str.substr(len - 6));
    }
    else if(len > 9 && len <= 12) {
        string billions = get_words_for_number(number_str.substr(0, len - 9));
        if(billions == "") ans = get_words_for_number(number_str.substr(len - 9));
        else ans = billions + " Billion " + get_words_for_number(number_str.substr(len - 9));
    }
    else if(len > 12 && len <= 15) {
        string trillions = get_words_for_number(number_str.substr(0, len - 12));
        if(trillions == "") ans = get_words_for_number(number_str.substr(len - 12));
        else ans = trillions + " Trillion " + get_words_for_number(number_str.substr(len - 12));
    }
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    string s;
    while(t-- > 0) {
        cin >> s;
        cout << get_words_for_number(s) << endl;
    }
    return 0;
}
