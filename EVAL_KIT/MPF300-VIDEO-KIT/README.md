# PolarFire For Microsemi FPGA


## Libero プロジェクト展開時にシャットダウンする不具合があります。その対応
* 症状
    - Videoキットのプロジェクトサンプルmpf_dg0849_liberosoc_dfを起動すると、ワーニング表示後に、アプリが落ちる。

* 対処方法
    1. VIDEO_KIT_TOP.sdbを当該プロジェクトのVIDEO_KIT_TOP.sdbと置き換える
        * 置換パス {プロジェクトパス}\VKPFC2RX2K4K_PIP\component\work\VIDEO_KIT_TOP\VIDEO_KIT_TOP.sdb
    2. その後、再度にLiberoを起動し、プロジェクトをオープンする。

* 原因
    - おそらくLibroのバグです。

