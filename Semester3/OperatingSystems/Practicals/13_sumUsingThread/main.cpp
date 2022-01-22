/**
 * Write a program to calculate sum of n numbers using thread library.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <pthread.h>

using namespace std;

long long sum;

void *runner(void *number);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cerr << "Usage: ./main <upper>" << endl;
    exit(1);
  }

  if (atoi(argv[1]) < 0)
  {
    cerr << "Argument must be non-negative." << endl;
    exit(1);
  }

  pthread_t tid;
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, runner, (void *)argv[1]);
  pthread_join(tid, NULL);

  cout << "Sum from 1 to " << atoi(argv[1])
       << " is " << sum << endl;

  return 0;
}

void *runner(void *upper)
{
  int num = atoi((const char *)(upper));
  for (int i = 1; i <= num; i++)
    sum += i;
  pthread_exit(0);
  return nullptr;
}
