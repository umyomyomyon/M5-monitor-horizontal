# 概要
- モニターアームを使用しているときに、ディスプレイが本当に水平になっているのか気になって仕方がなかったためお手軽な水平器を作成した。
- 加速度計の値をそのまま使用するとノイズ入っているのでRCフィルターを実装し、ある程度のノイズは削除した。

# IMAGE
すごく傾いているとき（赤）

<img width="632" alt="Screen Shot 2022-02-03 at 19 01 59" src="https://user-images.githubusercontent.com/44522011/152321223-5c6a8d7c-a128-4270-8948-4de36a2a96e7.png">

もう少し（緑）

<img width="630" alt="Screen Shot 2022-02-03 at 19 02 13" src="https://user-images.githubusercontent.com/44522011/152321234-50a74c8f-4ca5-4878-95a9-4dfabf48ebfc.png">

傾いていない（青）

<img width="627" alt="Screen Shot 2022-02-03 at 19 02 24" src="https://user-images.githubusercontent.com/44522011/152321248-d0db7f0d-25d6-493c-b3cc-ccda1a1adc1a.png">



# 参考

## M5stickCのセンサー周り
[M5StickCで振動を測定する - AmbientでIoTをはじめよう](https://pages.switch-science.com/letsiot/vibration/)

## LCD周り 
[LCD 画面表示](https://github.com/m5stack/m5-docs/blob/master/docs/ja/api/lcd.md)  

[【Arduino】M5StickCの画面制御を極める！画面表示のすすめ](https://karakuri-musha.com/inside-technology/arduino-m5stickc-04-time-display-for-m5stickc/)

## C言語周り
[Static - Arduino 日本語リファレンス](http://www.musashinodenpa.com/arduino/ref/index.php?f=0&pos=1736)

[引数による情報の受け渡し - 苦しんで覚えるC言語](https://9cguide.appspot.com/15-06.html)

## ノイズ除去周り
[センサの入力などに使うディジタルフィルタ | なんでも独り言](https://ehbtj.com/electronics/sensor-digital-filter/)

[【Arduino】センサのノイズをデジタルフィルタで低減する](https://ppdr.softether.net/arduino-digital-filter)
