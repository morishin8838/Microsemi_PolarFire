# PolarFire For Microsemi FPGA

## LibroへのHDL展開方法
1. SmartHLS上で、C++ソースコード作成する。シュミレーションなどを行う。問題なければ、2に進む
2. SmartHLS上で、Compile Software to Hardwareを実行し、hls_output/scripts/create_hdl_plus.tclを生成する。
3. Libroを起動し、展開したいプロジェクトをオープンする。オープン後、[Project] → [Execute Script...] をクリックし、create_hdl_plus.tcl ファイルを実行します。
4. 成功すると、Successメッセージが流れる。

## HDLの差し替え方法
1. SmartHLS上で、C++ソースコードを修正し、Compile Software to Hardwareを実行し、hls_output/scripts/create_hdl_plus.tclを生成する。
2. Libro上で、差し替え対象のHDLを選択し、unlinkを押す。Libro上で、HDLが欠落し赤く着色されていることを確認する。
3. [Project] → [Execute Script...] をクリックし、create_hdl_plus.tcl ファイルを実行します
4. 赤くなっている置き換え対象のコンポーネントを右クリックし、[Replace Component…] を選択し、新しくインポートされたモジュール名（例えば xxxx_topとか)を選択して、置き換えます。
5.  “Generate Component” ボタンをクリックし、その後、デザインフロータブから Generate FPGA Array Dataをクリックし、bitstrem生成を待つ。
6. FPGAデータを書き込む


## 問題対応
1. smarthlsのプロジェクトをインポート後、ソースコード上に赤い下線がある場合の修正方法
     * メニューProject からC/C++ Index-> を選択し、rebuild(再構築)を行う。これにより、Eclipse のインデックス作成の問題が修正されるみたい


