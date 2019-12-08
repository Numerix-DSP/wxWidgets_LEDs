@echo off

rem Build the application for Borland C++ V5.5.1 and wxWidgets > 2.6.0

bakefile -f borland project.bkl

make -f makefile.bcc -Dbuild=RELEASE -DWX_DEBUG=0

echo Done
