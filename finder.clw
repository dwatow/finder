; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFinderDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "finder.h"

ClassCount=3
Class1=CFinderApp
Class2=CFinderDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FINDER_DIALOG

[CLS:CFinderApp]
Type=0
HeaderFile=finder.h
ImplementationFile=finder.cpp
Filter=N

[CLS:CFinderDlg]
Type=0
HeaderFile=finderDlg.h
ImplementationFile=finderDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFinderDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=finderDlg.h
ImplementationFile=finderDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FINDER_DIALOG]
Type=1
Class=CFinderDlg
ControlCount=5
Control1=IDC_LIST1,listbox,1345388808
Control2=IDC_STATIC_SHOWNOW,static,1342308864
Control3=IDC_LIST2,listbox,1345388808
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,button,1342177287

