#include "phoneHash.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

phoneHash::phoneHash():
title(""), count(0), tableSize(initialTableSize),
phoneBook(NULL)
{
  //allocate new string with default table size
  phoneBook = new std::string*[tableSize];
  for(int i = 0; i < tableSize; i++)
    phoneBook[i] = NULL;
}

phoneHash::~phoneHash()
{
  //free all memory existing in hash table
  if(phoneBook != NULL) {
    for(int i = 0; i < tableSize; i++)
      if(phoneBook[i] != NULL)
        delete [] phoneBook[i];
    delete [] phoneBook;
  }
}

int phoneHash::entries() const
{
  return count;
}

bool phoneHash::insert(const std::string phoneNum, const std::string contact)
{
  //if not a valid phone number(12 digits)
  if(!verifyPhoneNumber(phoneNum))
    return false;

  //if our loadbalance is off we gotta rehash
  if((float)count/(float)tableSize > loadFactor)
    rehash();

  int hLoc = hash(phoneNum);

  //if hash is empty, allocate new spot
  if(phoneBook[hLoc] == NULL) {
    phoneBook[hLoc] = new std::string[2];
    phoneBook[hLoc][0] = phoneNum;
    phoneBook[hLoc][1] = contact;
    count++;
    return true;
  } else {
    while(true) {
      //if the spot is not empty, do linear probing
      hLoc++;
      //start at beginning if end is reached

      if(hLoc >= tableSize)
        hLoc = 0;

      if(phoneBook[hLoc] == NULL) {
        phoneBook[hLoc] = new std::string[2];
        phoneBook[hLoc][0] = phoneNum;
        phoneBook[hLoc][1] = contact;
        count++;
        return true;
      }
    }
  }
  return false;
}

bool phoneHash::remove(const std::string phoneNum)
{
  if(!verifyPhoneNumber(phoneNum))
    return false;
  int hLoc = hash(phoneNum);
  for(int i = 0; i < tableSize; i++) {
    if(phoneBook[hLoc] != NULL && phoneBook[hLoc][0] == phoneNum) {
      delete [] phoneBook[hLoc];
      phoneBook[hLoc] = NULL;
      count--;
      return true;
    }
    hLoc++;
    if(hLoc >= tableSize)
      hLoc = 0;
  }
  return false;
}

bool phoneHash::readPhonebook(const std::string fileName)
{
  //open file
  std::ifstream inFile(fileName.c_str());
  //end if not open
  if(!inFile.is_open())
    return false;
  std::string Ttitle;
  getline(inFile, Ttitle);
  title = Ttitle;
  std::string last, first, phoneNumber;
  //read in all of file
  inFile >> last >> first >> phoneNumber;
  while(inFile) {
    insert(phoneNumber, last + " " + first);
    inFile >> last >> first >> phoneNumber;
  }
}

std::string phoneHash::search(const std::string phoneNum)
{
  //verify correct phone number
  if(!verifyPhoneNumber(phoneNum))
    return "";
  //grab hash and look up
  int hLoc = hash(phoneNum);
  for(int i = 0; i < tableSize;i++) {
    if(phoneBook[hLoc] != NULL && phoneBook[hLoc][0] == phoneNum) {
      return phoneBook[hLoc][1];
    }
    hLoc++;
    if(hLoc >= tableSize)
      hLoc = 0;
  }
  return "";
}

void phoneHash::printPhonebook() const
{
  const char* bold = "\033[1m";
  const char* unbold = "\033[0m";
  std::string dashes;
  dashes.append(60, '-');
  std::cout << dashes << std::endl << bold << title
     << unbold << std::endl << std::endl;
  //cycle through and print all non NULL elements
  std::cout << std::left;
  for(int i = 0; i < tableSize; i++) {
    if(phoneBook[i] != NULL) {
      std::cout << "  " << std::setw(15) << phoneBook[i][0]
        << std::left << std::setw(3) <<
        phoneBook[i][1] << std::endl;
    }
  }
  std::cout << std::endl;
}

int phoneHash::getTablesize() const
{
  return tableSize;
}

bool phoneHash::verifyPhoneNumber(const std::string phoneNum)
{
  //if not proper length, false
  if(phoneNum.length() != 12)
    return false;
  //if any special character appear then false,
  //as well if the - does not appear on 3 or 7
  for(int i = 0; i < phoneNum.length(); i++) {
    if(i == 3 || i == 7) {
      if(phoneNum[i] != '-')
        return false;
    } else {
      if(!isdigit(phoneNum[i]))
        return false;
    }
  }
  return true;
}

int phoneHash::showHash(std::string hash_test) const
{
  return hash(hash_test);
}

int phoneHash::hash(const std::string phoneNumber) const
{
  //variable to represent hash result
  int phoneHashLoc = 0;
  std::istringstream (phoneNumber.substr(phoneNumber.length()-4,4))
    >> phoneHashLoc;
  //return the hash
  return phoneHashLoc % tableSize;
}

void phoneHash::rehash()
{
  //grab pointer to previous block of memory
  std::string oldEntries[count][2];
  int j = 0;
  for(int i = 0; i < tableSize; i++) {
    if(phoneBook[i] != NULL){
      oldEntries[j][0] = phoneBook[i][0];
      oldEntries[j][1] = phoneBook[i][1];
      j++;
    }
  }

  //now free old entry memory
  for(int i = 0; i < tableSize; i++)
    if(phoneBook[i] != NULL)
      delete [] phoneBook[i];
  delete [] phoneBook;

  //double table size
  tableSize = tableSize * 2;
  //create new table, set all elemnts inside to NULL
  phoneBook = new std::string*[tableSize];
  for(int i = 0; i < tableSize; i++)
    phoneBook[i] = NULL;
  count = 0;

  for(int i = 0; i < sizeof(oldEntries) / sizeof(oldEntries[0]); i++) {
    insert(oldEntries[i][0], oldEntries[i][1]);
  }
}
