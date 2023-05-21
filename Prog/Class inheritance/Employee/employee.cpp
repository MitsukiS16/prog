#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Employee.h"

using namespace std;

Employee::Employee()
  : name_("No name yet"), net_pay_(0) {
  // deliberately empty
}

Employee::Employee(string name)
  : name_(name), net_pay_(0) {
  // deliberately empty
}

string Employee::get_name() const {
  return name_;
}

double Employee::get_net_pay() const {
  return net_pay_;
}

void Employee::set_net_pay(double net_pay) {
  net_pay_ = net_pay;
}

void read_hours_worked(vector<Employee*> &employees) {
  
}
void calculate_pay(vector<Employee*>& employees) {

}
void print_checks(const vector<Employee*>& employees) {
  
}

int main() {

  { vector<Employee*> employees = {
    new SalariedEmployee("John", 2000),
    new HourlyEmployee("Mary", 10) };
  read_hours_worked(employees);
  calculate_pay(employees);
  print_checks(employees);
  for (const auto& e : employees) delete e; }

{ vector<Employee*> employees = {
    new HourlyEmployee("Peter", 10.31),  
    new SalariedEmployee("Ann", 1957.4) };
  read_hours_worked(employees);
  calculate_pay(employees);
  print_checks(employees);
  for (const auto& e : employees) delete e; }


{ vector<Employee*> employees = {
    new HourlyEmployee("Philip", 10.75),
    new HourlyEmployee("Elisabeth", 9.5),
    new SalariedEmployee("Charles", 5000) };
  read_hours_worked(employees);
  calculate_pay(employees);
  print_checks(employees);
  for (const auto& e : employees) delete e; }

{ vector<Employee*> employees = {
    new SalariedEmployee("John", 2123.5),
    new SalariedEmployee("Peter", 1999.9) };
  read_hours_worked(employees);
  calculate_pay(employees);
  print_checks(employees);
  for (const auto& e : employees) delete e; }

  return 0;
}