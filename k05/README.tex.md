# 課題5 レポート

aa83988848 薗田光太郎

## 課題

工学部20代の男性の身長は女性の身長より大きいと言えるか．男性と女性の平均身長が同じである蓋然性はどのくらいか．男性と女性の平均身長が同じとみなされるときに，標本男性の平均値と標本女性の平均値の差はどの範囲か．工学部20代の男性と女性の身長の分散は等しいとする．

等分散の2標本の平均の差の検定はt検定でおこなえる（調べてプログラムを書け）

## ソースコードの説明
ヒントをお願いします。

## 入出力結果

## 修正履歴

[comment #20200507]
- これは挑戦課題にしました．必修課題はk04までです．
- おそらく統計の授業の最終回あたりで勉強する内容です．
  - https://youtu.be/Det2IBRXajc の「等分散を仮定」の場合です．
  - 1つ目の課題は検定です．まずyoutubeにあるようなtを計算します（教科書にもあると思う）．使うのは，男女標本平均，男女不偏分散，男女サイズです．このtが2.37より大きければ，「危険率１％で差がないとは言えない」と言えます．
  - 2つ目の課題では，差がないときの標本平均の男女差を求めろという問題ですが，これは，上のt値の式で男女標本平均の差の部分（分子の部分）を仮にdとおいて，あとは実際の標本の値を入れて式を作ります．その式　t_d が　2.37以下であれば差がない可能性があると言います．t_dの式の分母を2.37側に移項すれば，dの不等式が求まると思います．やってみましょう！
