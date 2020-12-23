@echo off
set num=0
for %%a in (%*) do set /a num+=1

set usage_str="Usage : %0 --x86|--x64 --debug|--release sln_name project_name"

rem *************************
rem * 判断是否为4个参数     *
rem *************************
if %num% neq 4 (
    echo %usage_str%
    goto :eof
) else (
    rem
)

rem *************************
rem * 判断第1个参数是否合理 *
rem *************************
if "%1"=="--x86" (
   rem 
) else (
    if "%1"=="--x64" (
	rem
    ) else (
        echo "第1个参数不是--x86/--x64"
	echo %usage_str%
	goto :eof
    )
)

rem *************************
rem * 判断第2个参数是否合理 *
rem *************************
if "%2"=="--debug" (
    rem
) else (
    if "%2"=="--release" (
	rem
    ) else (
        echo "第2个参数不是--debug/--release"
	echo %usage_str%
	goto :eof
    )
)

rem **********************************************
rem * 第3个参数是sln文件名                       *
rem *    如果.sln后缀不存在，则自动加上          *
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
    echo "%sln_name%不存在"
    goto :eof
)

rem *****************************************************************
rem * 第4个参数是project目录名，里面必须有同名的.vcxproj            *
rem *    要求project名和目录名必须相同                              *
rem *****************************************************************
set project_dir=%4
if not exist %project_dir% (
    echo "项目%project_dir%不存在"
    goto :eof
)

rem ********************
rem * 设置各种编译变量 *
rem ********************
set BUILD_CMD="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe"

rem echo %sln_name%

if "%1"=="--x86" if "%2"=="--debug" (
    set BUILD_CONFIG="Debug|x86"
    echo VS building %sln_name%/%project_dir%.vcxproj in x86/debug mode
    goto :build
) else (
    rem if一定要有else，否则报错
)

if "%1"=="--x86" if "%2"=="--release" (
    set BUILD_CONFIG="Release|x86"
    echo VS building %sln_name%/%project_dir%.vcxproj in x86/release mode
    goto :build
) else (
    rem if一定要有else，否则报错
)

if "%1"=="--x64" if "%2"=="--debug" (
    set BUILD_CONFIG="Debug|x64"
    echo VS building %sln_name%/%project_dir%.vcxproj in x64/debug mode
    goto :build
) else (
    rem if一定要有else，否则报错
)

if "%1"=="--x64" if "%2"=="--release" (
    set BUILD_CONFIG="Release|x64"
    echo VS building %sln_name%/%project_dir%.vcxproj in x64/debug mode
    goto :build
) else (
    rem if一定要有else，否则报错
)

echo %usage_str%
goto :eof

:build
rem ********************************************************************************************************************************
rem * 如果不指定 /Out参数，则缺省输出到project_dir\debug\project_dir.log中，而且该文件是UTF-8格式，在cmd下显示乱码，需要重设代码页 *
rem ********************************************************************************************************************************
set log_name=log-%sln_mname%-%project_dir%.log
echo %log_name%
if exist %log_name% ( del %log_name% )

%BUILD_CMD% %sln_name% /Rebuild %BUILD_CONFIG% /Project %project_dir% /Out %log_name%
if exist %log_name% (
    type %log_name%
) else (
    echo 无法显示编译信息
)

echo 编译完成
goto :eof
