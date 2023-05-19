#include <vector>
#include <iostream>
#include "Date.h"
#include "Person.h"

using namespace std;

void born_before(const vector<Person>& persons, const Date& date) {
    Person current;
    Date current_birtdate;
    date.show();
    cout << ": ";
    for(unsigned long i=0; i<persons.size(); i++) {
        current = persons.at(i);
        current_birtdate = current.get_birth_date();
        if( current_birtdate.is_before(date)) {
            current.show();
            cout << " ";
        }
    }
}