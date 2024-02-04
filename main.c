#include <stdio.h>

#include "buddy_system.h"

// void main(){
//     int max_size = 1024;
//     make_mem(max_size);
//     void *temp1 = alloc(1,512);
//     print_stat();
//     void *temp2 = alloc(2,120);
//     print_stat();
//     //* This allocation fails as no memory available.
//     void *temp3 = alloc(3,512);
//     delloc(temp1);
//     print_stat();
//     //* Now this succeds
//     temp3 = alloc(3,512);
//     print_stat();
//     delloc(temp2);
//     print_stat();
//     delloc(temp3);
//     print_stat();
// }

/* void main() {
  int max_size = 1024;
  make_mem(max_size);
  int temp1_pg = allocate_page(1, 512);
  void* temp1 = get_process(1);
  printf("Alloc & get proc 1\n");
  print_stat();
  int temp2_pg = allocate_page(2, 512);
  void* temp2 = get_process(2);
  printf("Alloc & get proc 2\n");
  print_stat();
  // Will go in Virt mem
  int temp3_pg = allocate_page(3, 120);
  printf("Alloc proc 3\n");
  print_stat();
  // Will shift proc 3 in mem by shifting some process in virt mem
  get_process(3);
  printf("Get proc 3\n");
  print_stat();
  free_page(3);
  printf("Free proc 3\n");
  print_stat();
  free_page(1);
  printf("Free proc 1\n");
  print_stat();
  int temp4_pg = allocate_page(4, 120);
  printf("Alloc proc 4\n");
  print_stat();
  int temp5_pg = allocate_page(5, 512);
  printf("Alloc proc 5\n");
  print_stat();
  void* temp5 = get_process(5);
  printf("Get proc 5\n");
  print_stat();
} */
#include <stdio.h>
#include "buddy_system.h"

int main()
{
  int max_size;
  printf("Enter the maximum size of the memory: ");
  scanf("%d", &max_size);

  make_mem(max_size);

  int pid, size, choice;
  do
  {
    printf("\n1. Allocate Memory\n");
    printf("2. Free Memory\n");
    printf("3. Display Memory Status\n");
    printf("4. Get Process\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter process ID: ");
      scanf("%d", &pid);
      printf("Enter process size: ");
      scanf("%d", &size);
      allocate_page(pid, size);
      void *temp1 = get_process(1);

      break;

    case 2:
      printf("Enter process ID to free memory: ");
      scanf("%d", &pid);
      free_page(pid);
      get_process(pid);
      break;

    case 3:
      print_stat();
      break;

    case 4:
      printf("Enter process ID to get memory: ");
      scanf("%d", &pid);
      get_process(pid);
      break;

    case 5:
      printf("Exiting program.\n");
      break;

    default:
      printf("Invalid choice. Please enter a valid option.\n");
    }

  } while (choice != 5);

  return 0;
}
