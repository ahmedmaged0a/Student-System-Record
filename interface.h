
#ifndef STUDENTRECORD_INTERFACE_H
#define STUDENTRECORD_INTERFACE_H
#include "privileges.h"
#include <stdio.h>
#include <stdlib.h>
void system_mode(void);
void admin();
void admin_choose();
void admin_control();
void user();
void user_choose();
void user_control(int std_id);
#endif //STUDENTRECORD_INTERFACE_H
