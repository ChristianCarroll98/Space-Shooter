#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/573e22a/Bullet.o \
	${OBJECTDIR}/_ext/573e22a/Enemy.o \
	${OBJECTDIR}/_ext/573e22a/Entity.o \
	${OBJECTDIR}/_ext/573e22a/Explosion.o \
	${OBJECTDIR}/_ext/573e22a/Level.o \
	${OBJECTDIR}/_ext/573e22a/Pickup.o \
	${OBJECTDIR}/_ext/573e22a/Player.o \
	${OBJECTDIR}/GUI.o \
	${OBJECTDIR}/Graph.o \
	${OBJECTDIR}/Window.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`C:/MinGW/fltk-1.3.3/fltk-config --cxxflags` -std=gnu++11 
CXXFLAGS=`C:/MinGW/fltk-1.3.3/fltk-config --cxxflags` -std=gnu++11 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/MinGW/fltk-1.3.3/lib -lfltk

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/project.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/project.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/project ${OBJECTFILES} ${LDLIBSOPTIONS} `C:/MinGW/fltk-1.3.3/fltk-config --ldflags --use-images` -static-libgcc -static-libstdc++

${OBJECTDIR}/_ext/573e22a/Bullet.o: /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Bullet.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/573e22a
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/573e22a/Bullet.o /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Bullet.cpp

${OBJECTDIR}/_ext/573e22a/Enemy.o: /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Enemy.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/573e22a
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/573e22a/Enemy.o /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Enemy.cpp

${OBJECTDIR}/_ext/573e22a/Entity.o: /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Entity.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/573e22a
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/573e22a/Entity.o /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Entity.cpp

${OBJECTDIR}/_ext/573e22a/Explosion.o: /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Explosion.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/573e22a
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/573e22a/Explosion.o /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Explosion.cpp

${OBJECTDIR}/_ext/573e22a/Level.o: /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Level.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/573e22a
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/573e22a/Level.o /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Level.cpp

${OBJECTDIR}/_ext/573e22a/Pickup.o: /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Pickup.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/573e22a
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/573e22a/Pickup.o /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Pickup.cpp

${OBJECTDIR}/_ext/573e22a/Player.o: /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Player.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/573e22a
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/573e22a/Player.o /C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project/Player.cpp

${OBJECTDIR}/GUI.o: GUI.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GUI.o GUI.cpp

${OBJECTDIR}/Graph.o: Graph.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph.o Graph.cpp

${OBJECTDIR}/Window.o: Window.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Window.o Window.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/fltk-1.3.3 -I/C/Users/Christian/Desktop/School/Spring\ 2017/Computer\ Science\ II/Project/Netbeans\ Project\ Folder/Project -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
