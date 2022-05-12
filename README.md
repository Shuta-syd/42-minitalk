# minitalk

### Summary

このプロジェクトの目的は、UNIXシグナルを使った小さなデータ交換プログラムをコーディングすること

## Project instructions

- 実行ファイルにclientとserverという名前をつけてください。
    
    Name your executable files client and server.
    
- ソースファイルをコンパイルするためのMakefileを提出する必要があります。このファイルは
再リンクしてはいけません。
    
    You have to turn in a Makefile which will compile your source files. It must not
    relink.
    
- libftは使ってもかまいません。
    
    You can definitely use your libft.
    
- エラーを徹底的に処理しなければなりません。プログラムが予期せず終了するようなことがあってはなりません (セグメンテーションエラー、バスエラー、ダブルフリー、など)。
    
    You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
    
- メモリリークを起こさないこと。
    
    Your program mustn’t have memory leaks.
    
- グローバル変数は1つのプログラムにつき1つ（クライアント用とサーバー用）持つことができます。ただし、その使用の正当性を証明する必要があります。
    
    You can have one global variable per program (one for the client and one for the server), but you will have to justify their use.
    
- 必須パートを完了するために、以下のものを使用することが許されています。
関数を使用してください。
    
    write,  ft_printf and any equivalent YOU coded, signal, sigemptyset, sigaddset., sigaction, kill
    ,getpid, malloc, free, pause, sleep, usleep, exit
    

## Mandatory Part

クライアントとサーバーの形で通信プログラムを作成する必要があります。

You must create a communication program in the form of a client and a server.

- まず、サーバーを起動しなければなりません。起動後、PIDを表示する必要があります。
    
    The server must be started first. After its launch, it has to print its PID.
    
- クライアントは2つのパラメータを受け取ります。
    
    The client takes two parameters:
    
    - サーバーのPID
        
        The server PID.
        
    - 送信する文字列
        
        The string to send.
        
- クライアントは、パラメータとして渡された文字列をサーバーに送信しなければならない。
文字列を受信したら、サーバーはそれを表示しなければならない。
    
    The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
    
- サーバーは、かなり速く文字列を表示しなければならない。素早くというのは、もしあなたが
時間がかかりすぎると思ったら、それはおそらく長すぎるのです
    
    The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
    

> 100文字表示で1秒はやりすぎ！？
1 second for displaying 100 characters is way too much!
> 

サーバーは、再起動することなく、複数のクライアントから連続して文字列を受信できるはずです。

Your server should be able to receive strings from several clients in a row without
needing to restart.

- クライアントとサーバ間の通信は、UNIXのシグナルだけを使う必要があります。
UNIXのシグナルを使わなければなりません。
    
    The communication between your client and your server has to be done only using
    UNIX signals.
    
- 使用できるシグナルは次の2つだけです。SIGUSR1 と SIGUSR2 です
You can only use these two signals: SIGUSR1 and SIGUSR2.

> Linuxシステムは、すでに保留中のシグナルがある場合、シグナルをキューに入れることはありません。ボーナスタイム？
Linux system does NOT queue signals when you already have pending signals of this type! Bonus time?
> 

## Bonus Part

- サーバーは受信したすべてのメッセージに対して、クライアントにシグナルを送り返すことで承認します。
- Unicode 文字対応
