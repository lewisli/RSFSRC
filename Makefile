SCONS = RSFROOT=/Volumes/Communal/OSX/code-dev/RSF PYTHONPATH=/Volumes/Communal/OSX/code-dev/RSF/lib/python2.7/site-packages:/Users/lewisli/code-dev/RSF/lib/python2.7/site-packages:/Users/lewisli/code-dev/madagascar-1.6.5/book/Recipes:/Users/lewisli/code-dev/madagascar-1.6.5/book /Users/lewisli/code-dev/RSF/bin/scons

all:
	$(SCONS)

install:
	$(SCONS) install

clean:
	$(SCONS) -c
	rm .sconsign*

distclean:
	$(SCONS) -c install
	rm -r .sconsign* build

