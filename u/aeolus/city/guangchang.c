// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
set("short", "���ݹ㳡");
	set("long", @LONG
�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ���ֺ��е���
�����������������������������ݡ���������һ�ô��������̸���ڣ��ݴ�
��ǧ������䣬���������е���ʷ��֤�����ɵײ���һ���ܴ�Ķ�(shudong)����
���Կ������������Ը��ص��������������������������У�һ�ɷ������󣬶��߲�
ʱ�ش������ʵĶ�������������������������ˣ�һƬ�ྲ��
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city");

	set("item_desc", ([
		"shudong" : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�\n",
	]));

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
	]));

	set("objects", ([
		__DIR__"npc/liumang" : 2,
		__DIR__"npc/liumangtou" : 1,
 //  "/d/honghua/stealer" : 1,
	]));

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

/*
void do_rumor(object me)
{
	if (!me)    return;
	if (!userp(me)) return;
		CHANNEL_D->do_channel(this_player(),"rumor","������"+me->name()+"�ڽ����㱼ѽ��");
}
*/
void init()
{
/*	object me;
	me=this_player();
	if (!me->query_temp("armor/cloth") && me->query("race")=="����" ){
		if (time()-me->query_temp("rumor/nocloth")>10){
			me->set_temp("rumor/nocloth",time());
			call_out("do_rumor",random(5),me);
		}
	}
*/	
        add_action("do_enter", "enter");
//	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="shudong" ) 
	{
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
                         me->name() + "�Ӷ������˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
