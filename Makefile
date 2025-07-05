CMAKE = cmake 

main: builddir
	cd builddir && ninja 
	cp builddir/game .

builddir:
	mkdir builddir 
	cd builddir && cmake -G Ninja ..

clean:
	rm -rf builddir build game

git: clean
	git add .
	git commit -m "$(shell date)"
	git push

.PHONY: git clean main