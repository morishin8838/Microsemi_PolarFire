# PolarFire For Microsemi FPGA開発記録

## ファイル構成
```
├ EVAL_KIT/ 
│├ MPF300-EVAL-KIT/
│└ MPF300-VIDEO-KIT/
│
├ Identify/
│
├ Libero/
│└ PCIExpress/
│
├ SmartHLS/
│
├ SmartDebug/
│
├ Ubuntu/
│└ USB_Device_Name/
```


## Windows PCIe Driver開発手順
1. Visual Studio 2017 インストール
2. Windows SDKのインストール
    1. https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/
    2. インストール Windows 10 SDK, version 2004 (10.0.19041.0)
3. Windows Driver Kit (WDK) インストール
    1. download
        * https://learn.microsoft.com/ja-jp/windows-hardware/drivers/other-wdk-downloads?source=recommendations
        * Windows の対象バージョンにあったものを選択。ここでは、Windows 10、バージョン 21H2用 
        * https://go.microsoft.com/fwlink/?linkid=2128854
    2. wdksetup.exeをクリック実行
    
