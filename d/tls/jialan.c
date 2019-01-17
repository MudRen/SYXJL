// jialan.c

inherit ROOM;

void create()
{
        set("short", "伽蓝殿");
        set("long", @LONG
这是忠心护法伽蓝神殿，正中供奉着波斯匿王，左方是氏陀太子，右
边为给孤独长者。殿内两侧供奉着十八位伽蓝神。他们名字分别为：美音
梵音，天鼓，叹妙，叹美，摩妙，雷音，妙叹，梵想，人音，佛奴，颂德，
广目，妙眼，彻听，彻视，遍观。
LONG
        );
        set("exits", ([
                "east" : __DIR__"sanwugong",
                "west" : __DIR__"shengdian",
]));
        set("objects", ([
                __DIR__"npc/bencan": 1,
])); 
        set("no_clean_up", 0);
        set("coor/x",-70);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-70);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-70);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-70);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="west" && (!me->query("family") 
                || me->query("family")["family_name"]!="天龙寺"))
                return notify_fail("路中间竖着一个“石碑”，上面写到：非天龙寺弟子，请勿进入。\n");
        return ::valid_leave(me,dir);
}
