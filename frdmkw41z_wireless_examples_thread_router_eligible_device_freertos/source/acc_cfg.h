/*
 * acc_cfg.h
 *
 *  Created on: 18 nov 2024
 *      Author: adrgm
 */

#ifndef ACC_CFG_H_
#define ACC_CFG_H_

void accl_init(void);
void Angle_update (void);
uint16_t RangeX_values(void);
uint16_t RangeY_values(void);
uint16_t RangeZ_values(void);
uint16_t RetX(void);
uint16_t RetY(void);
uint16_t RetZ(void);

#endif /* ACC_CFG_H_ */
