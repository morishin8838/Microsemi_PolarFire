# USB JTAGをPCに認識させるための設定

## 手順1 libero用設定
1. udev_install スクリプトを動かす
```
$cd /home/<PATH>/Libero_SoC_v2022.1/Libero/bin
$sudo ./udev_install -t /tmp/
```
* こんな感じのメッセージが出る。GROUPIDを変更しなさいと
```
Replace GROUPID tag by the groupid of the Linux group assigned to use the FlashPro5 hardware and
copy the file to /etc/udev/rules.d.
```

2. GROUPIDを確認し、変更する
```
$id
```
* エディタで /tmp/70-microsemi.rules を編集します。"GROUPID"を自分のGROUPIDに変更する
* 自分の場合は uid=1000(xxxxx) gid=1000(xxxx) groups=1000(xxxx) なので "1000"に変更

3. ルールファイルを移動する
```
$sudo mv 70-microsemi.rules /etc/udev/rules.d/
```

4. udevルールをリロードする方法
$sudo udevadm control --reload-rules && udevadm trigger

5
$lsusb
