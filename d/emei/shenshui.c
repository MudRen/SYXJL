#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��ˮ��");
        set("long",
"�����Ƕ�ü�ɷ�ɽ�ϵ������ڣ��������ʯ�Ͽ��ż������֡�"HIW"���"NOR"��\n"
"�Ȼ������ұڣ������Ǿ����������ڼ�ָ����ͣ����˲�����࣬·����\n"
"һ����Ժ����ǰվ�ż�����ã��ֳֳ������ƺ����̲��ž������ˣ��˵ز���\n"
"���������ǿ��߰ɡ�\n"
        );

        set("exits", ([
                "southdown" : __DIR__"shijie2",
		"northup" : __DIR__"qingyin",        
               ]));
         set("objects",([
//           __DIR__"npc/xiaofan2" : 1,
            ]));
        set("no_fight",1);
        set("no_yun",1);
        set("no_beg",1);
        set("no_setal",1);
        set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",80);
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",80);
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",80);
	setup();
        replace_program(ROOM);
}
