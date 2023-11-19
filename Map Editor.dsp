# Microsoft Developer Studio Project File - Name="Map Editor" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Map Editor - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Map Editor.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Map Editor.mak" CFG="Map Editor - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Map Editor - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Map Editor - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Map Editor - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Map Editor - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "game source" /I "game header" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "INIT_GUID" /D "WIN32_LEAN_AND_MEAN" /D "FULLSCREEN" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Map Editor - Win32 Release"
# Name "Map Editor - Win32 Debug"
# Begin Group "Windows Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Game Source\DirectX.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\Gfx.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\Input.cpp"
# End Source File
# Begin Source File

SOURCE=.\WinMain.cpp

!IF  "$(CFG)" == "Map Editor - Win32 Release"

!ELSEIF  "$(CFG)" == "Map Editor - Win32 Debug"

# SUBTRACT CPP /YX

!ENDIF 

# End Source File
# End Group
# Begin Group "Windows Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\mssdk\include\ddraw.h
# End Source File
# Begin Source File

SOURCE=".\Game Header\DirectX.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\Gfx.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\Input.h"
# End Source File
# Begin Source File

SOURCE=.\WinMain.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Game Source"

# PROP Default_Filter ""
# Begin Group "Map Source"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Game Source\BlockMap.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\Level.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\Map.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\TileMap.cpp"
# End Source File
# End Group
# Begin Group "Object Source"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Game Source\Camera.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\Dropper.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\GObject.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\Person.cpp"
# End Source File
# End Group
# Begin Group "GWnd Source"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Game Source\CurrBlockGWnd.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\CurrTileGWnd.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\DialogGWnd.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\GWnd.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\MapViewGWnd.cpp"
# End Source File
# End Group
# Begin Source File

SOURCE=".\Game Source\FrameTimer.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\Game.cpp"
# End Source File
# Begin Source File

SOURCE=".\Game Source\Globals.cpp"
# End Source File
# End Group
# Begin Group "Game Header"

# PROP Default_Filter ""
# Begin Group "Map Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Game Header\BlockMap.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\Level.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\Map.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\TileMap.h"
# End Source File
# End Group
# Begin Group "Object Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Game Header\Camera.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\Dropper.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\GObject.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\Person.h"
# End Source File
# End Group
# Begin Group "GWnd Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Game Header\CurrBlockGWnd.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\CurrTileGWnd.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\DialogGWnd.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\GWnd.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\MapViewGWnd.h"
# End Source File
# End Group
# Begin Source File

SOURCE=".\Game Header\FrameTimer.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\Game.h"
# End Source File
# Begin Source File

SOURCE=".\Game Header\Globals.h"
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\mssdk\lib\dxguid.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk\lib\ddraw.lib
# End Source File
# Begin Source File

SOURCE=..\..\mssdk\lib\dinput.lib
# End Source File
# End Target
# End Project
