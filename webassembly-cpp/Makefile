hello:
	emcc hello.c -s WASM=1 -o hello.html

hello2:
	emcc -o hello2.html hello2.c -O3 -s WASM=1 --shell-file html_template/shell_minimal.html

develop:
	python -m http.server
