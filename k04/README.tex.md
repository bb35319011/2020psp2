# 課題4 レポート

bb35319011 江島奨悟

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
- l6:学生番号、性別、身長を保持する構造体を宣言
- l20~：
  ファイルオープン処理.
  fp1でheight.csv、fp2でID.csvを操作.
- l54~:
  ファイルから値を取り出して格納.
  height->buf1 , IDs -> buf2.
  格納先の構造体配列にポインタspでアクセス.
  height.csvの読み取りが完了したら終了させる.
- l70：検索値の入力を受け取る
- l73~:
  stDataに格納した学生番号と入力値を総当たり.
  一致した場合その番号のデータを出力してプログラムを終了.
  一致する値がない場合"no data"を出力して終了.


  

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

実行結果
```
input the filename of height:c:\Users\bb35319011\Desktop\2020psp2\sample\heights.csv
the filename of sample: c:\Users\bb35319011\Desktop\2020psp2\sample\heights.csv
input the filename of IDs:c:\Users\bb35319011\Desktop\2020psp2\sample\IDs.csv
the filename of sample: c:\Users\bb35319011\Desktop\2020psp2\sample\IDs.csv
which ID's data do you want?:45313125
---
ID:45313125
gender:female
height:152.400
---
```

## 修正履歴

