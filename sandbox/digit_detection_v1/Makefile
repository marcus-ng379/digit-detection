run: CMakeLists.txt
	@mkdir -p build
	@cd build && cmake ..
	@cd build && cmake --build .
	@./build/Digit_Detection
	@$(MAKE) clean

clean:
	@rm -rf build