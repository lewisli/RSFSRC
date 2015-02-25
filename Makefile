SCONS = RSFROOT=/home/lewisli/code-dev/RSF PYTHONPATH=/home/lewisli/code-dev/RSF/lib/python2.7/site-packages:/home/lewisli/code-dev/RSF/lib/python2.7/site-packages /home/lewisli/code-dev/RSF/bin/scons

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

