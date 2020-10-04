/*
 * LED.h
 *
 * Created: 26/09/2020 12:35:48 p. m.
 *  Author: brios
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "fsl_iomuxc.h"
#include "fsl_gpio.h"

/* GPIO_AD_B0_09 (coord F14), LED_PIN */
#define LED_PIN_GPIO                                        GPIO1   /*!< GPIO device name: GPIO1 */
#define LED_PIN_PORT                                        GPIO1   /*!< PORT device name: GPIO1 */
#define LED_PIN_PIN                                            9U   /*!< GPIO1 pin index: 9 */

/* Led State */
#define LED_ON	0
#define LED_OFF	1

void initLED();
void setLED(int newState);






#endif /* GPIO_H_ */
