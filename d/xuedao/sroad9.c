// sroad9.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","��ѩɽɽ��");
        set("long",@LONG
ɽ�����ػ�ѩ�����ܶ����ͱڡ�ֻ������һ�����ڣ������ƺ���
��ɽ����
LONG );
        set("exits",([
                "northdown" : __DIR__"wangyougu",
                "east"      : __DIR__"shandong2",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/shengdi" :1,
                CLASS_D("xueshan")+"/shanyong" :1,
        ]));
        set("outdoors", "xueshan");
        set("coor/x",-160);
	set("coor/y",-20);
	set("coor/z",80);
	set("coor/x",-160);
	set("coor/y",-20);
	set("coor/z",80);
	set("coor/x",-160);
	set("coor/y",-20);
	set("coor/z",80);
	set("coor/x",-160);
	set("coor/y",-20);
	set("coor/z",80);
	setup();
        replace_program(ROOM);
}

