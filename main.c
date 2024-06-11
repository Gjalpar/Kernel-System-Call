#include <linux/getInfoSpring2024.h>
#include <stdio.h>

int main() {
 struct structSpring2024 infoStructure;

 infoStructure.flag = 10;
 int result = getInfoSpring2024(&infoStructure);

 if(result == 0) {
  printf("Flag: %d\n", infoStructure.flag);
  printf("PID: %d\n", infoStructure.pid);
  printf("Parent PID: %d\n", infoStructure.pid_parent);
  printf("Process Counter: %d\n", infoStructure.process_counter);
  printf("Nice: %d\n", infoStructure.nice);
  printf("Parent's Nice: %d\n", infoStructure.nice_parent);
  printf("UID: %d\n", infoStructure.uid);
  printf("Weight: %d\n", infoStructure.weight);
 }

 else if(result == -1) {
  printf("Invalid flag value.\n");
 }

 else {
  printf("Weight: %d\n", result);
 }

 return 0;
}