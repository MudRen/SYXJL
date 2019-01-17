#include <ansi.h>
void auto_quest(int duration);
inherit F_DBASE;
string *quest = ({
"/d/baituo/bridge",
"/d/baituo/cao1",
"/d/baituo/cao2",
/*
"/d/baituo/caomeide",
"/d/baituo/caoping",
"/d/baituo/cave",
"/d/baituo/cave1",
"/d/baituo/cedong",
"/d/baituo/chaifang",
"/d/baituo/changlang",
"/d/baituo/chufang",
"/d/baituo/damen",
"/d/baituo/datiepu",
"/d/baituo/dating",
"/d/baituo/dongjie",
"/d/baituo/dongkou",
"/d/baituo/dongnei",
"/d/baituo/fang",
"/d/baituo/fende",
"/d/baituo/gebi",
"/d/baituo/guangchang",
"/d/baituo/houmen",
"/d/baituo/houyuan",
"/d/baituo/huayuan",
"/d/baituo/jiudian",
"/d/baituo/liangong",
"/d/baituo/menlang",
"/d/baituo/midao",
"/d/baituo/neishi",
"/d/baituo/nongshe",
"/d/baituo/shanlu",
"/d/baituo/shanlu1",
"/d/baituo/shijie",
"/d/baituo/shulin",
"/d/baituo/shulin1",
"/d/baituo/tuyuan",
"/d/baituo/wuqiku",
"/d/baituo/xiaolu1",
"/d/baituo/xiaolu2",
"/d/baituo/xiaolu3",
"/d/baituo/xiaolu4",
"/d/baituo/xijie",
"/d/baituo/ximen",
"/d/baituo/yaofang",
"/d/baituo/yuanzi",
"/d/baituo/zhulin",
"/d/baituo/zhuyuan",
"/d/city/beidajie1",
"/d/city/beidajie2",
"/d/city/beimen",
"/d/city/biaoju",
"/d/city/bingqiku",
"/d/city/bingyin",
"/d/city/bingyindamen",
"/d/city/bupu",
"/d/city/caizhu",
"/d/city/chaguan",
"/d/city/datiepu",
"/d/city/dayuan",
"/d/city/dongdajie1",
"/d/city/dongdajie2",
"/d/city/dongmen",
"/d/city/dongting",
"/d/city/duchang2",
"/d/city/guangchang",
"/d/city/houyuan",
"/d/city/jiagong",
"/d/city/kedian2",
"/d/city/lichunyuan",
"/d/city/ml1",
"/d/city/ml2",
"/d/city/ml3",
"/d/city/ml4",
"/d/city/ml5",
"/d/city/ml6",
"/d/city/ml7",
"/d/city/nandajie1",
"/d/city/nandajie2",
"/d/city/nanmen",
"/d/city/neizhai",
"/d/city/pomiao",
"/d/city/qianzhuang",
"/d/city/shuyuan",
"/d/city/xidajie1",
"/d/city/xidajie2",
"/d/city/ximen",
"/d/city/xiting",
"/d/city/xixiang",
"/d/city/yamen",
"/d/city/yaopu",
"/d/city/zahuopu",
"/d/city/zuixianlou",
"/d/city/zuixianlou2",
"/d/city2/alley1",
"/d/city2/alley2",
"/d/city2/alley3",
"/d/city2/anding",
"/d/city2/aobai1",
"/d/city2/aobai10",
"/d/city2/aobai11",
"/d/city2/aobai12",
"/d/city2/aobai2",
"/d/city2/aobai3",
"/d/city2/aobai4",
"/d/city2/aobai5",
"/d/city2/aobai6",
"/d/city2/aobai7",
"/d/city2/bingqiku",
"/d/city2/bingyin1",
"/d/city2/bingyin2",
"/d/city2/bridge",
"/d/city2/bridge2",
"/d/city2/bridge3",
"/d/city2/chaguan",
"/d/city2/chaoyan1",
"/d/city2/chaoyan2",
"/d/city2/chaoyang",
"/d/city2/datiepu",
"/d/city2/di_an1",
"/d/city2/di_an2",
"/d/city2/di_an3",
"/d/city2/di_an4",
"/d/city2/di_anmen",
"/d/city2/dongcha1",
"/d/city2/dongcha2",
"/d/city2/dongchangdamen",
"/d/city2/dongmen",
"/d/city2/duchang",
"/d/city2/duchang2",
"/d/city2/entrance_road",
"/d/city2/fotang",
"/d/city2/guancai2",
"/d/city2/guancaidian",
"/d/city2/haigang",
"/d/city2/hbridge",
"/d/city2/houtai",
"/d/city2/huayuan",
"/d/city2/huichunt",
"/d/city2/jiulou1",
"/d/city2/jiulou2",
"/d/city2/kang1",
"/d/city2/kang2",
"/d/city2/kang3",
"/d/city2/kedian1",
"/d/city2/kedian2",
"/d/city2/kedian3",
"/d/city2/kedian4",
"/d/dali/atoubu",
"/d/dali/badidian",
"/d/dali/baiyiminju",
"/d/dali/baiyiziguan",
"/d/dali/banshan",
"/d/dali/bijishan",
"/d/dali/biluoshan",
"/d/dali/biluoxueshan",
"/d/dali/bingying",
"/d/dali/buxiongbu",
"/d/dali/cangshan",
"/d/dali/cangshanlu1",
"/d/dali/cangshanzhong",
"/d/dali/caopo",
"/d/dali/center",
"/d/dali/chahuashan1",
"/d/dali/chahuashan2",
"/d/dali/chahuashan3",
"/d/dali/chahuashan4",
"/d/dali/chahuashan5",
"/d/dali/chahuashan6",
"/d/dali/changhu",
"/d/dali/dadao1",
"/d/dali/dadieshui",
"/d/dali/daduhe",
"/d/dali/dahejieeast",
"/d/dali/dahejiewest",
"/d/dali/dalangan1",
"/d/dali/dalangan2",
"/d/dali/dalinorth",
"/d/dali/dasenlin",
"/d/dali/dehuabei",
"/d/dali/dianchi",
"/d/dali/ershuiqiao",
"/d/dali/feilihu",
"/d/dali/feilihueast",
"/d/dali/feilihusouth",
"/d/dali/gaolishan1",
"/d/dali/gaolishan2",
"/d/dali/garments",
"/d/dali/gelucheng",
"/d/dali/gongmen",
"/d/dali/gudao",
"/d/dali/hebian",
"/d/dali/heilongling",
"/d/dali/heisenlin",
"/d/dali/heshang",
"/d/dali/hexi",
"/d/dali/hongsheng",
"/d/dali/hudiequan",
"/d/dali/jianchuan",
"/d/dali/jianchuankou",
"/d/dali/jinzhihe",
"/d/dali/langan1",
"/d/dali/langan2",
"/d/dali/langan3",
"/d/dali/langan4",
"/d/dali/longkou",
"/d/dali/luojiadian",
"/d/dali/lushui",
"/d/dali/lushuieast",
"/d/dali/luwang",
"/d/dali/luyuxi",
"/d/dali/milin",
"/d/dali/minadian",
"/d/dali/nianhuasi",
"/d/dali/nongtian1",
"/d/dali/nongtian2",
"/d/dali/nongtian3",
"/d/dali/nongtian4",
"/d/dali/nongtian5",
"/d/dali/northgate",
"/d/dali/paifang",
"/d/dali/qiandian",
"/d/dali/qingchi",
"/d/dali/qingxi",
"/d/dali/qingzhulin",
"/d/dali/road1",
"/d/dali/road2",
"/d/dali/road3",
"/d/dali/road4",
"/d/dali/road6",
"/d/dali/road7",
"/d/dali/sanglin",
"/d/dali/shanjian",
"/d/dali/shanlin",
"/d/dali/shanlu1",
"/d/dali/shanlu2",
"/d/dali/shanlu3",
"/d/dali/shanlu4",
"/d/dali/shanlu5",
"/d/dali/shanlu6",
"/d/dali/shanlu7",
"/d/dali/shanlu8",
"/d/dali/sheguta",
"/d/dali/shilin",
"/d/dali/shilin1",
"/d/dali/shilin2",
"/d/dali/shizilukou",
"/d/dali/shuangheqiao",
"/d/dali/shuitian",
"/d/dali/shulinwai",
"/d/dali/southgate",
"/d/dali/stoneshop",
"/d/dali/taihecheng",
"/d/dali/taiheeast",
"/d/dali/taihejiekou",
"/d/dali/taiheju",
"/d/dali/taiheju2",
"/d/dali/tianweijing",
"/d/dali/titian1",
"/d/dali/tusifu",
"/d/dali/wangfugate",
"/d/dali/wangfulu",
"/d/dali/wuding",
"/d/dali/wumeng",
"/d/dali/wunong",
"/d/dali/wuyiminju1",
"/d/dali/wuyiminju2",
"/d/dali/wuyiminju3",
"/d/dali/wuyiminju4",
"/d/dali/xiaguan",
"/d/dali/xiaodao1",
"/d/dali/xiaodao2",
"/d/dali/xiaojing",
"/d/dali/xingyunhu",
"/d/dali/xizhou",
"/d/dali/yanan1",
"/d/dali/yanan2",
"/d/dali/yanchi1",
"/d/dali/yanchi2",
"/d/dali/yanchi3",
"/d/dali/yangcanfang",
"/d/dali/yangzong",
"/d/dali/yaoshop",
"/d/dali/yixibu",
"/d/dali/yuhuayuan",
"/d/dali/yujia",
"/d/dali/yujie",
"/d/dali/yulin",
"/d/dali/yuxiashan",
"/d/dali/yuxuguanqian",
"/d/dali/zhenxiong",
"/d/dali/zhulin",
"/d/dali/zhulin2",
"/d/dali/zhulou1",
"/d/dali/zhulou2",
"/d/dali/zhulou3",
"/d/dali/zhulou4",
"/d/dali/zhulou5",
"/d/emei/beicemen",
"/d/emei/beilang",
"/d/emei/beilang1",
"/d/emei/beilang2",
"/d/emei/bgsgate",
"/d/emei/chfang1",
"/d/emei/chfang10",
"/d/emei/chfang11",
"/d/emei/chfang12",
"/d/emei/chfang2",
"/d/emei/chfang3",
"/d/emei/chfang4",
"/d/emei/chfang5",
"/d/emei/chfang6",
"/d/emei/chfang7",
"/d/emei/chfang8",
"/d/emei/chfang9",
"/d/emei/dadian",
"/d/emei/dcmen",
"/d/emei/dian1",
"/d/emei/dian2",
"/d/emei/dian3",
"/d/emei/dian4",
"/d/emei/dlang1",
"/d/emei/dlang2",
"/d/emei/dlang3",
"/d/emei/dlang4",
"/d/emei/dlang5",
"/d/emei/dxiang",
"/d/emei/fhuang",
"/d/emei/fuhusi",
"/d/emei/gate",
"/d/emei/gchang",
"/d/emei/guiyun",
"/d/emei/houmen",
"/d/emei/houyuan",
"/d/emei/huayuan1",
"/d/emei/huofang",
"/d/emei/jietuo",
"/d/emei/leidong",
"/d/emei/luofeng",
"/d/emei/qingyin",
"/d/emei/shanfang",
"/d/emei/shanmen",
"/d/emei/sheku",
"/d/emei/shendeng",
"/d/emei/shifang",
"/d/emei/shijie1",
"/d/emei/shijie10",
"/d/emei/shijie11",
"/d/emei/shijie12",
"/d/emei/shijie2",
"/d/emei/shijie3",
"/d/emei/shkjtou",
"/d/emei/shkrkou",
"/d/emei/shmdian",
"/d/emei/taizi",
"/d/emei/wannian",
"/d/emei/xdao1",
"/d/emei/xdao2",
"/d/emei/xfang1",
"/d/emei/xfang2",
"/d/emei/xfang3",
"/d/emei/xfang4",
"/d/emei/xiangfang",
"/d/emei/xiaodao",
"/d/emei/xicemen",
"/d/emei/xilang",
"/d/emei/xilang1",
"/d/emei/xilang2",
"/d/emei/xilang3",
"/d/emei/xilang4",
"/d/emei/xilang5",
"/d/emei/xilang6",
"/d/emei/yunvchi",
"/d/heimuya/road1",
"/d/heimuya/shidao",
"/d/heimuya/shidao2",
"/d/heimuya/shidao3",
"/d/heimuya/xingxingtan",
"/d/gumu/bzy",
"/d/gumu/jlg",
"/d/gumu/lyy",
"/d/gumu/ryy",
"/d/gumu/shanlu3",
"/d/gumu/shanxia",
"/d/gumu/shulin1",
"/d/gumu/sl1",
"/d/gumu/sl2",
"/d/gumu/sl3",
"/d/gumu/sl4",
"/d/gumu/xiaolu3",
"/d/gumu/ztm",
"/d/honghua/caoyuan",
"/d/honghua/caoyuan3",
"/d/honghua/damen",
"/d/honghua/goldroom",
"/d/honghua/shanxia",
"/d/honghua/xinxin-xia",
"/d/honghua/yixiangting",
"/d/honghua/zongduo",
"/d/honghua/zoulang",
"/d/honghua/zoulang2",
"/d/huanggon/fang1",
"/d/huanggon/fang2",
"/d/huanggon/houyuan",
"/d/huanggon/qihedian",
"/d/huanggon/zoulang1",
"/d/huanhua/bridge1",
"/d/huanhua/bridge2",
"/d/huanhua/bridge3",
"/d/huanhua/changlang",
"/d/huanhua/changlang2",
"/d/huanhua/changlang3",
"/d/huanhua/chashi",
"/d/huanhua/dating",
"/d/huanhua/guanyuge",
"/d/huanhua/huayuan",
"/d/huanhua/jianshi",
"/d/huanhua/jiantiand",
"/d/huanhua/jiashan",
"/d/huanhua/lianwuchang",
"/d/huanhua/podi",
"/d/huanhua/qiao",
"/d/huanhua/shanshiting",
"/d/huanhua/tingyulou",
"/d/huanhua/xiangfang",
"/d/huanhua/xiaoqiao",
"/d/huanhua/xiaoxuan",
"/d/huanhua/zhenmei",
"/d/huashan/baichi",
"/d/huashan/buwei1",
"/d/huashan/buwei2",
"/d/huashan/canglong",
"/d/huashan/chaoyang",
"/d/huashan/husun",
"/d/huashan/laojun",
"/d/kunlun/bayankala",
"/d/kunlun/damen",
"/d/kunlun/kekexili",
"/d/kunlun/klshanlu",
"/d/kunlun/shanjiao",
"/d/kunlun/shankou",
"/d/kunlun/shanlu",
"/d/kunlun/shanlu1",
"/d/kunlun/shanlu2",
"/d/kunlun/shanmen",
"/d/lingjiu/biguan",
"/d/lingjiu/caifeng",
"/d/lingjiu/changl1",
"/d/lingjiu/changl10",
"/d/lingjiu/changl11",
"/d/lingjiu/changl12",
"/d/lingjiu/changl13",
"/d/lingjiu/changl14",
"/d/lingjiu/changl15",
"/d/lingjiu/changl2",
"/d/lingjiu/changl3",
"/d/lingjiu/changl4",
"/d/lingjiu/changl5",
"/d/lingjiu/changl6",
"/d/lingjiu/changl7",
"/d/lingjiu/changl8",
"/d/lingjiu/changl9",
"/d/lingjiu/chufang",
"/d/lingjiu/daban",
"/d/lingjiu/dadao1",
"/d/lingjiu/dadao2",
"/d/lingjiu/damen",
"/d/lingjiu/dating",
"/d/lingjiu/huayuan",
"/d/lingjiu/jian",
"/d/lingjiu/liangong",
"/d/lingjiu/men1",
"/d/lingjiu/men2",
"/d/lingjiu/men3",
"/d/lingjiu/qiushi",
"/d/lingjiu/shanjiao",
"/d/lingjiu/shufang",
"/d/lingjiu/wuqiku",
"/d/lingjiu/xianchou",
"/d/lingjiu/xiaodao1",
"/d/lingjiu/xiaodao2",
"/d/lingjiu/xuanbing",
"/d/lingjiu/ya",
"/d/lingjiu/yan",
"/d/mj/banshanting",
"/d/mj/banshanyao1",
"/d/mj/beixiangfang",
"/d/mj/biqiku",
"/d/mj/caodi",
"/d/mj/caodi1",
"/d/mj/chashi2",
"/d/mj/danfang",
"/d/mj/diecong1",
"/d/mj/diecong2",
"/d/mj/diecong3",
"/d/mj/diecong4",
"/d/mj/diecong5",
"/d/mj/diecong6",
"/d/mj/guangchang1",
"/d/mj/guangming-ding",
"/d/mj/hongshuiqi",
"/d/mj/houtuqi",
"/d/mj/houyuan",
"/d/mj/jianyu",
"/d/mj/jumuqi",
"/d/mj/juyiting",
"/d/mj/jyentrance",
"/d/mj/liangongfang2",
"/d/mj/lianwu-chang1",
"/d/mj/lianwu-chang2",
"/d/mj/lianwu-chang3",
"/d/mj/lianwu-chang4",
"/d/mj/liehuoqi",
"/d/mj/liupeng",
"/d/mj/luzhou",
"/d/mj/neitang",
"/d/mj/niushi",
"/d/mj/qian-ting",
"/d/mj/qingcaodi",
"/d/mj/ruijinqi",
"/d/mj/shandao0",
"/d/mj/shandao1",
"/d/mj/shanjiao",
"/d/mj/shanlu1",
"/d/mj/shanlu2",
"/d/mj/shanlu3",
"/d/mj/shanlu4",
"/d/mj/shanmen",
"/d/mj/shanpo1",
"/d/mj/shanpo2",
"/d/mj/shanya",
"/d/mj/shenghuo-tang",
"/d/mj/shiwangdian",
"/d/mj/shulin",
"/d/mj/shulin1",
"/d/mj/shulin10",
"/d/mj/shulin11",
"/d/mj/shulin12",
"/d/mj/shulin2",
"/d/mj/shulin3",
"/d/mj/shulin4",
"/d/mj/shulin5",
"/d/mj/shulin6",
"/d/mj/shulin7",
"/d/mj/shulin8",
"/d/mj/shulin9",
"/d/mj/tingtang",
"/d/mj/xiaolu-1",
"/d/mj/xiaoting",
"/d/mj/xxiangfang",
"/d/mj/yuanzhenju",
"/d/mj/zhandao",
"/d/mj/zhang-shi",
"/d/mj/zoulang1",
"/d/mj/zoulang2",
"/d/mj/zoulang3",
"/d/mj/zoulang4",
"/d/mr/anbian",
"/d/mr/c13-1",
"/d/mr/c13-2",
"/d/mr/c13-3",
"/d/mr/c13",
"/d/mr/c14-1",
"/d/mr/c14-2",
"/d/mr/c14-3",
"/d/mr/c14-4",
"/d/mr/c14-5",
"/d/mr/c14",
"/d/mr/chufang",
"/d/mr/cl",
"/d/mr/cl1",
"/d/mr/cl2",
"/d/mr/fanting",
"/d/mr/hc",
"/d/mr/hc1",
"/d/mr/hc2",
"/d/mr/hc3",
"/d/mr/hc4",
"/d/mr/hffang",
"/d/mr/hhyuan",
"/d/mr/houtang",
"/d/mr/houyuan",
"/d/mr/hubian",
"/d/mr/hubian1",
"/d/mr/keting",
"/d/mr/liulin",
"/d/mr/liulin1",
"/d/mr/liulin2",
"/d/mr/liulin3",
"/d/mr/qianyuan",
"/d/mr/shiqiao",
"/d/mr/shiqiao1",
"/d/mr/shuichi",
"/d/mr/testmatou1",
"/d/mr/tingyuju",
"/d/mr/tingzi",
"/d/mr/xiaodao",
"/d/mr/xiaojing1-0",
"/d/mr/xiaojing1-1",
"/d/mr/xiaojing1",
"/d/mr/xiaojing2",
"/d/mr/xiaojing3",
"/d/mr/xiaojing4",
"/d/mr/xiaojing5",
"/d/mr/xiaojing6",
"/d/mr/xiaojing7",
"/d/mr/xiaojing8",
"/d/mr/xiaoshe",
"/d/mr/xiaoting",
"/d/mr/yunjinlou",
"/d/mr/zahuoshi",
"/d/mr/zhuangmen",
"/d/quanzhen/baguating",
"/d/quanzhen/baoquan",
"/d/quanzhen/baxiandian",
"/d/quanzhen/bwc",
"/d/quanzhen/cangjingge",
"/d/quanzhen/chexiangtan",
"/d/quanzhen/disandian",
"/d/quanzhen/donglang1",
"/d/quanzhen/donglang2",
"/d/quanzhen/donglang3",
"/d/quanzhen/donglang4",
"/d/quanzhen/donglang5",
"/d/quanzhen/dusongge",
"/d/quanzhen/gaoguanpubu",
"/d/quanzhen/guangchang",
"/d/quanzhen/guanyintai",
"/d/quanzhen/houdian",
"/d/quanzhen/houshan",
"/d/quanzhen/houyuan",
"/d/quanzhou/bamboo",
"/d/quanzhou/beimen",
"/d/quanzhou/haigang",
"/d/quanzhou/jiaxing",
"/d/quanzhou/jxnanmen",
"/d/quanzhou/laozhai",
"/d/quanzhou/nanhu",
"/d/quanzhou/nanhu1",
"/d/quanzhou/nanmen",
"/d/quanzhou/qinglong",
"/d/quanzhou/qinglong1",
"/d/quanzhou/qinglong2",
"/d/quanzhou/qinglong3",
"/d/quanzhou/qzroad1",
"/d/quanzhou/qzroad2",
"/d/quanzhou/qzroad3",
"/d/quanzhou/qzroad4",
"/d/quanzhou/qzroad5",
"/d/quanzhou/tieqiang",
"/d/quanzhou/xijie",
"/d/quanzhou/yanyu",
"/d/quanzhou/zahuopu",
"/d/quanzhou/zhongxin",
"/d/shaolin/bamboo1",
"/d/shaolin/bamboo10",
"/d/shaolin/bamboo11",
"/d/shaolin/bamboo12",
"/d/shaolin/bamboo13",
"/d/shaolin/bamboo14",
"/d/shaolin/bamboo2",
"/d/shaolin/bamboo3",
"/d/shaolin/bamboo4",
"/d/shaolin/bamboo5",
"/d/shaolin/bamboo6",
"/d/shaolin/bamboo7",
"/d/shaolin/bamboo8",
"/d/shaolin/bamboo9",
"/d/shaolin/banruo1",
"/d/shaolin/banruo2",
"/d/shaolin/banruo3",
"/d/shaolin/banruo4",
"/d/shaolin/banruo5",
"/d/shaolin/banruo6",
"/d/shaolin/banruo7",
"/d/shaolin/banruo8",
"/d/shaolin/banruo9",
"/d/shaolin/beilin1",
"/d/shaolin/beilin2",
"/d/shaolin/bydian",
"/d/shashou/enterance",
"/d/shashou/erlou",
"/d/shashou/fenglin",
"/d/shashou/fenglin1",
"/d/shashou/fenglin2",
"/d/shashou/jiaochang",
"/d/shashou/liangongfang",
"/d/taishan/baihe",
"/d/taishan/baozang",
"/d/taishan/beitian",
"/d/taishan/bixia",
"/d/taishan/daizong",
"/d/taishan/dongtian",
"/d/taishan/doumo",
"/d/taishan/ertian",
"/d/taishan/fengchan",
"/d/taishan/huima",
"/d/taishan/lianhua",
"/d/taishan/longmen",
"/d/taishan/nantian",
"/d/taishan/riguan",
"/d/taishan/shengxian",
"/d/taishan/shijin",
"/d/taishan/shixin",
"/d/taohua/bingqi",
"/d/taohua/chufang",
"/d/taohua/damen",
"/d/taohua/dating",
"/d/taohua/dayuan",
"/d/taohua/gui-in",
"/d/taohua/gui-out",
"/d/taohua/haitan",
"/d/taohua/houting",
"/d/taohua/houyuan",
"/d/taohua/hubinlu",
"/d/taohua/hubinlu1",
"/d/taohua/mudi",
"/d/taohua/qianyuan",
"/d/taohua/qianyuan1",
"/d/taohua/road1",
"/d/taohua/road2",
"/d/taohua/road3",
"/d/taohua/road4",
"/d/taohua/road5",
"/d/taohua/shiqiao",
"/d/taohua/shufang",
"/d/taohua/siguoshi",
"/d/taohua/taihu",
"/d/taohua/tanzhi",
"/d/taohua/tao0",
"/d/taohua/tao_in",
"/d/taohua/tao_out",
"/d/taohua/tingzi",
"/d/taohua/wofang",
"/d/taohua/zhangqian",
"/d/tls/banruotai",
"/d/tls/baodian",
"/d/tls/bingqifang",
"/d/tls/damen",
"/d/tls/doumugong",
"/d/tls/doushuai",
"/d/tls/fzlou",
"/d/tls/fzlou1",
"/d/tls/fzlou2",
"/d/tls/gulou",
"/d/tls/huangtianmen",
"/d/tls/jialan",
"/d/tls/jietan",
"/d/tls/munitang",
"/d/tls/ruihemen",
"/d/tls/sanwugong",
"/d/tls/shengdian",
"/d/tls/shijie1",
"/d/tls/shijie2",
"/d/tls/ta1",
"/d/tls/ta2",
"/d/tls/ta3",
"/d/tls/talin",
"/d/tls/wuchang",
"/d/tls/wuchang2",
"/d/tls/wuchang3",
"/d/tls/wuchang4",
"/d/tls/wuchangge",
"/d/tls/wujingge",
"/d/tls/wulege",
"/d/tls/wuwoge",
"/d/tls/wuwujing",
"/d/tls/xianghemen",
"/d/tls/xuanya",
"/d/tls/yaotai",
"/d/tls/yuhuayuan",
"/d/tls/zhonglou",
"/d/tls/zoulang1",
"/d/tls/zoulang2",
"/d/tls/zoulang3",
"/d/wenrou-po/shanlu",
"/d/wenrou-po/shanlu1",
"/d/wenrou-po/shanlu2",
"/d/wenrou-po/shanlu3",
"/d/wenrou-po/shanlu4",
"/d/wenrou-po/shanlu5",
"/d/wenrou-po/shanlu6",
"/d/wenrou-po/shichang",
"/d/wenrou-po/shichang1",
"/d/wudang/bolin",
"/d/wudang/cangjingge",
"/d/wudang/chaotian",
"/d/wudang/donglang1",
"/d/wudang/donglang2",
"/d/wudang/fuzhen1",
"/d/wudang/fuzhen2",
"/d/wudang/fuzhen3",
"/d/wudang/fuzhen4",
"/d/wudang/fuzhen5",
"/d/wudang/guangchang",
"/d/wudang/haohan",
"/d/wudang/hutou",
"/d/wudang/lameigt",
"/d/wudang/langmei",
"/d/wudang/liangongfang",
"/d/wudang/liantai",
"/d/wudang/nanyan",
"/d/wudang/sanlao",
"/d/wudang/sanqingdian",
"/d/wudang/santian",
"/d/wudang/shanmen",
"/d/wudang/shanmen",
"/d/wudang/shesheng",
"/d/wudang/shibapan",
"/d/wudang/shijie11",
"/d/wudang/shijie12",
"/d/wudang/shijie21",
"/d/wudang/shijie22",
"/d/wudang/shijie31",
"/d/wudang/shijie32",
"/d/wudang/shijie42",
"/d/wudang/shijie5",
"/d/wudang/shijie61",
"/d/wudang/shijie62",
"/d/wudang/shijie7",
"/d/wudang/shiliang",
"/d/wudang/shuijing",
"/d/wudang/taiziyan",
"/d/wudang/tufeiwo1",
"/d/wudang/tufeiwo2",
"/d/wudang/tufeiwo3",
"/d/wudang/tyroadct",
"/d/wudang/wdroad1",
"/d/wudang/wdroad2",
"/d/wudang/wdroad3",
"/d/wudang/wdroad4",
"/d/wudang/wdroad5",
"/d/wudang/wdroad6",
"/d/wudang/wdroad7",
"/d/wudang/wdroad8",
"/d/wudang/wulao",
"/d/wudang/wuyalin",
"/d/wudang/xiaochidian",
"/d/wudang/xiaolu1",
"/d/wudang/xiaolu2",
"/d/wudang/xiaolu4",
"/d/wudang/xiaoyuan",
"/d/wudang/xilang",
"/d/wudang/xuanwumen",
"/d/wudang/yuzheng",
"/d/wudang/zijincheng",
"/d/wudang/zixiaogong",
"/d/wugongzhen/baishulin1",
"/d/wugongzhen/baishulin2",
"/d/wugongzhen/baishulin3",
"/d/wugongzhen/baishulin4",
"/d/wugongzhen/beijie",
"/d/wugongzhen/cuipingfeng",
"/d/wugongzhen/cuipinggu",
"/d/wugongzhen/daguandao",
"/d/wugongzhen/daguandao2",
"/d/wugongzhen/dongjie",
"/d/wugongzhen/dongmen",
"/d/wugongzhen/fu-cemen",
"/d/wugongzhen/fu-ceting",
"/d/wugongzhen/fu-damen",
"/d/wugongzhen/fu-datang",
"/d/wugongzhen/fu-houyuan",
"/d/wugongzhen/fu-huating",
"/d/wugongzhen/fu-woshi",
"/d/wugongzhen/fu-xiaoyuan",
"/d/wugongzhen/fu-zhangfang",
"/d/wugongzhen/guandao1",
"/d/wugongzhen/guandao2",
"/d/wugongzhen/guanjinglou",
"/d/wugongzhen/hanguguan",
"/d/wugongzhen/houhuayuan",
"/d/wugongzhen/houhuayuan1",
"/d/wugongzhen/jiulou1",
"/d/wugongzhen/jiulou2",
"/d/wugongzhen/minju1",
"/d/wugongzhen/minju2",
"/d/wugongzhen/nanjie",
"/d/wugongzhen/road1",
"/d/wugongzhen/shanjiao",
"/d/wugongzhen/shanlu1",
"/d/wugongzhen/shanlu2",
"/d/wugongzhen/shanlu3",
"/d/wugongzhen/shanlu4",
"/d/wugongzhen/xiaocun",
"/d/wugongzhen/xiaolu1",
"/d/wugongzhen/xiaolu2",
"/d/wugongzhen/xiaomiao",
"/d/wugongzhen/xijie",
"/d/wugongzhen/ximen",
"/d/wugongzhen/zhongxin",
"/d/xiaoyao/bingqif",
"/d/xiaoyao/liangong",
"/d/xiaoyao/mubanlu",
"/d/xiaoyao/muwu1",
"/d/xiaoyao/muwu2",
"/d/xiaoyao/muwu3",
"/d/xiaoyao/pubu",
"/d/xiaoyao/qingcaop",
"/d/xiaoyao/shantang",
"/d/xiaoyao/shulin1",
"/d/xiaoyao/shulin2",
"/d/xiaoyao/shulin3",
"/d/xiaoyao/xiaodao1",
"/d/xiaoyao/xiaodao2",
"/d/xiaoyao/xiaodao3",
"/d/xiaoyao/xiaodao4",
"/d/xiaoyao/xiaodao5",
"/d/xingxiu/beijiang",
"/d/xingxiu/house",
"/d/xingxiu/house1",
"/d/xingxiu/jiayuguan",
"/d/xingxiu/luzhou",
"/d/xingxiu/nanjiang",
"/d/xingxiu/nanjiang1",
"/d/xingxiu/nanjiang2",
"/d/xingxiu/nanjiang3",
"/d/xingxiu/riyuedong",
"/d/xingxiu/saimachang",
"/d/xingxiu/shamo1",
"/d/xingxiu/shamo2",
"/d/xingxiu/shamo3",
"/d/xingxiu/shamo4",
"/d/xingxiu/shanjiao",
"/d/xingxiu/silk1",
"/d/xingxiu/silk2",
"/d/xingxiu/silk3",
"/d/xingxiu/silk4",
"/d/xingxiu/store",
"/d/xingxiu/tianroad1",
"/d/xingxiu/tianroad2",
"/d/xingxiu/tianroad3",
"/d/xingxiu/xxh1",
"/d/xingxiu/xxh2",
"/d/xingxiu/xxh3",
"/d/xingxiu/xxh4",
"/d/xingxiu/xxh5",
"/d/xingxiu/xxh6",
"/d/xingxiu/xxh7",
"/d/xingxiu/xxh8",
"/d/xingxiu/xxroad1",
"/d/xingxiu/xxroad2",
"/d/xingxiu/xxroad3",
"/d/xingxiu/xxroad4",
"/d/xingxiu/xxroad5",
"/d/xingxiu/xxroad6",
"/d/xuedao/nroad1",
"/d/xuedao/nroad2",
"/d/xuedao/nroad3",
"/d/xuedao/nroad4",
"/d/xuedao/nroad5",
"/d/xuedao/nroad6",
"/d/xuedao/nroad7",
"/d/xuedao/shandong2",
"/d/xuedao/sroad1",
"/d/xuedao/sroad2",
"/d/xuedao/sroad3",
"/d/xuedao/sroad4",
"/d/xuedao/sroad5",
"/d/xuedao/sroad6",
"/d/xuedao/sroad7",
"/d/xuedao/sroad8",
"/d/xuedao/sroad9",
"/d/xuedao/wangyougu",
"/d/xueshan/bieyuan",
"/d/xueshan/cangjingge",
"/d/xueshan/caoyuan",
"/d/xueshan/cedian1",
"/d/xueshan/cedian2",
"/d/xueshan/chang",
"/d/xueshan/dadian",
"/d/xueshan/dating",
"/d/xueshan/dilao",
"/d/xueshan/guangchang",
"/d/xueshan/houmen",
"/d/xueshan/houyuan",
"/d/xueshan/hubian1",
"/d/xueshan/hubian2",
"/d/xueshan/hubian3",
"/d/xueshan/hubian4",
"/d/xueshan/kedian",
"/d/xueshan/kufang",
"/d/xueshan/midao",
"/d/xueshan/mishi",
"/d/xueshan/neidian",
"/d/xueshan/shanjiao",
"/d/xueshan/shanlu1",
"/d/xueshan/shanlu2",
"/d/xueshan/shanmen",
"/d/xueshan/shenghu",
"/d/xueshan/tiantai",
"/d/xueshan/tulu1",
"/d/xueshan/tulu2",
"/d/xueshan/tulu3",
"/d/xueshan/xiaoyuan",
"/d/xueshan/zoulang1",
"/d/xueshan/zoulang2",
*/
"/d/xueshan/zoulang3"

});

void create()
{
        seteuid(getuid());
        set("name", "������");
        set("channel_id", "������(autoquest)");
        set("id", "autoquest");
        CHANNEL_D->do_channel( this_object(), "sys", "Ѱ��ϵͳ�Ѿ�������\n");
        remove_call_out("auto_quest");
        call_out("auto_quest", 5,0);
}

void auto_quest(int duration)
{
        object obj;
        obj = new("/u/byt/baowu/npc/xu");
        obj->move(quest[random(5)]);
	remove_call_out("auto_save");
	call_out("auto_quest", 50+random(10), duration);        
}