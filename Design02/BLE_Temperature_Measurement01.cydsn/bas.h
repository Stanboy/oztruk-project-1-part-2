/*******************************************************************************
* File Name: bas.h
*
* Version 1.0
*
* Description:
*  Contains the function prototypes and constants available to the example
*  project.
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <project.h>

/***************************************
*          Constants
***************************************/

#define BATTERY_TIMEOUT             (3u)       /* Counts of 1 second */

#define SIM_BATTERY_MIN             (0u)        /* Minimum simulated battery level measurement */
#define SIM_BATTERY_MAX             (10u)       /* Maximum simulated battery level measurement */
#define SIM_BATTERY_INCREMENT       (1u)        /* Value by which the battery level is incremented */                             

#define MEASURE_BATTERY_MAX         (3000)      /* Use 3V as battery voltage starting */
#define MEASURE_BATTERY_MID         (2800)      /* Use 2.8V as a knee point of discharge curve @ 29% */
#define MEASURE_BATTERY_MID_PERCENT (29)        
#define MEASURE_BATTERY_MIN         (2000)      /* Use 2V as a cut-off of battery life */
#define LOW_BATTERY_LIMIT           (10)        /* Low level limit in percent to switch on LED */
    
#define BAS_SERVICE_MEASURE         (0u)        /* First BAS service for measure actual batteru level */  
#define BAS_SERVICE_SIMULATE        (0u)        /* Second BAS service for simulation */  

#define ADC_VREF_MASK               (0x000000F0Lu)
#define ZeroMax                     (90)
#define OneMax                      (180)
#define TwoMax                      (250)
#define ThreeMax                    (370)
#define FourMax                     (480)
#define FiveMax                     (575)
#define SixMax                      (675)
#define SevenMax                    (770)
#define EightMax                    (880)
#define NineMax                     (980)
#define TenMax                      (1500)

/***************************************
*       Function Prototypes
***************************************/
void BasCallBack(uint32 event, void *eventParam);
void MeasureBattery(void);
void SimulateBattery(void);


/***************************************
* External data references
***************************************/
extern uint16 batterySimulation;
extern uint16 batteryMeasure;


/* [] END OF FILE */
