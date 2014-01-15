//<MStar Software>
//***********************************************************************************
//MStar Software
//Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
//All software, firmware and related documentation herein (“MStar Software”) are intellectual property of MStar Semiconductor, Inc. (“MStar”) and protected by law, including, but not limited to, copyright law and international treaties.  Any use, modification, reproduction, retransmission, or republication of all or part of MStar Software is expressly prohibited, unless prior written permission has been granted by MStar. 
//By accessing, browsing and/or using MStar Software, you acknowledge that you have read, understood, and agree, to be bound by below terms (“Terms”) and to comply with all applicable laws and regulations:
//
//1. MStar shall retain any and all right, ownership and interest to MStar Software and any modification/derivatives thereof.  No right, ownership, or interest to MStar Software and any modification/derivatives thereof is transferred to you under Terms.
//2. You understand that MStar Software might include, incorporate or be supplied together with third party’s software and the use of MStar Software may require additional licenses from third parties.  Therefore, you hereby agree it is your sole responsibility to separately obtain any and all third party right and license necessary for your use of such third party’s software. 
//3. MStar Software and any modification/derivatives thereof shall be deemed as MStar’s confidential information and you agree to keep MStar’s confidential information in strictest confidence and not disclose to any third party.  
//4. MStar Software is provided on an “AS IS” basis without warranties of any kind. Any warranties are hereby expressly disclaimed by MStar, including without limitation, any warranties of merchantability, non-infringement of intellectual property rights, fitness for a particular purpose, error free and in conformity with any international standard.  You agree to waive any claim against MStar for any loss, damage, cost or expense that you may incur related to your use of MStar Software.  
//   In no event shall MStar be liable for any direct, indirect, incidental or consequential damages, including without limitation, lost of profit or revenues, lost or damage of data, and unauthorized system use.  You agree that this Section 4 shall still apply without being affected even if MStar Software has been modified by MStar in accordance with your request or instruction for your use, except otherwise agreed by both parties in writing.
//5. If requested, MStar may from time to time provide technical supports or services in relation with MStar Software to you for your use of MStar Software in conjunction with your or your customer’s product (“Services”).  You understand and agree that, except otherwise agreed by both parties in writing, Services are provided on an “AS IS” basis and the warranty disclaimer set forth in Section 4 above shall apply.  
//6. Nothing contained herein shall be construed as by implication, estoppels or otherwise: (a) conferring any license or right to use MStar name, trademark, service mark, symbol or any other identification; (b) obligating MStar or any of its affiliates to furnish any person, including without limitation, you and your customers, any assistance of any kind whatsoever, or any information; or (c) conferring any license or right under any intellectual property right.
//7. These terms shall be governed by and construed in accordance with the laws of Taiwan, R.O.C., excluding its conflict of law rules.  Any and all dispute arising out hereof or related hereto shall be finally settled by arbitration referred to the Chinese Arbitration Association, Taipei in accordance with the ROC Arbitration Law and the Arbitration Rules of the Association by three (3) arbitrators appointed in accordance with the said Rules.  The place of arbitration shall be in Taipei, Taiwan and the language shall be English.  
//   The arbitration award shall be final and binding to both parties.
//
//本處所有軟體、韌體及相關文檔(下稱「MStar Software」)均為MStar Semiconductor, Inc. (下稱「MStar」)之智慧財產權並為相關法律(包括但不限於著作權法及國際條約)所保護，任何未經MStar事前書面野i之使用、修改、重製、傳送或公開均為禁止的。
//一旦您進入、瀏覽或使用MStar Software，您即聲明您已詳讀、了解並同意為下列條款（下稱「本條款」）所拘束並將遵守相關法規之規定：
//
//1.	MStar仍保有MStar Software及其修改物／衍生物之任何與全部的權利、所有權及利益，您並未因本條款而取得關於MStar Software及其修改物／衍生物之任何與全部的權利、所有權及利益。
//2.	您了解MStar Software可能含有或結合有屬於第三人之軟體或係與第三人之軟體一併提供，而使用MStar Software可能需另行向第三人取得授權，因此您同意您將自行負責向此等第三人取得授權以合法使用MStar Software。
//3.	MStar Software及其修改物／衍生物應被視為MStar的機密資訊，您同意將以最機密保存MStar的機密資訊且不將之揭露予任何第三人。
//4.	MStar Software係「依現狀」所提供而無任何擔保。MStar於此否認對MStar Software提供任何擔保，包括但不限於可商品化、不侵權、符合特定使用目的、無瑕疵及符合任何國際標準之擔保。您同意將不會對MStar主張您因使用MStar Software所生之任何損失、損害、費用或支出。於任何情況下，MStar對於直接的、間接的、附帶的或必然的損害均不負責任，包括但不限於利潤營收損失、資料之毀損遺失及系統被未經授權使用。您並同意，除雙方另有書面協議外，即使MStar曾依您的要求或指示而修改MStar Software，本第4條之規定仍繼續適用而不受影響。
//5.	如經要求，MStar不時將提供技術支援或服務予您，以利您的產品可以與MStar Software一同使用(下稱「服務」)，您了解並同意，除雙方另有書面協議外，所有服務均係「以現狀」提供，第4條之不提供擔保相關規定亦應適用之。
//6.	本條款之任何條款不得被解釋為(無論依默示、禁反言原則或其它)：(a) 授予任何權利以使用MStar之名稱、商標、服務標章、符號或其它識別圖像；(b)課予MStar或其關係企業提供予任何人(包括但不限於您及您的客戶)任何形式的協助或資訊的義務；或(c) 授予任何智慧財產權。
//7.	本條款應依中華民國法律為準據法(不含其衝突法則)。任何基於本條款所生或與本條款相關之爭議最終應依中華民國仲裁法及該協會之仲裁規則解決，仲裁應由3名仲裁人以英文在台灣台北進行，仲裁人應依中華民國仲裁協會之仲裁規則選出，仲裁判斷應為終局的且對雙方均有拘束力。
//***********************************************************************************
//<MStar Software>

