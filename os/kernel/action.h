#ifndef _ACTION_H
#define _ACTION_H

#include "vm.h"


/* action list */
typedef struct {
    int pid;			/* Owning process. */
    char name[256];
    char *script;
    vm_act_state state;
} peos_action_t;

/* list of nodes other than action nodes. These nodes have states and hence their state has to be saved in the context */

typedef struct {
	int pid;
	char name[256];
	vm_act_state state;
} peos_other_node_t;

/* list of resources */

typedef struct {
	int pid;
	char name[256];
	char value[256];
} peos_resource_t;


typedef enum { 
    ACT_SCRIPT, ACT_AGENT, ACT_REQUIRES, ACT_PROVIDES, ACT_TOOL 
} peos_field_t;

extern int num_actions;
extern int set_act_state(char *act, vm_act_state state, peos_action_t *actions, int num_actions);
extern vm_act_state get_act_state(char *act, peos_action_t *actions, int num_actions);
#endif
