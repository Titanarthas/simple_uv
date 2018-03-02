#1、定义您自己的宏，比如您自己模块根目录
LIBUV_DIR=$(WORK_ROOT)/src/libuv/include
SRC_DIR=$(WORK_ROOT)/src/simple_uv
#2、定义您自己的可执行文件名称
PLUGIN_NAME=$(WORK_ROOT)/lib/libsimple_uv

##################################################################### #

#3、指定您必须生成的工程文件
SOURCE = $(wildcard $(WORK_ROOT)/src/simple_uv/*.cpp) 
##################################################################### #

#5、指定您附加的搜索编译目录，不要指到其他模块内部
USER_CC_INC = -I$(LIBUV_DIR) -I$(SRC_DIR) -I$(WORK_ROOT)/src -I$(WORK_ROOT)/src/openssl/include/

######################################################################

######################################################################

USER_CC_FLAG =  $(PIC) 
USER_CC_FLAG =  $(PIC) -std=c++11 -fvisibility=hidden -fvisibility-inlines-hidden -D__STDC_CONSTANT_MACROS
#-fvisibility=hidden -fvisibility-inlines-hidden
#7、指定您附加的库文件搜索目录，例如：-L./MYSUBDIR
USER_LINK_INC = -L$(WORK_ROOT)/lib 

######################################################################

#8、指定您附加的库文件，例如：-lhello（假设您的动态库名称为libhello.so）
USER_LINK_LIBS = -luv -lcrypto -lssl

######################################################################

#9、包含统一文件，用来定义编译环境，不要更改
include $(WORK_ROOT)/mk_inc/rules.mak

$(PLUGIN_NAME).so: $(OBJECTS)
	@rm -rf $(PLUGIN_NAME).so
	@rm -rf $(MODULE_TEMPLATES_FILE)
	$(SOLINK.cc) $(PLUGIN_NAME).so $(OBJECTS) $(LINK_ARG)
	chmod a+rx $(PLUGIN_NAME).so
	
all: $(PLUGIN_NAME).so
	@echo "[Complier end   time -- `date`]"

