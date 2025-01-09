/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()

#include "utils.h"

std::string kYourName = "Eshan Bhargava"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.

  std::ifstream ifs(filename);
  std::set<std::string> set;

  if (ifs.is_open()){
    std::string line;
    while (std::getline(ifs, line)){
      set.insert(line);
      // std::cout << line << std::endl;
    }
  }
  ifs.close();

  return set;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> same_initials_q;
  auto start = students.begin();
  auto end = students.end();

  for (auto it = start; it != end; ++it){
    const auto& elem = *it;
    std::stringstream ss(elem);
    std::string f_name;
    std::string l_name;

    std::getline(ss, f_name, ' ');
    std::getline(ss, l_name, ' ');

    if (f_name[0] == 'E' && l_name[0] == 'B'){ same_initials_q.push(&elem); }
    
  }

  return same_initials_q;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  std::vector<std::string> vec;
  auto tmpQ = matches;

  while (!tmpQ.empty()){
    vec.push_back(*tmpQ.front());
    tmpQ.pop();
  }
  std::srand(std::time(nullptr)); // Seed with current time
  int randomIndex = std::rand() % vec.size();

  return vec[randomIndex];
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
