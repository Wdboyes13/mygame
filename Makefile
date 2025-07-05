CMAKE = cmake 

main: builddir
	cd builddir && ninja 

builddir:
	mkdir builddir 
	cd builddir && cmake -G Ninja ..

clean:
	rm -rf builddir build

git: clean
	git add .
	git commit -m "$(shell date)"
	git push

.PHONY: git clean main