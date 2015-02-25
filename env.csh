#!/bin/csh

# Path for Madagascar installation directory
setenv RSFROOT /Volumes/Communal/OSX/code-dev/RSF

# Path for Madagascar source directory
setenv RSFSRC /Volumes/Communal/OSX/code-dev/RSFSRC

# Path for Python packages
if ($?PYTHONPATH) then
setenv PYTHONPATH $RSFROOT/lib/python2.7/site-packages:${PYTHONPATH}
else
setenv PYTHONPATH $RSFROOT/lib/python2.7/site-packages
endif

# Path for binary data files part of RSF datasets
setenv DATAPATH /Volumes/Communal/OSX/tmp/

# Path for manual pages
setenv MANPATH `manpath`:$RSFROOT/share/man

# Path for shared object files
if ($?LD_LIBRARY_PATH) then
setenv LD_LIBRARY_PATH $RSFROOT/lib:${LD_LIBRARY_PATH}
else
setenv LD_LIBRARY_PATH $RSFROOT/lib
endif

# Path for executables
set path = ($RSFROOT/bin $path)
