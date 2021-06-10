hello:
	emcc hello.c -s WASM=1 -o hello.html

hello2:
	emcc -o hello2.html hello2.c -O3 -s WASM=1 --shell-file html_template/shell_minimal.html

hello3:
	emcc -o hello3.html hello3.c -O3 -s WASM=1 --shell-file html_template/shell_minimal.html -s NO_EXIT_RUNTIME=1  -s "EXPORTED_RUNTIME_METHODS=['ccall']"

develop:
	python -m http.server
