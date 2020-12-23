@echo off
set num=0
for %%a in (%*) do set /a num+=1

set usage_str="Usage : %0 --x86|--x64 --debug|--release sln_name project_name"

rem *************************
rem * �ж��Ƿ�Ϊ4������     *
rem *************************
if %num% neq 4 (
    echo %usage_str%
    goto :eof
) else (
    rem
)

rem *************************
rem * �жϵ�1�������Ƿ���� *
rem *************************
if "%1"=="--x86" (
   rem 
) else (
    if "%1"=="--x64" (
	rem
    ) else (
        echo "��1����������--x86/--x64"
	echo %usage_str%
	goto :eof
    )
)

rem *************************
rem * �жϵ�2�������Ƿ���� *
rem *************************
if "%2"=="--debug" (
    rem
) else (
    if "%2"=="--release" (
	rem
    ) else (
        echo "��2����������--debug/--release"
	echo %usage_str%
	goto :eof
    )
)

rem **********************************************
rem * ��3��������sln�ļ���                       *
rem *    ���.sln��׺�����ڣ����Զ�����          *
rem **********************************************
set sln_name=%3
set sln_mname=%~n3
set sln_ename=%~x3

if "%sln_ename%"==".sln" (
    rem
) else (
    set sln_name=%3.sln
)

if not exist %sln_name% (
    echo "%sln_name%������"
    goto :eof
)

rem *****************************************************************
rem * ��4��������projectĿ¼�������������ͬ����.vcxproj            *
rem *    Ҫ��project����Ŀ¼��������ͬ                              *
rem *****************************************************************
set project_dir=%4
if not exist %project_dir% (
    echo "��Ŀ%project_dir%������"
    goto :eof
)

rem ********************
rem * ���ø��ֱ������ *
rem ********************
set BUILD_CMD="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe"

rem echo %sln_name%

if "%1"=="--x86" if "%2"=="--debug" (
    set BUILD_CONFIG="Debug|x86"
    echo VS building %sln_name%/%project_dir%.vcxproj in x86/debug mode
    goto :build
) else (
    rem ifһ��Ҫ��else�����򱨴�
)

if "%1"=="--x86" if "%2"=="--release" (
    set BUILD_CONFIG="Release|x86"
    echo VS building %sln_name%/%project_dir%.vcxproj in x86/release mode
    goto :build
) else (
    rem ifһ��Ҫ��else�����򱨴�
)

if "%1"=="--x64" if "%2"=="--debug" (
    set BUILD_CONFIG="Debug|x64"
    echo VS building %sln_name%/%project_dir%.vcxproj in x64/debug mode
    goto :build
) else (
    rem ifһ��Ҫ��else�����򱨴�
)

if "%1"=="--x64" if "%2"=="--release" (
    set BUILD_CONFIG="Release|x64"
    echo VS building %sln_name%/%project_dir%.vcxproj in x64/debug mode
    goto :build
) else (
    rem ifһ��Ҫ��else�����򱨴�
)

echo %usage_str%
goto :eof

:build
rem ********************************************************************************************************************************
rem * �����ָ�� /Out��������ȱʡ�����project_dir\debug\project_dir.log�У����Ҹ��ļ���UTF-8��ʽ����cmd����ʾ���룬��Ҫ�������ҳ *
rem ********************************************************************************************************************************
set log_name=log-%sln_mname%-%project_dir%.log
echo %log_name%
if exist %log_name% ( del %log_name% )

%BUILD_CMD% %sln_name% /Rebuild %BUILD_CONFIG% /Project %project_dir% /Out %log_name%
if exist %log_name% (
    type %log_name%
) else (
    echo �޷���ʾ������Ϣ
)

echo �������
goto :eof
