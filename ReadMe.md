# ����
�o�O�@�ӼW�i�M�P�ơB�B�ͤ������c�@�@�{���C

# �\��
UI��ܧR���{���C

��ڤW�OŪ���w�Ъ��Ҧ��ؿ�(�C�b����)�A�åB��ؼа��ɦW(�w�]��.doc)���ɮ׵��C�X��(�C�b�k��)�C

![Alt text](main_dialog.png)

# �ק�

## �����{��

�ثe��bgithub�W�������A�O�i�H���`�����������C

�n�ק令�c�@�@�����p�A�y�����Y�������W�A�i�H�̤U�C�B�J�ק�A�����L�k���`�������{���C

finderDlg.cpp

line 294 �Ѱ�����
~~~
// 	AfxMessageBox("�Ы��u�T�w�v�~��R���C");
~~~

line 327 �[�W����
~~~
CDialog::OnClose();
~~~

�粒���ĪG�A���������{���|�o��o�˪��T��

![Alt text](close_dialog_message.png)

�����ϥΤu�@�޲z���~�i�H����

## �ק�ؼа��ɦW

�ѩ󤣦P���B�ͷ|���߹q���̤��P���ɮסA�ҥH�A�S�O���@�U�p��ק�ؼа��ɦW�C

finderDlg.cpp: line 191
~~~
const CString filetype("*.doc");  //target file
~~~
�Ndoc�令���󪺨䥦�w�������ɦW�Y�i�C

## �w�]�ϥΡu�t�κ޲z������v

�]�w Visual Studio �M����

[Project]>[Properties]>[Linker]>[Manifest File]

�]�wUAC Execution Level: requireAdministrator

�ѦҡGhttp://mqjing.blogspot.tw/2008/12/blog-post.html