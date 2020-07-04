# 課題 4 レポート

bb35319015 沖野玄勇

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた 14 人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本 14 人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の 3 つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
まずは構造体配列に、学籍番号、性別、身長を格納した。
その次に、入力したＩＤが構造体配列に格納されているＩＤと一致すれば、構造体配列に格納されているＩＤ、性別、身長を出力する。
## 入出力結果

例えば，ID 45313125 のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124 のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment #20200507]
- 課題じたいを私が書き換えています．簡単になったと思うので再度挑戦してみてください．

[comment #20200621]
- IDは整数なので, IDに関係するところを整数型にしましょう. 

[comment #20200704]
- OKです.
