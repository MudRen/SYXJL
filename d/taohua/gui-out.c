#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "ׯ�ڵ�·");
        set("long",@LONG
����һ���������ѵ�С·���������Ÿ�����ľ����ס��
������ߡ�΢�������������Χ�����ĵġ�Զ��ż������һ
����С��㲻���뵽��"���ˣ��Ҹò�����·�˰ɡ�"
LONG
        );
       set("exits", ([
     "south" : __DIR__"houting",
     "north" : __DIR__"gui0",
]));
    
        set("outdoors","taohua");

        set("coor/x",10);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}
void init()
{       object ob;
        mapping myfam;
        if( interactive( ob = this_player()))
        if(query("exits/north")) 
        if ((int)ob->query_skill("qimen-wuxing",1) >= 70 )
        {
        delete("exits/north");
        set("exits/north", __DIR__"gui-in");
	return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "�һ���")
        {
        delete("exits/north");
        set("exits/north", __DIR__"gui-in");
	return ;
        }       
  	delete("exits/north");
        set("exits/north", __DIR__"gui0");
}