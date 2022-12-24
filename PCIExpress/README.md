# 開発環境構築手順
 
## Windows PCIe Driver開発手順
* Windows10 21H2
1. Visual Studio 2017 インストール
    * https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/

2. Windows SDKのインストール
    * https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/
    
3. Windows Driver Kit (WDK) インストール
    1. download
        * https://learn.microsoft.com/ja-jp/windows-hardware/drivers/other-wdk-downloads?source=recommendations
        * WDK for Windows 10 Version 1709をダウンロード
    2. wdksetup.exeをクリック実行

### pci_driver ビルドエラー事例と対策
1. 'ntddk.h' : No such file or directory が発生した場合
    - Windowバージョンに適した、WDKのバージョンをインストールする。
        * WDKインストール前に、インストールWDKバージョンに必要なSDKをインストールしておくこと。
    - パスを通す
        * "C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\km"
    
2. "No Target Architecture"が発生した場合
    - プリプロセッサ定義に、"_AMD64_" or "_X86_"を追加
    
3. 'wdf.h':No such file or directory が発生した場合
    - パスを通す
        * "C:\Program Files (x86)\Windows Kits\10\Include\wdf\kmdf\1.31"

4. 'Write.tmh':No such file or directory が発生した場合
  - コンパイル済中間ファイルディレクトリ(objchk_win7_ia64)からtmhをコピーする
  * ここで不具合調査中
    
## Lunux開発手順
* 確認中

