// writed by shadow

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʦ�����" );
        set("long",
"\n        ��������ʦ����ҽ����ĵط����������ʲô����Ҫ����ʦ��̣�\n"
"��������������(post)�������������ǣ�浽���ջ����Ѿ��ڰ����ļ���\n"
"����ϸ˵������ʦ�ǾͲ�һ����ش�¥������ʦ��Ϣ�ң�һ����ҵ���\n"
"�����ϲ�ȥ�ˡ�\n\n"
""YEL"   1) ����Ϸ�ĸп�����ɧ�뷢�������ݿ͵����԰塣\n"
"   3) postǰ����ϸ������ʦ�����ԣ��������Ѿ������Ĳ��ٴ���\n"
"   4) ����Ϸ���������post���ṩ��ϸ���ݣ������账��\n"
"   5) ����������������ɾ������������ߵĴ����ҹ��档"NOR"\n\n"
);
        set("no_fight", "1");
	set("no_study", 1);
        set("no_sleep_room", 1);
        set("no_yun", "1");
        set("exits", ([
                "up" : __DIR__"wizard_room",
                "southeast" : "/d/city/wumiao",

        ]));

         create_door("southeast", "����", "northwest");

        set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	setup();

        call_other("/clone/board/towiz_b", "???");
}

void init()
{
        add_action("do_look","l");
        add_action("do_look","look");
}

int do_look(string arg)
{
        object me=this_player();
        if ( !arg ) return 0;
        if ( arg == "up" && !wizardp(me) && wizhood(me) !="(immortal)" ) {
                write("�����ϱߺܸߣ�������ʲôҲ�����塣\n");
               return 1;
       }
       if ( arg == "board" ) {
               write("����һ��ר�Ÿ������������ʦ���������԰塣\n");
               return 1;
       }
        return 0;
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) && wizhood(me) !="(immortal)" )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}


// guest_room.c ��ʦ�����
