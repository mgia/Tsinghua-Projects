/****************************************************************************** #
#
#
#    main.cpp
#
#    By: Marc G Tan <marc> <findmarcg@gmail.com>
#
#    Created: 2018/01/20 10:37:01 by marc
#    Updated: 2018/01/20 10:37:15 by marc
#
# **************************************************************************** */


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <stdlib.h>
using namespace std;

//Used to split the IP address into vectors
template<typename Out>

void split(const std::string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

// Pretty self-explanatory
int ft_check(vector<int> input, vector<int> range) {
    for (int i=0;i<4;i++) {
        if (input[i] < range[2*i] || input[i] > range[2*i+1])
        return (0);
    }
    return (1);
}

int main()
{
    string ip_range = "";
    int n = 0;
    string input = "";

    cin >> ip_range >> n;
    vector<string> str = split(ip_range, '.');

    vector<int> range;
    vector<string> temp;
    //Splitting IP Range Filter into 8 elements
    for(int i=0;i<4;i++){
        if(str[i] == "*"){
            range.push_back(0);
            range.push_back(255);
        }
        else if (str[i].find('-') != (-1))
        {
            temp = split(str[i], '-');
            range.push_back(atoi(temp[0].c_str()));
            range.push_back(atoi(temp[1].c_str()));
        }
        else
        {
            range.push_back(atoi(str[i].c_str()));
            range.push_back(atoi(str[i].c_str()));
        }
    }

    while (n > 0)
    {
        cin >> input;
        //Splitting test IP Address into 4 elements
        temp = split(input, '.');
        vector<int> res;
        for(int i=0;i<4;i++)
        res.push_back(atoi(temp[i].c_str()));
        //Test and print
        cout << (ft_check(res, range) ? "Accepted" : "Failed") << endl;
        n--;
    }
    return (0);
}
