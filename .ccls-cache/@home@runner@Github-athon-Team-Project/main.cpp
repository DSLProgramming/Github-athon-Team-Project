#include "DataValidation.h"

#include <chrono>

#include <iostream>

#include <sys/time.h>

#include <ctime>

#include <string>

#include <math.h>

#include <bits/stdc++.h>

#include <fstream>

#include <iomanip>

#include <stdlib.h>

#include <cctype>

#include <cstring>

#include <vector>

#include <stdio.h>

#include <ctype.h>

#include <array>

#include <cstdlib>

#include <bits/stdc++.h>

using namespace std;

struct userData {
  string donation, donator;

};

void sort(vector < userData > & );
void sortd(vector < userData > & );
void search(vector < userData > & );
void searchd(vector < userData > & );

int main() {
  vector < userData > donations;

  bool loopThrough = true;

  int responseInt = 0;

  string responseStr = "";

  cout << "Welcome to the CompSci Charity System.";

  while (loopThrough) {
    do {
      //menu for user
      cout << "What would you like to do?\n\t1). Donate with your name/organization\n\t2). Donate anonymously\n\t3). View previous donations\n\t4). Search for a donation\n\t5). Exit the CompSci Charity System\n";
    } while (!(getValidInt(responseInt)) || responseInt < 0 || responseInt > 5);
    string name, item;
    userData temp;
    //give user different options depending on what they choose
    switch (responseInt) {
      //asks user for organization and donation
    case 1:
      cout << "What is your name/organization name?\n";
      getline(cin, temp.donator);
      cout << "What are you donating?\n";
      getline(cin, temp.donation);
      donations.push_back(temp);
      break;

      //asks the user for donation and leaves them anonymous
    case 2:
      temp.donator = "Anonymous";
      cout << "What are you donating?\n";
      getline(cin, temp.donation);
      donations.push_back(temp);
      break;

      //allows user to sort data by item
    case 3:
      int sorto;
      cout << "\nWould you like to sort the data by item before you begin?(y/n)\n";
      getline(cin, responseStr);
      if (responseStr == "y" || responseStr == "Y") {
        do {
          cout << "\n1) Sort by donation\n2) Sort by donator" << endl;

        } while (!(getValidInt(sorto)) || sorto < 0 || sorto > 2);
        if (sorto == 1) {
          sort(donations);
        } else if (sorto == 2) {
          sortd(donations);
        }
      } else {
        if (donations.size() == 0) {
          cout << "\nThere is no data\n";
        } else {
          for (int i = 0; i < donations.size(); i++) {
            cout << "\nDonation " << i + 1 << "";
            cout << "\nDonator: " << donations[i].donator;
            cout << "\nItem donated: " << donations[i].donation << "\n";
          }
        }
      }
      break;

      //allows the user to search for donated items
    case 4:
      int searcht;
      do {
        cout << "\n1) Search by donation\n2) Search by donator" << endl;

      } while (!(getValidInt(searcht)) || searcht < 0 || searcht > 2);

      if (searcht == 1) {
        search(donations);
      } else if (searcht == 2) {
        searchd(donations);
      }
      break;
    case 5:
      loopThrough = false;
      break;

    default:
      cout << "Invalid input, please try again." << endl;
      break;
    }
  }

}

void sort(vector < userData > & data) {
  userData temp;
  for (int i = data.size() - 1; i > 0; i--) {
    int first = 0;
    for (int j = 1; j <= i; j++) {
      if (data[j].donation > data[first].donation) {
        first = j;
        //finding the largest value
      }
      //swapping values
      temp = data[first];
      data[first] = data[i];
      data[i] = temp;
    }
  }
  if (data.size() == 0) {
    cout << "\nThere is no data\n";
  } else {
    for (int i = 0; i < data.size(); i++) {
      cout << "\nDonation " << i + 1 << "";
      cout << "\nDonator: " << data[i].donator;
      cout << "\nItem donated: " << data[i].donation << "\n";
    }
  }
}

void sortd(vector < userData > & data) {
  userData temp;
  for (int i = data.size() - 1; i > 0; i--) {
    int first = 0;
    for (int j = 1; j <= i; j++) {
      if (data[j].donator > data[first].donator) {
        first = j;
        //finding the largest value
      }
      //swapping values
      temp = data[first];
      data[first] = data[i];
      data[i] = temp;
    }
  }
  if (data.size() == 0) {
    cout << "\nThere is no data\n";
  } else {
    for (int i = 0; i < data.size(); i++) {
      cout << "\nDonation " << i + 1 << "";
      cout << "\nDonator: " << data[i].donator;
      cout << "\nItem donated: " << data[i].donation << "\n";
    }
  }
}

void search(vector < userData > & data) {
  string key = "";
  int occurances = 0;
  cout << "\nWhat donation would you look to look for?\n" << endl;
  getline(cin, key);
  for (int i = 0; i < data.size(); i++) {
    //allows the data to be entered and compared regardless of caps locks
    if (strcasecmp(key.c_str(), data[i].donation.c_str()) == 0) {
      cout << "\nA donation of the item was found in index " << i + 1 << ", it was donated by " << data[i].donator << "." << endl;
      occurances++;
    }
  }
  if (occurances == 0) {
    cout << "\nThe donation was not found in the data." << endl;
  }
}

void searchd(vector < userData > & data) {
  string key = "";
  int occurances = 0;
  cout << "\nWhat donator would you look to look for?\n" << endl;
  getline(cin, key);
  for (int i = 0; i < data.size(); i++) {
    //allows the data to be entered and compared regardless of caps locks
    if (strcasecmp(key.c_str(), data[i].donator.c_str()) == 0) {
      cout << "\nThe donator of was found in index " << i + 1 << ", the item donated was " << data[i].donation << "." << endl;
      occurances++;
    }
  }
  if (occurances == 0) {
    cout << "\nThe donator was not found in the data." << endl;
  }
}