##################################################################### #
#1、定义您自己的宏，比方您自己模块根目录
TEST_DIR=$(WORK_ROOT)/src/testclient
UV_DIR=$(WORK_ROOT)/src/libuv/include
SIMPLE_UV_DIR=$(WORK_ROOT)/src/simple_uv

#2、定义您自己的可执行文件名称
PROGRAM_NAME=$(WORK_ROOT)/bin/testclient
##################################################################### #
#3、指定您必须生成的工程文件

SOURCE = $(wildcard $(TEST_DIR)/*.cpp)

##################################################################### #


#4、指定您附加的搜索编译目录，不要指到其他模块内部
USER_CC_INC = -I$(TEST_DIR) \
			-I$(UV_DIR) \
			-I$(SIMPLE_UV_DIR)  -I$(WORK_ROOT)/src/openssl/include/
			

#6、指定您附加的库文件搜索目录，例如：-L./MYSUBDIR
USER_LINK_INC = -L$(WORK_ROOT)/lib

#7、指定您附加的库文件，例如：-lhello（假设您的动态库名称为libhello.so）
#USER_LINK_LIBS = -lACE -laxis2 -lsagsoapstub -lplatform -lz
USER_LINK_LIBS = -luv -lsimple_uv

USER_CC_FLAG =  $(PIC) -std=c++11
#####################################################################
#
#8、包含统一文件，用来定义编译环境，不要更改
include $(WORK_ROOT)/mk_inc/rules.mak


