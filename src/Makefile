all:
	rm -rf $(WORK_ROOT)/src/openssl && rm -rf $(WORK_ROOT)/src/openssl-1.0.1e
	#cp -r $(WORK_ROOT)/src/openssl-1.0.1e.tar.gz $(WORK_ROOT)/src/openssl-1.0.1e.tar.gz
	tar -zxf $(WORK_ROOT)/src/openssl-1.0.1e.tar.gz
	#rm -rf $(WORK_ROOT)/src/openssl-1.0.1e.tar.gz
	cd $(WORK_ROOT)/src/openssl-1.0.1e && ./config --prefix=$(WORK_ROOT)/src/openssl shared
	cd $(WORK_ROOT)/src/openssl-1.0.1e && make && make install
	rm -rf $(WORK_ROOT)/src/openssl-1.0.1e
	rm -f $(WORK_ROOT)/lib/libcrypto.so* $(WORK_ROOT)/lib/libssl.so*
	cp -f $(WORK_ROOT)/src/openssl/lib/libcrypto.so.1.0.0 $(WORK_ROOT)/lib/libcrypto.so.1.0.0
	cp -f $(WORK_ROOT)/src/openssl/lib/libssl.so.1.0.0 $(WORK_ROOT)/lib/libssl.so.1.0.0
	cp -f $(WORK_ROOT)/lib/libcrypto.so.1.0.0 $(WORK_ROOT)/lib/libcrypto.so
	cp -f $(WORK_ROOT)/lib/libssl.so.1.0.0 $(WORK_ROOT)/lib/libssl.so
	
	cd $(WORK_ROOT)/src/simple_uv && make clean && make
	cd $(WORK_ROOT)/src/uvtest && make clean && make
	cd $(WORK_ROOT)/src/testclient && make clean && make
	
uv:
	cd $(WORK_ROOT)/src/simple_uv && make clean && make
	cd $(WORK_ROOT)/src/uvtest && make clean && make
	cd $(WORK_ROOT)/src/testclient && make clean && make
	

clean:
	cd $(WORK_ROOT)/src/simple_uv && make clean
	cd $(WORK_ROOT)/src/uvtest && make clean
	cd $(WORK_ROOT)/src/testclient && make clean
