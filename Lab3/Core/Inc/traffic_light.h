/*
 * traffic_light.h
 *
 *  Created on: Nov 24, 2025
 *      Author: TD
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"

//điều khiển đèn giao thông hướng X
void light_traffic_redX(void);
void light_traffic_yellowX(void);
void light_traffic_greenX(void);

//điều khiển đèn giao thông hướng Y
void light_traffic_redY(void);
void light_traffic_yellowY(void);
void light_traffic_greenY(void);

//toggle cho manual mode
void toggle_all_red(void);
void toggle_all_green(void);
void toggle_all_yellow(void);


void clear_red_green_yellow(void);

#endif /* INC_TRAFFIC_LIGHT_H_ */
