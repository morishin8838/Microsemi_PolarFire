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
3. Windows Driver Kit (WDK) インストール
    1. download
        * https://learn.microsoft.com/ja-jp/windows-hardware/drivers/other-wdk-downloads?source=recommendations
        * WDK for Windows 10 Version 1709をダウンロード
    2. wdksetup.exeをクリック実行
    
