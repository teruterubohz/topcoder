:******************************************************************************
: eclipse -clean 起動コマンド (Windows 用)
: eclipse.exe と同じディレクトリに置いて使用。
:******************************************************************************
start /d "%~dp0" .\eclipse.exe -clean %*
