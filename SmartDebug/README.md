# 手順

## MPF300評価ボード 観測ポイント
*  回路図
    ![PROB_TestPin_CircuitDiagram](images/00A_PROB_TestPin_CircuitDiagram.png "PROB_TestPin_CircuitDiagram")

* MPF300評価ボードの場合、H6/G6は予約されている。
    ![PROB_TestPin](images/00B_PROB_TestPin.png "PROB_TestPin")

* MPF300評価ボードの場合、H6/G6は予約されている。
    ![Constrains](images/01_Constrains.png "Constrains")

## 前準備
1. ホストとターゲット基板をFlashPro5で接続する
2. ターゲット基板電源ON

## 手順
1. SmartDebug( スマート・デバッグ ) の起動 
    1. Generate SmartDebug FPGA Arrayを行う
        ![FPGA_Array](images/02_GenerateSmartDebugFPGAArray.png "FPGA_Array")

    2. SmartDebug Designを起動する
        ![Excute](images/03A_LaunchSmartDebug.png "Excute")

    3. Debug FPGA Arrayを選択
        ![Excute](images/03B_LaunchSmartDebug.png "Excute")

    4. 観察データを設定する。
        1. 信号選択
        2. Addを押す。
        3. Probe A or Bを割り当てる
        ![Excute](images/04_Settingu.png "Excute")


2. 信号を観察する
    1. テストピンにプローブを配置する。
        ![TP](images/00C_PROB_TestPin.png "TP")

    2. 信号を観察する
        ![Oscilloscopes](images/05_Oscilloscopes.png "Oscilloscopes")
        * 500msタイマ信号
        * プッシュボタン信号