///////////////////////////////////////////////////////////////////////////////////////////////////
///
/// file    cmd_secure.c
/// @brief  SCS Main Function
/// @author MStar Semiconductor Inc.
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <common.h>
#include <command.h>
#include <secure/MsSecureBoot.h>
#include <secure/MsSecureUpgrade.h>
#include <secure/MsSignature.h>
          

U_BOOT_CMD(
    store_secure_info, 3, 0, do_save_secure_info,
    "store secure info\n",
    "store_secure_info targetName(hex) imageDramAddr(hex)\n"
    );

U_BOOT_CMD(SecureInit, 7, 0, do_Secure_Init,
            "Init security booting.\n",
            "SecureInit\n"
            );

U_BOOT_CMD(
	verify_sha256, 5, 0,do_verify_sha256,
	"This command is only for verification \n",
	"verify_sha256 intAddr(hex) outAddr(hex) intLen(hex) count(hex)\n"
    );

U_BOOT_CMD(
	sha256, 4, 0,do_sha256,
	"The sha256 cacluate \n",
	"sha256 intAddr(hex) outAddr(hex) intLen(hex)\n"
    );

U_BOOT_CMD(
	rsa, 4, 0,do_rsa,
	"rsa cacluate \n",
	"rsa signAddr(hex) keyAddr(hex) outAddr(hex)\n"
    );

U_BOOT_CMD(se_ut1, 1, 0, do_DoSecureEngUnitTestCase1,
            "The test case 1 for secure engine \n",
            "se_ut1"
            );
U_BOOT_CMD(se_ut2, 1, 0, do_DoSecureEngUnitTestCase2,
            "The test case 2 for secure engine \n",
            "se_ut2"
            );
U_BOOT_CMD(se_ut3, 1, 0, do_DoSecureEngUnitTestCase3,
            "The test case 3 for secure engine \n",
            "se_ut3"
            );

U_BOOT_CMD(se_ut4, 1, 0, do_DoSecureEngUnitTestCase4,
            "The test case 4 for secure engine \n",
            "se_ut4"
            );

U_BOOT_CMD(se_ut5, 1, 0, do_DoSecureEngUnitTestCase5,
            "The test case 5 for secure engine \n",
            "se_ut5"
            );


U_BOOT_CMD(filepartloadSegAES, 7, 0, do_file_part_load_with_segment_aes_decrypted,
            "load a part of file to RAM and do descrypted",
            "filepartloadSegAES interface(hex) device(hex) addr(hex) filename(hex) offset(hex) bytes(hex)\n"
            );


U_BOOT_CMD(fileSegRSA, 4, 0, do_file_segment_rsa_authendication,
            "do file segment rsa authendication",
            "fileSegRSA interface(hex) device(hex) filename(hex) \n"
            );


U_BOOT_CMD(authenticate, 2, 0, do_Authenticate,
            "authenticate the kernel image",
            "[image name]\n"
            "image name]:KL RFS,MSLIB,APP\n"
            );

U_BOOT_CMD(dumpSignature, 2, 0, do_DumpSignature,
            "dump the signature",
            "[target file]\n"
            "target file:KL,RFS,MSLIB,APP\n"
            );

U_BOOT_CMD(
    stest, 3, 1,    do_performance_test,
    "test IO performance on continue mode or interleave mode]\n",
    "-c [partition]\n"
    "-i [partition]\n"    
);


