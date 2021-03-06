/*******************************************************************************
* File Name: Wg1.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Wg1.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Wg1_PC =   (Wg1_PC & \
                                (uint32)(~(uint32)(Wg1_DRIVE_MODE_IND_MASK << (Wg1_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Wg1_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Wg1_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Wg1_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Wg1_DR & (uint8)(~Wg1_MASK));
    drVal = (drVal | ((uint8)(value << Wg1_SHIFT) & Wg1_MASK));
    Wg1_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Wg1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Wg1_DM_STRONG     Strong Drive 
*  Wg1_DM_OD_HI      Open Drain, Drives High 
*  Wg1_DM_OD_LO      Open Drain, Drives Low 
*  Wg1_DM_RES_UP     Resistive Pull Up 
*  Wg1_DM_RES_DWN    Resistive Pull Down 
*  Wg1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Wg1_DM_DIG_HIZ    High Impedance Digital 
*  Wg1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Wg1_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Wg1__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Wg1_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Wg1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Wg1_Read(void) 
{
    return (uint8)((Wg1_PS & Wg1_MASK) >> Wg1_SHIFT);
}


/*******************************************************************************
* Function Name: Wg1_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Wg1_ReadDataReg(void) 
{
    return (uint8)((Wg1_DR & Wg1_MASK) >> Wg1_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Wg1_INTSTAT) 

    /*******************************************************************************
    * Function Name: Wg1_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Wg1_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Wg1_INTSTAT & Wg1_MASK);
		Wg1_INTSTAT = maskedStatus;
        return maskedStatus >> Wg1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
