/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.22                          *
*        Compiled Jul  4 2013, 15:16:01                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END
#define WT_WINDOWS_TEST_GLOBALS

#include "DIALOG.h"
#include "k_storage.h"
#include "wt_task_gui.h"
#include "wt_bsp_key_led.h"
#include "k_rtc.h"
#include "wt_bsp_file.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)
#define ID_LISTBOX_0    (GUI_ID_USER + 0x01)
#define ID_TEXT_0     (GUI_ID_USER + 0x02)
#define ID_TREEVIEW_0     (GUI_ID_USER + 0x03)
#define ID_BUTTON_OK     (GUI_ID_USER + 0x04)
#define ID_BUTTON_CANCEL     (GUI_ID_USER + 0x05)
#define ID_TEXT_1     (GUI_ID_USER + 0x06)
#define ID_DROPDOWN_0    (GUI_ID_USER + 0x07)



// USER START (Optionally insert additional defines)
// USER END
extern uint8_t WT_StoreFiles_Init(void);

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 100, 25, 280, 200, 0, 0x0, 0 },
	{ LISTBOX_CreateIndirect, "Listbox", ID_LISTBOX_0, 64, 34, 139, 100, 0, 0x0, 0 },
	{ DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_0, 122, 8, 80, 19, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "Filebowser", ID_TEXT_0, 40, 8, 80, 20, 0, 0x0, 0 },
  //{ TREEVIEW_CreateIndirect, "Treeview", ID_TREEVIEW_0, 16, 34, 138, 100, 0, 0x0, 0 },
  //{ TEXT_CreateIndirect, "Text", ID_TEXT_1, 182, 14, 80, 20, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "确定", ID_BUTTON_OK, 37, 170, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "取消", ID_BUTTON_CANCEL, 152, 170, 80, 20, 0, 0x0, 0 },

  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  TREEVIEW_ITEM_Handle   hTreeItemCur;
  TREEVIEW_ITEM_Handle   hTreeItemNew;
  WM_HWIN                hItem;
  int                    NCode;
  int                    Id;
	int 									  i;
  // USER START (Optionally insert additional variables)
  // USER END
	hItem = pMsg->hWin;
	WINDOW_SetBkColor(hItem, GUI_LIGHTGRAY);
	
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
	//WM_SetFocus(hItem);
	
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetFont(hItem,&GUI_Fonthzk12);
    TEXT_SetText(hItem, "测试文件选择");  
	  //
    // Initialization of 'Dropdown'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
		DROPDOWN_SetFont(hItem,&GUI_Fonthzk12);
    DROPDOWN_AddString(hItem, "U盘");
    DROPDOWN_AddString(hItem, "SD卡");
	//
    // Initialization of 'Treeview'
    //
		//WireTest_Process();
		//WT_StoreFiles_Init();
		WT_StoreFiles_Read();
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
		for(i=0;i<TestFolder.number_TotalFile;i++)
		{
			LISTBOX_AddString(hItem, TestFolder.FilesName[i]);
		}
		LISTBOX_SetSel(hItem,TestFolder.number_CurrentFile);

//    hItem = WM_GetDialogItem(pMsg->hWin, ID_TREEVIEW_0);

//    hTreeItemCur = TREEVIEW_GetItem(hItem, 0, TREEVIEW_GET_LAST);
//	  hTreeItemNew = TREEVIEW_ITEM_Create(TREEVIEW_ITEM_TYPE_NODE, "0", 0);
//		TREEVIEW_AttachItem(hItem, hTreeItemNew, hTreeItemCur, TREEVIEW_INSERT_BELOW);
//		hTreeItemCur = TREEVIEW_GetItem(hItem, 0, TREEVIEW_GET_LAST);
//		hTreeItemNew = TREEVIEW_ITEM_Create(TREEVIEW_ITEM_TYPE_NODE, "1", 0);
//		TREEVIEW_AttachItem(hItem, hTreeItemNew, hTreeItemCur, TREEVIEW_INSERT_BELOW);
//   
//		for(i=0;i<TestFolder.number_TotalFile;i++)
//		{
//			hTreeItemCur = TREEVIEW_GetItem(hItem, 0, TREEVIEW_GET_LAST);
//			if(i==0)
//			{
//				TREEVIEW_InsertItem(hItem, TREEVIEW_ITEM_TYPE_LEAF, hTreeItemCur, TREEVIEW_INSERT_FIRST_CHILD,TestFolder.FilesName[i]);
//			}
//			else TREEVIEW_InsertItem(hItem, TREEVIEW_ITEM_TYPE_LEAF, hTreeItemCur, TREEVIEW_INSERT_BELOW,TestFolder.FilesName[i]);
//			
//		}
		//hTreeItemCur = TREEVIEW_GetItem(hItem, 0, TREEVIEW_GET_LAST);
		//TREEVIEW_ITEM_Expand(hItem);
    
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_OK);
		BUTTON_SetFont(hItem,&GUI_Fonthzk12);
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_CANCEL);
		BUTTON_SetFont(hItem,&GUI_Fonthzk12);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_TREEVIEW_0: // Notifications sent by 'Treeview'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_OK: // Notifications sent by 'ok'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_CANCEL: // Notifications sent by 'cancel'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
	case WM_KEY:
		GUI_SendKeyMsg(GUI_KEY_TAB, 1);//改变输入焦点
		break;
	case MY_MESSAGE_CLICK:
		hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
		if(WM_HasFocus(hItem))
		{
			LISTBOX_IncSel(hItem);
		}
		hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
		if(WM_HasFocus(hItem))
		{
			DROPDOWN_IncSel(hItem);
		}
		
		break;
	case MY_MESSAGE_OK:
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_OK);
		if(WM_HasFocus(hItem))
		{
			hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
			TestFolder.number_CurrentFile=LISTBOX_GetSel(hItem);
			TestFile.command = 0;
		}
		else 
		{
			TestFolder.number_CurrentFile=0;
			TestFile.command = 0;
		}
		
		GUI_EndDialog(pMsg->hWin,0);
		//Number_Windos = 0;
		break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN Create_TestDlgWindow( WM_HWIN hWin_para);
WM_HWIN Create_TestDlgWindow( WM_HWIN hWin_para) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, hWin_para, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
