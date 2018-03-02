###################################################################

###################################################################
#
OUTPUT_FLAG = -o $@

#CC_XXX flags
###################################################################
#
CC_INC = -I./ 

CC_CCFLAG = -DUSING_EPOLL -D_LINUX_PLATFORM_
CC_CCFLAG += -Wpointer-arith -m64 -D_REENTRANT -D_GNU_SOURCE -w -pipe

ifeq ($(release),1)
CC_CCFLAG += -O3 -mtune=native -march=native
else
CC_CCFLAG +=  -DDONNT_USING_MEMORY_MANAGE -ggdb -fstack-protector -fno-inline -fno-default-inline
endif

CC_LINK = -m64

ifeq ($(release),1)
CC_LINK += -O3 -mtune=native  -march=native
else
CC_LINK += -ggdb -fstack-protector 
endif
CC_LINK +=  -lpthread -lm -lrt -ldl

CC_CCFLAG += -I/usr/include/mysql

CC_LINK += -L/usr/lib64/mysql 


####################################################################
#编译开关：-misalign极大影响性能，勿要使用

ifeq ($(purify),1)
	MYCC = purify -best-effort g++
else
	ifeq ($(quantify),1)
		MYCC = quantify -best-effort g++
	else
		ifeq ($(purecov),1)
			MYCC = purecov -best-effort g++
		else
			MYCC = g++
		endif	
	endif

endif

#define compiler
##################################################
CXX           = $(MYCC)
CCC           = $(MYCC)
CC            = $(MYCC)
PIC           = -fPIC
AR            = ar
ARFLAGS       = rsuv
SOLINK.cc = $(CXX) $(PIC) -shared -o
##################################################

#
###################################################################

# Define Objects and PROGRAMS and release ....
#################################################

CC_ARG = $(CC_DFLAG)  $(STLPORT_INC) $(CC_INC) $(USER_CC_INC)  $(STLPORT_CCFLAG) $(CC_CCFLAG) $(USER_CC_FLAG)
LINK_ARG = $(CC_DFLAG)  $(STLPORT_LINK) $(CC_LINK) $(USER_LINK_INC) $(USER_LINK_LIBS)  $(STLPORT_LIBS) $(CC_LIBS)
#################################################

OBJECTS = $(SOURCE:.cpp=.o)

#################################################
.PHONY: all
all: $(PROGRAM_NAME)

display_env:
	@echo "[ Compiler: \"$(CCC)\"    Args: \"$(CC_ARG)\" ]"
	@echo "[ Linker: \"$(CCC)\"    Args: \"$(LINK_ARG)\" ]"

clean:
	@echo "[Cleanning...]"
	@rm -rf $(PROGRAM_NAME)
	@rm -rf $(PLUGIN_NAME).so
	@rm -rf $(OBJECTS) core* ir.out
	@rm -rf $(C_OBJECTS) core* ir.out
	@rm -rf *.a *.so

cl:
	@echo "[Cleanning...]"
	@rm -rf $(PROGRAM_NAME)
	@rm -rf *.o core ir.out

%.o: %.cpp
	$(COMPILE.cc) $(CC_ARG) $< $(OUTPUT_FLAG)

%.o: %.c
	$(COMPILE.cc) $(CC_ARG) $< $(OUTPUT_FLAG)

$(PROGRAM_NAME): $(OBJECTS)
	$(LINK.cc) $(OUTPUT_FLAG) $(OBJECTS) $(CC_ARG) $(LINK_ARG) 
