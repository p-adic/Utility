// c:/Users/user/Documents/Programming/Utility/Time/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"
#include <chrono>

static inline chrono::system_clock::time_point& GetWatch() { static chrono::system_clock::time_point watch; return watch; }
static inline int& GetWatchCount() { static int watch_count; return watch_count; }

void StartWatch( const string& process_name )
{

  static int count = 0;

  if( GetWatchCount() == 0 ){

    if( process_name == "nothing" ){

      cout << count << ". Start counting execution time:" << endl;;

    } else {

    cout << count << ". Start counting execution time of " << process_name << " " << endl;

    }

    count++;
    GetWatch() = chrono::system_clock::now();

  }
  
  return;

}

void StopWatch( const int& how_many_times )
{

  int& count = GetWatchCount();
  count++;

  if( count == how_many_times ){

    const double time = static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - GetWatch() ).count() / 1000.0 );
    cout << "Stop counting execution time: " << time << " [ms] par " << how_many_times << " executions" << endl;
    count = 0;

  }
  
  return;

}
