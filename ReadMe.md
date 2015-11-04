# 說明
這是一個增進和同事、朋友之間的惡作劇程式。

# 功能
UI顯示刪除程式。

實際上是讀取硬碟的所有目錄(列在左邊)，並且把目標副檔名(預設為.doc)的檔案給列出來(列在右邊)。

![Alt text](main_dialog.png)

# 關閉程式

直接關閉程式會得到這樣的訊息

![Alt text](close_dialog_message.png)

必須使用工作管理員才可以關閉

# 使用方式


## 修改目標副檔名
由於不同的朋友會關心電腦裡不同的檔案，所以，特別說一下如何修改目標副檔名。

~~~
finderDlg.cpp: line 191
const CString filetype("*.doc");  //target file
~~~
將doc改成任何的其它已知的副檔名即可。
