#include <linux/getInfoSpring2024.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <asm/current.h>
#include <asm/uaccess.h>

asmlinkage int sys_getInfoSpring2024(struct structSpring2024 *data) {
 cli();

 struct structSpring2024 infoStructure;
 struct task_struct *currentStructure;

 copy_from_user(&infoStructure, data, sizeof(struct structSpring2024));
 currentStructure = get_current();

 if(infoStructure.flag <= 24 && infoStructure.flag > 0) {
  infoStructure.pid = currentStructure->pid;
  infoStructure.pid_parent = currentStructure->p_opptr->pid;
  infoStructure.process_counter = currentStructure->counter;
  infoStructure.nice = currentStructure->nice;
  infoStructure.nice_parent = currentStructure->p_opptr->nice;
  infoStructure.uid = currentStructure->uid;
  infoStructure.weight = (currentStructure->counter) ? currentStructure->counter + 20 - currentStructure->nice: 0;
  copy_to_user(data, &infoStructure, sizeof(struct structSpring2024));
  sti();
  return 0;
 }

 else if(infoStructure.flag > 24) {
  int weight = (currentStructure->counter) ? currentStructure->counter + 20 - currentStructure->nice: 0;
  sti();
  return weight;
 }

 else {
  sti();
  return -1;
 }
}