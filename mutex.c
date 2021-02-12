#include <stdlib.h> 
#include <stdio.h> 
#include <pthread.h>
#include <string.h>
#include <unistd.h>



// function declarations
void display(int n1, int n2, char ch, int result);
void* add();
void* subtract();

//mutex declaration
pthread_mutex_t mutex;

// main function
int main(int argc, char* argv[])
{
//thread declaration
pthread_t p1, p2;

//mutex initialization
if(pthread_mutex_init(&mutex, NULL) != 0)
{
 printf("can't initiate mutex");
}

//thread creation or initialization
if (pthread_create(&(p1), NULL, &add, NULL) != 0)
 { 
}
if (pthread_create(&(p2), NULL, &subtract, NULL) != 0) 
{
}

//join is used to wait for the termination of a thread
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
//destroy the mutex created
    pthread_mutex_destroy(&mutex); 
//to end a thread - pthread_exit()
//to end a process - exit()
//Note: If we use exit() instead of pthread_exit() to end a thread,
//the whole process with all associated threads will be terminated even if some of the threads may still be running.
    pthread_exit(NULL);
  
  return 0;
}

// function for taking input from user
int input()
{
  int n;
  printf("Enter number: ");
  scanf("%d",&n);
  return n;
}

// function for displaying the result.
void display(int n1, int n2, char ch, int result)
{
  printf("%d %c %d = %d\n", n1, ch, n2, result);
}

// function for addition of two numbers
void* add()
{
  pthread_mutex_lock(&mutex);
  int n1, n2;
  n1 = input();
  n2 = input();
  display(n1,n2,'+',n1+n2);
  pthread_mutex_unlock(&mutex);
}
 
// function for subtraction of two numbers
void* subtract()
{
  pthread_mutex_lock(&mutex);
  int n1, n2;
  n1 = input();
  n2 = input();
  display(n1,n2,'-',n1-n2);
  pthread_mutex_unlock(&mutex); 
}





