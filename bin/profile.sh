PWD=`pwd`
WORK_ROOT=${PWD%/*}
LD_LIBRARY_PATH=$WORK_ROOT/lib:/usr/lib64:/usr/lib:/usr/openwin/lib:/usr/local/lib:$HOME/tools/valgrind/lib
PATH=./:$WORK_ROOT/bin:$HOME/tools/valgrind/bin:$PATH

export WORK_ROOT
export LD_LIBRARY_PATH
export PATH

#alias pss='ps -ef|grep -v grep| grep -w'
#alias pp='pss hydog; pss dispatch_center;pss gateway;pss media_node;pss alarm_manage_center'
#alias pmem='ps -ef | grep valgrind'
