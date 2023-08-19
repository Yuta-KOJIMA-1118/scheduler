# scheduler
  作成者  : 小島佑太
  作成年月: 2023/7/30
### アプリケーションの概要
　このアプリケーションは，FCFS(到着順)とSPT(実行時間順),Round-Robin(定時間は2)の３種類のアルゴリズムを用いたスケジューラーを模擬的に実装したものである．この３つのアルゴリズムのうち，どのアルゴリズムを使用するかを選択することができる．
　また，実行方法には各アルゴリズムごとに２種類ずつあり，あらかじめ用意したテストケースを入力する方法と，プロセスを自動生成し，プログラムを手動で終了するまで無限に実行し続ける方法がある．

### アプリケーションの実行環境と実行方法
　このアプリケーションは，Windows11上での運用を想定されている．それ以外のOS上での動作は保証されない．Windows上で実行すること．
コンパイル方法は，FCFS.c Round_Robin.c scheduler.c scheduler_Main.c SPT.cの５つのファイルをリンクし，同ディレクトリに，FCFS.h, Round_Robin.h, scheduler.h, SPT.hの４つのヘッダーファイルがある状態でコンパイルをする必要がある．
以下のコマンドを使用すればコンパイルが可能である．環境によっては，-std=c99が必要な場合がある.    
　　gcc FCFS.c Round_Robin.c scheduler.c scheduler_Main.c SPT.c -o scheduler   
また，例題のテストケースは，testフォルダに保存されている．リダイレクトで使うことができる．

### 入力の仕様
　Q N
　arrive0 length0
　arrive1 length1
　...
　arrivek lengthk
　...
　arriveN lengthN

　ただし，
Qは，Q=0,1,2を満たし，FCFS,SPT,Round_Robinのうち，どのアルゴリズムを使用するかを表す．  
  FCFS:0, SPT:1, Round_Robin:2  
Nは，プロセスの数を表す. 
arrivekは，k番目のプロセスの到着時間を表す．
lengthkは，k番目のプロセスの実行時間の長さを表す．

N=0が入力された場合，プロセスをランダムで自動生成する．
この場合，arrivek lengthkは入力しない．
その場合，プロセスが終了するごとに，1かそれ以外の数値の入力を要求され，1を入力すると次のプロセスの実行を開始し，それ以外の数値を入力すると，プロセスの実行を停止し，それまでに処理したプロセスの平均応答時間を出力する．
 
###  出力の仕様
arriveは，到着時間を表す．  
startは，実行開始時刻を表す．  
finishは，実行完了時刻を表す．  
responseは，到着してから実行完了するまでにかかった時間を表す．  
response averageは，各プロセスのresponseの平均値を表す．  
また，FCFS_log.txt,SPT_log.txt,R_R_log.txtの1行目に全体のプロセス数と，平均応答時間が書き込まれる．  
2行目以降は，プロセスの実行時間ごとのプロセス数と，平均応答時間が書き込まれる．  
  
### N=0で動作させたときの注意点
　N=0の場合，無限にプロセスが割り振り続けられるとして処理を続ける．そのため，1以外の数値の入力によってプログラムを停止した場合，処理が終わらず，キューに残ったプロセスが存在する．その影響で，Round_Robinにおいて，途中まで実行したが，処理が終わっていないプロセスがキューに残り，平均応答時間に誤差が生じる．Round_Robinの平均応答時間を正確に算出する場合は，十分に大きいプロセス数を処理し，処理が完了していないプロセスの影響を小さくするか，N≠0で実行して，すべてのプロセスの処理を完了させる必要がある．

### make_test.exeの使い方．
　パイプ処理を使い，make_test.exeでの実行結果を，scheduler.exeへ渡す．
この場合，Q Nの順に入力が必要で，例えば，Round_Robinを用いて，1000のプロセスを処理させたい場合は下記のように実行する．   
　　make_test.exe | scheduler.exe   
　　2 1000   
ただし，このプログラムはO(n)に従うため，特別に効率が悪いわけではないが，出力量が多いため，N=100000など，プロセス数を大きくする場合，次にコマンドを使用して，出力をせずにlogへの書き込みでデータを収集することを推奨する．  
    make_test.exe | scheduler.exe > NUL
