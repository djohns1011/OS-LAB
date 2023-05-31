#include<stdio.h>
struct priority_scheduling {
  int process_id;
  int burst_time;
  int arrival_time;
  int waiting_time;
  int turn_around_time;
  int priority;
};

int main() {
  int number_of_process;
  struct priority_scheduling temp_process;
  int position;
  float total_waiting_time, total_turnaround_time;
  float average_waiting_time, average_turnaround_time;
  printf("Enter the total number of Processes: ");
  scanf("%d", & number_of_process);
  struct priority_scheduling process[number_of_process];
  printf("\nPlease Enter the  Burst Time, Arrival Time and Priority of each process:\n");
  for (int i = 0; i < number_of_process; i++) {
    printf("\nEnter the details of the process %d: \n", i+1);
    scanf("%d %d %d", & process[i].burst_time, & process[i].arrival_time, & process[i].priority);
  }
  for (int i = 0; i < number_of_process; i++) {
    position = i;
    for (int j = i + 1; j < number_of_process; j++) {
      if (process[j].priority > process[position].priority)
        position = j;
    }
    temp_process = process[i];
    process[i] = process[position];
    process[position] = temp_process;
  }
  process[0].waiting_time = 0;
  for (int i = 1; i < number_of_process; i++) {
    process[i].waiting_time = 0;
    for (int j = 0; j < i; j++) {
      process[i].waiting_time += process[j].burst_time;
    }         
    total_waiting_time += process[i].waiting_time;
  }
  
  average_waiting_time = (float) total_waiting_time / (float) number_of_process;
  printf("\n\n|Process_id |\t Burst Time |\t Arrival Time |\t Priority |\t Waiting Time |\t Turnaround Time|\n");
  printf("---------------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < number_of_process; i++) {
    process[i].turn_around_time = process[i].burst_time + process[i].waiting_time;
    total_turnaround_time += process[i].turn_around_time;
    printf("\t  %d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d", i, process[i].burst_time, process[i].arrival_time, process[i].priority, process[i].waiting_time, process[i].turn_around_time);
    printf("\n---------------------------------------------------------------------------------------------------\n");
  }
  average_turnaround_time = (float) total_turnaround_time / (float) number_of_process;
  printf("\nTotal Waiting Time : %f", total_waiting_time);
  printf("\nTotal Turnaround Time : %f", total_turnaround_time);
  printf("\n Average Waiting Time : %f", average_waiting_time);
  printf("\n Average Turnaround Time: %f\n", average_turnaround_time);
  return 0;
}
