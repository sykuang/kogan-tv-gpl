//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all 
// or part of MStar Software is expressly prohibited, unless prior written 
// permission has been granted by MStar. 
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.  
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software. 
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s 
//    confidential information in strictest confidence and not disclose to any
//    third party.  
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.  
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or 
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.  
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>

#ifndef __DRV_URSA_6M40_C__
#define __DRV_URSA_6M40_C__

//-------------------------------------------------------------------------------------------------
//  Include files
//-------------------------------------------------------------------------------------------------
#include "ursa_6m40.h"

//-------------------------------------------------------------------------------------------------
//  Define
//-------------------------------------------------------------------------------------------------
#define URSA_6M40_CMD_DATA_SUM          (7)
#define URSA_6M40_I2C_BUS_NUM           (2)
#define URSA_6M40_DDC2BI_MODE_ADDR		(0x40)
#define URSA_6M40_I2C_SUB_ADDR          (0)

static SWI2C_BusCfg Ursa_6m40_I2cBusCfg[URSA_6M40_I2C_BUS_NUM]=
{
    // Bus-0
    {PAD_DDCR_CK, PAD_DDCR_DA, 400}, //IS_SW_I2C  /SCL_PAD /SDA_PAD /Delay
    // Bus-1
    {PAD_TGPIO2, PAD_TGPIO3, 400},   //IS_SW_I2C  /SCL_PAD /SDA_PAD /Delay
    // Others, add other bus here
};

//-------------------------------------------------------------------------------------------------
//  Function define
//-------------------------------------------------------------------------------------------------
void MDrv_Ursa_6M40_SWI2C_Init(void)
{
	MApi_SWI2C_Init(Ursa_6m40_I2cBusCfg, URSA_6M40_I2C_BUS_NUM);
}

MS_BOOL MDrv_Ursa_6M40_SWI2C_WriteBytes(MS_U16 u16BusNumSlaveID, MS_U8 u8addrnum, MS_U8* pu8addr, MS_U16 u16size, MS_U8* pu8data)
{
    return MApi_SWI2C_WriteBytes(u16BusNumSlaveID, u8addrnum, pu8addr, u16size, pu8data);
}

MS_BOOL MDrv_Ursa_6M40_SWI2C_ReadBytes(MS_U16 u16BusNumSlaveID, MS_U8 u8addrnum, MS_U8* pu8addr, MS_U16 u16size, MS_U8* pu8data)
{
    return MApi_SWI2C_ReadBytes(u16BusNumSlaveID, u8addrnum, pu8addr, u16size, pu8data);
}

MS_BOOL MDrv_Ursa_6M40_SendCmd(URSA_6M40_CMD_TYPE eCmdType)
{
    MS_U8 pCmdData[URSA_6M40_CMD_DATA_SUM] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    MS_BOOL bUnkown = FALSE;
    MS_BOOL bRet = FALSE;
    
    switch(eCmdType)
    {
        case CMD_6M40_OSD_MUTE:
            {
            //0x43, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00
                pCmdData[0] = 0x43;
                pCmdData[1] = 0x03;
                pCmdData[2] = 0x01;
            }
            break;

        case CMD_6M40_OSD_ON:
            {
            //0x51,  0x04,  0x01,  0x00,  0x00,  0x00,  0x00
                pCmdData[0] = 0x51;
                pCmdData[1] = 0x04;
                pCmdData[2] = 0x01;
            }
            break;

        case CMD_6M40_OSD_OFF:
            {
            //0x41,  0x04,  0x00,  0x00,  0x00,  0x00,  0x00
                pCmdData[0] = 0x41;
                pCmdData[1] = 0x04;
            }
            break;
            
        case CMD_6M40_OSD_UNMUTE:
            {
            //0x33, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
                pCmdData[0] = 0x33;
                pCmdData[1] = 0x03;
            }
            break;

        case CMD_6M40_LVDS_ON:
            {
            //0x93, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00
                pCmdData[0] = 0x93;
                pCmdData[1] = 0x08;
                pCmdData[2] = 0x01;
            }
            break;

        case CMD_6M40_LVDS_OFF:
            {
            //0x83, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00
                pCmdData[0] = 0x83;
                pCmdData[1] = 0x08;
            }
            break;

        default:
            bUnkown = TRUE;
            break;
    }

    if(!bUnkown)
    {
        bRet  = MDrv_Ursa_6M40_Write_Cmd(pCmdData);
        printf("[6m40]Send cmd:%d, return:%d\n", eCmdType, bRet);
    }
    else
    {
        bRet = FALSE;
        printf("[6m40]Can not find the command, please check!\n");
    }
    
    return bRet;
}

MS_BOOL MDrv_Ursa_6M40_Write_Cmd(MS_U8 *pu8CmdData)
{
    MS_U16 u16BusNumSlaveID = URSA_6M40_DDC2BI_MODE_ADDR;
    MS_U8 u8SubAddr = URSA_6M40_I2C_SUB_ADDR;
    
    MDrv_Ursa_6M40_SWI2C_Init();
    printf("[6m40]Write cmd:%x,%x,%x,%x,%x,%x,%x\n", pu8CmdData[0], pu8CmdData[1], pu8CmdData[2], pu8CmdData[3], pu8CmdData[4], pu8CmdData[5], pu8CmdData[6]);
    return MDrv_Ursa_6M40_SWI2C_WriteBytes(u16BusNumSlaveID, u8SubAddr, NULL, URSA_6M40_CMD_DATA_SUM, pu8CmdData);
}
//-------------------------------------------------------------------------------------------------
//  Member Function
//-------------------------------------------------------------------------------------------------
MS_BOOL MDrv_Ursa_6M40_Set_Osd_On(void)
{
    return MDrv_Ursa_6M40_SendCmd(CMD_6M40_OSD_ON);
}

MS_BOOL MDrv_Ursa_6M40_Set_Osd_Off(void)
{
    return MDrv_Ursa_6M40_SendCmd(CMD_6M40_OSD_OFF);
}

MS_BOOL MDrv_Ursa_6M40_Set_Osd_Mute(void)
{
    return MDrv_Ursa_6M40_SendCmd(CMD_6M40_OSD_MUTE);
}

MS_BOOL MDrv_Ursa_6M40_Set_Osd_Unmute(void)
{
    return MDrv_Ursa_6M40_SendCmd(CMD_6M40_OSD_UNMUTE);
}

MS_BOOL MDrv_Ursa_6M40_Set_Lvds_On(void)
{
    return MDrv_Ursa_6M40_SendCmd(CMD_6M40_LVDS_ON);
}

MS_BOOL MDrv_Ursa_6M40_Set_Lvds_Off(void)
{
    return MDrv_Ursa_6M40_SendCmd(CMD_6M40_LVDS_OFF);
}

#endif //__DRV_URSA_6M40_C__

