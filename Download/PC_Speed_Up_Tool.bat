::
::PC Speed Up Tool - Speeds up your PC
::
::Copyright 2018 Dominik Reichl
::
::Developed by Dominik Reichl
::
::This program is free software; you can redistribute it and/or modify
::it under the terms of the GNU General Public License as published by
::the Free Software Foundation; either version 2 of the License, or
::(at your option) any later version.
::
::This program is distributed in the hope that it will be useful,
::but WITHOUT ANY WARRANTY; without even the implied warranty of
::MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
::GNU General Public License for more details.
::
::You should have received a copy of the GNU General Public License
::along with this program; if not, write to the Free Software
::Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
::
::As a special exception, you may use this file as part of a free software
::program without restriction.  Specifically, if other files instantiate
::templates or use macros or inline functions from this file, or you compile
::this file and link it with other files to produce an executable, this
::file does not by itself cause the resulting executable to be covered by
::the GNU General Public License.  This exception does not however
::invalidate any other reasons why the executable file might be covered by
::the GNU General Public License.
::

@echo off
GOTO CHECK

:CHECK
net session >nul 2>&1
if %errorLevel% == 0 (
	GOTO BEGIN
) else (
	echo ################################################################
	echo PC speed up tool
	echo ################################################################
	echo Administrative permissions required
	echo Detecting permissions... Failure
	echo 1 Start as administrator
	echo 2 Exit
	CHOICE /N /C:12 /M "PICK A NUMBER (1 or 2)"
	IF ERRORLEVEL ==2 GOTO EXIT
	IF ERRORLEVEL ==1 GOTO RESTART
)

:RESTART
powershell -Command "Start-Process cmd -Verb RunAs -file %0"
GOTO EXIT

:BEGIN
CLS
echo ################################################################
echo PC speed up tool
echo ################################################################
echo 1 Clear temporary files now
echo 2 Clear temporary files on every startup
echo 3 Defragment all local volumes on the disk
echo 4 Registry improvements
echo 5 Exit
CHOICE /N /C:12345 /M "PICK A NUMBER (1, 2, 3, 4 or 5)"
IF ERRORLEVEL ==5 GOTO EXIT
IF ERRORLEVEL ==4 GOTO REG
IF ERRORLEVEL ==3 GOTO DEFRAG
IF ERRORLEVEL ==2 GOTO TMPBOOT
IF ERRORLEVEL ==1 GOTO CLRTMP

:CLRTMP
del /s /f /q c:\windows\temp\*.*
rd /s /q c:\windows\temp
md c:\windows\temp
del /s /f /q C:\WINDOWS\Prefetch
del /s /f /q %temp%\*.*
rd /s /q %temp%
md %temp%
deltree /y c:\windows\tempor~1
deltree /y c:\windows\temp
deltree /y c:\windows\tmp
deltree /y c:\windows\ff*.tmp
deltree /y c:\windows\prefetch
deltree /y c:\windows\history
deltree /y c:\windows\cookies
deltree /y c:\windows\recent
deltree /y c:\windows\spool\printers
del c:\WIN386.SWP
GOTO DONE

:TMPBOOT
cls
cd %appdata%\Microsoft\Windows\Start Menu\Programs\Startup
(
  echo del /s /f /q c:\windows\temp\*.*
  echo rd /s /q c:\windows\temp
  echo md c:\windows\temp
  echo del /s /f /q C:\WINDOWS\Prefetch
  echo del /s /f /q %temp%\*.*
  echo rd /s /q %temp%
  echo md %temp%
  echo deltree /y c:\windows\tempor~1
  echo deltree /y c:\windows\temp
  echo deltree /y c:\windows\tmp
  echo deltree /y c:\windows\ff*.tmp
  echo deltree /y c:\windows\prefetch
  echo deltree /y c:\windows\history
  echo deltree /y c:\windows\cookies
  echo deltree /y c:\windows\recent
  echo deltree /y c:\windows\spool\printers
  echo del c:\WIN386.SWP
) > clrtmp.bat
GOTO DONE

:DEFRAG
cls
Defrag /C
GOTO DONE

:REG
cls
echo ################################################################
echo PC speed up tool
echo ################################################################
echo 1 Apply
echo 2 Restore Default
CHOICE /N /C:12 /M "PICK A NUMBER (1 or 2)"
IF ERRORLEVEL ==2 GOTO REG_RESTORE
IF ERRORLEVEL ==1 GOTO REG_APPLY

:REG_APPLY
cls
::[HKEY_USERS\.DEFAULT\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects]"VisualFXSetting"=dword:00000003"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\ControlAnimations]"DefaultApplied"=dword:00000000"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\CursorShadow]"DefaultApplied"=dword:00000000"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\DropShadow]"DefaultApplied"=dword:00000000"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\ListBoxSmoothScrolling]"DefaultApplied"=dword:00000000"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\ListviewShadow]"DefaultApplied"=dword:00000000"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\TaskbarAnimations]"DefaultApplied"=dword:00000000"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\TooltipAnimation]"DefaultApplied"=dword:00000000"
echo Doesn't work yet
pause
GOTO DONE

:REG_RESTORE
cls
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\ControlAnimations]"DefaultApplied"=dword:00000001"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\CursorShadow]"DefaultApplied"=dword:00000001"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\DropShadow]"DefaultApplied"=dword:00000001"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\ListBoxSmoothScrolling]"DefaultApplied"=dword:00000001"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\ListviewShadow]"DefaultApplied"=dword:00000001"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\TaskbarAnimations]"DefaultApplied"=dword:00000001"
::[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects\TooltipAnimation]"DefaultApplied"=dword:00000001"
::[HKEY_USERS\.DEFAULT\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects]"VisualFXSetting"=dword:00000001"
echo Doesn't work yet
pause
GOTO DONE

:DONE
cls
echo ################################################################
echo PC speed up tool
echo ################################################################
echo Done!
echo 1 Do something else
echo 2 Exit
CHOICE /N /C:12 /M "PICK A NUMBER (1 or 2)"
IF ERRORLEVEL ==2 GOTO EXIT
IF ERRORLEVEL ==1 GOTO BEGIN


:EXIT
cls
exit