# 課題 4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた 14 人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本 14 人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の 3 つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

まず、int 型のメンバ名 gender、double 型のメンバ名 heights をもつ構造体 struct heights を typedef で man_data と再定義した。
main 関数の中は k01~k03 とほとんど同じ。
違うのは while 文の中とその一行前。
新しく宣言した変数は、man_data 型の配列 man。配列 man にアクセスするための添え字用整数型変数 n。
while 文の前に fgets()を使って、読み込む必要がない行を一行目をとばした。
while 文の中では、まず buf に一行分の文字列を格納する。
次に buf から、区切りを", "で指定して、構造体配列へ格納。
最後に構造体配列の中身を表示し、添え字を一つ進める。

推定範囲についてはまったくわからなかった。

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
