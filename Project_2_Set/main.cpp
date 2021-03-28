#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int maxset = 'Z' + 1;

void print(bool s[maxset], ofstream &outf);
void init(bool universal[maxset], bool vowel[maxset], bool myname[maxset]);
void setUnion(bool first[maxset], bool second[maxset], bool result[maxset]);
void intersect(bool first[maxset], bool second[maxset], bool result[maxset]);
void difference(bool first[maxset], bool second[maxset], bool result[maxset]);
void empty(bool s[maxset]);
bool subset(bool first[maxset], bool second[maxset]);
bool equal(bool first[maxset], bool second[maxset]);
int cardinality(bool s[maxset]);

int main() {
    bool universal[maxset], vowel[maxset], myname[maxset], consonant[maxset], answer[maxset];

    ofstream outf("out.dat");
    init(universal, vowel, myname);


    outf << "The universal set is: " << endl;
    print(universal, outf);

    outf << "The vowel set is: " << endl;
    print(vowel, outf);

    outf << "The myname set is: " << endl;
    print(myname, outf);

    // 4) Write a function to find the union of any two sets

    setUnion(vowel, myname, answer);
    outf << "The union of vowel and myname is: " << endl;
    print(answer, outf);


    // 5) Write a function to find the intersection of any two sets
    intersect(vowel, myname, answer);
    outf << "The intersection of vowel and myname is: " << endl;
    print(answer, outf);


    // 6) Write a function to find the set difference of any two sets
    difference(universal, vowel, consonant);
    outf << "The set of consonants is: " << endl;
    print(consonant, outf);


    // 7) Write a function to find if two sets are equal
    if (equal(vowel, myname)) {
        outf << "The sets vowel and myname are equal" << endl;
    } else {
        outf << "The sets vowel and myname are not equal" << endl;
    }

    if (equal(vowel, vowel)) {
        outf << "The sets vowel and vowel are equal" << endl;
    } else {
        outf << "The sets vowel and vowel are not equal" << endl;
    }
    outf << endl;

    // 8) Write a function to find if a set is a subset of another
    if (subset(vowel, myname)) {
        outf << "The set vowel is a subset of myname" << endl;
    } else {
        outf << "The set vowel is not a subset of myname" << endl;
    }

    if (subset(vowel, universal)) {
        outf << "The set vowel is a subset of universal" << endl;
    } else {
        outf << "The set vowel is not a subset of universal" << endl;
    }
    outf << endl;


    // 9) add a funciton to find the number of elements in a set called cardinality
    outf << "The cardinality of vowel is: " << cardinality(vowel) << endl;
    outf << "The cardinality of consonant is: " << cardinality(consonant) << endl;

    return 0;
}


void print(bool s[maxset], ofstream &outf) {
    int i;

    for(i='A'; i <= 'Z'; i++) {
        if(s[i]) {
            outf << setw(2) << (char)i;
        } else {
            outf << setw(2) << " ";
        }
    }

    outf << endl << endl;
}


void init(bool universal[maxset], bool vowel[maxset], bool myname[maxset]) {
    int i;
    char ch;
    ifstream inf("in.dat");

    for(i = 'A'; i <= 'Z'; i++) {
        universal[i] = true;
    }

    empty(vowel);
    vowel['A'] = true;
    vowel['E'] = true;
    vowel['I'] = true;
    vowel['O'] = true;
    vowel['U'] = true;

    empty(myname);
    while(!inf.eof()) {
        inf >> ch;
        myname[ch] = true;
    }
}


void setUnion(bool first[maxset], bool second[maxset], bool result[maxset]){ 
    empty(result);
    for(int i = 'A'; i <= 'Z'; i++) {
        if(first[i] || second[i]) {
            result[i] = true;
        }
    }
}


void intersect(bool first[maxset], bool second[maxset], bool result[maxset]) {
    empty(result);
    for(int i = 'A'; i <= 'Z'; i++) {
        if(first[i] && second[i]) {
            result[i] = true;
        }
    }
}


void difference(bool first[maxset], bool second[maxset], bool result[maxset]) {
    empty(result);
    for(int i = 'A'; i <= 'Z'; i++) {
        if(first[i] && !second[i]) {
            result[i] = true;
        }
    }
}


void empty(bool s[maxset]) {
    int i;
    for(i = 'A'; i <= 'Z'; i++) {
        s[i] = false;
    }
}

bool subset(bool first[maxset], bool second[maxset]) {
    bool result = true;
    for(int i = 'A'; i <= 'Z' && result; i++) {
        if(first[i] && !second[i]) {
            result = false;
        }
    }
    return result;
}


bool equal(bool first[maxset], bool second[maxset]) {
    bool result = false;
    if(subset(first, second) && subset(second, first)) {
        result = true;
    }
    return result;
}


int cardinality(bool s[maxset]) {
    int count = 0, i;
    for(i = 'A'; i <= 'Z'; i++) {
        if(s[i]) {
            count++;
        }
    }
    return count;
}
